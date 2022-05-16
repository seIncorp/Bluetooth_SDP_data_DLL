# Data elements
* PDEFAULT_EXPORT default_export ([DETAILS](DEFAULT_EXPORT.md))
* PNETWORK network_handle_export
* PSUPPORTED_FEATURES supported_features_handle_export


# Substrucutres


## NETWORK_S
This structure is child of DEFAULT_OBJECT ([DETAILS](DEFAULT_OBJECT.md)).

### Functions
* void print(T v, IOCTL_S::DEFAULT_DATA& dd)





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




## SUPPORTED_FEATURES_S
### Data elements
* SR_S* repo;
* SHORT temp_data;

### Functions
* SUPPORTED_FEATURES_DATA_S(SHORT a)
* std::string getSupportedFeatures_AG_String()
* std::string getSupportedFeaturesString()