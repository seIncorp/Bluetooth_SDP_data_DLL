# Data elements
* PDEFAULT_EXPORT default_export ([DETAILS](DEFAULT_EXPORT.md))
* SDP::MAP::PGOEPL2CAPPSM goepl2cappsm_handle_export ([DETAILS](PGOEPL2CAPPSM.md))
* PSUPPORTED_REPOSITORIES supported_repositories_handle_export
* PPBAP_SUPPORTED_FEATURES pbap_supported_features_handle_export


# Substrucutres
## SUPPORTED_REPOSITORIES_S
This structure is child of DEFAULT_OBJECT ([DETAILS](DEFAULT_OBJECT.md)).
### Data elements
* VV VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA& dd)

### Substrucutres
#### VV
This structure is child of VALUE ([DETAILS](VALUE.md)).
##### Data elements
* SUPPORTED_REPOSITORIES_DATA_S* srs

#### SUPPORTED_REPOSITORIES_DATA_S
##### Data elements
* SR_S* repo
##### Functions
* SUPPORTED_REPOSITORIES_DATA_S(BYTE* a)
* std::string getSupportedRepositoriesString()



## PBAP_SUPPORTED_FEATURES_S
This structure is child of DEFAULT_OBJECT ([DETAILS](DEFAULT_OBJECT.md)).

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA& dd)

