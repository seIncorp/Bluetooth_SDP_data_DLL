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
- getBthDeviceInfo()
- getLocalBthInfo()
