#include "pch.h"

/***********************************************************************/
// set functions

// SERVICES
void  IOCTL_S::DEFAULT_DATA::set_all_SDP_service_for_search()
{
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::Headset, 1);
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::AudioSource, 1);
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::Headset_Audio_Gateway, 1);
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::Handsfree, 1);
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::OBEXObjectPush, 1);
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::A_V_RemoteControl, 1);
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::A_V_RemoteControlTarget, 1);
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::A_V_RemoteControlController, 1);
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::PANU, 1);
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::_NAP, 1);
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::HandsfreeAudioGateway, 1);
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE, 1);
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::Message_Access_Server, 1);
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::PnPInformation, 1);
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::GenericAudio, 1);
}

void IOCTL_S::DEFAULT_DATA::set_SDP_service_for_search(unsigned int service, int onOff)
{
	// TODO: add return 1 if is OK or 0 if fail
	switch (service)
	{
		case SDP::SERVICE_CLASS_ID::AudioSource:
			if (onOff)
				services_for_search.AudioSource = 0x01;
			else
				services_for_search.AudioSource = 0x00;
		break;

		case SDP::SERVICE_CLASS_ID::Message_Access_Server:
			if (onOff)
				services_for_search.Message_Access_Server = 0x01;
			else
				services_for_search.Message_Access_Server = 0x00;
		break;

		case SDP::SERVICE_CLASS_ID::_NAP:
			if (onOff)
				services_for_search._NAP = 0x01;
			else
				services_for_search._NAP = 0x00;
		break;

		case SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE:
			if (onOff)
				services_for_search.Phonebook_Access_PSE = 0x01;
			else
				services_for_search.Phonebook_Access_PSE = 0x00;
		break;

		case SDP::SERVICE_CLASS_ID::OBEXObjectPush:
			if (onOff)
				services_for_search.OBEXObjectPush = 0x01;
			else
				services_for_search.OBEXObjectPush = 0x00;
		break;

		case SDP::SERVICE_CLASS_ID::Handsfree:
			if (onOff)
				services_for_search.Handsfree = 0x01;
			else
				services_for_search.Handsfree = 0x00;
		break;

		case SDP::SERVICE_CLASS_ID::HandsfreeAudioGateway:
			if (onOff)
				services_for_search.HandsfreeAudioGateway = 0x01;
			else
				services_for_search.HandsfreeAudioGateway = 0x00;
		break;

		case SDP::SERVICE_CLASS_ID::PnPInformation:
			if (onOff)
				services_for_search.PnPInformation = 0x01;
			else
				services_for_search.PnPInformation = 0x00;
		break;

		case SDP::SERVICE_CLASS_ID::A_V_RemoteControl:
			if (onOff)
				services_for_search.A_V_RemoteControl = 0x01;
			else
				services_for_search.A_V_RemoteControl = 0x00;
		break;

		case SDP::SERVICE_CLASS_ID::A_V_RemoteControlTarget:
			if (onOff)
				services_for_search.A_V_RemoteControlTarget = 0x01;
			else
				services_for_search.A_V_RemoteControlTarget = 0x00;
		break;

		case SDP::SERVICE_CLASS_ID::A_V_RemoteControlController:
			if (onOff)
				services_for_search.A_V_RemoteControlController = 0x01;
			else
				services_for_search.A_V_RemoteControlController = 0x00;
		break;

		case SDP::SERVICE_CLASS_ID::Headset:
			if (onOff)
				services_for_search.Headset = 0x01;
			else
				services_for_search.Headset = 0x00;
		break;

		case SDP::SERVICE_CLASS_ID::Headset_Audio_Gateway:
			if (onOff)
				services_for_search.Headset_Audio_Gateway = 0x01;
			else
				services_for_search.Headset_Audio_Gateway = 0x00;
		break;
	}
}

// ATTRIBUTES
void IOCTL_S::DEFAULT_DATA::set_all_attr_search_for_service()
{
	attr_search_for_service.all = 1;

	set_all_default_attr_search_for_service(1);

	set_all_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::PnPInformation, 1);
	set_all_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE, 1);
	set_all_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::OBEXObjectPush, 1);
	set_all_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::_NAP, 1);
	set_all_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::Headset, 1);
	set_all_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::HandsfreeAudioGateway, 1);
	set_all_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::A_V_RemoteControlTarget, 1);
	set_all_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::AudioSource, 1);
	set_all_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::Message_Access_Server, 1);
}

void IOCTL_S::DEFAULT_DATA::set_all_default_attr_search_for_service(int onOff)
{
	if (onOff)
	{
		set_default_attr_search_for_service(SDP::ATTRIBUTE_ID::ServiceRecordHandle, 1);
		set_default_attr_search_for_service(SDP::ATTRIBUTE_ID::ServiceClassIDList, 1);
		set_default_attr_search_for_service(SDP::ATTRIBUTE_ID::ProtocolDescriptorList, 1);
		set_default_attr_search_for_service(SDP::ATTRIBUTE_ID::ServiceName, 1);
		set_default_attr_search_for_service(SDP::ATTRIBUTE_ID::BluetoothProfileDescriptorList, 1);
		set_default_attr_search_for_service(SDP::ATTRIBUTE_ID::ProviderName, 1);
		set_default_attr_search_for_service(SDP::ATTRIBUTE_ID::LanguageBaseAttributeIDList, 1);
		set_default_attr_search_for_service(SDP::ATTRIBUTE_ID::ServiceDescription, 1);
	}
	else
	{
		set_default_attr_search_for_service(SDP::ATTRIBUTE_ID::ServiceRecordHandle, 0);
		set_default_attr_search_for_service(SDP::ATTRIBUTE_ID::ServiceClassIDList, 0);
		set_default_attr_search_for_service(SDP::ATTRIBUTE_ID::ProtocolDescriptorList, 0);
		set_default_attr_search_for_service(SDP::ATTRIBUTE_ID::ServiceName, 0);
		set_default_attr_search_for_service(SDP::ATTRIBUTE_ID::BluetoothProfileDescriptorList, 0);
		set_default_attr_search_for_service(SDP::ATTRIBUTE_ID::ProviderName, 0);
		set_default_attr_search_for_service(SDP::ATTRIBUTE_ID::LanguageBaseAttributeIDList, 0);
		set_default_attr_search_for_service(SDP::ATTRIBUTE_ID::ServiceDescription, 0);
	}
}

void IOCTL_S::DEFAULT_DATA::set_all_special_attr_search_for_service(unsigned int service, int onOff)
{
	switch (service)
	{
		case SDP::SERVICE_CLASS_ID::AudioSource:
			if (onOff)
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::AudioSource, SDP::A2DP::ATTRIBUTE_ID_DEVICE_A2DP::SupportedFeatures, 1);
			else
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::AudioSource, SDP::A2DP::ATTRIBUTE_ID_DEVICE_A2DP::SupportedFeatures, 0);
		break;

		case SDP::SERVICE_CLASS_ID::Message_Access_Server:
			if (onOff)
			{
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::Message_Access_Server, SDP::MAP::ATTRIBUTE_ID_MAP::GoepL2capPsm, 1);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::Message_Access_Server, SDP::MAP::ATTRIBUTE_ID_MAP::SupportedMessageTypes, 1);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::Message_Access_Server, SDP::MAP::ATTRIBUTE_ID_MAP::MASInstanceID, 1);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::Message_Access_Server, SDP::MAP::ATTRIBUTE_ID_MAP::MapSupportedFeatures, 1);
			}
			else
			{
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::Message_Access_Server, SDP::MAP::ATTRIBUTE_ID_MAP::GoepL2capPsm, 0);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::Message_Access_Server, SDP::MAP::ATTRIBUTE_ID_MAP::SupportedMessageTypes, 0);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::Message_Access_Server, SDP::MAP::ATTRIBUTE_ID_MAP::MASInstanceID, 0);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::Message_Access_Server, SDP::MAP::ATTRIBUTE_ID_MAP::MapSupportedFeatures, 0);
			}
		break;

		case SDP::SERVICE_CLASS_ID::_NAP:
			if (onOff)
			{
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::_NAP, SDP::NAP::ATTRIBUTE_ID_PAN::SecurityDescription, 1);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::_NAP, SDP::NAP::ATTRIBUTE_ID_PAN::NetAccessType, 1);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::_NAP, SDP::NAP::ATTRIBUTE_ID_PAN::MaxNetAccessrate, 1);
			}
			else
			{
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::_NAP, SDP::NAP::ATTRIBUTE_ID_PAN::SecurityDescription, 0);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::_NAP, SDP::NAP::ATTRIBUTE_ID_PAN::NetAccessType, 0);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::_NAP, SDP::NAP::ATTRIBUTE_ID_PAN::MaxNetAccessrate, 0);
			}
		break;

		case SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE:
			if (onOff)
			{
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE, SDP::PBAP::ATTRIBUTE_ID_PBAP::GoepL2capPsm, 1);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE, SDP::PBAP::ATTRIBUTE_ID_PBAP::SupportedRepositories, 1);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE, SDP::PBAP::ATTRIBUTE_ID_PBAP::PbapSupportedFeatures, 1);
			}
			else
			{
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE, SDP::PBAP::ATTRIBUTE_ID_PBAP::GoepL2capPsm, 0);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE, SDP::PBAP::ATTRIBUTE_ID_PBAP::SupportedRepositories, 0);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE, SDP::PBAP::ATTRIBUTE_ID_PBAP::PbapSupportedFeatures, 0);
			}
		break;

		case SDP::SERVICE_CLASS_ID::OBEXObjectPush:
			if (onOff)
			{
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::OBEXObjectPush, SDP::OBEX::ATTRIBUTE_ID_OBEX::GoepL2capPsm, 1);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::OBEXObjectPush, SDP::OBEX::ATTRIBUTE_ID_OBEX::SupportedFormatsList, 1);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::OBEXObjectPush, SDP::OBEX::ATTRIBUTE_ID_OBEX::ServiceVersion, 1);
			}
			else
			{
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::OBEXObjectPush, SDP::OBEX::ATTRIBUTE_ID_OBEX::GoepL2capPsm, 0);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::OBEXObjectPush, SDP::OBEX::ATTRIBUTE_ID_OBEX::SupportedFormatsList, 0);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::OBEXObjectPush, SDP::OBEX::ATTRIBUTE_ID_OBEX::ServiceVersion, 0);
			}
		break;

		case SDP::SERVICE_CLASS_ID::Handsfree:

		case SDP::SERVICE_CLASS_ID::HandsfreeAudioGateway:
			if (onOff)
			{
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::HandsfreeAudioGateway, SDP::HFP::ATTRIBUTE_ID_HFP::Network, 1);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::HandsfreeAudioGateway, SDP::HFP::ATTRIBUTE_ID_HFP::SupportedFeatures, 1);
			}
			else
			{
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::HandsfreeAudioGateway, SDP::HFP::ATTRIBUTE_ID_HFP::Network, 0);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::HandsfreeAudioGateway, SDP::HFP::ATTRIBUTE_ID_HFP::SupportedFeatures, 0);
			}
		break;

		case SDP::SERVICE_CLASS_ID::PnPInformation:
			if (onOff)
			{
				attr_search_for_service.att_PNPINFO.PnpInfo = 1;
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::SpecificationID, 1);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::VendorID, 1);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::ProductID, 1);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::Version, 1);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::PrimaryRecord, 1);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::VendorIDSource, 1);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::ClientExecutableURL, 1);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::DocumentationURL, 1);
			}
			else
			{
				attr_search_for_service.att_PNPINFO.PnpInfo = 0;
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::SpecificationID, 0);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::VendorID, 0);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::ProductID, 0);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::Version, 0);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::PrimaryRecord, 0);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::VendorIDSource, 0);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::ClientExecutableURL, 0);
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::DocumentationURL, 0);
			}
		break;

		case SDP::SERVICE_CLASS_ID::A_V_RemoteControl:

		case SDP::SERVICE_CLASS_ID::A_V_RemoteControlTarget:

		case SDP::SERVICE_CLASS_ID::A_V_RemoteControlController:
			if (onOff)
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::A_V_RemoteControlController, SDP::AVRCP::ATTRIBUTE_ID_DEVICE_AVRCP::SupportedFeatures, 1);
			else
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::A_V_RemoteControlController, SDP::AVRCP::ATTRIBUTE_ID_DEVICE_AVRCP::SupportedFeatures, 0);
		break;

		case SDP::SERVICE_CLASS_ID::Headset:
	
		case SDP::SERVICE_CLASS_ID::Headset_Audio_Gateway:
			if (onOff)
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::Headset_Audio_Gateway, SDP::HSP::ATTRIBUTE_ID_DEVICE_HSP::RemoteAudioVolumeControl, 1);
			else
				set_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::Headset_Audio_Gateway, SDP::HSP::ATTRIBUTE_ID_DEVICE_HSP::RemoteAudioVolumeControl, 0);
		break;
	}
}

void IOCTL_S::DEFAULT_DATA::set_special_attr_search_for_service(unsigned int service, unsigned int attr, int onOff)
{
	// TODO: return 1 ali 0 odvisno ali je v redi ali failed
	switch (service)
	{
		case SDP::SERVICE_CLASS_ID::AudioSource:
			switch (attr)
			{
				case SDP::A2DP::ATTRIBUTE_ID_DEVICE_A2DP::SupportedFeatures:
					if (onOff)
						attr_search_for_service.att_A2DP.SupportedFeatures = 1;
					else
						attr_search_for_service.att_A2DP.SupportedFeatures = 0;
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::Message_Access_Server:
			switch (attr)
			{
				case SDP::MAP::ATTRIBUTE_ID_MAP::GoepL2capPsm:
					if (onOff)
						attr_search_for_service.att_MAP.Goepl2cappsm = 1;
					else
						attr_search_for_service.att_MAP.Goepl2cappsm = 0;
				break;

				case SDP::MAP::ATTRIBUTE_ID_MAP::MASInstanceID:
					if (onOff)
						attr_search_for_service.att_MAP.MasInstanceId = 1;
					else
						attr_search_for_service.att_MAP.MasInstanceId = 0;
				break;

				case SDP::MAP::ATTRIBUTE_ID_MAP::SupportedMessageTypes:
					if (onOff)
						attr_search_for_service.att_MAP.SupportedMessageTypes = 1;
					else
						attr_search_for_service.att_MAP.SupportedMessageTypes = 0;
				break;

				case SDP::MAP::ATTRIBUTE_ID_MAP::MapSupportedFeatures:
					if (onOff)
						attr_search_for_service.att_MAP.MapSupportedFeatures = 1;
					else
						attr_search_for_service.att_MAP.MapSupportedFeatures = 0;
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::_NAP:
			switch (attr)
			{
				case SDP::NAP::ATTRIBUTE_ID_PAN::SecurityDescription:
					if (onOff)
						attr_search_for_service.att_NAP.SecurityDescription = 1;
					else
						attr_search_for_service.att_NAP.SecurityDescription = 0;
				break;

				case SDP::NAP::ATTRIBUTE_ID_PAN::NetAccessType:
					if (onOff)
						attr_search_for_service.att_NAP.NetAccessType = 1;
					else
						attr_search_for_service.att_NAP.NetAccessType = 0;
				break;

				case SDP::NAP::ATTRIBUTE_ID_PAN::MaxNetAccessrate:
					if (onOff)
						attr_search_for_service.att_NAP.MaxNetAccessRate = 1;
					else
						attr_search_for_service.att_NAP.MaxNetAccessRate = 0;
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE:
			switch (attr)
			{
				case SDP::PBAP::ATTRIBUTE_ID_PBAP::GoepL2capPsm:
					if (onOff)
						attr_search_for_service.att_PBAP.Goepl2cappsm = 1;
					else
						attr_search_for_service.att_PBAP.Goepl2cappsm = 0;
				break;

				case SDP::PBAP::ATTRIBUTE_ID_PBAP::SupportedRepositories:
					if (onOff)
						attr_search_for_service.att_PBAP.SupportedRepositories = 1;
					else
						attr_search_for_service.att_PBAP.SupportedRepositories = 0;
				break;

				case SDP::PBAP::ATTRIBUTE_ID_PBAP::PbapSupportedFeatures:
					if (onOff)
						attr_search_for_service.att_PBAP.SupportedFeatures = 1;
					else
						attr_search_for_service.att_PBAP.SupportedFeatures = 0;
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::OBEXObjectPush:
			switch (attr)
			{
				case SDP::OBEX::ATTRIBUTE_ID_OBEX::GoepL2capPsm:
					if (onOff)
						attr_search_for_service.att_OBEX.Goepl2cappsm = 1;
					else
						attr_search_for_service.att_OBEX.Goepl2cappsm = 0;
				break;

				case SDP::OBEX::ATTRIBUTE_ID_OBEX::SupportedFormatsList:
					if (onOff)
						attr_search_for_service.att_OBEX.SupportedFormats = 1;
					else
						attr_search_for_service.att_OBEX.SupportedFormats = 0;
				break;

				case SDP::OBEX::ATTRIBUTE_ID_OBEX::ServiceVersion:
					if (onOff)
						attr_search_for_service.att_OBEX.ServiceVersion = 1;
					else
						attr_search_for_service.att_OBEX.ServiceVersion = 0;
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::Handsfree:

		case SDP::SERVICE_CLASS_ID::HandsfreeAudioGateway:
			switch (attr)
			{
			case SDP::HFP::ATTRIBUTE_ID_HFP::Network:
				if (onOff)
					attr_search_for_service.att_HFP.Network = 1;
				else
					attr_search_for_service.att_HFP.Network = 0;
				break;

			case SDP::HFP::ATTRIBUTE_ID_HFP::SupportedFeatures:
				if (onOff)
					attr_search_for_service.att_HFP.SupportedFeatures = 1;
				else
					attr_search_for_service.att_HFP.SupportedFeatures = 0;
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::PnPInformation:
			switch (attr)
			{
				case SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::SpecificationID:
					if (onOff)
						attr_search_for_service.att_PNPINFO.SpecificationID = 1;
					else
						attr_search_for_service.att_PNPINFO.SpecificationID = 0;
				break;

				case SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::VendorID:
					if (onOff)
						attr_search_for_service.att_PNPINFO.VendorID = 1;
					else
						attr_search_for_service.att_PNPINFO.VendorID = 0;
				break;

				case SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::ProductID:
					if (onOff)
						attr_search_for_service.att_PNPINFO.ProductID = 1;
					else
						attr_search_for_service.att_PNPINFO.ProductID = 0;
				break;

				case SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::Version:
					if (onOff)
						attr_search_for_service.att_PNPINFO.Version = 1;
					else
						attr_search_for_service.att_PNPINFO.Version = 0;
				break;

				case SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::PrimaryRecord:
					if (onOff)
						attr_search_for_service.att_PNPINFO.PrimaryRecord = 1;
					else
						attr_search_for_service.att_PNPINFO.PrimaryRecord = 0;
				break;

				case SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::VendorIDSource:
					if (onOff)
						attr_search_for_service.att_PNPINFO.VendorIDSource = 1;
					else
						attr_search_for_service.att_PNPINFO.VendorIDSource = 0;
				break;

				case SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::ClientExecutableURL:
					if (onOff)
						attr_search_for_service.att_PNPINFO.ClientExecutableURL = 1;
					else
						attr_search_for_service.att_PNPINFO.ClientExecutableURL = 0;
				break;

				case SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::DocumentationURL:
					if (onOff)
						attr_search_for_service.att_PNPINFO.DocumentationURL = 1;
					else
						attr_search_for_service.att_PNPINFO.DocumentationURL = 0;
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::A_V_RemoteControl:
			
		case SDP::SERVICE_CLASS_ID::A_V_RemoteControlTarget:
			
		case SDP::SERVICE_CLASS_ID::A_V_RemoteControlController:
			switch (attr)
			{
				case SDP::AVRCP::ATTRIBUTE_ID_DEVICE_AVRCP::SupportedFeatures:
					if (onOff)
						attr_search_for_service.att_AVRCP.SupportedFeatures = 1;
					else
						attr_search_for_service.att_AVRCP.SupportedFeatures = 0;
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::Headset:
			
		case SDP::SERVICE_CLASS_ID::Headset_Audio_Gateway:
			switch (attr)
			{
				case SDP::HSP::ATTRIBUTE_ID_DEVICE_HSP::RemoteAudioVolumeControl:
					if (onOff)
						attr_search_for_service.att_HSP.RemoteAudioVolumeControl = 1;
					else
						attr_search_for_service.att_HSP.RemoteAudioVolumeControl = 0;
				break;
			}
		break;
	}
}

void IOCTL_S::DEFAULT_DATA::set_default_attr_search_for_service(unsigned int attr, int onOff)
{
	switch (attr)
	{
		case SDP::ATTRIBUTE_ID::ServiceRecordHandle:
			if (onOff)
				attr_search_for_service.att_DEFAULT.ServiceRecord = 1;
			else
				attr_search_for_service.att_DEFAULT.ServiceRecord = 0;
		break;

		case SDP::ATTRIBUTE_ID::ServiceClassIDList:
			if (onOff)
				attr_search_for_service.att_DEFAULT.ServiceClassIDList = 1;
			else
				attr_search_for_service.att_DEFAULT.ServiceClassIDList = 0;
			break;

		case SDP::ATTRIBUTE_ID::ProtocolDescriptorList:
			if (onOff)
				attr_search_for_service.att_DEFAULT.ProtocolDescriptorList = 1;
			else
				attr_search_for_service.att_DEFAULT.ProtocolDescriptorList = 0;
			break;

		case SDP::ATTRIBUTE_ID::ServiceName:
			if (onOff)
				attr_search_for_service.att_DEFAULT.ServiceName = 1;
			else
				attr_search_for_service.att_DEFAULT.ServiceName = 0;
			break;

		case SDP::ATTRIBUTE_ID::BluetoothProfileDescriptorList:
			if (onOff)
				attr_search_for_service.att_DEFAULT.BluetoothProfileDescriptorList = 1;
			else
				attr_search_for_service.att_DEFAULT.BluetoothProfileDescriptorList = 0;
			break;

		case SDP::ATTRIBUTE_ID::ProviderName:
			if (onOff)
				attr_search_for_service.att_DEFAULT.ProviderName = 1;
			else
				attr_search_for_service.att_DEFAULT.ProviderName = 0;
			break;

		case SDP::ATTRIBUTE_ID::LanguageBaseAttributeIDList:
			if (onOff)
				attr_search_for_service.att_DEFAULT.LanguageBaseAttributeIdList = 1;
			else
				attr_search_for_service.att_DEFAULT.LanguageBaseAttributeIdList = 0;
			break;

		case SDP::ATTRIBUTE_ID::ServiceDescription:
			if (onOff)
				attr_search_for_service.att_DEFAULT.ServiceDescription = 1;
			else
				attr_search_for_service.att_DEFAULT.ServiceDescription = 0;
			break;
	}
}


/***********************************************************************/
// reset functions

void IOCTL_S::DEFAULT_DATA::reset_all_SDP_service_for_search()
{
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::Headset, 0);
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::AudioSource, 0);
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::Headset_Audio_Gateway, 0);
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::Handsfree, 0);
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::OBEXObjectPush, 0);
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::A_V_RemoteControl, 0);
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::A_V_RemoteControlTarget, 0);
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::A_V_RemoteControlController, 0);
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::PANU, 0);
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::_NAP, 0);
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::HandsfreeAudioGateway, 0);
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE, 0);
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::Message_Access_Server, 0);
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::PnPInformation, 0);
	set_SDP_service_for_search(SDP::SERVICE_CLASS_ID::GenericAudio, 0);
}


void IOCTL_S::DEFAULT_DATA::reset_all_attr_search_for_service()
{
	attr_search_for_service.all = 0;

	set_all_default_attr_search_for_service(0);

	set_all_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::PnPInformation, 0);
	set_all_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE, 0);
	set_all_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::OBEXObjectPush, 0);
	set_all_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::_NAP, 0);
	set_all_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::Headset, 0);
	set_all_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::HandsfreeAudioGateway, 0);
	set_all_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::A_V_RemoteControlTarget, 0);
	set_all_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::AudioSource, 0);
	set_all_special_attr_search_for_service(SDP::SERVICE_CLASS_ID::Message_Access_Server, 0);
}



/***********************************************************************/
// printing functions
void IOCTL_S::DEFAULT_DATA::set_all_default_attr_service_PRINT(int onOff)
{
	if (onOff)
	{
		set_default_attr_service_PRINT(SDP::ATTRIBUTE_ID::ServiceRecordHandle, 1);
		set_default_attr_service_PRINT(SDP::ATTRIBUTE_ID::ServiceClassIDList, 1);
		set_default_attr_service_PRINT(SDP::ATTRIBUTE_ID::ProtocolDescriptorList, 1);
		set_default_attr_service_PRINT(SDP::ATTRIBUTE_ID::ServiceName, 1);
		set_default_attr_service_PRINT(SDP::ATTRIBUTE_ID::BluetoothProfileDescriptorList, 1);
		set_default_attr_service_PRINT(SDP::ATTRIBUTE_ID::ProviderName, 1);
		set_default_attr_service_PRINT(SDP::ATTRIBUTE_ID::LanguageBaseAttributeIDList, 1);
		set_default_attr_service_PRINT(SDP::ATTRIBUTE_ID::ServiceDescription, 1);
	}
	else
	{
		set_default_attr_service_PRINT(SDP::ATTRIBUTE_ID::ServiceRecordHandle, 0);
		set_default_attr_service_PRINT(SDP::ATTRIBUTE_ID::ServiceClassIDList, 0);
		set_default_attr_service_PRINT(SDP::ATTRIBUTE_ID::ProtocolDescriptorList, 0);
		set_default_attr_service_PRINT(SDP::ATTRIBUTE_ID::ServiceName, 0);
		set_default_attr_service_PRINT(SDP::ATTRIBUTE_ID::BluetoothProfileDescriptorList, 0);
		set_default_attr_service_PRINT(SDP::ATTRIBUTE_ID::ProviderName, 0);
		set_default_attr_service_PRINT(SDP::ATTRIBUTE_ID::LanguageBaseAttributeIDList, 0);
		set_default_attr_service_PRINT(SDP::ATTRIBUTE_ID::ServiceDescription, 0);
	}
}

void IOCTL_S::DEFAULT_DATA::set_all_special_attr_service_PRINT(unsigned int service, int onOff)
{
	switch (service)
	{
		case SDP::SERVICE_CLASS_ID::AudioSource:
			if (onOff)
			{
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::AudioSource, SDP::A2DP::ATTRIBUTE_ID_DEVICE_A2DP::SupportedFeatures, 1);
			}
			else
			{
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::AudioSource, SDP::A2DP::ATTRIBUTE_ID_DEVICE_A2DP::SupportedFeatures, 0);
			}
		break;

		case SDP::SERVICE_CLASS_ID::Message_Access_Server:
			if (onOff)
			{
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::Message_Access_Server, SDP::MAP::ATTRIBUTE_ID_MAP::GoepL2capPsm, 1);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::Message_Access_Server, SDP::MAP::ATTRIBUTE_ID_MAP::SupportedMessageTypes, 1);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::Message_Access_Server, SDP::MAP::ATTRIBUTE_ID_MAP::MASInstanceID, 1);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::Message_Access_Server, SDP::MAP::ATTRIBUTE_ID_MAP::MapSupportedFeatures, 1);
			}
			else
			{
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::Message_Access_Server, SDP::MAP::ATTRIBUTE_ID_MAP::GoepL2capPsm, 0);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::Message_Access_Server, SDP::MAP::ATTRIBUTE_ID_MAP::SupportedMessageTypes, 0);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::Message_Access_Server, SDP::MAP::ATTRIBUTE_ID_MAP::MASInstanceID, 0);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::Message_Access_Server, SDP::MAP::ATTRIBUTE_ID_MAP::MapSupportedFeatures, 0);
			}
		break;

		case SDP::SERVICE_CLASS_ID::_NAP:
			if (onOff)
			{
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::_NAP, SDP::NAP::ATTRIBUTE_ID_PAN::SecurityDescription, 1);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::_NAP, SDP::NAP::ATTRIBUTE_ID_PAN::NetAccessType, 1);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::_NAP, SDP::NAP::ATTRIBUTE_ID_PAN::MaxNetAccessrate, 1);
			}
			else
			{
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::_NAP, SDP::NAP::ATTRIBUTE_ID_PAN::SecurityDescription, 0);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::_NAP, SDP::NAP::ATTRIBUTE_ID_PAN::NetAccessType, 0);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::_NAP, SDP::NAP::ATTRIBUTE_ID_PAN::MaxNetAccessrate, 0);
			}
		break;

		case SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE:
			if (onOff)
			{
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE, SDP::PBAP::ATTRIBUTE_ID_PBAP::GoepL2capPsm, 1);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE, SDP::PBAP::ATTRIBUTE_ID_PBAP::SupportedRepositories, 1);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE, SDP::PBAP::ATTRIBUTE_ID_PBAP::PbapSupportedFeatures, 1);
			}
			else
			{
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE, SDP::PBAP::ATTRIBUTE_ID_PBAP::GoepL2capPsm, 0);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE, SDP::PBAP::ATTRIBUTE_ID_PBAP::SupportedRepositories, 0);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE, SDP::PBAP::ATTRIBUTE_ID_PBAP::PbapSupportedFeatures, 0);
			}
		break;

		case SDP::SERVICE_CLASS_ID::OBEXObjectPush:
			if (onOff)
			{
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::OBEXObjectPush, SDP::OBEX::ATTRIBUTE_ID_OBEX::GoepL2capPsm, 1);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::OBEXObjectPush, SDP::OBEX::ATTRIBUTE_ID_OBEX::SupportedFormatsList, 1);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::OBEXObjectPush, SDP::OBEX::ATTRIBUTE_ID_OBEX::ServiceVersion, 1);
			}
			else
			{
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::OBEXObjectPush, SDP::OBEX::ATTRIBUTE_ID_OBEX::GoepL2capPsm, 0);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::OBEXObjectPush, SDP::OBEX::ATTRIBUTE_ID_OBEX::SupportedFormatsList, 0);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::OBEXObjectPush, SDP::OBEX::ATTRIBUTE_ID_OBEX::ServiceVersion, 0);
			}
		break;

		case SDP::SERVICE_CLASS_ID::Handsfree:
			if (onOff)
			{
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::Handsfree, SDP::HFP::ATTRIBUTE_ID_HFP::Network, 1);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::Handsfree, SDP::HFP::ATTRIBUTE_ID_HFP::SupportedFeatures, 1);
			}
			else
			{
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::Handsfree, SDP::HFP::ATTRIBUTE_ID_HFP::Network, 0);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::Handsfree, SDP::HFP::ATTRIBUTE_ID_HFP::SupportedFeatures, 0);
			}
		break;

		case SDP::SERVICE_CLASS_ID::HandsfreeAudioGateway:
			if (onOff)
			{
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::HandsfreeAudioGateway, SDP::HFP::ATTRIBUTE_ID_HFP::Network, 1);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::HandsfreeAudioGateway, SDP::HFP::ATTRIBUTE_ID_HFP::SupportedFeatures, 1);
			}
			else
			{
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::HandsfreeAudioGateway, SDP::HFP::ATTRIBUTE_ID_HFP::Network, 0);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::HandsfreeAudioGateway, SDP::HFP::ATTRIBUTE_ID_HFP::SupportedFeatures, 0);
			}
		break;

		case SDP::SERVICE_CLASS_ID::PnPInformation:
			if (onOff)
			{
				attr_search_for_service.att_PNPINFO.PnpInfo = 1;
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::SpecificationID, 1);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::VendorID, 1);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::ProductID, 1);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::Version, 1);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::PrimaryRecord, 1);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::VendorIDSource, 1);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::ClientExecutableURL, 1);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::DocumentationURL, 1);
			}
			else
			{
				attr_search_for_service.att_PNPINFO.PnpInfo = 0;
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::SpecificationID, 0);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::VendorID, 0);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::ProductID, 0);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::Version, 0);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::PrimaryRecord, 0);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::VendorIDSource, 0);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::ClientExecutableURL, 0);
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::PnPInformation, SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::DocumentationURL, 0);
			}
		break;

		case SDP::SERVICE_CLASS_ID::A_V_RemoteControl:
			if (onOff)
			{
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::A_V_RemoteControl, SDP::AVRCP::ATTRIBUTE_ID_DEVICE_AVRCP::SupportedFeatures, 1);
			}
			else
			{
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::A_V_RemoteControl, SDP::AVRCP::ATTRIBUTE_ID_DEVICE_AVRCP::SupportedFeatures, 0);
			}
		break;

		case SDP::SERVICE_CLASS_ID::A_V_RemoteControlTarget:
			if (onOff)
			{
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::A_V_RemoteControlTarget, SDP::AVRCP::ATTRIBUTE_ID_DEVICE_AVRCP::SupportedFeatures, 1);
			}
			else
			{
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::A_V_RemoteControlTarget, SDP::AVRCP::ATTRIBUTE_ID_DEVICE_AVRCP::SupportedFeatures, 0);
			}
		break;

		case SDP::SERVICE_CLASS_ID::A_V_RemoteControlController:
			if (onOff)
			{
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::A_V_RemoteControlController, SDP::AVRCP::ATTRIBUTE_ID_DEVICE_AVRCP::SupportedFeatures, 1);
			}
			else
			{
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::A_V_RemoteControlController, SDP::AVRCP::ATTRIBUTE_ID_DEVICE_AVRCP::SupportedFeatures, 0);
			}
		break;

		case SDP::SERVICE_CLASS_ID::Headset:
			if (onOff)
			{
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::Headset, SDP::HSP::ATTRIBUTE_ID_DEVICE_HSP::RemoteAudioVolumeControl, 1);
			}
			else
			{
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::Headset, SDP::HSP::ATTRIBUTE_ID_DEVICE_HSP::RemoteAudioVolumeControl, 0);
			}
		break;

		case SDP::SERVICE_CLASS_ID::Headset_Audio_Gateway:
			if (onOff)
			{
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::Headset_Audio_Gateway, SDP::HSP::ATTRIBUTE_ID_DEVICE_HSP::RemoteAudioVolumeControl, 1);
			}
			else
			{
				set_special_attr_service_PRINT(SDP::SERVICE_CLASS_ID::Headset_Audio_Gateway, SDP::HSP::ATTRIBUTE_ID_DEVICE_HSP::RemoteAudioVolumeControl, 0);
			}
		break;
	}
}

void IOCTL_S::DEFAULT_DATA::set_default_attr_service_PRINT(unsigned int attr, int onOff)
{
	switch (attr)
	{
		case SDP::ATTRIBUTE_ID::ServiceRecordHandle:
			if (onOff)
				sdp_settings.print_service.print_service_record = 1;
			else
				sdp_settings.print_service.print_service_record = 0;
		break;

		case SDP::ATTRIBUTE_ID::ServiceClassIDList:
			if (onOff)
				sdp_settings.print_service.print_service_class_id_list = 1;
			else
				sdp_settings.print_service.print_service_class_id_list = 0;
		break;

		case SDP::ATTRIBUTE_ID::ProtocolDescriptorList:
			if (onOff)
				sdp_settings.print_service.print_protocol_descriptor_list = 1;
			else
				sdp_settings.print_service.print_protocol_descriptor_list = 0;
		break;

		case SDP::ATTRIBUTE_ID::ServiceName:
			if (onOff)
				sdp_settings.print_service.print_service_name = 1;
			else
				sdp_settings.print_service.print_service_name = 0;
		break;

		case SDP::ATTRIBUTE_ID::BluetoothProfileDescriptorList:
			if (onOff)
				sdp_settings.print_service.print_bluetooth_profile_descriptor_list = 1;
			else
				sdp_settings.print_service.print_bluetooth_profile_descriptor_list = 0;
		break;

		case SDP::ATTRIBUTE_ID::ProviderName:
			if (onOff)
				sdp_settings.print_service.print_provider_name = 1;
			else
				sdp_settings.print_service.print_provider_name = 0;
		break;

		case SDP::ATTRIBUTE_ID::LanguageBaseAttributeIDList:
			if (onOff)
				sdp_settings.print_service.print_language_base_attribute_id_list = 1;
			else
				sdp_settings.print_service.print_language_base_attribute_id_list = 0;
		break;

		case SDP::ATTRIBUTE_ID::ServiceDescription:
			if (onOff)
				sdp_settings.print_service.print_service_description = 1;
			else
				sdp_settings.print_service.print_service_description = 0;
		break;
	}
}

void IOCTL_S::DEFAULT_DATA::set_special_attr_service_PRINT(unsigned int service, unsigned int attr, int onOff)
{
	switch (service)
	{
		case SDP::SERVICE_CLASS_ID::AudioSource:
			switch (attr)
			{
			case SDP::A2DP::ATTRIBUTE_ID_DEVICE_A2DP::SupportedFeatures:
				if (onOff)
					sdp_settings.print_service.print_A2DP_attributes.print_supported_features = 1;
				else
					sdp_settings.print_service.print_A2DP_attributes.print_supported_features = 0;
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::Message_Access_Server:
			switch (attr)
			{
			case SDP::MAP::ATTRIBUTE_ID_MAP::GoepL2capPsm:
				if (onOff)
					sdp_settings.print_service.print_MAP_attributes.print_goepl2cappsm = 1;
				else
					sdp_settings.print_service.print_MAP_attributes.print_goepl2cappsm = 0;
				break;

			case SDP::MAP::ATTRIBUTE_ID_MAP::MASInstanceID:
				if (onOff)
					sdp_settings.print_service.print_MAP_attributes.print_mas_instance_id = 1;
				else
					sdp_settings.print_service.print_MAP_attributes.print_mas_instance_id = 0;
				break;

			case SDP::MAP::ATTRIBUTE_ID_MAP::SupportedMessageTypes:
				if (onOff)
					sdp_settings.print_service.print_MAP_attributes.print_supported_message_types = 1;
				else
					sdp_settings.print_service.print_MAP_attributes.print_supported_message_types = 0;
				break;

			case SDP::MAP::ATTRIBUTE_ID_MAP::MapSupportedFeatures:
				if (onOff)
					sdp_settings.print_service.print_MAP_attributes.print_map_supported_features = 1;
				else
					sdp_settings.print_service.print_MAP_attributes.print_map_supported_features = 0;
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::_NAP:
			switch (attr)
			{
			case SDP::NAP::ATTRIBUTE_ID_PAN::SecurityDescription:
				if (onOff)
					sdp_settings.print_service.print_NAP_attributes.print_security_description = 1;
				else
					sdp_settings.print_service.print_NAP_attributes.print_security_description = 0;
				break;

			case SDP::NAP::ATTRIBUTE_ID_PAN::NetAccessType:
				if (onOff)
					sdp_settings.print_service.print_NAP_attributes.print_net_access_type = 1;
				else
					sdp_settings.print_service.print_NAP_attributes.print_net_access_type = 0;
				break;

			case SDP::NAP::ATTRIBUTE_ID_PAN::MaxNetAccessrate:
				if (onOff)
					sdp_settings.print_service.print_NAP_attributes.print_max_net_access_rate = 1;
				else
					sdp_settings.print_service.print_NAP_attributes.print_max_net_access_rate = 0;
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::Phonebook_Access_PSE:
			switch (attr)
			{
			case SDP::PBAP::ATTRIBUTE_ID_PBAP::GoepL2capPsm:
				if (onOff)
					sdp_settings.print_service.print_PBAP_attributes.print_goepl2cappsm = 1;
				else
					sdp_settings.print_service.print_PBAP_attributes.print_goepl2cappsm = 0;
				break;

			case SDP::PBAP::ATTRIBUTE_ID_PBAP::SupportedRepositories:
				if (onOff)
					sdp_settings.print_service.print_PBAP_attributes.print_supported_repositories = 1;
				else
					sdp_settings.print_service.print_PBAP_attributes.print_supported_repositories = 0;
				break;

			case SDP::PBAP::ATTRIBUTE_ID_PBAP::PbapSupportedFeatures:
				if (onOff)
					sdp_settings.print_service.print_PBAP_attributes.print_pbap_supported_features = 1;
				else
					sdp_settings.print_service.print_PBAP_attributes.print_pbap_supported_features = 0;
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::OBEXObjectPush:
			switch (attr)
			{
			case SDP::OBEX::ATTRIBUTE_ID_OBEX::GoepL2capPsm:
				if (onOff)
					sdp_settings.print_service.print_OBEX_attributes.print_goepl2cappsm = 1;
				else
					sdp_settings.print_service.print_OBEX_attributes.print_goepl2cappsm = 0;
				break;

			case SDP::OBEX::ATTRIBUTE_ID_OBEX::SupportedFormatsList:
				if (onOff)
					sdp_settings.print_service.print_OBEX_attributes.print_supported_formats = 1;
				else
					sdp_settings.print_service.print_OBEX_attributes.print_supported_formats = 0;
				break;

			case SDP::OBEX::ATTRIBUTE_ID_OBEX::ServiceVersion:
				if (onOff)
					sdp_settings.print_service.print_OBEX_attributes.print_service_version = 1;
				else
					sdp_settings.print_service.print_OBEX_attributes.print_service_version = 0;
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::Handsfree:

		case SDP::SERVICE_CLASS_ID::HandsfreeAudioGateway:
			switch (attr)
			{
			case SDP::HFP::ATTRIBUTE_ID_HFP::Network:
				if (onOff)
					sdp_settings.print_service.print_HFP_attributes.print_network = 1;
				else
					sdp_settings.print_service.print_HFP_attributes.print_network = 0;
				break;

			case SDP::HFP::ATTRIBUTE_ID_HFP::SupportedFeatures:
				if (onOff)
					sdp_settings.print_service.print_HFP_attributes.print_supported_features = 1;
				else
					sdp_settings.print_service.print_HFP_attributes.print_supported_features = 0;
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::PnPInformation:
			switch (attr)
			{
			case SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::SpecificationID:
				if (onOff)
					sdp_settings.print_service.print_PNPINFO_attributes.SpecificationID = 1;
				else
					sdp_settings.print_service.print_PNPINFO_attributes.SpecificationID = 0;
				break;

			case SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::VendorID:
				if (onOff)
					sdp_settings.print_service.print_PNPINFO_attributes.VendorID = 1;
				else
					sdp_settings.print_service.print_PNPINFO_attributes.VendorID = 0;
				break;

			case SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::ProductID:
				if (onOff)
					sdp_settings.print_service.print_PNPINFO_attributes.ProductID = 1;
				else
					sdp_settings.print_service.print_PNPINFO_attributes.ProductID = 0;
				break;

			case SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::Version:
				if (onOff)
					sdp_settings.print_service.print_PNPINFO_attributes.Version = 1;
				else
					sdp_settings.print_service.print_PNPINFO_attributes.Version = 0;
				break;

			case SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::PrimaryRecord:
				if (onOff)
					sdp_settings.print_service.print_PNPINFO_attributes.PrimaryRecord = 1;
				else
					sdp_settings.print_service.print_PNPINFO_attributes.PrimaryRecord = 0;
				break;

			case SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::VendorIDSource:
				if (onOff)
					sdp_settings.print_service.print_PNPINFO_attributes.VendorIDSource = 1;
				else
					sdp_settings.print_service.print_PNPINFO_attributes.VendorIDSource = 0;
				break;

			case SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::ClientExecutableURL:
				if (onOff)
					sdp_settings.print_service.print_PNPINFO_attributes.ClientExecutableURL = 1;
				else
					sdp_settings.print_service.print_PNPINFO_attributes.ClientExecutableURL = 0;
				break;

			case SDP::PNPINFO::ATTRIBUTE_ID_DEVICE_SDP::DocumentationURL:
				if (onOff)
					sdp_settings.print_service.print_PNPINFO_attributes.DocumentationURL = 1;
				else
					sdp_settings.print_service.print_PNPINFO_attributes.DocumentationURL = 0;
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::A_V_RemoteControl:

		case SDP::SERVICE_CLASS_ID::A_V_RemoteControlTarget:

		case SDP::SERVICE_CLASS_ID::A_V_RemoteControlController:
			switch (attr)
			{
			case SDP::AVRCP::ATTRIBUTE_ID_DEVICE_AVRCP::SupportedFeatures:
				if (onOff)
					sdp_settings.print_service.print_AVRCP_attributes.print_supported_features = 1;
				else
					sdp_settings.print_service.print_AVRCP_attributes.print_supported_features = 0;
				break;
			}
		break;

		case SDP::SERVICE_CLASS_ID::Headset:

		case SDP::SERVICE_CLASS_ID::Headset_Audio_Gateway:
			switch (attr)
			{
			case SDP::HSP::ATTRIBUTE_ID_DEVICE_HSP::RemoteAudioVolumeControl:
				if (onOff)
					sdp_settings.print_service.print_HSP_attributes.print_remote_audio_volume_control = 1;
				else
					sdp_settings.print_service.print_HSP_attributes.print_remote_audio_volume_control = 0;
				break;
			}
		break;
	}
}

void IOCTL_S::DEFAULT_DATA::set_printing_type(IOCTL_DATA_STRUCTURES_S::PRINTING_TYPES* obj_types)
{
	sdp_settings.debug = obj_types->debug;
	sdp_settings.print = obj_types->print;
	sdp_settings.print_info = obj_types->print_info;
	sdp_settings.print_with_outside_funct = obj_types->print_with_outside_funct;
}







void IOCTL_S::printErrorMessage(DWORD id, DEFAULT_DATA& dd)
{
	if (dd.error == nullptr)
		dd.error = new IOCTL_DATA_STRUCTURES_S::returned_ERROR();

	dd.error->error_occurred_flag = 1;
	dd.error->id = id;

	// TODO: naredi se za outside function
	if (id != 0x00)
		switch (id)
		{
			case 0x00:
				if (dd.sdp_settings.debug == 1)
				{
					printf("ERROR [0x%X - %d] [OK]\n", id, id);
				}

				dd.error->name = "OK";
			break;

			case 0x01:
				printf("ERROR [0x%X - %d] [ERROR_INVALID_FUNCTION]\n", id, id);
				dd.error->name = "ERROR_INVALID_FUNCTION";
			break;

			case 0x02:
				printf("ERROR [0x%X - %d] [ERROR_FILE_NOT_FOUND]\n", id, id);
				dd.error->name = "ERROR_FILE_NOT_FOUND";
			break;

			case 0x6:
				printf("ERROR [0x%X - %d] [ERROR_INVALID_HANDLE]\n", id, id);
				dd.error->name = "ERROR_INVALID_HANDLE";
			break;

			case 0x35:
				printf("ERROR [0x%X - %d] [ERROR_BAD_NETPATH]\n", id, id);
				dd.error->name = "ERROR_BAD_NETPATH";
			break;

			case 0x3A:
				printf("ERROR [0x%X - %d] [ERROR_BAD_NET_RESP]\n", id, id);
				dd.error->name = "ERROR_BAD_NET_RESP";
			break;

			case 0x57:
				printf("ERROR [0x%X - %d] [ERROR_INVALID_PARAMETER]\n", id, id);
				dd.error->name = "ERROR_INVALID_PARAMETER";
			break;

			case 0x79:
				printf("ERROR [0x%X - %d] [ERROR_SEM_TIMEOUT]\n", id, id);
				dd.error->name = "ERROR_SEM_TIMEOUT";
			break;

			case 0x7A:
				printf("ERROR [0x%X - %d] [ERROR_INSUFFICIENT_BUFFER]\n", id, id);
				dd.error->name = "ERROR_INSUFFICIENT_BUFFER";
			break;

			case 0x7B:
				printf("ERROR [0x%X - %d] [ERROR_INVALID_NAME]\n", id, id);
				dd.error->name = "ERROR_INVALID_NAME";
			break;

			case 0x32:
				printf("ERROR [0x%X - %d] [ERROR_NOT_SUPPORTED]\n", id, id);
				dd.error->name = "ERROR_NOT_SUPPORTED";
			break;

			case 0x522:
				printf("ERROR [0x%X - %d] [ERROR_PRIVILEGE_NOT_HELD]\n", id, id);
				dd.error->name = "ERROR_PRIVILEGE_NOT_HELD";
			break;

			case 0x48F:
				printf("ERROR [0x%X - %d] [ERROR_DEVICE_NOT_CONNECTED]\n", id, id);
				dd.error->name = "ERROR_DEVICE_NOT_CONNECTED";
			break;

			case 0x6F8:
				printf("ERROR [0x%X - %d] [ERROR_INVALID_USER_BUFFER]\n", id, id);
				dd.error->name = "ERROR_INVALID_USER_BUFFER";
			break;

			default:
				printf("ERROR [0x%X - %d] [????]\n", id, id);
				dd.error->name = "????";
			break;
		}
}

int IOCTL_S::connectToDevice(const wchar_t* name, DEFAULT_DATA& dd)
{
	// TODO: razmisli ali se to avtomaticno naredi, ali naj raje user to naredi z importanjem file-a s seznamom
	dd.fill_vendors_list();


	dd.hDevice = CreateFileW(
		name,									// drive to open
		FILE_READ_DATA | FILE_WRITE_DATA,		// no access to the drive
		FILE_SHARE_READ | FILE_SHARE_WRITE,		// share mode
		NULL,									// default security attributes
		OPEN_EXISTING,							// disposition
		0,										// file attributes
		NULL);									// do not copy file attributes

	if (dd.hDevice == INVALID_HANDLE_VALUE)
	{
		printErrorMessage(GetLastError(), dd);

		return 0;
	}

	return 1;
}

int IOCTL_S::closeConnectionToDevice(DEFAULT_DATA& dd)
{
	if (CloseHandle(dd.hDevice) == 0)
	{
		printErrorMessage(GetLastError(), dd);
		return 0;
	}
	else
	{
		if(dd.sdp_settings.print_info == 1)
			printf("CONNECTION TO DEVICE CLOSED!\n");

		return 1;
	}
}

int IOCTL_S::str2ba(const char* straddr, BTH_ADDR& btaddr)
{
	int i;
	unsigned int aaddr[6];
	BTH_ADDR tmpaddr = 0;

	if (sscanf_s(straddr, "%02x:%02x:%02x:%02x:%02x:%02x",
		&aaddr[0], &aaddr[1], &aaddr[2],
		&aaddr[3], &aaddr[4], &aaddr[5]) != 6)
		return 1;
	btaddr = 0;
	for (i = 0; i < 6; i++) {
		tmpaddr = (BTH_ADDR)(aaddr[i] & 0xff);
		btaddr = ((btaddr) << 8) + tmpaddr;
	}
	return 0;
}


void IOCTL_S::test123(DEFAULT_DATA& dd)
{
	/*
	
	https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_hci_vendor_command
	



	*/
	
	
	BYTE data[5000]{ 0 };

	BTH_COMMAND_HEADER bch = { 0 };

	_BTH_VENDOR_SPECIFIC_COMMAND bvsc = { 0 };
	
	BTH_VENDOR_EVENT_INFO bvei = { 0 };

	dd.bResult = DeviceIoControl(
		dd.hDevice,						// device to be queried
		IOCTL_BTH_HCI_VENDOR_COMMAND,			// operation to perform
		&bvsc, sizeof(bvsc),							// no input buffer
		&bvei, sizeof(bvei),					// output buffer
		&dd.junk,							// # bytes returned
		(LPOVERLAPPED)NULL);				// synchronous I/O


	if (dd.bResult)
	{

		printf("DELA!!!\n");
	}
}


// LIST OF CACHED BTH SEARCHED DEVICES
int IOCTL_S::getBthDeviceInfo(DEFAULT_DATA& dd, int print)
{
	BYTE data[sizeof(BTH_DEVICE_INFO_LIST) + (MAX_SEARCHED_SHOWED_DEVICE - 1) * sizeof(BTH_DEVICE_INFO)]{ 0 };

	dd.bResult = DeviceIoControl(
		dd.hDevice,						// device to be queried
		IOCTL_BTH_GET_DEVICE_INFO,			// operation to perform
		NULL, 0,							// no input buffer
		data, sizeof(data),					// output buffer
		&dd.junk,							// # bytes returned
		(LPOVERLAPPED)NULL);				// synchronous I/O

	printErrorMessage(GetLastError(), dd);

	if (dd.bResult)
	{
		BTH_DEVICE_INFO_LIST* bdil = (BTH_DEVICE_INFO_LIST*)data;
		BTH_DEVICE_INFO* bdi = bdil->deviceList;

		dd.exported_data.devices = new BTH_DEVICES::SEARCHED_CACHED_DEVICES();
		dd.exported_data.devices->numOfDevices = bdil->numOfDevices;

		for (int a = 0; a < bdil->numOfDevices; a++)
		{
			BLUETOOTH_ADDRESS_STRUCT* bas = (BLUETOOTH_ADDRESS_STRUCT*)&((bdi + a)->address);

			BTH_DEVICES::CACHED_DEVICE_S temp{ (bdi + a)->name, bas->rgBytes, (bdi + a)->flags };

			dd.exported_data.devices->devices.push_back(temp);


			// TODO: klici se posebej za device tole --> IOCTL_BTH_GET_RADIO_INFO
			// verjetno je to za connected devices


		}

		if (print == 1)
			dd.exported_data.devices->print();

		return 1;
	}
	else
		return 0;
}

// information about the local Bluetooth system and radio
int IOCTL_S::getLocalBthInfo(DEFAULT_DATA& dd, int print)
{
	BTH_LOCAL_RADIO_INFO blri{ 0 };

	dd.bResult = DeviceIoControl(
		dd.hDevice,					// device to be queried
		IOCTL_BTH_GET_LOCAL_INFO,		// operation to perform
		NULL, 0,						// no input buffer
		&blri, sizeof(blri),			// output buffer
		&dd.junk,						// # bytes returned
		(LPOVERLAPPED)NULL);			// synchronous I/O

	//printErrorMessage(GetLastError());

	if (dd.bResult)
	{
		BTH_DEVICE_INFO bdi = blri.localInfo;
		BTH_RADIO_INFO* bri = &blri.radioInfo;

		dd.exported_data.local_device_radio = new BTH_DEVICES::LOCAL_RADIO_DEVICE_DATA(
			blri.flags,
			blri.hciRevision,
			blri.hciVersion
		);

		//BTH_DEVICES::DEVICE_DATA_S temp_d;

		dd.exported_data.local_device_radio->device = new BTH_DEVICES::DEVICE_DATA();

		dd.exported_data.local_device_radio->device->init(
			((BLUETOOTH_ADDRESS_STRUCT*)(&bdi.address))->rgBytes,
			bdi.flags,
			bdi.name
		);
		
		COD_PARSER::PDEVICE_PARSED_COD_DATA cod_temp = new COD_PARSER::DEVICE_PARSED_COD_DATA();
		parseCODdata((COD_PARSER::COD_data*)&bdi.classOfDevice, cod_temp);
		dd.exported_data.local_device_radio->device->cod = cod_temp;

		dd.exported_data.local_device_radio->radio = new BTH_DEVICES::RADIO_DATA{ bri->lmpSupportedFeatures ,bri->mfg,bri->lmpSubversion, bri->lmpVersion };

		// TODO: preveri tezavo s prikazom zunaj
		
		
		if(print == 1)
			dd.exported_data.local_device_radio->print();

		if (dd.outside_print_function != NULL && dd.sdp_settings.print_with_outside_funct == 1)
		{
			// TODO: naredi se za outside func
		}

		return 1;
	}
	else
	{
		printErrorMessage(GetLastError(), dd);

		return 0;
	}
}




int IOCTL_S::SDPsearch(DEFAULT_DATA& dd, char address[])	// TODO: preimenuj v pravo ime
{
	
	
	/********************************************************************/
	/* INIT */

	SDP::DEVICE_DATA_SDP* device_data_sdp = new SDP::DEVICE_DATA_SDP();
	
	SDP::FUNCTIONS::SDP_INIT_CONNECT::init_for_IOCTL_BTH_SDP_CONNECT(address, *device_data_sdp, dd);

	/********************************************************************/
	/* CONNECT TO DEVICE */

	if (SDP::FUNCTIONS::SDP_INIT_CONNECT::call_IOCTL_BTH_SDP_CONNECT(*device_data_sdp, dd))
	{
		if(dd.sdp_settings.print_info == 1)
			printf("DEVICE CONNECTED!!\n");

		/******************************************/
		/* SERVICE SEARCH */

		if (dd.services_for_search.Headset == 0x01)
		{
			device_data_sdp->current_used_service = SDP::Headset;
			SDP::FUNCTIONS::call_and_search_service(*device_data_sdp, dd);
		}

		if (dd.services_for_search.Headset_Audio_Gateway == 0x01)
		{
			device_data_sdp->current_used_service = SDP::Headset_Audio_Gateway;
			SDP::FUNCTIONS::call_and_search_service(*device_data_sdp, dd);
		}

		if (dd.services_for_search.AudioSource == 0x01)
		{
			device_data_sdp->current_used_service = SDP::AudioSource;
			SDP::FUNCTIONS::call_and_search_service(*device_data_sdp, dd);
		}

		if (dd.services_for_search.GenericAudio == 0x01)
		{
			device_data_sdp->current_used_service = SDP::GenericAudio;
			SDP::FUNCTIONS::call_and_search_service(*device_data_sdp, dd);
		}

		if (dd.services_for_search.Handsfree == 0x01)
		{
			device_data_sdp->current_used_service = SDP::Handsfree;
			SDP::FUNCTIONS::call_and_search_service(*device_data_sdp, dd);
		}

		if (dd.services_for_search.HandsfreeAudioGateway == 0x01)
		{
			device_data_sdp->current_used_service = SDP::HandsfreeAudioGateway;
			SDP::FUNCTIONS::call_and_search_service(*device_data_sdp, dd);
		}

		if (dd.services_for_search.OBEXObjectPush == 0x01)
		{
			device_data_sdp->current_used_service = SDP::OBEXObjectPush;
			SDP::FUNCTIONS::call_and_search_service(*device_data_sdp, dd);
		}

		if (dd.services_for_search.A_V_RemoteControl == 0x01)
		{
			device_data_sdp->current_used_service = SDP::A_V_RemoteControl;
			SDP::FUNCTIONS::call_and_search_service(*device_data_sdp, dd);
		}

		if (dd.services_for_search.A_V_RemoteControlTarget == 0x01)
		{
			device_data_sdp->current_used_service = SDP::A_V_RemoteControlTarget;
			SDP::FUNCTIONS::call_and_search_service(*device_data_sdp, dd);
		}

		if (dd.services_for_search.A_V_RemoteControlController == 0x01)
		{
			device_data_sdp->current_used_service = SDP::A_V_RemoteControlController;
			SDP::FUNCTIONS::call_and_search_service(*device_data_sdp, dd);
		}

		if (dd.services_for_search.PANU == 0x01)
		{
			device_data_sdp->current_used_service = SDP::PANU;
			SDP::FUNCTIONS::call_and_search_service(*device_data_sdp, dd);
		}

		if (dd.services_for_search._NAP == 0x01)
		{
			device_data_sdp->current_used_service = SDP::_NAP;
			SDP::FUNCTIONS::call_and_search_service(*device_data_sdp, dd);
		}

		if (dd.services_for_search.Phonebook_Access_PSE == 0x01)
		{
			device_data_sdp->current_used_service = SDP::Phonebook_Access_PSE;
			SDP::FUNCTIONS::call_and_search_service(*device_data_sdp, dd);
		}

		if (dd.services_for_search.Message_Access_Server == 0x01)
		{
			device_data_sdp->current_used_service = SDP::Message_Access_Server;
			SDP::FUNCTIONS::call_and_search_service(*device_data_sdp, dd);
		}

		if (dd.services_for_search.PnPInformation == 0x01)
		{
			device_data_sdp->current_used_service = SDP::PnPInformation;
			SDP::FUNCTIONS::call_and_search_service(*device_data_sdp, dd);
		}



		/******************************************/
		/* DISCONNECTION FROM DEVICE (IMPORTANT!!!) */

		SDP::FUNCTIONS::SDP_INIT_DISCONNECT::init_for_IOCTL_BTH_SDP_DISCONNECT(*device_data_sdp);

		return SDP::FUNCTIONS::SDP_INIT_DISCONNECT::call_IOCTL_BTH_SDP_DISCONNECT(*device_data_sdp, dd);
	}

	return 0;
}

void IOCTL_S::DEFAULT_DATA::fill_vendors_list()
{
	vendors_list = new std::vector<IOCTL_DATA_STRUCTURES_S::vendor_ID_s*>();
	
	std::ifstream file;

	file.open(COMPANY_IDs);

	if (file.is_open())
	{
		if(sdp_settings.debug == 1)
			printf("OPENED!!\n");

		while (!file.eof()) 
		{
			char word[100];

			file.getline(word, 100, '\n');
			
			char* next_token = nullptr;
			// Returns first token
			char* token = strtok_s(word,",", &next_token);

			vendors_list->push_back(new IOCTL_DATA_STRUCTURES_S::vendor_ID_s);
			size_t vendors_size = vendors_list->size();

			int count = 0;
			while (token != NULL)
			{
				switch (count)
				{
					case 0:
						{
							std::string temp_string = "";
							
							for (int i = 1; i < (sizeof(token)); i++)
							{
								if (token[i] == 0x00)
									break;

								if (token[i] != 0x22)
								{
									temp_string += token[i];
								}
							}

							std::stringstream ss1;
							//short x;
							ss1 << std::dec << temp_string;
							ss1 >> vendors_list->at(vendors_size - 1)->decimal;
						}
					break;

				case 1:
				{
					std::stringstream ss1;
					//short x;
					ss1 << std::hex << token;
					ss1 >> vendors_list->at(vendors_size - 1)->hexadecimal;
				}
				break;

				case 3:
					vendors_list->at(vendors_size - 1)->company = token;
					break;
				}
				
				token = strtok_s(NULL, "\"", &next_token);
				count++;
			}
		}

		file.close();

		if (sdp_settings.debug == 1)
			printf("FINISHED!!\n");
	}
	else
	{
		if (sdp_settings.debug == 1)
			printf("NOT OPENED!!\n");
	}

	//for (int i = 0; i < vendors_list->size(); i++)
		//std::cout << vendors_list->at(i)->company << std::endl;
}








