# Bluetooth Service Discovery Protocol API
Source code for Bluetooth Service Discovery Protocol (SDP) using only communication with local bluetooth radio through driver (using IOCTL). 
This DLL does not use any Windows Bluetooth api (bluetoothapis.h).


# How to use it
## Included headers and libraries for using dll
- stdio.h
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
- connectToDevice()
> connecting to local bluetooth radio before any search/retriving data is made
- closeConnectionToDevice()
> disconnection from local radio (THIS MUST BE CALLED BEFORE APP IS CLOSED!!!)
#### Search and retriving data functions
- SDPsearch()
> search for service for specific device
- getBthDeviceInfo()
> retriving list of cached bluetooth devices from previous search
- getLocalBthInfo()
> information about the local Bluetooth system and radio
#### DEFAULT_DATA structures functions
- reset_SDP_service_for_search()
- set_all_SDP_service_for_search()

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

