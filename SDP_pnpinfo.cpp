#include "pch.h"



/*********************************************************************************************************************/
/* PNPINFO SPECIFIC */



SDP::PNPINFO::PNPINFO_class::PNPINFO_class()
{
	info_handle = new INFO();
}

void SDP::PNPINFO::PNPINFO_class::call_ALL_ATTR(ULONG recordHandle, HANDLE_SDP_TYPE aa, IOCTL_S::DEFAULT_DATA dd)
{
	BYTE bssr_response[5000]{ 0 };

	BOOL test = FALSE;

	for (SHORT bb = SpecificationID; bb < (VendorIDSource + 0x01); bb++)
	{
		printf("0x%04X\n", bb);

		test = SDP::FUNCTIONS::SDP_ATTRIBUTE_SEARCH::set_and_call_BTH_SDP_ATTRIBUTE_SEARCH(recordHandle, aa, bb, bb, bssr_response, 5000, dd);

		if (test)
		{
			printf("IOCTL_BTH_SDP_ATTRIBUTE_SEARCH --> OK\n");

			SDP::FUNCTIONS::printResponse(bssr_response);
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

SDP::PNPINFO::PINFO_EXPORT SDP::PNPINFO::PNPINFO_class::export_ALL_ATTR()
{
	exp = new INFO_EXPORT();

	exp->info_handle_export = info_handle;

	return exp;
}