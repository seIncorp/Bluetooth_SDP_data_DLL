# Fields
* ULONG numOfDevices
> here is saved final number of returned devices
* std::vector<CACHED_DEVICE> devices
> vector of CACHED_DEVICE structure

# Functions
* void print()
> print all data of returned previously searched and cached devices

# Structures
### CACHED_DEVICE
#### Fields
All are private.
#### Functions
* void print()
> print name, flags and address of returned device
* char* getName()
> return pointer to **string of BTH_MAX_NAME_SIZE**  device name of returned device
* ULONG getFlags()
> return **ULONG number** of flags of returned device
* BYTE* getAddress()
> return pointer to **BYTE array[6]** containing bluetooth address of returned device