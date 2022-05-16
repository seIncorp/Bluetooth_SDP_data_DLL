# Data elements
## SDP services
* BYTE default_export ([DETAILS](DEFAULT_EXPORT.md))
* BYTE a2dp_export ([DETAILS](a2dp.md))
* BYTE avrcp_export_avrc ([DETAILS](avrcp.md))
* BYTE avrcp_export_avrct ([DETAILS](avrcp.md))
* BYTE avrcp_export_avrcc ([DETAILS](avrcp.md))
* BYTE hfp_export_Handsfree ([DETAILS](hfp.md))
* BYTE hfp_export_HandsfreeAG ([DETAILS](hfp.md))
* BYTE hsp_export_headset ([DETAILS](hsp.md))
* BYTE hsp_export_headsetAG ([DETAILS](hsp.md))
* BYTE map_export ([DETAILS](map.md))
* BYTE nap_export ([DETAILS](nap.md))
* BYTE obex_export ([DETAILS](obex.md))
* BYTE pbap_export ([DETAILS](pbap.md))
* BYTE pnpinfo_export ([DETAILS](pnp.md))

## cached bluetooth devices
* BTH_DEVICES::SEARCHED_CACHED_DEVICES_S devices

## local radio data
* BTH_DEVICES::LOCAL_RADIO_DEVICE_DATA_S local_device_radio


# Substrucutres
## SEARCHED_CACHED_DEVICES_S
### Data elements
* ULONG numOfDevices;
* vector of CACHED_DEVICE devices;

### Functions
* void print()

### Substrucutres
#### CACHED_DEVICE
### Functions
* CACHED_DEVICE_S(char n[BTH_MAX_NAME_SIZE], BYTE add[6], ULONG fl)
* print()
* getName()
* getFlags()
* getAddress()


## LOCAL_RADIO_DEVICE_DATA_S
### Data elements
* ULONG flags
* USHORT HCI_minor_version
* UCHAR HCI_major_version
* PDEVICE_DATA device
* PRADIO_DATA radio

### Functions
* LOCAL_RADIO_DEVICE_DATA_S(ULONG f, USHORT hciR, UCHAR hciV)
* print()

### Substrucutres
#### DEVICE_DATA
##### Data elements
* CHAR name[BTH_MAX_NAME_SIZE]
* BYTE address[6]
* ULONG flags
* COD_PARSER::PDEVICE_PARSED_COD_DATA cod

##### Functions
* void init(BYTE add[6], ULONG f, char n[BTH_MAX_NAME_SIZE])
* void print()




#### RADIO_DATA
##### Data elements
* ULONGLONG LMP_SupportedFeatures
* USHORT mfg
* USHORT LMP_minor_version
* UCHAR LMP_major_version

##### Functions
* RADIO_DATA_S(ULONGLONG lsf, USHORT m, USHORT ls, UCHAR lv)
* void print()




#### DEVICE_PARSED_COD_DATA
##### Data elements
* major_service_class
* major_device_class
* minor_device_class

##### Functions
* void print()