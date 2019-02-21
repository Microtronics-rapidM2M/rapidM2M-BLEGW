/**
 * Display module
 * Include functions to control TFT Display
 */
#pragma library DISPLAY

/**
 * <summary>
 *   Display app state.
 * </summary>
 */
const
{
  DISPLAY_APP_STATE_NON = 0,
  DISPLAY_APP_STATE_OK,
  DISPLAY_APP_STATE_CALIB,
  DISPLAY_APP_STATE_SERVICE,
  DISPLAY_APP_STATE_ERROR,         /* u32Count = error number */
  DISPLAY_APP_STATE_LOADER,        /* u32Count = loader state (0-8) */
  DISPLAY_APP_STATE_CONNECTION,    /* u32Count = conn. bar (1-3) */
  DISPLAY_APP_STATE_SYNC,          /* u32Count = sync. bar (1-3) */
  DISPLAY_APP_STATE_CHECK_GSM,     /* u32Count = time (0-5min) [s] */
  DISPLAY_APP_STATE_RETRY,         /* u32Count = retry count */
  DISPLAY_APP_STATE_BLE_CONNECT,   /* u32Count = conn. bar (1-3) */
  DISPLAY_APP_STATE_CONNECT_PCM,   /* u32Count = conn. bar (1-3) */
  DISPLAY_APP_STATE_SHOW_SETUP,    /* show setup mode with last RSSI values */
  DISPLAY_APP_STATE_PCM_OK,        /* ok for myDatalogPCM */
  DISPLAY_APP_STATE_SERVICE_MD,    /* service module */
  DISPLAY_APP_STATE_TRANSPORT,     /* transport mode */
  DISPLAY_APP_STATE_SPLASH_SCREEN, /* splash screen */
};

#define DISPLAY_STATE_PCM_FLAG 0x01 /* flag for PCM communication is ok */
#define DISPLAY_STATE_BLE_FLAG 0x02 /* flag for BLE connection is ok */
#define DISPLAY_STATE_SRV_FLAG 0x04 /* flag for last server connection was ok */

/**
 * <summary>
 *   DateTime structure.
 * </summary>
 * <param name="Name">
 *   Name of Sensor / Application.
 *   Text of SplashScreen.
 * </param>
 * <param name="State">
 *   State of device (see App state.).
 * </param>
 * <param name="Count">
 *   Count (different behavour of .State, see App state.).
 * </param>
 * <param name="GSM_Signal">
 *   GSM signal strength [dB].
 * </param>
 * <param name="SOC">
 *   SOC [%].
 * </param>
 * <param name="Temp">
 *   Temperatur [°C].
 * </param>
 * <param name="Service">
 *   Next service intervall [day].
 * </param>
 * <param name="Calib">
 *   Next calib intervall [day].
 * </param>
 * <param name="Value">
 *   Value [ppm].
 * </param>
 * <param name="RSSI values of startup mode">
 *   array[6] of RSSI [dB].
 * </param>
 * <param name="PCMState">
 *   PCMState of PCM:
 *   DISPLAY_STATE_PCM_FLAG - communication with PCM ok
 *   DISPLAY_STATE_BLE_FLAG - communication with BLE module ok
 *   DISPLAY_STATE_SRV_FLAG - communication with server ok
 * </param>
 * <param name="Unit">
 *   Unit to display
 * </param>
 * <param name="SerNumBig">
 *   SerNum to display at Module Calibration/Service
 * </param>
 * <param name="SensorCount">
 *   count of actual sensor displayed (1 - SensorMax)
 * </param>
 * <param name="SensorMax">
 *   count of maximum sensors inserted
 * </param>
 * <param name="Text1">
 *   first columne of SplashScreen
 * </param>
 * <param name="Text2">
 *   second columne of SplashScreen
 * </param>
 */
#define TDisplay[.Name{20}, 
                    .State, 
                    .Count, 
                    .GSM_Signal, 
                    .SOC, 
                    .Temp, 
                    .Service, 
                    .Calib, 
                    .Value, 
                    .SerNum{20}, 
                    .RSSI[6], 
                    .PCMState, 
                    .Unit{8}, 
                    .SerNumBig{20}, 
                    .SensorCount, 
                    .SensorMax,
                    .Text1{20},
                    .Text2{20}]

/**
 * <summary>
 *   Power on display (needs 300ms to be powered on).
 * </summary>
 *
 * <returns>
 *   <em>OK</em> if successful, otherwise <em>ERROR</em>.
 * </returns>
 */
native Display_On();

/**
 * <summary>
 *   Power off display.
 * </summary>
 *
 * <returns>
 *   <em>OK</em> if successful, otherwise <em>ERROR</em>.
 * </returns>
 */
native Display_Off();

/**
 * <summary>
 *   Set values to display.
 * </summary>
 *
 * <param name="values">
 *   see TDisplay.
 * </param>
 *
 * <returns>
 *   <em>OK</em> if successful, otherwise <em>ERROR</em>.
 * </returns>
 */
native Display_SetValues(values[TDisplay], len=sizeof values);