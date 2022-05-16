# Data elements
* PDEFAULT_EXPORT default_export ([DETAILS](DEFAULT_EXPORT.md))
* PSECURITY_DESCRIPTION security_description_handle_export
* PNET_ACCESS_TYPE net_access_type_handle_export
* PMAX_NET_ACCESS_RATE max_net_access_rate_handle_export


# Substrucutres

## SECURITY_DESCRIPTION_S
This structure is child of DEFAULT_OBJECT ([DETAILS](DEFAULT_OBJECT.md)).
### Data elements
* VV VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA& dd)

### Substrucutres
#### VV
This structure is child of VALUE ([DETAILS](VALUE.md)).
##### Data elements
* SHORT security_value



## NET_ACCESS_TYPE_S
This structure is child of DEFAULT_OBJECT ([DETAILS](DEFAULT_OBJECT.md)).
### Data elements
* VV VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA& dd)

### Substrucutres
#### VV
This structure is child of VALUE ([DETAILS](VALUE.md)).
##### Data elements
* SHORT NetAccessType


## MAX_NET_ACCESS_RATE_S
This structure is child of DEFAULT_OBJECT ([DETAILS](DEFAULT_OBJECT.md)).
### Data elements
* VV VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA& dd)

### Substrucutres
#### VV
This structure is child of VALUE ([DETAILS](VALUE.md)).
##### Data elements
* DWORD Maximum_possible_Network_Access_Data_Rate