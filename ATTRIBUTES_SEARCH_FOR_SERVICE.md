# Data elements
* int all
* att_search_DEFAULT att_DEFAULT
* att_search_PNPINFO att_PNPINFO
* att_search_PBAP att_PBAP
* att_search_OBEX att_OBEX
* att_search_NAP att_NAP
* att_search_HSP att_HSP
* att_search_HFP att_HFP
* att_search_AVRCP att_AVRCP
* att_search_A2DP att_A2DP
* att_search_MAP att_MAP


# Substrucutres
## att_search_DEFAULT
### Data elements
* int ServiceRecord
* int ServiceClassIDList
* int ProtocolDescriptorList
* int ServiceName
* int BluetoothProfileDescriptorList
* int ProviderName
* int LanguageBaseAttributeIdList
* int ServiceDescription

## att_search_PNPINFO
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

## att_search_PBAP
### Data elements
* int Goepl2cappsm
* int SupportedRepositories
* int SupportedFeatures

## att_search_OBEX
### Data elements
* int Goepl2cappsm
* int SupportedFormats
* int ServiceVersion

## att_search_NAP
### Data elements
* int SecurityDescription
* int NetAccessType
* int MaxNetAccessRate

## att_search_HSP
### Data elements
* int RemoteAudioVolumeControl

## att_search_HFP
### Data elements
* int Network
* int SupportedFeatures

## att_search_AVRCP
### Data elements
* int SupportedFeatures

## att_search_A2DP
### Data elements
* int SupportedFeatures

## att_search_MAP
### Data elements
* int Goepl2cappsm
* int SupportedMessageTypes
* int MasInstanceId
* int MapSupportedFeatures

