# Bluetooth Service Discovery Protocol API
Source code for Bluetooth Service Discovery Protocol (SDP) using only communication with local bluetooth radio through driver (using IOCTL). 
This DLL does not use any Windows Bluetooth api (bluetoothapis.h).


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

## Settings of dll (IN PROGRESS...)
- debug
- print

## Main structures
- DEFAULT_DATA
> Containe all next structures and functions
- SDP_services_for_search
> here you can enable/disable which service will be searched on remote device
- SDP_exported_data
> here you get exported all data from searched service/services
- SDP_settings
> here you can enable/disable debug and print data (DEFAULT: disabled)

