# Data elements
* PDEFAULT_EXPORT default_export ([DETAILS](DEFAULT_EXPORT.md))
* PSUPPORTED_FEATURES supported_features_handle_export


# Substrucutres

## SUPPORTED_FEATURES_S
This structure is child of DEFAULT_OBJECT ([DETAILS](DEFAULT_OBJECT.md)).
### Data elements
* VV VALUE

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA& dd)

### Substrucutres
#### VV
This structure is child of VALUE ([DETAILS](VALUE.md)).
##### Data elements
* SHORT supported_features_value
* SUPPORTED_FEATURES_DATA_S* sfds


## SUPPORTED_FEATURES_DATA_S
### Data elements
* SR_S* repo

### Functions
* SUPPORTED_FEATURES_DATA_S(SHORT* a)
* std::string getSupportedFeaturesString()