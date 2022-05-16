# Structure
* DEFAULT_DATA ([DETAILS](default_data.md))



# Functions
## Connection and disconnection functions
* int connectToDevice(const wchar_t* name, DEFAULT_DATA& dd)
* int closeConnectionToDevice(DEFAULT_DATA& dd)

## Search and retriving data functions
* int SDPsearch(DEFAULT_DATA& dd, char address[])
* int getBthDeviceInfo(DEFAULT_DATA& dd, int print = 1)
* int getLocalBthInfo(DEFAULT_DATA& dd, int print = 1)

## Other
* void printErrorMessage(DWORD id, DEFAULT_DATA& dd)