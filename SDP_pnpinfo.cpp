#include "pch.h"

//#include <iostream>
//#include <fstream>
//#include <sstream>


/*********************************************************************************************************************/
/* PNPINFO SPECIFIC */



SDP::PNPINFO::PNPINFO_class::PNPINFO_class()
{
	info_handle = new INFO();
}

void SDP::PNPINFO::PNPINFO_class::call_ATTR(SHORT attr, ULONG recordHandle, HANDLE_SDP_TYPE aa, IOCTL_S::DEFAULT_DATA& dd)
{
	BYTE bssr_response[5000]{ 0 };

	BOOL test = FALSE;

	if (dd.sdp_settings.debug == 1)
		printf("0x%04X\n", attr);

	test = SDP::FUNCTIONS::SDP_ATTRIBUTE_SEARCH::set_and_call_BTH_SDP_ATTRIBUTE_SEARCH(recordHandle, aa, attr, attr, bssr_response, 5000, dd);

	if (test)
	{
		if (dd.sdp_settings.debug == 1)
		{
			printf("IOCTL_BTH_SDP_ATTRIBUTE_SEARCH --> OK\n");
			SDP::FUNCTIONS::printResponse(bssr_response);
		}

		int position = SDP::FUNCTIONS::set_save_ATTRIBUTE_ELEMENT<SDP::PNPINFO::INFO*, BYTE[]>(info_handle, bssr_response, 5000);

		position = SDP::FUNCTIONS::set_save_VALUE_ELEMENT<SDP::PNPINFO::INFO*, BYTE[]>(info_handle, bssr_response, 5000, position);
	}
}

void SDP::PNPINFO::PNPINFO_class::call_ALL_ATTR(ULONG recordHandle, HANDLE_SDP_TYPE aa, IOCTL_S::DEFAULT_DATA& dd)
{
	if (dd.attr_search_for_service.all == 1 ||
		dd.attr_search_for_service.att_PNPINFO.PnpInfo == 1 ||
		dd.attr_search_for_service.att_PNPINFO.SpecificationID == 1
		)
	{
		call_ATTR(SpecificationID, recordHandle, aa, dd);

		SHORT temp = 0x00;
		temp |= info_handle->VALUE.value[0];
		temp <<= 8;
		temp |= info_handle->VALUE.value[1];
		info_handle->setIDdata<SHORT>(SpecificationID, temp, dd);
	}

	if (dd.attr_search_for_service.all == 1 ||
		dd.attr_search_for_service.att_PNPINFO.PnpInfo == 1 ||
		dd.attr_search_for_service.att_PNPINFO.VendorID == 1
		)
	{
		call_ATTR(VendorID, recordHandle, aa, dd);

		// TODO: preveri iz CVS katero podjetje je to in shrani v struct

		SHORT temp = 0x00;
		temp |= info_handle->VALUE.value[0];
		temp <<= 8;
		temp |= info_handle->VALUE.value[1];
		info_handle->setIDdata<SHORT>(VendorID, temp, dd);

		
		


	}

	if (dd.attr_search_for_service.all == 1 ||
		dd.attr_search_for_service.att_PNPINFO.PnpInfo == 1 ||
		dd.attr_search_for_service.att_PNPINFO.ProductID == 1
		)
	{
		call_ATTR(ProductID, recordHandle, aa, dd);

		SHORT temp = 0x00;
		temp |= info_handle->VALUE.value[0];
		temp <<= 8;
		temp |= info_handle->VALUE.value[1];
		info_handle->setIDdata<SHORT>(ProductID, temp, dd);



	}

	if (dd.attr_search_for_service.all == 1 ||
		dd.attr_search_for_service.att_PNPINFO.PnpInfo == 1 ||
		dd.attr_search_for_service.att_PNPINFO.Version == 1
		)
	{
		call_ATTR(Version, recordHandle, aa, dd);

		SHORT temp = 0x00;
		temp |= info_handle->VALUE.value[0];
		temp <<= 8;
		temp |= info_handle->VALUE.value[1];
		info_handle->setIDdata<SHORT>(Version, temp, dd);
	}

	if (dd.attr_search_for_service.all == 1 ||
		dd.attr_search_for_service.att_PNPINFO.PnpInfo == 1 ||
		dd.attr_search_for_service.att_PNPINFO.PrimaryRecord == 1
		)
	{
		call_ATTR(PrimaryRecord, recordHandle, aa, dd);

		info_handle->setIDdata<BOOL>(PrimaryRecord, info_handle->VALUE.value[0], dd);
	}

	if (dd.attr_search_for_service.all == 1 ||
		dd.attr_search_for_service.att_PNPINFO.PnpInfo == 1 ||
		dd.attr_search_for_service.att_PNPINFO.VendorIDSource == 1
		)
	{
		call_ATTR(VendorIDSource, recordHandle, aa, dd);

		SHORT temp = 0x00;
		temp |= info_handle->VALUE.value[0];
		temp <<= 8;
		temp |= info_handle->VALUE.value[1];
		info_handle->setIDdata<SHORT>(VendorIDSource, temp, dd);
	}

	if (dd.attr_search_for_service.all == 1 ||
		dd.attr_search_for_service.att_PNPINFO.PnpInfo == 1 ||
		dd.attr_search_for_service.att_PNPINFO.ClientExecutableURL == 1
		)
	{
		call_ATTR(ClientExecutableURL, recordHandle, aa, dd);

		// TODO: dodaj se za parsanje in shranjevanje (dobi en example)
	}

	if (dd.attr_search_for_service.all == 1 ||
		dd.attr_search_for_service.att_PNPINFO.PnpInfo == 1 ||
		dd.attr_search_for_service.att_PNPINFO.DocumentationURL == 1
		)
	{
		call_ATTR(DocumentationURL, recordHandle, aa, dd);

		// TODO: dodaj se za parsanje in shranjevanje (dobi en example)
	}
	
}

void SDP::PNPINFO::PNPINFO_class::print_ALL_ATTR(IOCTL_S::DEFAULT_DATA& dd)
{
	if (info_handle != NULL)
		info_handle->print<INFO_S::VV>(info_handle->VALUE, dd);
}

SDP::PNPINFO::PINFO_EXPORT SDP::PNPINFO::PNPINFO_class::export_ALL_ATTR()
{
	exp = new INFO_EXPORT();

	exp->info_handle_export = info_handle;

	return exp;
}