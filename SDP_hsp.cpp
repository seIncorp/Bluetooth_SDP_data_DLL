#include "pch.h"


/*********************************************************************************************************************/
/* HSP SPECIFIC */

void SDP::HSP::parse_REMOTE_AUDIO_VOLUME_CONTROL_HSP(PREMOTE_AUDIO_VOLUME_CONTROL handle)
{
	// TODO: najdi primer za parsanje
}


/*********************************************************************************************************************/
/* CLASS HSP_all_attributes functions */


SDP::HSP::HSP_class::HSP_class(IOCTL_S::DEFAULT_DATA& dd)
{
	setDefaultObjects(dd);

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_HSP.RemoteAudioVolumeControl == 1)
		remote_audio_volume_control_handle = new REMOTE_AUDIO_VOLUME_CONTROL();
}

void SDP::HSP::HSP_class::call_RemoteAudioVolumeControl(DEVICE_DATA_SDP& device_data_sdp, IOCTL_S::DEFAULT_DATA& dd)
{
	FUNCTIONS::getAndParse_DEAFULT<PREMOTE_AUDIO_VOLUME_CONTROL, REMOTE_AUDIO_VOLUME_CONTROL::VV>(
		device_data_sdp.buffer_res[0],
		device_data_sdp.bsc->HANDLE_SDP_FIELD_NAME,
		remote_audio_volume_control_handle,
		RemoteAudioVolumeControl,
		RemoteAudioVolumeControl,
		device_data_sdp,
		dd,
		0
	);
}

void SDP::HSP::HSP_class::call_ALL_ATTR(DEVICE_DATA_SDP& device_data_sdp, IOCTL_S::DEFAULT_DATA& dd)
{
	callDefaultAttributes(device_data_sdp, dd);

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_HSP.RemoteAudioVolumeControl == 1)
		call_RemoteAudioVolumeControl(device_data_sdp, dd);
}

void SDP::HSP::HSP_class::print_ALL_ATTR(IOCTL_S::DEFAULT_DATA& dd)
{
	printDefaultData(dd);

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_HSP.RemoteAudioVolumeControl == 1)
		if (remote_audio_volume_control_handle != NULL && (dd.sdp_settings.print == 1 || dd.sdp_settings.print_service.print_HSP_attributes.print_remote_audio_volume_control == 1))
			remote_audio_volume_control_handle->print<REMOTE_AUDIO_VOLUME_CONTROL_S::VV>(remote_audio_volume_control_handle->VALUE, dd);
}

SDP::HSP::PHSP_EXPORT SDP::HSP::HSP_class::export_ALL_ATTR(IOCTL_S::DEFAULT_DATA& dd)
{
	exp = new HSP_EXPORT();

	exp->default_export = export_default_ATTR(dd);

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_HSP.RemoteAudioVolumeControl == 1)
		if (remote_audio_volume_control_handle != NULL)
			exp->remote_audio_volume_control_handle_export = remote_audio_volume_control_handle;

	return exp;
}