# Data elements
* PDEFAULT_EXPORT default_export ([DETAILS](DEFAULT_EXPORT.md))
* SDP::MAP::PGOEPL2CAPPSM goepl2cappsm_handle_export ([DETAILS](PGOEPL2CAPPSM.md))
* PSERVICE_VERSION service_version_handle_export
* PSUPPORTED_FORMATS supported_formats_handle_export


# Substrucutres
## SERVICE_VERSION_S
This structure is child of DEFAULT_OBJECT ([DETAILS](DEFAULT_OBJECT.md)).



## SUPPORTED_FORMATS_S
### Data elements
* VV VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA& dd)

### Substrucutres
#### VV
This structure is child of VALUE ([DETAILS](VALUE.md)).
##### Data elements
* int num_of_formats
* BYTE* formats