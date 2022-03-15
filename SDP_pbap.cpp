#include "pch.h"


/*********************************************************************************************************************/
/* PBAP SPECIFIC */

// FOR	 GoepL2CapPsm YOU CAN USE FROM MAP



void SDP::PBAP::parse_SUPPORTED_REPOSITORIES_PBAP(PSUPPORTED_REPOSITORIES handle)
{
	handle->VALUE.srs = new SUPPORTED_REPOSITORIES_DATA_S(handle->VALUE.value);
}

void SDP::PBAP::parse_PBAP_SUPPORTED_FEATURES_PBAP(PPBAP_SUPPORTED_FEATURES handle)
{
	// TODO: prevedi values kaj pomeni
	// TODO: poisci device ki ima verzijo 1.2 ali vec
}



/*********************************************************************************************************************/
/* CLASS PBAP_all_attributes functions */


SDP::PBAP::PBAP_class::PBAP_class()
{
	// set all objects
	setDefaultObjects();

	goepl2cappsm_handle = new SDP::MAP::GOEPL2CAPPSM();
	supported_repositories_handle = new SUPPORTED_REPOSITORIES();
	pbap_supported_features_handle = new PBAP_SUPPORTED_FEATURES();
}

void SDP::PBAP::PBAP_class::call_ALL_ATTR(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd)
{
	callDefaultAttributes(device_data_sdp, dd);

	FUNCTIONS::getAndParse_DEAFULT<SDP::MAP::PGOEPL2CAPPSM, SDP::MAP::GOEPL2CAPPSM::VV>(
		device_data_sdp->buffer_res[0],
		device_data_sdp->bsc->HANDLE_SDP_FIELD_NAME,
		goepl2cappsm_handle,
		SDP::MAP::GoepL2capPsm,
		SDP::MAP::GoepL2capPsm,
		device_data_sdp,
		dd,
		0
	);

	FUNCTIONS::getAndParse_DEAFULT<PSUPPORTED_REPOSITORIES, SUPPORTED_REPOSITORIES::VV>(
		device_data_sdp->buffer_res[0],
		device_data_sdp->bsc->HANDLE_SDP_FIELD_NAME,
		supported_repositories_handle,
		SupportedRepositories,
		SupportedRepositories,
		device_data_sdp,
		dd,
		0
	);

	FUNCTIONS::getAndParse_DEAFULT<PPBAP_SUPPORTED_FEATURES, PBAP_SUPPORTED_FEATURES::VV>(
		device_data_sdp->buffer_res[0],
		device_data_sdp->bsc->HANDLE_SDP_FIELD_NAME,
		pbap_supported_features_handle,
		PbapSupportedFeatures,
		PbapSupportedFeatures,
		device_data_sdp,
		dd,
		0
	);
}

void SDP::PBAP::PBAP_class::print_ALL_ATTR(IOCTL_S::DEFAULT_DATA dd)
{
	printDefaultData(dd);

	if (goepl2cappsm_handle != NULL &&
		(dd.sdp_settings.print == 1 || dd.sdp_settings.print_service.print_PBAP_attributes.print_goepl2cappsm == 1
	))
		goepl2cappsm_handle->print<SDP::MAP::GOEPL2CAPPSM_S::VV>(goepl2cappsm_handle->VALUE, dd);
	
	if (supported_repositories_handle != NULL && 
		(dd.sdp_settings.print == 1 || dd.sdp_settings.print_service.print_PBAP_attributes.print_supported_repositories == 1
	))
		supported_repositories_handle->print<SUPPORTED_REPOSITORIES::VV>(supported_repositories_handle->VALUE, dd);
	
	if (pbap_supported_features_handle != NULL && 
		(dd.sdp_settings.print == 1 || dd.sdp_settings.print_service.print_PBAP_attributes.print_pbap_supported_features == 1
	))
		pbap_supported_features_handle->print<PBAP_SUPPORTED_FEATURES::VV>(pbap_supported_features_handle->VALUE, dd);
	
}

SDP::PBAP::PPBAP_EXPORT SDP::PBAP::PBAP_class::export_ALL_ATTR()
{
	exp = new PBAP_EXPORT();

	exp->default_export = export_default_ATTR();

	if (goepl2cappsm_handle != NULL)
		exp->goepl2cappsm_handle_export = goepl2cappsm_handle;

	if (supported_repositories_handle != NULL)
		exp->supported_repositories_handle_export = supported_repositories_handle;

	if (pbap_supported_features_handle != NULL)
		exp->pbap_supported_features_handle_export = pbap_supported_features_handle;

	return exp;
}