# Data elements
* PSERVICE_RECORD record_handle_export
* PSERVICE_CLASS_ID_LIST class_id_handle_export
* PPROTOCOL_DESCRIPTOR_LIST protocol_descriptor_list_handle_export
* PSERVICE_NAME service_name_handle_export
* PPROVIDER_NAME provider_name_export
* PBLUETOOTH_PROFILE_DESCRIPTOR_LIST bluetooth_profile_descriptor_list_handle_export
* PLANGUAGE_BASE_ATTRIBUTE_ID_LIST language_base_attribute_id_list_export
* PSERVICE_DESCRIPTION service_description_export



# Substrucutres
## SERVICE_RECORD_S
This structure is child of DEFAULT_OBJECT ([DETAILS](DEFAULT_OBJECT.md)).
### Data elements
* VV VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA& dd)

### Substrucutres
#### VV
This structure is child of VALUE ([DETAILS](VALUE.md)).




## SERVICE_CLASS_ID_LIST_S
This structure is child of DEFAULT_OBJECT ([DETAILS](DEFAULT_OBJECT.md)).
### Data elements
* VV VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA& dd)

### Substrucutres
#### VV
This structure is child of VALUE ([DETAILS](VALUE.md)).
##### Data elements
* int num_classes
* SERVICE_CLASS* classes

#### SERVICE_CLASS
##### Data elements
* ATTRIBUTE_ID_ELEMENT* element ([DETAILS](ATTRIBUTE_ID_ELEMENT.md))
* int additional_bits_flag
* SHORT value



## PROTOCOL_DESCRIPTOR_LIST_S
This structure is child of DEFAULT_OBJECT ([DETAILS](DEFAULT_OBJECT.md)).
### Data elements
* VV VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA& dd)

### Substrucutres
#### VV
This structure is child of VALUE ([DETAILS](VALUE.md)).
##### Data elements
* int num_protocols
* PROTOCOL_DESCRIPTOR* protocols
* int _BNEP_flag

#### PROTOCOL_DESCRIPTOR
##### Data elements
* ATTRIBUTE_ID_ELEMENT* element ([DETAILS](ATTRIBUTE_ID_ELEMENT.md))
* int size_bytes
* int additional_bits_flag
* int additional_bits_for_size
* BYTE* value
* ATTRIBUTE_ID_ELEMENT* element_protocol ([DETAILS](ATTRIBUTE_ID_ELEMENT.md))
* SHORT protocol_id
* int additional_parameters_flag
* PROTOCOL_DESCRIPTOR_SPECIFIC_PARAMETER* pdsp

#### PROTOCOL_DESCRIPTOR_SPECIFIC_PARAMETER
##### Data elements
* ATTRIBUTE_ID_ELEMENT* element ([DETAILS](ATTRIBUTE_ID_ELEMENT.md))
* int server_channel_num
* SHORT PSM
* SHORT Version
###### for PANU
* ATTRIBUTE_ID_ELEMENT* element_PANU ([DETAILS](ATTRIBUTE_ID_ELEMENT.md))
* int additional_bits_flag_PANU
* int additional_bits_for_size_PANU
* int num_of_Supported_Network_Packet_Type_List_PANU
* SHORT* Supported_Network_Packet_Type_List


## SERVICE_NAME_S
### Data elements
* VV VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA& dd)

### Substrucutres
#### VV
This structure is child of VALUE ([DETAILS](VALUE.md)).
##### Data elements
* char* service_name


## PROVIDER_NAME_S
### Data elements
* VV VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA& dd)

### Substrucutres
#### VV
This structure is child of VALUE ([DETAILS](VALUE.md)).
##### Data elements
* char* provider_name






## BLUETOOTH_PROFILE_DESCRIPTOR_LIST_S
### Data elements
* VV VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA& dd)

### Substrucutres
#### VV
This structure is child of VALUE ([DETAILS](VALUE.md)).
##### Data elements
* SHORT profile_UUID
* SHORT profile_version






## LANGUAGE_BASE_ATTRIBUTE_ID_LIST_S
### Data elements
* VV VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA& dd)

### Substrucutres
#### VV
This structure is child of VALUE ([DETAILS](VALUE.md)).
##### Data elements
* SHORT triplet_id_natural_lang
* SHORT triplet_id_char_encoding
* SHORT triplet_attribute_id




## SERVICE_DESCRIPTION_S
### Data elements
* VV VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA& dd)

### Substrucutres
#### VV
This structure is child of VALUE ([DETAILS](VALUE.md)).
##### Data elements
* char* description


