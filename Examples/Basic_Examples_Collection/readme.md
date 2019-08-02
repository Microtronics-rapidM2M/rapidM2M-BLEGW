## Explanation
The examples included in the basic example collection are designed to demonstrate how to use the rapidM2M Device API. In addition to the basic handling you also find best practice examples. With the increasing number at the beginning of the name, the complexity of the example increases as well. 

## Example overview
* **[00_common_0_Main.p](https://github.com/Microtronics-rapidM2M/rapidM2M-BLEGW/tree/master/Examples/Basic_Examples_Collection/00_common_0_Main.p)** <br/>
*Simple rapidM2M "Hello World"* <br/>
Prints "Hello World" to the development console once after starting the script.
* **[00_common_1_Timer_1.p](https://github.com/Microtronics-rapidM2M/rapidM2M-BLEGW/tree/master/Examples/Basic_Examples_Collection/00_common_1_Timer_1.p)** <br/>
*Extended rapidM2M "Hello World" Example* <br/>
Prints "Hello World" every second to the development console
* **[00_common_1_Timer_2.p](https://github.com/Microtronics-rapidM2M/rapidM2M-M2/blob/master/Examples/rapidM2M_Base_Starter/Basic_Examples_Collection/00_common_1_Timer_2.p)** <br/>
*Extended rapidM2M "Hello World" Example* <br/>
Prints "Hello World" every 5 seconds to the development console
* **[00_common_2_get_module_info.p](https://github.com/Microtronics-rapidM2M/rapidM2M-BLEGW/tree/master/Examples/Basic_Examples_Collection/00_common_2_get_module_info.p)** <br/>
Prints the information for identifying the rapidM2M hardware and the implemented API level to the development console.
* **[00_common_3_NamedArray.p](https://github.com/Microtronics-rapidM2M/rapidM2M-BLEGW/tree/master/Examples/Basic_Examples_Collection/00_common_3_NamedArray.p)** <br/>
*Simple "Array" Example* <br/>
A two-dimensional array is used to store several data records. <br/>
* **[00_common_4_pack.p](https://github.com/Microtronics-rapidM2M/rapidM2M-BLEGW/tree/master/Examples/Basic_Examples_Collection/00_common_4_pack.p)** <br/>
* Simple "Pack/Unpack" Example * <br/>
First packs a float32 type variable into a byte array and then unpacks the data back into a float32 type variable. After that, the float32 type variable is issued via the console. <br/>
* **[00_common_5_data_types.p](https://github.com/Microtronics-rapidM2M/rapidM2M-BLEGW/tree/master/Examples/Basic_Examples_Collection/00_common_5_data_types.p)** <br/>
*Simple "Data Types" Example* <br/>
Example on how to implement, handle and convert integer, floating-point and boolean variables in rapidM2M projects. <br/>
* **[00_common_6_array.p](https://github.com/Microtronics-rapidM2M/rapidM2M-BLEGW/tree/master/Examples/Basic_Examples_Collection/00_common_6_array.p)** <br/>
*Simple "Array" Example* <br/>
Declarations and handling of arrays and the sizeof operator <br/>
* **[00_common_7_conditional.p](https://github.com/Microtronics-rapidM2M/rapidM2M-BLEGW/tree/master/Examples/Basic_Examples_Collection/00_common_7_conditional.p)** <br/>
*Simple rapidM2M "Conditional" Example* <br/>
Example on how to use if and switch statements in rapidM2M projects <br/>
* **[00_common_8_loop.p](https://github.com/Microtronics-rapidM2M/rapidM2M-BLEGW/tree/master/Examples/Basic_Examples_Collection/00_common_8_loop.p)** <br/>
*Simple rapidM2M "Loop" Example* <br/>
Example on how to use loops in rapidM2M projects <br/>
* **[10_Switch.p](https://github.com/Microtronics-rapidM2M/rapidM2M-BLEGW/tree/master/Examples/Basic_Examples_Collection/10_Switch.p)** <br/>
*Simple "Button" Example* <br/>
Evaluates the state of a button <br/>
* **[10_Switch_Long.p](https://github.com/Microtronics-rapidM2M/rapidM2M-BLEGW/tree/master/Examples/Basic_Examples_Collection/10_Switch_Long.p)** <br/>
*Extended "Button" Example* <br/>
Evaluates the state of the button and also detects if the button was pressed only briefly or for a longer time <br/>
* **[12_Transmission_0.p](https://github.com/Microtronics-rapidM2M/rapidM2M-BLEGW/tree/master/Examples/Basic_Examples_Collection/12_Transmission_0.p)** <br/>
*Simple "Transmission" Example*<br/>
Initiates a connection to the server. The synchronisation of the configuration, registration and measurement data is automatically done by the firmware. <br/>
* **[12_Transmission_2_cyclic_connection.p](https://github.com/Microtronics-rapidM2M/rapidM2M-BLEGW/tree/master/Examples/Basic_Examples_Collection/12_Transmission_2_cyclic_connection.p)** <br/>
*Extended "Transmission" Example*<br/>
Initiates a connection to the server every 2 hours. The synchronisation of the configuration, registration and measurement data is automatically done by the firmware. <br/>
* **[12_Transmission_3_ForceOnline.p](https://github.com/Microtronics-rapidM2M/rapidM2M-BLEGW/tree/master/Examples/Basic_Examples_Collection/12_Transmission_3_ForceOnline.p)** <br/>
*Extended "Online Mode Transmission" Example*<br/>
Establishes and tries to maintain an online connection to the server. As long as the device is in online mode, a synchronisation of the configuration, registration and measurement data is initiated every 2 hours.<br/>
* **[30_System_Values_0.p](https://github.com/Microtronics-rapidM2M/rapidM2M-BLEGW/tree/master/Examples/Basic_Examples_Collection/30_System_Values_0.p)** <br/>
*Simple "System Values" Example* <br/>
Reads the last valid values for Temp and RH from the system and issues them every second via the console <br/>
* **[30_System_Values_1.p](https://github.com/Microtronics-rapidM2M/rapidM2M-BLEGW/tree/master/Examples/Basic_Examples_Collection/30_System_Values_1.p)** <br/>
*Extended "System Values" Example* <br/>
Reads the last valid values for Temp and RH periodically (record interval) from the system and stores the generated data record in the flash of the system. The measurement data generated this way is then transmitted periodically (transmission interval) to the server. <br/>
* **[30_System_Values_2.p](https://github.com/Microtronics-rapidM2M/rapidM2M-BLEGW/tree/master/Examples/Basic_Examples_Collection/30_System_Values_2.p)** <br/>
*Extended "System Values" Example* <br/>
Reads the last valid values for Temp and RH periodically (record interval) from the system and stores the generated data record in the flash of the system. The measurement data generated this way is then transmitted periodically (transmission interval) to the server. The interval for recording and transmitting measurement data can be configured via the server. <br/>
* **[30_System_Values_3.p](https://github.com/Microtronics-rapidM2M/rapidM2M-BLEGW/tree/master/Examples/Basic_Examples_Collection/30_System_Values_3.p)** <br/>
*Extended "System Values" Example* <br/>
Reads the last valid values for Temp and RH periodically (record interval) from the system and stores the generated data record in the flash of the system. The measurement data generated this way is then transmitted periodically (transmission interval) to the server. The interval for recording and transmitting measurement data as well as the transmission mode (interval, wakeup or online) can be configured via the server.
* **[32_ble_demo_shtc31.p](https://github.com/Microtronics-rapidM2M/rapidM2M-BLEGW/tree/master/Examples/Basic_Examples_Collection/32_ble_demo_shtc31.p)** <br/>
* Extended "BLE" example * <br/>
The script is designed to read the current temperature and humidity for a “Sensirion SHT31 Smart Gadget” via Bluetooth Low Energy.  The determined values are issued every 4sec. via the console. The scan for BLE devices and the following connection to the “Sensirion SHT31 Smart Gadget” found is triggered by closing the reed switch of the BLEGW. The BLE connection is terminated by closing the reed switch of the BLEGW again.<br/>
* **[32_ble_scan.p](https://github.com/Microtronics-rapidM2M/rapidM2M-BLEGW/tree/master/Examples/Basic_Examples_Collection/32_ble_scan.p)** <br/>
*Simple "BLE" example * <br/>
Scans continuously for BLE devices in advertising mode and issues the info and data of the scan response via the console. The continuous scan for BLE devices is activated by closing the reed switch. By closing the reed switch again the scan is deactivated. <br/>
* **[50_filetransfer_send_multiple.p](https://github.com/Microtronics-rapidM2M/rapidM2M-BLEGW/tree/master/Examples/Basic_Examples_Collection/50_filetransfer_send_multiple.p)** <br/>
*Extended "File transfer" Example* <br/>
Simulates receiving a big file (Uart.txt) from e.g. UART and sends it to the server. <br/>
* **[61_alarm_1.p](https://github.com/Microtronics-rapidM2M/rapidM2M-BLEGW/tree/master/Examples/Basic_Examples_Collection/61_alarm_1.p)** <br/>
*Simple "Alarm" Example* <br/>
Simulates and records (record interval) a temperature value that changes between 19°C and 31°C in 1°C steps. The measurement data generated this way is then transmitted periodically (transmission interval) to the server. If the temperature exceeds 25°C, an alarm is triggered. Once an alarm has been triggered and the temperature falls below 25°C again, the alarm is released. In both cases (when triggering or releasing the alarm) an alarm record is generated and transmitted to the server immediately.<br/>
* **[61_alarm_2.p](https://github.com/Microtronics-rapidM2M/rapidM2M-BLEGW/tree/master/Examples/Basic_Examples_Collection/61_alarm_2.p)** <br/>
*Extended "Alarm" Example* <br/>
Simulates and records (record interval) a temperature value that changes between 19°C and 31°C in 1°C steps. The measurement data generated this way is then transmitted periodically (transmission interval) to the server. If the temperature is greater than or equal to 25°C, an alarm is triggered. Once an alarm has been triggered and the temperature falls to or below 25°C - 5% (i.e. 23,75°C) again, the alarm is released. In both cases (when triggering  or releasing the alarm) an alarm record is generated and transmitted to the server immediately. </br>
* **[61_alarm_3.p](https://github.com/Microtronics-rapidM2M/rapidM2M-BLEGW/tree/master/Examples/Basic_Examples_Collection/61_alarm_3.p)** <br/>
*Extended "Alarm" Example* <br/>
Simulates and records (record interval) a temperature value that changes between 19°C and 31°C in 1°C steps. The measurement data generated this way is then transmitted periodically (transmission interval) to the server. If the temperature is greater than or equal to 25°C, an alarm is triggered. Once an alarm has been triggered and the temperature falls to or below 25°C - 5% (i.e. 23,75°C) again, the alarm is released. In both cases (when triggering or releasing the alarm) an alarm record is generated and transmitted to the server immediately. </br>
* **[Alarm.inc](https://github.com/Microtronics-rapidM2M/rapidM2M-BLEGW/tree/master/Examples/Basic_Examples_Collection/Alarm.inc)** <br/>
*Alarm interface functions* <br/>
Provides generic functions and constants for alarm implementation. <br/>

## rapidM2M Device API functions used in the examples 

Click on the name of the function to view in which example it is used.

### [Timer, date & time](http://support.microtronics.com/Developer_Documentation/Content/Developer_Documentation/sw/Pawn_rM2M_Time.htm)

<details>
<summary>**rM2M_GetTime(&hour=0, &minute=0, &second=0, timestamp=0)**</summary>
+ 50_filetransfer_send_multiple.p <br/>
</details>

<details>
<summary>**rM2M_GetDate(&year=0, &month=0, &day=0, timestamp=0)**</summary>
+ 00_common_7_conditional.p <br/>
</details>

<details>
<summary>**rM2M_GetDateTime(datetime[TrM2M_DateTime])**</summary>
+ 00_common_7_conditional.p <br/>
</details>

<details>
<summary>**rM2M_TimerAdd(funcidx)**</summary>
+ 00_common_1_Timer_1.p<br/> 
+ 10_Switch_Long.p<br/>  
+ 12_Transmission_2_cyclic_connection.p<br/>  
+ 12_Transmission_3_ForceOnline.p<br/>  
+ 30_System_Values_0.p<br/>  
+ 30_System_Values_1.p<br/>  
+ 30_System_Values_2.p<br/>
+ 30_System_Values_3.p<br/>
+ 31_i2c_sht21_0.p<br/>
+ 31_i2c_sht21_1.p<br/>
+ 31_i2c_sht21_2.p  <br/>
+ 31_i2c_tmp112_0.p<br/>
+ 31_i2c_tmp112_1.p<br/>
+ 31_i2c_tmp112_2.p<br/>
+ 32_ble_demo_shtc31.p <br/>
+ 32_ble_demo_shtc31.p <br/> 
+ 50_filetransfer_send_multiple.p <br/>
+ 61_alarm_1.p<br/>  
+ 61_alarm_2.p<br/>  
+ 61_alarm_3.p<br/> 
</details>

<details>
<summary>**rM2M_TimerRemove(funcidx)**</summary>
+ 10_Switch_Long.p<br/>
</details>

<details>
<summary>**rM2M_TimerAddExt(funcidx, bool:cyclic, time)**</summary>
+ 00_common_1_Timer_1.p<br/> 
+ 00_common_1_Timer_2.p<br/> 
+ 10_Switch_Long.p<br/>
+ 50_filetransfer_send_multiple.p<br/>
</details>

<details>
<summary>**rM2M_TimerRemoveExt(funcidx)**</summary>
+ 10_Switch_Long.p<br/>
</details>

### [Uplink](http://support.microtronics.com/Developer_Documentation/Content/Developer_Documentation/sw/Pawn_rM2M_Uplink.htm)

<details>
<summary>**rM2M_TxStart(flags=0)**</summary>
+ 12_Transmission_0.p<br/>
+ 12_Transmission_2_cyclic_connection.p<br/>
+ 12_Transmission_3_ForceOnline.p<br/>
+ 30_System_Values_1.p<br/>
+ 30_System_Values_2.p<br/>
+ 30_System_Values_3.p<br/>
+ 61_alarm_1.p<br/>
+ 61_alarm_2.p<br/>
+ 61_alarm_3.p<br/>
</details>

<details>
<summary>**rM2M_TxSetMode(mode, flags=0)**</summary>
+ 12_Transmission_3_ForceOnline.p<br/>
+ 30_System_Values_2.p<br/>
+ 30_System_Values_3.p<br/>
+ 50_filetransfer_send_multiple.p<br/>
</details>

<details>
<summary>**rM2M_TxGetStatus(&errorcode=0)**</summary>
+ 12_Transmission_3_ForceOnline.p<br/> 
</details>

<details>
<summary>**rM2M_RecData(timestamp, const data{}, len)**</summary>
+ 30_System_Values_1.p<br/>
+ 30_System_Values_2.p<br/>
+ 30_System_Values_3.p<br/>
+ 61_alarm_1.p<br/>
+ 61_alarm_2.p<br/>
+ 61_alarm_3.p<br/>
+ Alarm.inc <br/>
</details>

<details>
<summary>**rM2M_CfgRead(cfg, pos, data{}, size)**</summary>
+ 30_System_Values_2.p<br/>
+ 30_System_Values_3.p<br/>
</details>

<details>
<summary>**rM2M_CfgOnChg(funcidx)**</summary>
+ 30_System_Values_2.p<br/>
+ 30_System_Values_3.p<br/>
</details>

### [Encoding](http://support.microtronics.com/Developer_Documentation/Content/Developer_Documentation/sw/Pawn_rM2M_Encoding.htm)

<details>
<summary>**rM2M_SetPackedB(data{}, pos, const block[], size)**</summary>
+ 50_filetransfer_send_multiple.p<br/>
</details>

<details>
<summary>**rM2M_GetPackedB(const data{}, pos, block[], size)**</summary>
+ 32_ble_demo_shtc31.p <br/>
+ 32_ble_scan.p<br/>
</details>

<details>
<summary>**rM2M_Pack(const data{}, pos, &{Float,Fixed,_}:value, type)**</summary>
+ 00_common_4_pack.p <br/>
+ 30_System_Values_1.p<br/>
+ 30_System_Values_2.p<br/>
+ 30_System_Values_3.p<br/>
+ 32_ble_demo_shtc31.p <br/>
+ 32_ble_scan.p <br/>
+ 61_alarm_1.p<br/>
+ 61_alarm_2.p<br/>
+ 61_alarm_3.p<br/>
+ Alarm.inc<br/>
</details>

### [Char & String](http://support.microtronics.com/Developer_Documentation/Content/Developer_Documentation/sw/Pawn_Erweiterungen_String_Funktionen.htm)
<details>
<summary>**strlen(const string[])**</summary>
+ 50_filetransfer_send_multiple.p<br/>
</details>

<details>
<summary>**strcmp(const string1[], const string2[], length=cellmax)**</summary>
+ 32_ble_demo_shtc31.p<br/>
</details>

### [Various](http://support.microtronics.com/Developer_Documentation/Content/Developer_Documentation/sw/Pawn_Erweiterungen_Hilfsfunktionen.htm)

<details>
<summary>**getapilevel()**</summary>
+ 00_common_2_get_module_info.p<br/>
</details>

<details>
<summary>**CRC32(data{}, len, initial=0)**</summary>
+ 50_filetransfer_send_multiple.p<br/>
</details>

<details>
<summary>**rM2M_GetId(id[TrM2M_Id], len=sizeof id)**</summary>
+ 00_common_2_get_module_info.p<br/>
+ 32_ble_scan.p<br/>
</details>

<details>
<summary>**funcidx(const name[])**</summary>
+ 00_common_1_Timer_1.p<br/>
+ 00_common_1_Timer_2.p<br/>
+ 10_Switch.p<br/>
+ 10_Switch_Long.p<br/>
+ 12_Transmission_2_cyclic_connection.p<br/>
+ 12_Transmission_3_ForceOnline.p<br/>
+ 30_System_Values_0.p<br/>
+ 30_System_Values_1.p<br/>
+ 30_System_Values_2.p<br/>
+ 30_System_Values_3.p<br/>
+ 32_ble_demo_shtc31.p<br/>
+ 32_ble_scan.p <br/>
+ 50_filetransfer_send_multiple.p<br/>
+ 61_alarm_1.p<br/>
+ 61_alarm_2.p<br/>
+ 61_alarm_3.p<br/>
</details>

### [Console](http://support.microtronics.com/Developer_Documentation/Content/Developer_Documentation/sw/Pawn_Erweiterungen_Consolen_Funktionen.htm)

<details>
<summary>**print(const string[])**</summary>
+ 00_common_0_Main.p<br/>
+ 00_common_7_conditional.p<br/>
+ 00_common_8_loop.p<br/>
+ 10_Switch_Long.p<br/>
+ 30_System_Values_1.p<br/>
+ 30_System_Values_2.p<br/>
+ 30_System_Values_3.p<br/>
+ 32_ble_demo_shtc31.p<br/>
+ 61_alarm_1.p<br/>
+ 61_alarm_2.p<br/>
+ 61_alarm_3.p<br/>
</details>

<details>
<summary>**printf(const format[], {Float,Fixed,_}:...)**</summary>
+ 00_common_1_Timer_1.p<br/>
+ 00_common_1_Timer_2.p<br/>
+ 00_common_2_get_module_info.p<br/>
+ 00_common_3_NamedArray.p<br/> //TODO
+ 00_common_4_pack.p<br/> //TODO
+ 00_common_5_data_types.p<br/>
+ 00_common_6_array.p<br/>
+ 00_common_8_loop.p<br/>
+ 10_Switch.p<br/>
+ 10_Switch_Long.p<br/> 
+ 12_Transmission_0.p<br/>
+ 12_Transmission_2_cyclic_connection.p<br/>
+ 12_Transmission_3_ForceOnline.p<br/>
+ 30_System_Values_0.p<br/>
+ 30_System_Values_1.p<br/>
+ 30_System_Values_2.p<br/>
+ 30_System_Values_3.p<br/>
+ 32_ble_demo_shtc31.p<br/>
+ 32_ble_scan.p  <br/>
+ 50_filetransfer_send_multiple.p<br/>
+ 61_alarm_1.p<br/>
+ 61_alarm_2.p<br/>
+ 61_alarm_3.p<br/>
</details>

### [File Transfer](https://support.microtronics.com/Developer_Documentation/Content/Developer_Documentation/sw/Pawn_Erweiterungen_File_Transfer_Funktionen.htm)

<details>
<summary>**FT_Register(const name{}, id, funcidx)**</summary>
+ 50_filetransfer_send_multiple.p<br/>
</details>

<details>
<summary>**FT_SetPropsExt(id, props[TFT_Info], len=sizeof props)**</summary>
+ 50_filetransfer_send_multiple.p<br/>
</details>

<details>
<summary>**FT_Read(id, const data{}, len)**</summary>
+ 50_filetransfer_send_multiple.p<br/>
</details>

<details>
<summary>**FT_Error(id)**</summary>
+ 50_filetransfer_send_multiple.p<br/>
</details>
