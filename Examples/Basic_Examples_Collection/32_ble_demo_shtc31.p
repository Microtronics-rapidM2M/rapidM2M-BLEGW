/*
 *                  _     _  __  __ ___  __  __
 *                 (_)   | ||  \/  |__ \|  \/  |
 *  _ __ __ _ _ __  _  __| || \  / |  ) | \  / |
 * | '__/ _` | '_ \| |/ _` || |\/| | / /| |\/| |
 * | | | (_| | |_) | | (_| || |  | |/ /_| |  | |
 * |_|  \__,_| .__/|_|\__,_||_|  |_|____|_|  |_|
 *           | |
 *           |_|
 *
 * Extended "BLE" example
 *
 * The script is designed to read the current temperature and humidity for a “Sensirion SHT31 Smart Gadget” via Bluetooth Low Energy. 
 * The determined values are issued every 4sec. via the console. The scan for BLE devices and the following connection to the 
 * “Sensirion SHT31 Smart Gadget” found is triggered by closing the reed switch of the BLEGW. The BLE connection is 
 * terminated by closing the reed switch of the BLEGW again.
 *
 * 
 * Note: Before the initialisation of the BLE scan, the BLE module of the “Sensirion SHT31 Smart Gadget” 
 *       must be activated by pressing the button of the “Sensirion SHT31 Smart Gadget” for at least 1sec.
 *
 * Only compatible with BLE Gateway
 * Special hardware(Sensirion SHT31 Smart Gadget) necessary
 *
 * @version 20190712
 */

/* Path for hardware-specific include file */
#include ".\rapidM2M BLEGW\blegw"

#include <string>

//#define DEBUG

/* Forward declarations of the public functions */
forward public Timer1s();                   // Called up 1x per sec. for the program sequence
forward public KeyChanged(iKeyState);       // Called up when the reed switch is closed or opened
forward public BLE_Event(event, connhandle, const data{}, len);// Called up when a BLE event (e.g.
                                                               // data has been read) occurs

static iBLE_Enable;                         // Current BLE mode (0 = switched off, 1 = active)
static iConState;                           // Current connection state 
                                            // (0 = off, 1 = scanning, 2 = connecting, 3 = active)
static iInit = 0;                           // Initialisation state for BLE interface
                                            // (0 = not initialised, 1 = initialisation, 2 = already initialised)

static sDevice[TBLE_Scan];                  // Scan response of the device to which a connection should be established

const
{
  // BLE mode
  BLE_OFF            = 0,
  BLE_ON             = 1,

  // BLE Connection state
  STATE_OFFLINE      = 0,                   // Offline
  STATE_SCANNING     = 1,                   // Scanning for BLE devices
  STATE_CONNECTING   = 2,                   // Connecting to a specific BLE device
  STATE_ACTIVE       = 3,                   // BLE connection established
  
  // Initialisation
  STATE_NO_INIT      = 0,                   // BLE interface not initialised yet
  STATE_INIT         = 1,                   // Initialises BLE interface
  STATE_ALREADY_INIT = 2,                   // BLE interface already initialised
  
  // Measurement state
  MEASUREMENT_TEMP   = 0,                   // Reads temperature value
  MEASUREMENT_rH     = 1,                   // Reads humidity value
}

/* Application entry point */
main()
{
  /* Temporary memory for the index of a public function and the return value of a function             */
  new iIdx, iResult;

  /* Initialisation of the reed switch -> evaluation by the script activated
     - Determining the function index that should be called up when closing or opening the reed switch
     - Transferring the index to the system and inform it that the reed switch is controlled by the script
     - Index and return value of the init function are issued by the console                            */
  iIdx = funcidx("KeyChanged");                        
  iResult = Switch_Init(SWITCH_MODE_SCRIPT, iIdx);     
  printf("Switch_Init(%d) = %d\r\n", iIdx, iResult);

  /* Initialisation of a 1 sec. timer used for the general program sequence
     - Determining the function index that should be executed 1x per sec.
     - Transferring the index to the system
     - Index and function return value used to generate the timer are issued via the console            */
  iIdx = funcidx("Timer1s");
  iResult = rM2M_TimerAdd(iIdx);
  printf("rM2M_TimerAdd(%d) = %d\r\n", iIdx, iResult);
}

/* 1sec. timer is used for the general program sequence */
public Timer1s()
{
  Handle_BLE();                             // Control of the BLE communication
}

/* Control of the BLE communication */
Handle_BLE()
{
  new iBLEState;                            // Temporary memory for the BLE state
  new iResult;                              // Temporary memory for the return value of a function

  iBLEState = BLE_GetState();               // Reads current BLE status from the system
#if defined DEBUG
  printf("BLE State: %d\r\n", iBLEState);
#endif
/*
  if(iBLEState == BLE_STATE_OFF)            // If the BLE interface is off ->
  {
//    Since the state of the BLEGW is set to BLE_STATE_READY by firmware after booting, this
//    condition will never be true when using BLEGW hardware. The BLE interface also cannot be
//    closed or deactivated and is therefore never in state BLE_STATE_OFF. When connection is
//    lost, the interface will return to BLE_STATE_READY again.
  }
*/  
  if(iBLEState == BLE_STATE_READY)          // If the BLE interface is ready ->
  {
    if(iBLE_Enable == 0)                    // If BLE is switched off ->
    {
      if (BLE_GetConnState())               // If the BLE interface is connected to a device ->
      {
        BLE_Disconnect();                   // Disconnects the device
        printf("disconnecting...\r\n");
      }
      else                                  // Otherwise ->
      {
        if(iInit == STATE_NO_INIT)          // If BLE interface has not been initialised yet ->
          iInit = STATE_INIT;
        iConState = STATE_OFFLINE;          // Sets BLE Connection state to "offline"
      }
    }
    else                                    // If BLE is active ->
    {
      if(iInit == STATE_INIT)               // If BLE has not been initialised yet ->
      {
        /* Inits and configures BLE interface
           - Determining the function index that should be called up when an BLE event occurs
           - Transferring the index to the system
           - Return value of the init function is issued by the console                                   */
        iResult = BLE_Init(funcidx("BLE_Event"));
        printf("BLE_Init() %d\r\n", iResult);
        iInit = STATE_ALREADY_INIT;         // Initialisation only once when using BLEGW
      }
      // If the BLE connection state is "offline" or "Scanning for BLE devices" ->
      if( (iConState == STATE_OFFLINE) ||
          (iConState == STATE_SCANNING)   )
      {
        /* Starts next scan */
        if(BLE_Scan(10, 1) >= OK)           // If an "active scan" with 10sec. scan time could be started ->
        {
          printf("searching for BLE devices ...\r\n");
          iConState = STATE_SCANNING;       // Sets BLE Connection state to "Scanning for BLE devices"
        }
      }
      // Otherwise -> If the BLE connection state is "Connecting to a specific BLE device" ->
      else if (iConState == STATE_CONNECTING)
      {
        printf("conntecting to BLE device ...\r\n");
        // If the BLE interface could be connected to the BLE device -> Sets BLE Connection state to "BLE connection established"
        if(BLE_Connect(sDevice.addr) >= OK) iConState = STATE_ACTIVE;
      }
      // Otherwise -> If the BLE connection state is "BLE connection established" ->
      else if (iConState == STATE_ACTIVE)
      {
        static iMeasurementState;           // Static variable for the current measurement state

        switch(iMeasurementState)           // Switches current measurement state ->
        {
          case MEASUREMENT_TEMP:            // Temperature value should be read
          {
            iResult = BLE_Read(0,0x0032);   // Reads temperatur value from the "Smart Humigadget" handle 0x32
            // If the reading of the temperature could be triggered -> sets current measurement state to "Read humidity value"
            if(iResult >= OK)iMeasurementState = MEASUREMENT_rH;
          }
          case MEASUREMENT_rH:              // Humidity value should be read
          {
            iResult = BLE_Read(0,0x0037);   // Reads humidity value from the "Smart Humigadget" handle 0x37
            // If the reading of the humidity could be triggered -> Sets current measurement state to "Read temperature value"
            if(iResult >= OK)iMeasurementState = MEASUREMENT_TEMP;
          }
          // Default -> sets current measurement state to "Read temperature value"
          default: iMeasurementState = MEASUREMENT_TEMP;
        }
      }
    }
  }
}

/**
 * Function that is called up when a BLE event occurs
 *
 * @param event:s32      - BLE event that causes the call up of the callback function 
 * @param connhandle:s32 - Connection handle 
 * @param data[]:u8      - Array that contains the data associated with the event.
 *                         The structure depends on the event that occurs 
 * @param len:s32        - Size of the data block in bytes 
 */
public BLE_Event(event, connhandle, const data{}, len)
{
  // If a BLE device was found during a passive or active scan ->
  if((event == BLE_EVENT_SCAN) ||
     (event == BLE_EVENT_SCAN_RSP))
  {
    new sScan[TBLE_Scan];                   // Temporary memory for the scan response of a device

    /* Unpacks TBLE_Scan structure */
    rM2M_Pack(data, 0, sScan.addr_type, RM2M_PACK_GET|RM2M_PACK_U8);
    rM2M_GetPackedB(data, 1, sScan.addr, 6);
    rM2M_Pack(data, 7, sScan.rssi, RM2M_PACK_GET|RM2M_PACK_S8);
    rM2M_GetPackedB(data, 8, sScan.name, 32+1);
    rM2M_Pack(data, 41, sScan.msd_len, RM2M_PACK_GET|RM2M_PACK_U8);
    rM2M_GetPackedB(data, 42, sScan.msd, 32);

    // Issues the infos of the scan response via the console
    printf("BLE: \"%s\",%d,", sScan.name, sScan.rssi); // Device name and received signal strength
    printf("\"%02X:%02X:%02X:%02X:%02X:%02X\",",       // Bluetooth MAC address of the device
      sScan.addr{0}, sScan.addr{1}, sScan.addr{2},
      sScan.addr{3}, sScan.addr{4}, sScan.addr{5});
    printf("%d\r\n", sScan.addr_type);                 // Type of the address (e.g. 2 for public address)

    // If a "Smart Humigadget" has been found during the scan ->
    if(strcmp(sScan.name, "Smart Humigadget", 16) == 0)
    {
      /* Chooses this device to connect to by coping the temporary memory for the scan response to the
         static variable for the scan response of the device to which a connection should be established*/
      sDevice = sScan;

      // Sets BLE connection state to "Connecting to a specific BLE device"
      iConState = STATE_CONNECTING;
    }
  }
  // Otherwise -> If data has been read ->
  else if(event == BLE_EVENT_READ)
  {
    static iFlags = 0;                      // Indicates which values are valid (Bit0 =^ Temperature, Bit1 =^ Humidity)
    static Float: fTemp;                    // Current temperature in °C
    static Float: fRH;                      // Current humidity in %

    /* Decodes data */
    new sRead[TBLE_Read];                   // Temporary memory for the data read from a device

    /* Unpacks TBLE_Read structure
       Offset = 2 bytes because byte 0 and 1 contain the connection handle when using BLEGW */
    rM2M_Pack(data, 2, sRead.handle, RM2M_PACK_GET|RM2M_PACK_U16);
    rM2M_Pack(data, 4, sRead.offset, RM2M_PACK_GET|RM2M_PACK_U16);
    rM2M_Pack(data, 6, sRead.data_len, RM2M_PACK_GET|RM2M_PACK_U8);
    rM2M_GetPackedB(data, 7, sRead.data, 32);
    
    switch(sRead.handle)                    // Switches the handle
    {
      case 0x0032:                          // Data containing the temperature value (handle 0x32)
      {
        if(sRead.data_len == 4)
        {
          rM2M_Pack(sRead.data, 0, fRH, RM2M_PACK_GET|RM2M_PACK_F32);
          iFlags |= 0x01;
        }
      }
      case 0x0037:                          // Data containing the humidity value (handle 0x37)
      {
        if(sRead.data_len == 4)
        {
          rM2M_Pack(sRead.data, 0, fTemp, RM2M_PACK_GET|RM2M_PACK_F32);
          iFlags |= 0x02;
        }
      }
    }
    if(iFlags == 0x03)                      // If the temperature and humidity value is valid ->
    {
      iFlags = 0;                           // Clears flags indicating which values are valid

      // Issues the current values via the console
      printf("%.2f°C %.2fRH\r\n", fTemp, fRH);
    }
  }
}

/* Function that enables a transmission to be triggered when the button is pressed */
public KeyChanged(iKeyState)
{
  printf("K:%d\r\n", iKeyState);            // Issues action via the console (0=release, 1=press)

  if(!iKeyState)                            // If the button has been released ->
  {
    if(iBLE_Enable == 0)                    // If BLE is switched off ->
    {
      if(iConState == STATE_OFFLINE)        // If the BLE connection state is "offline" 
      {
        iBLE_Enable = 1;                    // Activates BLE
        print("BLE ON\r\n");
      }
    }
    else                                    // Otherwise ->
    {
      iBLE_Enable = 0;                      // Switches off BLE
      print("BLE OFF\r\n");
    }
  }                                              
}
