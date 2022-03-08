#include "pch.h"




/*********************************************************************************************************************/
/* AVRCP SPECIFIC */

void SDP::AVRCP::parse_SUPPORTED_FEATURES_AVRCP(PSUPPORTED_FEATURES handle, SHORT current_used_service)
{
	// TODO: popravi bug, ker se ne pravilno parsa
	
	SHORT temp = 0x00;

	temp |= handle->VALUE.value[0];
	temp <<= 8;
	temp |= handle->VALUE.value[1];


	handle->VALUE.supported_features_value = temp;

	// TODO: preveri ce se pravilno shrani oz. na pravo mesto
	 
	if (current_used_service == SDP::A_V_RemoteControl ||
		current_used_service == SDP::A_V_RemoteControlController
		)
	{
		handle->VALUE.sfds = new SUPPORTED_FEATURES_DATA_S(&temp, 0);
	}

	if (current_used_service == SDP::A_V_RemoteControlTarget)
		handle->VALUE.sfds = new SUPPORTED_FEATURES_DATA_S(&temp,1);
}


/*********************************************************************************************************************/
/* CLASS AVRCP_all_attributes functions */


SDP::AVRCP::AVRCP_class::AVRCP_class()
{
	setDefaultObjects();

	provider_name_handle = new PROVIDER_NAME();
	supported_features_handle = new SUPPORTED_FEATURES();
}

void SDP::AVRCP::AVRCP_class::call_ALL_ATTR(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd)
{
	callDefaultAttributes(device_data_sdp, dd);

	FUNCTIONS::getAndParse_DEAFULT<PPROVIDER_NAME, PROVIDER_NAME::VV>(
		device_data_sdp->buffer_res[0],
		device_data_sdp->bsc->HANDLE_SDP_FIELD_NAME,
		provider_name_handle,
		SDP::ProviderName,
		SDP::ProviderName,
		device_data_sdp,
		dd,
		0
	);

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

	dds = device_data_sdp;
}

void SDP::AVRCP::AVRCP_class::print_ALL_ATTR(IOCTL_S::DEFAULT_DATA dd)
{
	printDefaultData(dd);
	if (dd.sdp_settings.print == 1)
	{
		supported_features_handle->print<SUPPORTED_FEATURES::VV>(supported_features_handle->VALUE, dd);
	}
}

SDP::AVRCP::PAVRCP_EXPORT SDP::AVRCP::AVRCP_class::export_ALL_ATTR()
{
	exp = new AVRCP_EXPORT();

	exp->default_export = export_default_ATTR();

	if (supported_features_handle != NULL)
		exp->supported_features_handle_export = supported_features_handle;

	return exp;
}

