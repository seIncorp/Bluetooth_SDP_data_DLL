#include "pch.h"



/*********************************************************************************************************************/
/* A2DP SPECIFIC */

void SDP::A2DP::parse_SUPPORTED_FEATURES_A2DP(PSUPPORTED_FEATURES handle)
{
	SHORT temp = 0x00;
	temp |= handle->VALUE.value[0];
	temp <<= 8;
	temp |= handle->VALUE.value[1];

	handle->VALUE.supported_features_value = temp;

	handle->VALUE.sfds = new SUPPORTED_FEATURES_DATA_S(&handle->VALUE.supported_features_value);

}


/*********************************************************************************************************************/
/* CLASS A2DP_all_attributes functions */


SDP::A2DP::A2DP_class::A2DP_class(IOCTL_S::DEFAULT_DATA dd)
{
	setDefaultObjects(dd);

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.ProviderName == 1)
		provider_name_handle = new PROVIDER_NAME();

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_A2DP.SupportedFeatures == 1)
		supported_features_handle = new SUPPORTED_FEATURES();
}

void SDP::A2DP::A2DP_class::call_SupportedFeatures(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd)
{
	FUNCTIONS::getAndParse_DEAFULT<PSUPPORTED_FEATURES, SUPPORTED_FEATURES::VV>(
		device_data_sdp->buffer_res[0],
		device_data_sdp->bsc->HANDLE_SDP_FIELD_NAME,
		supported_features_handle,
		SupportedFeatures,
		SupportedFeatures,
		device_data_sdp,
		dd,
		0
	);
}


void SDP::A2DP::A2DP_class::call_ALL_ATTR(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd)
{
	callDefaultAttributes(device_data_sdp, dd);

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.ProviderName == 1)
		call_ProviderName(device_data_sdp, dd);

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_A2DP.SupportedFeatures == 1)
		call_SupportedFeatures(device_data_sdp, dd);
}

void SDP::A2DP::A2DP_class::print_ALL_ATTR(IOCTL_S::DEFAULT_DATA dd)
{
	printDefaultData(dd);

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_A2DP.SupportedFeatures == 1)
		if (supported_features_handle  != NULL && (dd.sdp_settings.print == 1 || dd.sdp_settings.print_service.print_A2DP_attributes.print_supported_features == 1))
			supported_features_handle->print<SUPPORTED_FEATURES_S::VV>(supported_features_handle->VALUE, dd);
}

SDP::A2DP::PA2DP_EXPORT SDP::A2DP::A2DP_class::export_ALL_ATTR(IOCTL_S::DEFAULT_DATA dd)
{
	exp = new A2DP_EXPORT();

	exp->default_export = export_default_ATTR(dd);

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_A2DP.SupportedFeatures == 1)
		if (supported_features_handle != NULL)
			exp->supported_features_handle_export = supported_features_handle;

	return exp;
}


