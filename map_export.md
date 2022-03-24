# Notes
* This is valid for all services.
* All services structures are children of DEFAULT_OBJECT structure.

# Fields
* default_export
* service specific attributes fields (Look down for more information)

# Default Structures
### DEFAULT_EXPORT
#### Fields
* record_handle_export
* class_id_handle_export
* protocol_descriptor_list_handle_export
* service_name_handle_export
* provider_name_export
* bluetooth_profile_descriptor_list_handle_export
* language_base_attribute_id_list_export
* service_description_export

## Parent main structures
### DEFAULT_OBJECT (parent structure)
#### Fields
* ATTR_ID* attr_id
* struct VV (children of structure VALUE)
#### Functions
* void printATTR_ELEMENT(IOCTL_S::DEFAULT_DATA dd) (USED ONLY FOR INTERNAL!!)
* template void printVALUE_ELEMENT(T v, IOCTL_S::DEFAULT_DATA dd) (USED ONLY FOR INTERNAL!!)
* template void print(T v, IOCTL_S::DEFAULT_DATA dd) (USED ONLY FOR INTERNAL!!)
### ATTR_ID
#### Fields
* ATTRIBUTE_ID_ELEMENT* element
* int size_bytes
* int additional_bits_flag
* int additional_bits_for_size
* BYTE* value
### ATTRIBUTE_ID_ELEMENT (bit field structure)
#### Fields
* element.size
* element.type
### VALUE
#### Fields
* ATTRIBUTE_ID_ELEMENT* element
* int size_bytes
* int additional_bits_flag
* int additional_bits_for_size
* ULONG size_bytes_additional
* BYTE* value

## Attribute Structures
**Note: All attributes structures are children of parent main structures**

### SERVICE_RECORD
#### Fields
Same of parent structure
#### Functions
* template void print(T v, IOCTL_S::DEFAULT_DATA dd)
> Modified to print attribute specific data
### SERVICE_CLASS_ID_LIST
#### Fields
* additional attribute specific fields in struct VV:
1. int num_classes
2. SERVICE_CLASS* classes
#### Functions
* template void print(T v, IOCTL_S::DEFAULT_DATA dd)
> Modified to print attribute specific data
### PROTOCOL_DESCRIPTOR_LIST
#### Fields
* additional attribute specific fields in struct VV:
1. int num_protocols
2. PROTOCOL_DESCRIPTOR* protocols
3. int _BNEP_flag
#### Functions
* template void print(T v, IOCTL_S::DEFAULT_DATA dd)
> Modified to print attribute specific data
### SERVICE_NAME
#### Fields
* additional attribute specific fields in struct VV:
1. char* service_name
#### Functions
* template void print(T v, IOCTL_S::DEFAULT_DATA dd)
> Modified to print attribute specific data
### PROVIDER_NAME
#### Fields
* additional attribute specific fields in struct VV:
1. char* provider_name
#### Functions
* template void print(T v, IOCTL_S::DEFAULT_DATA dd)
> Modified to print attribute specific data
### BLUETOOTH_PROFILE_DESCRIPTOR_LIST
#### Fields
* additional attribute specific fields in struct VV:
1. SHORT profile_UUID
2. SHORT profile_version
#### Functions
* template void print(T v, IOCTL_S::DEFAULT_DATA dd)
> Modified to print attribute specific data
### LANGUAGE_BASE_ATTRIBUTE_ID_LIST
#### Fields
* additional attribute specific fields in struct VV:
1. SHORT triplet_id_natural_lang
2. SHORT triplet_id_char_encoding
3. SHORT triplet_attribute_id
#### Functions
* template void print(T v, IOCTL_S::DEFAULT_DATA dd)
> Modified to print attribute specific data
### SERVICE_DESCRIPTION
#### Fields
* additional attribute specific fields in struct VV:
1. char* description
#### Functions
* template void print(T v, IOCTL_S::DEFAULT_DATA dd)
> Modified to print attribute specific data

## Attribute specific Structures
### SERVICE_CLASS
#### Fields
* ATTRIBUTE_ID_ELEMENT* element
* int additional_bits_flag
* SHORT value
### PROTOCOL_DESCRIPTOR
#### Fields
* ATTRIBUTE_ID_ELEMENT* element
* int size_bytes
* int additional_bits_flag
* int additional_bits_for_size
* BYTE* value
* ATTRIBUTE_ID_ELEMENT* element_protocol
* SHORT protocol_id
* int additional_parameters_flag
* PROTOCOL_DESCRIPTOR_SPECIFIC_PARAMETER* pdsp
### PROTOCOL_DESCRIPTOR_SPECIFIC_PARAMETER
#### Fields
* ATTRIBUTE_ID_ELEMENT* element
* int server_channel_num
* SHORT PSM
* SHORT Version
* ATTRIBUTE_ID_ELEMENT* element_PANU
* int additional_bits_flag_PANU
* int additional_bits_for_size_PANU
* int num_of_Supported_Network_Packet_Type_List_PANU
* SHORT* Supported_Network_Packet_Type_List

# Service specific structures
## MAP export
### Main structures
#### MAP_EXPORT
##### Fields
* default_export (Look at **Default Structures**)
* goepl2cappsm_handle_export
* supported_message_types_handle
* mas_instance_id_handle
* map_supported_features_handle

### Attribute structures
**Note: All attributes structures are children of default parent main structures**
#### GOEPL2CAPPSM
##### Fields
additional attribute specific fields in struct VV:

* SHORT GoepL2CapPsm_value 
##### Functions
* template void print(T v, IOCTL_S::DEFAULT_DATA dd)
> Modified to print attribute specific data
#### SUPPORTED_MESSAGE_TYPES
##### Fields
additional attribute specific fields in struct VV:

* SUPPORTED_FEATURES_MESSAGES_S* sfm
##### Functions
* template void print(T v, IOCTL_S::DEFAULT_DATA dd)
> Modified to print attribute specific data
#### MAS_INSTANCE_ID
##### Fields
additional attribute specific fields in struct VV:

* BYTE instance_ID
##### Functions
* template void print(T v, IOCTL_S::DEFAULT_DATA dd)
> Modified to print attribute specific data
#### MAP_SUPPORTED_FEATURES
##### Fields
additional attribute specific fields in struct VV:

* SUPPORTED_FEATURES_MESSAGES_S* sfm
##### Functions
* template void print(T v, IOCTL_S::DEFAULT_DATA dd)
> Modified to print attribute specific data

### Attribute substructures
#### SUPPORTED_FEATURES_MESSAGES_S
##### Fields
* SMT_S* ttt
* SF_S* aaa
* int flag
* DWORD sf_s_value
* BYTE smt_s_value

## A2DP export
### Main structures
#### A2DP_EXPORT
##### Fields
* default_export (Look at **Default Structures**)
* supported_features_handle_export

### Attribute structures
#### SUPPORTED_FEATURES
##### Fields
additional attribute specific fields in struct VV:

* SHORT supported_features_value
* SUPPORTED_FEATURES_DATA_S* sfds
##### Functions
* template void print(T v, IOCTL_S::DEFAULT_DATA dd)
> Modified to print attribute specific data

### Attribute substructures
#### SUPPORTED_FEATURES_DATA_S





