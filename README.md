# Bluetooth Service Discovery Protocol API
Source code for Bluetooth Service Discovery Protocol (SDP) using only communication with local bluetooth radio through driver (using IOCTL). 
This DLL does not use any Windows Bluetooth api (bluetoothapis.h).

# Prerequisites
- Visual studio 2019
- Windows 10
- Windows 7 (not tested yet)

# How to get/open project and building it
1. download this project from Github
2. open it 
3. set x64 or x86 (it must be the same as app which will be using it)
4. build it
5. in main folder you will get ioctl_data.h
6. in ..\x64\Debug you will find SDP_data.lib and SDP_data.dll (for X64)
7. in ..\Debug you will find SDP_data.lib and SDP_data.dll (for X86)

OR

1. you can download all three builded files from Github (IN PROGRESS...)

# How to use it
## Included headers and libraries for using dll
- stdio.h
- vector
- iostream
- winsock2.h
- bthdef.h
- bthioctl.h

## DLL, lib and header
Before you can use this dll file, you must add to your app:
1. header: 

> #include "ioctl_data.h"

2. .lib file:

> #pragma comment(lib, "SDP_data.lib")

3. .dll file:

> Add SDP_data.dll into folder where .exe of app will be

## Functions
DLL have next functions:
#### Connection and disconnection functions
- connectToDevice(const wchar_t* name, DEFAULT_DATA* dd)
> connecting to local bluetooth radio before any search/retriving data is made 
> 
> input parameters: 
> - physical device name (example: \\\\?\\GLOBALROOT\\Device\\USBPDO-4)
> - pointer to DEFAULT_DATA structure
- closeConnectionToDevice(DEFAULT_DATA* dd)
> disconnection from local radio (THIS MUST BE CALLED BEFORE APP IS CLOSED!!!)
> 
> input parameters: 
> - pointer to DEFAULT_DATA structure
#### Search and retriving data functions
- SDPsearch(DEFAULT_DATA* dd, char address[])
> search for service for specific device
> 
> input parameters: 
> - pointer to DEFAULT_DATA structure
> - remote Bluetooth device address
- getBthDeviceInfo(DEFAULT_DATA* dd, int print = 1)
> retriving list of cached bluetooth devices from previous search
> 
> input parameters: 
> - pointer to DEFAULT_DATA structure
> - integer as a flag for printing data in cmd
- getLocalBthInfo(DEFAULT_DATA* dd, int print = 1)
> information about the local Bluetooth system and radio
> 
> input parameters: 
> - pointer to DEFAULT_DATA structure
> - integer as a flag for printing data in cmd
#### Other functions
- printErrorMessage(DWORD id)
> print error message
> 
> input parameters: 
> - id of error from GetLastError function
#### DEFAULT_DATA structures functions
- reset_SDP_service_for_search()
> all flags in SDP_services_for_search structure are set to 0x00 value [false]
- set_all_SDP_service_for_search()
> all flags in SDP_services_for_search structure are set to 0x01 value [true]

## Settings of dll
- debug
> if you set this to 1 you will get printed raw data from bluetooth response
- print
> you will get printed all parsed data of every attribute of the searched service
> and also override every flag in SDP_print_service structure
- print_info
> print events when is app connected to radio, remote device, disconnected from remote device, local radio
- print_service flags
> here you can enable/disable printing of particular attribute of the searched service (NOTE: only if print is disabled!!)

## Main structures
- DEFAULT_DATA
> Containe all next structures and functions
- SDP_services_for_search
> here you can enable/disable which service will be searched on remote device
- SDP_exported_data
> here you get exported all data from: 
> - searched service/services
> - cached bluetooth remote devices
> - data of local radio/device
- SDP_settings
> here you can enable/disable:
> - debug (DEFAULT: disabled)
> - print data (NOTE: printing all attributes of the service) (DEFAULT: disabled)
> - printf_info (DEFAULT: disabled)
> - printing only selected attribute from searched device (NOTE: only if print is disabled) (DEFAULT: disabled)

