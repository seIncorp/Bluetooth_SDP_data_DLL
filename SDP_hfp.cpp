#include "pch.h"


/*********************************************************************************************************************/
/* HFP SPECIFIC */


void SDP::HFP::parse_NETWORK_HFP(PNETWORK handle)
{

}

void SDP::HFP::parse_SUPPORTED_FEATURES_HFP(PSUPPORTED_FEATURES handle)
{
	SHORT temp = 0x00;

	temp |= handle->VALUE.value[0];
	temp <<= 8;
	temp |= handle->VALUE.value[1];

	handle->VALUE.supported_features_value = temp;
	handle->VALUE.sfds = new SDP::HFP::SUPPORTED_FEATURES_DATA_S(temp);
}



/*********************************************************************************************************************/
/* CLASS HFP_all_attributes functions */

SDP::HFP::HFP_class::HFP_class()
{
	setDefaultObjects();

	network_handle = new NETWORK();
	supported_features_handle = new SUPPORTED_FEATURES();
}

void SDP::HFP::HFP_class::call_Network(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd)
{
	FUNCTIONS::getAndParse_DEAFULT<PNETWORK, NETWORK::VV>(
		device_data_sdp->buffer_res[0],
		device_data_sdp->bsc->HANDLE_SDP_FIELD_NAME,
		network_handle,
		Network,
		Network,
		device_data_sdp,
		dd,
		0
	);
}

void SDP::HFP::HFP_class::call_SupportedFeatures(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd)
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

void SDP::HFP::HFP_class::call_ALL_ATTR(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd)
{
	callDefaultAttributes(device_data_sdp, dd);

	call_Network(device_data_sdp, dd);
	call_SupportedFeatures(device_data_sdp, dd);
}

void SDP::HFP::HFP_class::print_ALL_ATTR(IOCTL_S::DEFAULT_DATA dd)
{
	printDefaultData(dd);
	if (dd.sdp_settings.print == 1)
	{
		network_handle->print<NETWORK::VV>(network_handle->VALUE, dd);
		supported_features_handle->print<SUPPORTED_FEATURES::VV>(supported_features_handle->VALUE, dd);
	}
}

SDP::HFP::PHFP_EXPORT SDP::HFP::HFP_class::export_ALL_ATTR()
{
	exp = new HFP_EXPORT();

	exp->default_export = export_default_ATTR();

	if (network_handle != NULL)
		exp->network_handle_export = network_handle;

	if (supported_features_handle != NULL)
		exp->supported_features_handle_export = supported_features_handle;

	return exp;
}
