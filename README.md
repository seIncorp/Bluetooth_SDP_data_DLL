# Bluetooth Service Discovery Protocol API
Source code for Bluetooth Service Discovery Protocol (SDP) using only communication with local bluetooth radio through driver. This DLL does not use any Windows Bluetooth api.


# How to use it
## Included libraries
- stdio.h
- vector
- iostream
- winsock2.h
- ws2bth.h
- bthdef.h
- bthsdpdef.h
- bthioctl.h

## DLL, lib and header
Before you can use this dll file, you must add to your app:
1. header: 
ioctl_data.h
2. .lib file:
SDP_data.lib
3. .dll file:
SDP_data.dll

