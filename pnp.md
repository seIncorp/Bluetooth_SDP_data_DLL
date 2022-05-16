# Data elements
* PINFO info_handle_export



# Substrucutres
## INFO_S
This structure is child of DEFAULT_OBJECT ([DETAILS](DEFAULT_OBJECT.md)).
### Data elements
* Specification_ID SpecificationID
* SHORT VendorID_vector_location
* SHORT ProductID
* Version_data Version
* BOOL PrimaryRecord
* SHORT VendorIDSource


### Functions
* void setIDdata(SHORT id, A data, IOCTL_S::DEFAULT_DATA& dd)
* void print_SpecificationID()
* void print_VendorID(IOCTL_S::DEFAULT_DATA& dd)
* void print(T v, IOCTL_S::DEFAULT_DATA& dd)



## Specification_ID
### Data elements
* SHORT value
* BYTE major_number
* BYTE minor_number

## Version_data
### Data elements
* int major_version
* int minor_version
* int sub_minor_version
