#include "pch.h"



/*********************************************************************************************************************/
/* PNPINFO SPECIFIC */



SDP::PNPINFO::PNPINFO_class::PNPINFO_class()
{
	info_handle = new INFO();
}

void SDP::PNPINFO::PNPINFO_class::call_ALL_ATTR(ULONG recordHandle, HANDLE_SDP_TYPE aa, IOCTL_S::DEFAULT_DATA dd)
{
	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_PNPINFO.PnpInfo == 1)
	{
		BYTE bssr_response[5000]{ 0 };

		BOOL test = FALSE;

		for (SHORT bb = SpecificationID; bb < (VendorIDSource + 0x01); bb++)
		{
			if (dd.sdp_settings.debug == 1)
				printf("0x%04X\n", bb);

			test = SDP::FUNCTIONS::SDP_ATTRIBUTE_SEARCH::set_and_call_BTH_SDP_ATTRIBUTE_SEARCH(recordHandle, aa, bb, bb, bssr_response, 5000, dd);

			if (test)
			{
				if (dd.sdp_settings.debug == 1)
				{
					printf("IOCTL_BTH_SDP_ATTRIBUTE_SEARCH --> OK\n");
					SDP::FUNCTIONS::printResponse(bssr_response);
				}

				int position = SDP::FUNCTIONS::set_save_ATTRIBUTE_ELEMENT<SDP::PNPINFO::INFO*, BYTE[]>(info_handle, bssr_response, 5000);

				position = SDP::FUNCTIONS::set_save_VALUE_ELEMENT<SDP::PNPINFO::INFO*, BYTE[]>(info_handle, bssr_response, 5000, position);

				if (bb == PrimaryRecord)
				{
					info_handle->setIDdata<BOOL>(bb, info_handle->VALUE.value[0]);
				}
				else
				{
					SHORT temp = 0x00;
					temp |= info_handle->VALUE.value[0];
					temp <<= 8;
					temp |= info_handle->VALUE.value[1];
					info_handle->setIDdata<SHORT>(bb, temp);
				}
			}
		}
	}
}

void SDP::PNPINFO::PNPINFO_class::print_ALL_ATTR(IOCTL_S::DEFAULT_DATA dd)
{
	if (info_handle != NULL && (dd.sdp_settings.print == 1 || dd.sdp_settings.print_service.print_PNPINFO_attributes.print_pnp_info == 1))
		info_handle->print<INFO_S::VV>(info_handle->VALUE, dd);
}

SDP::PNPINFO::PINFO_EXPORT SDP::PNPINFO::PNPINFO_class::export_ALL_ATTR()
{
	exp = new INFO_EXPORT();

	exp->info_handle_export = info_handle;

	return exp;
}