#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>

#include <stdio.h>
#include <vector>
#include <iostream>
#include <initguid.h>
#include <winsock2.h>
#include <ws2bth.h>
#include <strsafe.h>
#include <intsafe.h>
#include <bluetoothapis.h>
#include <bthdef.h>
#include <bthsdpdef.h>
#include <combaseapi.h>
#include <bthdef.h>
#include <winioctl.h>
#include <bthioctl.h>

#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "Bthprops.lib")
#pragma comment(lib, "Ole32.lib")
