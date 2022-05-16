# Data elements
* HANDLE hDevice
* BOOL bResult
* DWORD junk
* SHORT service_class_id_in_use
* IOCTL_DATA_STRUCTURES_S::SDP_services_for_search services_for_search ([DETAILS](SDP_services_for_search.md))
* IOCTL_DATA_STRUCTURES_S::SDP_exported_data exported_data ([DETAILS](SDP_exported_data.md))
* IOCTL_DATA_STRUCTURES_S::SDP_settings sdp_settings ([DETAILS](SDP_settings.md))
* IOCTL_DATA_STRUCTURES_S::ATTRIBUTES_SEARCH_FOR_SERVICE attr_search_for_service ([DETAILS](ATTRIBUTES_SEARCH_FOR_SERVICE.md))
* IOCTL_DATA_STRUCTURES_S::returned_ERROR* error ([DETAILS](returned_ERROR.md))
* vector of IOCTL_DATA_STRUCTURES_S::vendor_ID_s vendors_list  ([DETAILS](vendor_ID_s.md))
* BYTE* data_outside_print_function
* SHORT temp_class_id
* SHORT temp_service	

# Functions

## Settings
* void set_all_SDP_service_for_search()
* void set_SDP_service_for_search(unsigned int service, int onOff)
* void set_all_attr_search_for_service()
* void set_all_default_attr_search_for_service(int onOff)
* void set_all_special_attr_search_for_service(unsigned int service, int onOff)
* void set_default_attr_search_for_service(unsigned int attr, int onOff)
* void set_special_attr_search_for_service(unsigned int service, unsigned int attr, int onOff)


## Resetings
* void reset_all_SDP_service_for_search()
* void reset_all_attr_search_for_service()


## Printings
* void set_all_default_attr_service_PRINT(int onOff)
* void set_all_special_attr_service_PRINT(unsigned int service, int onOff)
* void set_default_attr_service_PRINT(unsigned int attr, int onOff)
* void set_special_attr_service_PRINT(unsigned int service, unsigned int attr, int onOff)
* void fill_vendors_list()
* void outside_print_function (std::string text)


