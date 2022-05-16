# Data elements
* PDEFAULT_EXPORT default_export ([DETAILS](DEFAULT_EXPORT.md))
* PGOEPL2CAPPSM goepl2cappsm_handle_export ([DETAILS](PGOEPL2CAPPSM.md))
* PSUPPORTED_MESSAGE_TYPES supported_message_types_handle
* PMAS_INSTANCE_ID mas_instance_id_handle
* PMAP_SUPPORTED_FEATURES map_supported_features_handle



# Substrucutres

## SUPPORTED_MESSAGE_TYPES_S
This structure is child of DEFAULT_OBJECT ([DETAILS](DEFAULT_OBJECT.md)).
### Data elements
* VV VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA& dd)

### Substrucutres
#### VV
This structure is child of VALUE ([DETAILS](VALUE.md)).
##### Data elements
* SUPPORTED_FEATURES_MESSAGES_S* sfm




## MAS_INSTANCE_ID_S
This structure is child of DEFAULT_OBJECT ([DETAILS](DEFAULT_OBJECT.md)).
### Data elements
* VV VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA& dd)

### Substrucutres
#### VV
This structure is child of VALUE ([DETAILS](VALUE.md)).
##### Data elements
* BYTE instance_ID





## MAP_SUPPORTED_FEATURES_S
This structure is child of DEFAULT_OBJECT ([DETAILS](DEFAULT_OBJECT.md)).
### Data elements
* VV VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA& dd)

### Substrucutres
#### VV
This structure is child of VALUE ([DETAILS](VALUE.md)).
##### Data elements
* SUPPORTED_FEATURES_MESSAGES_S* sfm





## SUPPORTED_FEATURES_MESSAGES_S
### Data elements
* SMT_S* ttt
* SF_S* aaa
* int flag
* DWORD sf_s_value
* BYTE smt_s_value

### Features
* SUPPORTED_FEATURES_MESSAGES_S(int i, DWORD a1, BYTE a2)