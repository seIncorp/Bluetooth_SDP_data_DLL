# Data elements
* int debug
* int print
* int print_info
* int print_with_outside_funct
* SDP_print_service print_service



# Substrucutres
## SDP_print_service
### Data elements
#### Default attr.
* int print_service_record
* int print_service_class_id_list
* int print_protocol_descriptor_list
* int print_service_name
* int print_provider_name
* int print_bluetooth_profile_descriptor_list
* int print_language_base_attribute_id_list
* int print_service_description
#### Special attr.
* print_PNPINFO print_PNPINFO_attributes
* print_PBAP print_PBAP_attributes
* print_OBEX print_OBEX_attributes
* print_NAP print_NAP_attributes
* print_HSP print_HSP_attributes
* print_HFP print_HFP_attributes
* print_AVRCP print_AVRCP_attributes
* print_A2DP print_A2DP_attributes
* print_MAP print_MAP_attributes


## print_MAP
### Data elements
* int print_goepl2cappsm
* int print_supported_message_types
* int print_mas_instance_id
* int print_map_supported_features

## print_A2DP
### Data elements
* int print_supported_features

## print_AVRCP
### Data elements
* int print_supported_features

## print_HFP
### Data elements
* int print_network
* int print_supported_features

## print_HSP
### Data elements
* int print_remote_audio_volume_control

## print_NAP
### Data elements
* int print_security_description
* int print_net_access_type
* int print_max_net_access_rate

## print_OBEX
### Data elements
* int print_goepl2cappsm
* int print_supported_formats
* int print_service_version

## print_PBAP
### Data elements
* int print_goepl2cappsm
* int print_supported_repositories
* int print_pbap_supported_features

## print_PNPINFO
### Data elements
* int PnpInfo
* int SpecificationID
* int VendorID
* int ProductID
* int Version
* int PrimaryRecord
* int VendorIDSource
* int ClientExecutableURL
* int DocumentationURL
