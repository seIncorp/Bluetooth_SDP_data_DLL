# Bluetooth Service Discovery Protocol API (DONE!!)
Source code for Bluetooth Service Discovery Protocol (SDP) using only communication with local bluetooth radio through driver (using IOCTL). 
This DLL does not use any Windows Bluetooth api (bluetoothapis.h).

# Prerequisites (DONE!!)
- at least Visual studio 2019
- Windows 10
- Windows 7 (not tested yet)
- Bluetooth USB dongle or integrated Bluetooth radio (laptop)
- Currently you can use only x64 version of DLL (REASON: empty pointer to function)

# How to get/open project and building it (DONE!!)
1. download this project from Github
2. open it 
3. set x64 or x86 (it must be the same as app which will be using it)
4. build it
5. in main folder you will get ioctl_data.h
6. in ..\x64\Debug you will find SDP_data.lib and SDP_data.dll (for X64)
7. in ..\Debug you will find SDP_data.lib and SDP_data.dll (for X86)


# Structures  (DONE!!)
Here you can get details explanations of used structures of exported data.
* namespace IOCTL_S ([DETAILS](IOCTL_S.md))
* DEFAULT_DATA ([DETAILS](default_data.md))




# Functions
DLL have next functions:

## Connection and disconnection functions (DONE!!)
* int connectToDevice(const wchar_t* name, DEFAULT_DATA& dd)
> connecting to local bluetooth radio before any search/retriving data is made 
> 
> input parameters: 
> * physical device name (example: \\\\?\\GLOBALROOT\\Device\\USBPDO-4)
> * reference to DEFAULT_DATA structure
* int closeConnectionToDevice(DEFAULT_DATA& dd)
> disconnection from local radio (THIS MUST BE CALLED BEFORE APP IS CLOSED!!!)
> 
> input parameters: 
> * reference to DEFAULT_DATA structure



## Search and retriving data functions (DONE!!)
* int SDPsearch(DEFAULT_DATA& dd, char address[])
> search for service of specific device
> 
> input parameters: 
> * reference to DEFAULT_DATA structure
> * remote Bluetooth device address


* int getBthDeviceInfo(DEFAULT_DATA& dd, int print = 1)
> retriving list of cached bluetooth devices from previous search
> 
> input parameters: 
> * reference to DEFAULT_DATA structure
> * integer as a flag for printing data in cmd (default: true)


* int getLocalBthInfo(DEFAULT_DATA& dd, int print = 1)
> information about the local Bluetooth system and radio
> 
> input parameters: 
> * reference to DEFAULT_DATA structure
> * integer as a flag for printing data in cmd (default: true)


## Other functions (DONE!!)
* void printErrorMessage(DWORD id, DEFAULT_DATA& dd)
> print error message
> 
> input parameters: 
> * id of error (example: from GetLastError function)
> * reference to DEFAULT_DATA structure



# How to use it (DONE!!)
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







# Settings of dll

## Printing
* debug
> if you set this to 1 you will get printed raw data from bluetooth response
```
default_data.sdp_settings.debug = 1;
```

* print
> you will get printed all parsed data of every attribute of the searched service and also override every flag in SDP_print_service structure
```
default_data.sdp_settings.print = 1;
```

* print_info
> print events when is app connected to radio, remote device, disconnected from remote device, local radio
```
default_data.sdp_settings.print_info = 1;
```


- print_service flags
> here you can enable/disable printing of particular attribute of the searched service (NOTE: only if print is disabled!!)
- print_with_outside_funct
> here you enable printing with your own function saved in outside_print_function parameter
#### Attributes Searching
- all
> set every attribute to TRUE (NOTE: override other flags)
- Default and service specific attributes
> here you can enable/disable searching for attributes (NOTE: only if all flag is disabled)
#### Service Searching
> here you can enable/disable service to search (NOTE: disabled by default)

## Main structures
- DEFAULT_DATA
> Containe all next structures and functions
- services_for_search
> here you can enable/disable which service will be searched on remote device
- exported_data
> here you get exported all data from: 
> - searched service/services
> - cached bluetooth remote devices
> - data of local radio/device
- sdp_settings
> here you can enable/disable:
> - debug (DEFAULT: disabled)
> - print data (NOTE: printing all attributes of the service) (DEFAULT: disabled)
> - printf_info (DEFAULT: disabled)
> - printing only selected attribute from searched device (NOTE: only if print is disabled) (DEFAULT: disabled)
- attr_search_for_service
> here you can enable/disable every attribute in service to search it

# Examples 
## Notes (applies to all examples):
For every use you must:
1. before any call define default data structure
> IOCTL_S::DEFAULT_DATA dd;
2. Connect to local bluetooth radio
> int connected = IOCTL_S::connectToDevice(L"\\\\?\\GLOBALROOT\\Device\\USBPDO-5", &dd);
3. Disconnection from local radio (NOTE: it must be done this at the end of everything)
> IOCTL_S::closeConnectionToDevice(&dd);
## SDP example
1. use steps from Notes (step 1 and 2)
2. Settings
```
// example of outside function (user defined)
void test(std::string text, ...)
{
  std::cout << "> " << text << std::endl;
}

dd.outside_print_function = test;				      // saving to function pointer, dll will use this pointer
dd.sdp_settings.print_with_outside_funct = 1;	// enabling this pointer function

// printing all searched device attributes
dd.sdp_settings.print = 1;		

// printing debug data (responses in bytes)
dd.sdp_settings.debug = 1;		

// enabling to print goepl2cappsm attribute for MAP service (NOTE: used only when MAP service is searched)
dd.sdp_settings.print_service.print_MAP_attributes.print_goepl2cappsm = 1;	

// enabling to print service_record of current searched service (NOTE: only if dd.sdp_settings.print is disabled)
dd.sdp_settings.print_service.print_service_record = 1; 

// enable all services for searching
dd.set_all_SDP_service_for_search();	

// those two functions are recommended if you are not using set_all_SDP_service_for_search or dd.attr_search_for_service.all
dd.reset_SDP_service_for_search();		// reseting to false all services for searching
dd.reset_attr_search_for_service();		// reseting to false all attributes for searching

// enabling to search goepl2cappsm attribute for MAP service (NOTE: used only when MAP service is searched)
dd.attr_search_for_service.att_MAP.Goepl2cappsm = 1;	

// enabling to search service_record of current enabled service
dd.attr_search_for_service.ServiceRecord = 1;			

// enabling AudioSource service for searching
dd.services_for_search.AudioSource = 0x01;		
```
3. calling SDPsearch after all settings are ready
```
// bluetooth device address
char add[] = "A8:B8:6E:E7:5A:B6";

// calling SDPsearch function
IOCTL_S::SDPsearch(&dd, add);
```
4. retriving exported data from searched services/attributes
```
//	For example service name of Audio source
SDP::A2DP::A2DP_EXPORT* ex = (SDP::A2DP::A2DP_EXPORT_S*)dd.exported_data.a2dp_export;
printf("--> %s\n", ex->default_export->service_name_handle_export->VALUE.service_name);
```
5. use last step from Notes
## getBthDeviceInfo example
1. use steps from Notes (step 1 and 2)
2. call
```
// currently all devices will be printed
IOCTL_S::getBthDeviceInfo(&dd);	

// currently all devices will not be printed
IOCTL_S::getBthDeviceInfo(&dd, 0);		
```
3. retriving of exported data
```
// retriving and printing number of devices
printf("---> num: %d\n", dd.exported_data.devices->numOfDevices);	

// for loop of all devices and retriving and printing device name
for (int n = 0; n < dd.exported_data.devices->numOfDevices; n++)	
  printf("%s\n", dd.exported_data.devices->devices.at(n).getName());
```
4. use last step from Notes
## getLocalBthInfo example
1. use steps from Notes (step 1 and 2)
2. call
```
// by default print is TRUE
IOCTL_S::getLocalBthInfo(&dd);		

// printing is disabled
IOCTL_S::getLocalBthInfo(&dd, 0);		
```
3. retriving of exported data
```
printf("--> %s\n", dd.exported_data.local_device_radio->device->name);
```
4. use last step from Notes

# TODOs
- export to JSON (as string and as file)
- export to XML (as string and as file)
- fixing bugs

