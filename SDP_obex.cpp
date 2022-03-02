#include "pch.h"


/*********************************************************************************************************************/
/* OBEX SPECIFIC */

// FOR	 GoepL2CapPsm YOU CAN USE FROM MAP

std::string SDP::OBEX::getSupportedFormatsString(BYTE data_arr[], int size)
{
	std::string temp = "";

	for (int aa = 0; aa < size; aa++)
		switch (data_arr[aa])
		{
		case 0x01:
			temp += "vCard 2.1\n";
			break;

		case 0x02:
			temp += "vCard 3.0\n";
			break;

		case 0x03:
			temp += "vCal 1.0\n";
			break;

		case 0x04:
			temp += "iCal 2.0\n";
			break;

		case 0x05:
			temp += "vNote\n";
			break;

		case 0x06:
			temp += "vMessage\n";
			break;

		case 0xff:
			temp += "any type of object\n";
			break;
		};

	return temp;
}


void SDP::OBEX::parse_SERVICE_VERSION_OBEX(PSERVICE_VERSION handle)
{
	// TODO: najdi neki primer zaradi parsanja
}

void SDP::OBEX::parse_SUPPORTED_FORMATS_LIST_OBEX(PSUPPORTED_FORMATS handle)
{
	handle->VALUE.num_of_formats = handle->VALUE.size_bytes / 2;

	handle->VALUE.formats = new BYTE[handle->VALUE.num_of_formats]();

	for (int aa = 1, bb = 0; aa < handle->VALUE.size_bytes; aa += 2, bb++)
	{
		handle->VALUE.formats[bb] = handle->VALUE.value[aa];
	}
}


/*********************************************************************************************************************/
/* CLASS NAP_PANU_all_attributes functions */


SDP::OBEX::OBEX_class::OBEX_class()
{
	// set all objects
	setDefaultObjects();

	goepl2cappsm_handle = new SDP::MAP::GOEPL2CAPPSM();
	supported_formats_handle = new SUPPORTED_FORMATS();
	service_version_handle = new SERVICE_VERSION();
}

void SDP::OBEX::OBEX_class::call_ALL_ATTR(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd)
{
	callDefaultAttributes(device_data_sdp, dd);

	FUNCTIONS::getAndParse_DEAFULT<SDP::MAP::PGOEPL2CAPPSM, SDP::MAP::GOEPL2CAPPSM::VV>(
		device_data_sdp->buffer_res[0],
		device_data_sdp->bsc->HANDLE_SDP_FIELD_NAME,
		goepl2cappsm_handle,
		GoepL2capPsm,
		GoepL2capPsm,
		device_data_sdp,
		dd,
		0
	);

	FUNCTIONS::getAndParse_DEAFULT<PSUPPORTED_FORMATS, SUPPORTED_FORMATS::VV>(
		device_data_sdp->buffer_res[0],
		device_data_sdp->bsc->HANDLE_SDP_FIELD_NAME,
		supported_formats_handle,
		SupportedFormatsList,
		SupportedFormatsList,
		device_data_sdp,
		dd,
		0
	);

	FUNCTIONS::getAndParse_DEAFULT<PSERVICE_VERSION, SERVICE_VERSION::VV>(
		device_data_sdp->buffer_res[0],
		device_data_sdp->bsc->HANDLE_SDP_FIELD_NAME,
		service_version_handle,
		ServiceVersion,
		ServiceVersion,
		device_data_sdp,
		dd,
		0
		);
}

void SDP::OBEX::OBEX_class::print_ALL_ATTR(IOCTL_S::DEFAULT_DATA dd)
{
	printDefaultData(dd);
	if (dd.sdp_settings.print == 1)
	{
		goepl2cappsm_handle->print<SDP::MAP::GOEPL2CAPPSM_S::VV>(goepl2cappsm_handle->VALUE, dd);
		supported_formats_handle->print<SUPPORTED_FORMATS_S::VV>(supported_formats_handle->VALUE, dd);
		service_version_handle->print<SERVICE_VERSION_S::VV>(service_version_handle->VALUE, dd);
	}
}

SDP::OBEX::POBEX_EXPORT SDP::OBEX::OBEX_class::export_ALL_ATTR()
{
	exp = new OBEX_EXPORT();

	exp->default_export = export_default_ATTR();

	if (goepl2cappsm_handle != NULL)
		exp->goepl2cappsm_handle_export = goepl2cappsm_handle;

	if (service_version_handle != NULL)
		exp->service_version_handle_export = service_version_handle;

	if (supported_formats_handle != NULL)
		exp->supported_formats_handle_export = supported_formats_handle;

	return exp;
}


