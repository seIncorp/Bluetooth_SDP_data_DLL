#include "pch.h"


/*********************************************************************************************************************/
/* HSP SPECIFIC */

void SDP::HSP::parse_REMOTE_AUDIO_VOLUME_CONTROL_HSP(PREMOTE_AUDIO_VOLUME_CONTROL handle)
{
	// TODO: najdi primer za parsanje
}


/*********************************************************************************************************************/
/* CLASS HSP_all_attributes functions */


SDP::HSP::HSP_class::HSP_class()
{
	setDefaultObjects();

	remote_audio_volume_control_handle = new REMOTE_AUDIO_VOLUME_CONTROL();
}

void SDP::HSP::HSP_class::call_ALL_ATTR(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd)
{
	callDefaultAttributes(device_data_sdp, dd);

	FUNCTIONS::getAndParse_DEAFULT<PREMOTE_AUDIO_VOLUME_CONTROL, REMOTE_AUDIO_VOLUME_CONTROL::VV>(
		device_data_sdp->buffer_res[0],
		device_data_sdp->bsc->HANDLE_SDP_FIELD_NAME,
		remote_audio_volume_control_handle,
		RemoteAudioVolumeControl,
		RemoteAudioVolumeControl,
		device_data_sdp,
		dd,
		0
		);
}

void SDP::HSP::HSP_class::print_ALL_ATTR(IOCTL_S::DEFAULT_DATA dd)
{
	printDefaultData(dd);

	remote_audio_volume_control_handle->print<REMOTE_AUDIO_VOLUME_CONTROL_S::VV>(remote_audio_volume_control_handle->VALUE,dd);
}

SDP::HSP::PHSP_EXPORT SDP::HSP::HSP_class::export_ALL_ATTR()
{
	exp = new HSP_EXPORT();

	exp->default_export = export_default_ATTR();

	if (remote_audio_volume_control_handle != NULL)
		exp->remote_audio_volume_control_handle_export = remote_audio_volume_control_handle;

	return exp;
}