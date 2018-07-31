/**
 * rapidM2M BLEGW HW1.x specific include file
 */
#pragma library BLEGW

#include "pm"
#include "display"

/**
 * <summary>
 *   Switch Modes.
 * </summary>
 */
const
{
  SWITCH_MODE_INTERNAL = 0, // switch is controlled by FW
  SWITCH_MODE_SCRIPT,       // switch is controlled by Script
};

/**
 * <summary>
 *   Init and configure switch interface.
 * </summary>
 *
 * <param name="mode">
 *   see Switch Modes.
 * </param>
 * <param name="funcidx">
 *   Index of callback function if script mode. Function is called on switch state change.
 *   Has to be of type: public func(key);
 * </param>
 *
 * <returns>
 *   <em>OK</em> if successful, otherwise <em>ERROR</em>.
 * </returns>
 */
native Switch_Init(mode, funcidx=-1);

/**
 * <summary>
 *   Close and deactivate switch interface.
 * </summary>
 *
 * <returns>
 *   <em>OK</em> if successful, otherwise <em>ERROR</em>.
 * </returns>
 */
native Switch_Close();

/**
 * <summary>
 *   Init and configure sensor detect interface.
 * </summary>
 *
 * <param name="funcidx">
 *   Index of callback function. Function is called on sensor detect state change.
 *   Has to be of type: public func(key);
 * </param>
 *
 * <returns>
 *   <em>OK</em> if successful, otherwise <em>ERROR</em>.
 * </returns>
 */
native BLEGW_SensorDetect_Init(funcidx);

/**
 * <summary>
 *   Close and deactivate sensor detect interface.
 * </summary>
 *
 * <returns>
 *   <em>OK</em> if successful, otherwise <em>ERROR</em>.
 * </returns>
 */
native BLEGW_SensorDetect_Close();

/**
 * <summary>
 *   Sys info structure.
 * </summary>
 * <param name="Temp">
 *   Temperatur [0.1°C]
 * </param>
 * <param name="RH">
 *   Relative Humidity [0.1%RH]
 * </param>
 */
#define TBLEGW_SysValue[.Temp, .RH]

/**
 * <summary>
 *   Retrieve sys values of device.
 * </summary>
 *
 * <param name="values">
 *   Structure where sys values are filled in.
 * </param>
 * <param name="len">
 *   length of values Structure, max size according to TBLEGW_SysValue
 * </param>
 *
 * <returns>
 *   Returns:
 *   <ul>
 *     <li><em>used size of id struct</em></li>
 *     <li><em>ERROR</em> - if address/length pair for id struct is invalid or a sys value is invalid.</li>
 *   </ul>
 * </returns>
 */
native BLEGW_GetSysValues(values[TBLEGW_SysValue], len=sizeof values);

/**
 * <summary>
 *   Identification structure of BLE chip.
 * </summary>
 * <param name="FWVersion">
 *   Firmware Version of BLE chip
 * </param>
 */
#define TBLEGW_Id[.FWVersion]

/**
 * <summary>
 *   Retrieve identification of BLE chip.
 * </summary>
 *
 * <param name="id">
 *   Structure where identification is filled in.
 * </param>
 * <param name="len">
 *   length of id Structure, max size according to TBLEGW_Id
 * </param>
 *
 * <returns>
 *   Returns:
 *   <ul>
 *     <li>number of filled cells for id struct</li>
 *     <li><em>ERROR</em> - if address/length pair for id struct is invalid.</li>
 *   </ul>
 * </returns>
 */
native BLEGW_GetId(id[TBLEGW_Id], len=sizeof id);

#define TBLE_Scan[.addr_type, .addr{6}, .rssi, .name{32+1}, .msd_len, .msd{32}]
#define TBLE_Notify[.handle, .data_len, .data{32}]
#define TBLE_Read[.handle, .offset, .data_len, .data{32}]

/**
 * <summary>
 *   Maximal supported connections.
 * </summary>
 */
#define BLE_MAX_CONNECTIONS 5

/**
 * <summary>
 *   BLE states.
 * </summary>
 */
const
{
  BLE_STATE_OFF = 0,
  BLE_STATE_INIT,
  BLE_STATE_READY,
  BLE_STATE_BUSY
};

/**
 * <summary>
 *   BLE events.
 * </summary>
 */
const
{
  BLE_EVENT_SCAN = 0,
  BLE_EVENT_SCAN_RSP,
  BLE_EVENT_NOTIFY,
  BLE_EVENT_READ,
};

/**
 * <summary>
 *   Init and configure BLE interface.
 * </summary>
 *
 * <param name="funcidx">
 *   Index of event callback function. Function is called on ble events.
 *   Has to be of type: public func(event, connhandle, const data{}, len);
 * </param>
 *
 * <returns>
 *   <em>OK</em> if successful, otherwise <em>ERROR</em>.
 * </returns>
 */
native BLE_Init(funcidx);

/**
 * <summary>
 *   Close and deactivate BLE interface.
 * </summary>
 *
 * <returns>
 *   <em>OK</em> if successful, otherwise <em>ERROR</em>.
 * </returns>
 */
native BLE_Close();

/**
 * <summary>
 *   Reset BLE interface.
 * </summary>
 *
 * <returns>
 *   <em>OK</em> if successful, otherwise <em>ERROR</em>.
 * </returns>
 */
native BLE_Reset();

/**
 * <summary>
 *   Get BLE interface state.
 * </summary>
 *
 * <returns>
 *   State of BLE interface (see BLE states).
 * </returns>
 */
native BLE_GetState();

/**
 * <summary>
 *   Start scan
 * </summary>
 *
 * <param name="time">
 *   Time to scan in [s].
 * </param>
 *
 * <param name="flags">
 *   Flags for scanning.
 * </param>
 *
 * <returns>
 *   <em>OK</em> if successful, otherwise <em>ERROR</em>.
 * </returns>
 */
native BLE_Scan(time = 10, flags = 0);

/**
 * <summary>
 *   Connect to BLE device.
 * </summary>
 *
 * <param name="addr">
 *   BLE address of device.
 * </param>
 *
 * <param name="itv">
 *   Connection interval in [ms] (valid 8..1000).
 * </param>
 *
 * <returns>
 *   Connection handle if successful, otherwise <em>ERROR</em>.
 * </returns>
 */
native BLE_Connect(addr{6}, itv = -1);

/**
 * <summary>
 *   Disconnect from BLE device (device must be connected).
 * </summary>
 *
 * <param name="connhandle">
 *   Connection handle.
 * </param>
 *
 * <returns>
 *   <em>OK</em> if successful
 *   <em>ERROR</em> if error
 *   <em>ERROR-1</em> if BLE device isn't connected.
 * </returns>
 */
native BLE_Disconnect(connhandle = 0);

/**
 * <summary>
 *   Get connection state.
 * </summary>
 *
 * <param name="connhandle">
 *   Connection handle.
 * </param>
 *
 * <returns>
 *   Connection state (0 = disconnected, >0 = connected).
 * </returns>
 */
native BLE_GetConnState(connhandle = 0);

/**
 * <summary>
 *   Write to BLE device (device must be connected).
 * </summary>
 *
 * <param name="connhandle">
 *   Connection handle.
 * </param>
 *
 * <param name="handle">
 *   Handle.
 * </param>
 *
 * <param name="data">
 *   Data.
 * </param>
 *
 * <param name="size">
 *   Length of data.
 * </param>
 *
 * <returns>
 *   <em>OK</em> if successful
 *   <em>ERROR</em> if error
 *   <em>ERROR-1</em> if BLE device isn't connected.
 * </returns>
 */
native BLE_Write(connhandle = 0, handle, const data{}, size);

/**
 * <summary>
 *   Read from BLE device (device must be connected).
 * </summary>
 *
 * <param name="connhandle">
 *   Connection handle.
 * </param>
 *
 * <param name="handle">
 *   Handle.
 * </param>
 *
 * <returns>
 *   <em>OK</em> if successful
 *   <em>ERROR</em> if error
 *   <em>ERROR-1</em> if BLE device isn't connected.
 * </returns>
 */
native BLE_Read(connhandle = 0, handle);

/**
 * <summary>
 *   Change connection intervall (device must be connected).
 * </summary>
 *
 * <param name="connhandle">
 *   Connection handle.
 * </param>
 *
  * <param name="connhandle">
 *   Connection handle.
 * </param>*
 *
 * <param name="conitv">
 *   Connection interval in [ms] (valid 8..1000).
 * </param>
 *
 * <returns>
 *   <em>OK</em> if successful
 *   <em>ERROR</em> if error
 *   <em>ERROR-1</em> if BLE device isn't connected.
 * </returns>
 */
native BLE_ChgConItv(connhandle = 0, conitv);

/**
 * <summary>
 *   Set scan response data.
 * </summary>
 *
 * <param name="data">
 *   Data.
 * </param>
 *
 * <param name="size">
 *   Length of data.
 * </param>
 *
 * <returns>
 *   <em>OK</em> if successful
 *   <em>ERROR</em> if error
 *   <em>ERROR-1</em> if busy
 *   <em>OK+1</em> if adv. disabled
 * </returns>
 */
native BLE_SetScanResponseData(const data{}, size);
