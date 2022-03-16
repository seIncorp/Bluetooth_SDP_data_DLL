#include "pch.h"




/*********************************************************************************************************************/
/* MAP SPECIFIC */

std::string SDP::MAP::getMessageTypesString(SDP::MAP::SUPPORTED_FEATURES_MESSAGES_S* sfm)
{
	std::string temp = "";

	if (sfm->ttt->a0)
	{
		temp.append("EMAIL\n");
	}

	if (sfm->ttt->a1)
	{
		temp.append("SMS_GSM\n");
	}

	if (sfm->ttt->a2)
	{
		temp.append("SMS_CDMA\n");
	}

	if (sfm->ttt->a3)
	{
		temp.append("MMS\n");
	}

	if (sfm->ttt->a4)
	{
		temp.append("IM\n");
	}

	return temp;
}

std::string SDP::MAP::getSupportedFeaturesString(SDP::MAP::SUPPORTED_FEATURES_MESSAGES_S* sfm)
{
	std::string temp = "";

	if (sfm->aaa->a0)
	{
		temp.append("Notification Registration Feature\n");
	}

	if (sfm->aaa->a1)
	{
		temp.append("Notification Feature\n");
	}

	if (sfm->aaa->a2)
	{
		temp.append("Browsing Feature\n");
	}

	if (sfm->aaa->a3)
	{
		temp.append("Uploading Feature\n");
	}

	if (sfm->aaa->a4)
	{
		temp.append("Delete Feature\n");
	}

	if (sfm->aaa->a5)
	{
		temp.append("Instance Information Feature\n");
	}

	if (sfm->aaa->a6)
	{
		temp.append("Extended Event Report 1.1\n");
	}

	if (sfm->aaa->a7)
	{
		temp.append("Event Report Version 1.2\n");
	}

	if (sfm->aaa->a8)
	{
		temp.append("Message Format Version 1.1\n");
	}

	if (sfm->aaa->a9)
	{
		temp.append("MessagesListing Format Version 1.1\n");
	}

	if (sfm->aaa->a10)
	{
		temp.append("Persistent Message Handles\n");
	}

	if (sfm->aaa->a11)
	{
		temp.append("Database Identifier\n");
	}

	if (sfm->aaa->a12)
	{
		temp.append("Folder Version Counter\n");
	}

	if (sfm->aaa->a13)
	{
		temp.append("Conversation Version Counters\n");
	}

	if (sfm->aaa->a14)
	{
		temp.append("Participant Presence Change Notification\n");
	}

	if (sfm->aaa->a15)
	{
		temp.append("Participant Chat State Change Notification\n");
	}

	if (sfm->aaa->a16)
	{
		temp.append("PBAP Contact Cross Reference\n");
	}

	if (sfm->aaa->a17)
	{
		temp.append("Notification Filtering\n");
	}

	if (sfm->aaa->a18)
	{
		temp.append("UTC Offset Timestamp Format\n");
	}

	if (sfm->aaa->a19)
	{
		temp.append("MapSupportedFeatures in Connect Request\n");
	}

	if (sfm->aaa->a20)
	{
		temp.append("Conversation listing\n");
	}

	if (sfm->aaa->a21)
	{
		temp.append("Owner Status\n");
	}

	if (sfm->aaa->a22)
	{
		temp.append("Message Forwarding\n");
	}

	return temp;
}



void SDP::MAP::parse_GOEPL2CAPPSM_MAP(PGOEPL2CAPPSM handle)
{
	SHORT temp = 0x00;
	temp |= handle->VALUE.value[0];
	temp <<= 8;
	temp |= handle->VALUE.value[1];

	handle->VALUE.GoepL2CapPsm_value = temp;
}

void SDP::MAP::parse_SUPPORTED_MESSAGE_TYPES_MAP(PSUPPORTED_MESSAGE_TYPES handle)
{
	handle->VALUE.sfm = new SUPPORTED_FEATURES_MESSAGES_S(0, 0, handle->VALUE.value[handle->VALUE.size_bytes-1]);
}

void SDP::MAP::parse_MAS_INSTANCE_ID_MAP(PMAS_INSTANCE_ID handle)
{
	handle->VALUE.instance_ID = handle->VALUE.value[0];
}

void SDP::MAP::parse_MAP_SUPPORTED_FEATURES_MAP(PMAP_SUPPORTED_FEATURES handle)
{
	DWORD temp = 0x00;

	temp |= handle->VALUE.value[0];
	temp <<= 8;
	temp |= handle->VALUE.value[1];
	temp <<= 8;
	temp |= handle->VALUE.value[2];
	temp <<= 8;
	temp |= handle->VALUE.value[3];

	handle->VALUE.sfm = new SUPPORTED_FEATURES_MESSAGES_S(1, temp,0);
}


/*********************************************************************************************************************/
/* CLASS MAP_all_attributes functions */


SDP::MAP::MAP_class::MAP_class(IOCTL_S::DEFAULT_DATA dd)
{
	// set all objects
	setDefaultObjects(dd);

	goepl2cappsm_handle = new GOEPL2CAPPSM();
	supported_message_types_handle = new SUPPORTED_MESSAGE_TYPES();
	mas_instance_id_handle = new MAS_INSTANCE_ID();
	map_supported_features_handle = new MAP_SUPPORTED_FEATURES();
}

void SDP::MAP::MAP_class::call_ALL_ATTR(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd)
{
	callDefaultAttributes(device_data_sdp, dd);

	FUNCTIONS::getAndParse_DEAFULT<PGOEPL2CAPPSM, GOEPL2CAPPSM::VV>(
		device_data_sdp->buffer_res[0],
		device_data_sdp->bsc->HANDLE_SDP_FIELD_NAME,
		goepl2cappsm_handle,
		SDP::MAP::GoepL2capPsm,
		SDP::MAP::GoepL2capPsm,
		device_data_sdp,
		dd,
		0
	);

	FUNCTIONS::getAndParse_DEAFULT<PSUPPORTED_MESSAGE_TYPES, SUPPORTED_MESSAGE_TYPES::VV>(
		device_data_sdp->buffer_res[0],
		device_data_sdp->bsc->HANDLE_SDP_FIELD_NAME,
		supported_message_types_handle,
		SDP::MAP::SupportedMessageTypes,
		SDP::MAP::SupportedMessageTypes,
		device_data_sdp,
		dd,
		0
	);

	FUNCTIONS::getAndParse_DEAFULT<PMAS_INSTANCE_ID, MAS_INSTANCE_ID::VV>(
		device_data_sdp->buffer_res[0],
		device_data_sdp->bsc->HANDLE_SDP_FIELD_NAME,
		mas_instance_id_handle,
		SDP::MAP::MASInstanceID,
		SDP::MAP::MASInstanceID,
		device_data_sdp,
		dd,
		0
	);

	FUNCTIONS::getAndParse_DEAFULT<PMAP_SUPPORTED_FEATURES, MAP_SUPPORTED_FEATURES::VV>(
		device_data_sdp->buffer_res[0],
		device_data_sdp->bsc->HANDLE_SDP_FIELD_NAME,
		map_supported_features_handle,
		SDP::MAP::MapSupportedFeatures,
		SDP::MAP::MapSupportedFeatures,
		device_data_sdp,
		dd,
		0
	);
}

void SDP::MAP::MAP_class::print_ALL_ATTR(IOCTL_S::DEFAULT_DATA dd)
{
	printDefaultData(dd);

	if (goepl2cappsm_handle != NULL && 
		(dd.sdp_settings.print == 1 || dd.sdp_settings.print_service.print_MAP_attributes.print_goepl2cappsm == 1
	))
		goepl2cappsm_handle->print<GOEPL2CAPPSM_S::VV>(goepl2cappsm_handle->VALUE, dd);

	if (supported_message_types_handle != NULL && 
		(dd.sdp_settings.print == 1 || dd.sdp_settings.print_service.print_MAP_attributes.print_supported_message_types == 1
	))
		supported_message_types_handle->print<SUPPORTED_MESSAGE_TYPES_S::VV>(supported_message_types_handle->VALUE, dd);

	if (mas_instance_id_handle != NULL && 
		(dd.sdp_settings.print == 1 || dd.sdp_settings.print_service.print_MAP_attributes.print_mas_instance_id == 1
	))
		mas_instance_id_handle->print<MAS_INSTANCE_ID_S::VV>(mas_instance_id_handle->VALUE, dd);

	if (map_supported_features_handle != NULL && 
		(dd.sdp_settings.print == 1 || dd.sdp_settings.print_service.print_MAP_attributes.print_map_supported_features == 1
	))
		map_supported_features_handle->print<MAP_SUPPORTED_FEATURES_S::VV>(map_supported_features_handle->VALUE, dd);
}

SDP::MAP::PMAP_EXPORT SDP::MAP::MAP_class::export_ALL_ATTR(IOCTL_S::DEFAULT_DATA dd)
{
	exp = new MAP_EXPORT();

	exp->default_export = export_default_ATTR(dd);

	if(goepl2cappsm_handle != NULL)
		exp->goepl2cappsm_handle_export = goepl2cappsm_handle;

	if (supported_message_types_handle != NULL)
		exp->supported_message_types_handle = supported_message_types_handle;

	if (mas_instance_id_handle != NULL)
		exp->mas_instance_id_handle = mas_instance_id_handle;

	if (map_supported_features_handle != NULL)
		exp->map_supported_features_handle = map_supported_features_handle;

	return exp;
}




