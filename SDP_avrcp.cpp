#include "pch.h"




/*********************************************************************************************************************/
/* AVRCP SPECIFIC */

void SDP::AVRCP::parse_SUPPORTED_FEATURES_AVRCP(PSUPPORTED_FEATURES handle, SHORT current_used_service)
{
	SHORT temp = 0x00;

	temp |= handle->VALUE.value[0];
	temp <<= 8;
	temp |= handle->VALUE.value[1];

	handle->VALUE.supported_features_value = temp;

	if (current_used_service == SDP::A_V_RemoteControl ||
		current_used_service == SDP::A_V_RemoteControlController
		)
	{
		handle->VALUE.sfds = new SUPPORTED_FEATURES_DATA_S(&temp, 0);

		handle->VALUE.supp_features_string_value = handle->VALUE.sfds->getSupportedFeaturesString_AVRC_AVRCC();
	}

	if (current_used_service == SDP::A_V_RemoteControlTarget)
	{
		handle->VALUE.sfds = new SUPPORTED_FEATURES_DATA_S(&temp, 1);

		handle->VALUE.supp_features_string_value = handle->VALUE.sfds->getSupportedFeaturesString_AVRCT();
	}
}


/*********************************************************************************************************************/
/* CLASS AVRCP_all_attributes functions */


SDP::AVRCP::AVRCP_class::AVRCP_class(IOCTL_S::DEFAULT_DATA& dd)
{
	setDefaultObjects(dd);

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.ProviderName == 1)
		provider_name_handle = new PROVIDER_NAME();

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_AVRCP.SupportedFeatures == 1)
		supported_features_handle = new SUPPORTED_FEATURES();
}


void SDP::AVRCP::AVRCP_class::call_SupportedFeatures(DEVICE_DATA_SDP& device_data_sdp, IOCTL_S::DEFAULT_DATA& dd)
{
	FUNCTIONS::getAndParse_DEAFULT<PSUPPORTED_FEATURES, SUPPORTED_FEATURES::VV>(
		device_data_sdp.buffer_res[0],
		device_data_sdp.bsc->HANDLE_SDP_FIELD_NAME,
		supported_features_handle,
		SupportedFeatures,
		SupportedFeatures,
		device_data_sdp,
		dd,
		0
	);
}


void SDP::AVRCP::AVRCP_class::call_ALL_ATTR(DEVICE_DATA_SDP& device_data_sdp, IOCTL_S::DEFAULT_DATA& dd)
{
	callDefaultAttributes(device_data_sdp, dd);

	// this is used to show correct data from supported features (show data based on returned class and not searched class)
	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.ServiceClassIDList == 1)
	{
		
		// TODO: ????
		//device_data_sdp.current_used_service = class_id_handle->VALUE.classes[0].value;
		//dd.temp_class_id = device_data_sdp.current_used_service;
	}

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.ProviderName == 1)
		call_ProviderName(device_data_sdp, dd);

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_AVRCP.SupportedFeatures == 1)
		call_SupportedFeatures(device_data_sdp, dd);

	// TODO: preveri ali se to sploh rabi!!!
	dds = &device_data_sdp;
}

void SDP::AVRCP::AVRCP_class::print_ALL_ATTR(IOCTL_S::DEFAULT_DATA& dd)
{
	printDefaultData(dd);

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_AVRCP.SupportedFeatures == 1)
		if (supported_features_handle != NULL && (dd.sdp_settings.print == 1 || dd.sdp_settings.print_service.print_AVRCP_attributes.print_supported_features == 1))
			supported_features_handle->print<SUPPORTED_FEATURES::VV>(supported_features_handle->VALUE, dd);
	
}

SDP::AVRCP::PAVRCP_EXPORT SDP::AVRCP::AVRCP_class::export_ALL_ATTR(IOCTL_S::DEFAULT_DATA& dd)
{
	exp = new AVRCP_EXPORT();

	exp->default_export = export_default_ATTR(dd);

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_AVRCP.SupportedFeatures == 1)
		if (supported_features_handle != NULL)
			exp->supported_features_handle_export = supported_features_handle;

	return exp;
}

