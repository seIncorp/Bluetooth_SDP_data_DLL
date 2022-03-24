# Fields
* ULONG flags
* USHORT HCI_minor_version
* UCHAR HCI_major_version
* PDEVICE_DATA device
* PRADIO_DATA radio

# Functions
* void print()
* 
# Structures
### DEVICE_DATA
#### Fields
* CHAR name[BTH_MAX_NAME_SIZE]
* BYTE address[6]
* ULONG flags
* COD_PARSER::PDEVICE_PARSED_COD_DATA cod
#### Functions
* void print()
* void init(BYTE add[6], ULONG f, char n[BTH_MAX_NAME_SIZE])
### RADIO_DATA
#### Fields
* ULONGLONG LMP_SupportedFeatures
* USHORT mfg
* USHORT LMP_minor_version
* UCHAR LMP_major_version
#### Functions
* void print()
### DEVICE_PARSED_COD_DATA
#### Fields
* std::vector<char*> major_service_class
* std::vector<char*> major_device_class
* std::vector<char*> minor_device_class
#### Functions
* void print()