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
};

/**
 * <summary>
 *   DateTime structure.
 * </summary>
 * <param name="Name">
 *   Name of Sensor / Application.
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
 */
#define TDisplay[.Name{20}, .State, .Count, .GSM_Signal, .SOC, .Temp, .Service, .Calib, .Value, .SerNum{20}]

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