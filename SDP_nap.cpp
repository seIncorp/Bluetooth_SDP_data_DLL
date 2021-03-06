#include "pch.h"




/*********************************************************************************************************************/
/* NAP and PANU SPECIFIC */

std::string SDP::NAP::getSecurityDescriptionString(SHORT type)
{
	std::string temp;

	switch (type)
	{
		case 0x0000:
			temp = "None";
		break;

		case 0x0001:
			temp = "Service - level enforced Security";
		break;

		case 0x0002:
			temp = "802.1x Security";
		break;
	}

	return temp;
}

std::string SDP::NAP::getNetAccessTypeString(SHORT type)
{
	std::string temp;

	switch (type)
	{
		case 0x0000:
			temp = "PSTN";
		break;

		case 0x0001:
			temp = "ISDN";
		break;

		case 0x0002:
			temp = "DSL";
		break;

		case 0x0003:
			temp = "Cable Modem";
		break;

		case 0x0004:
			temp = "10Mb Ethernet";
		break;

		case 0x0005:
			temp = "100Mb Ethernet";
		break;

		case 0x0006:
			temp = "4 Mb Token Ring";
		break;

		case 0x0007:
			temp = "16 Mb Token Ring";
		break;

		case 0x0008:
			temp = "100 Mb Token Ring";
		break;

		case 0x0009:
			temp = "FDDI";
		break;

		case 0x000A:
			temp = "GSM";
		break;

		case 0x000B:
			temp = "CDMA";
		break;

		case 0x000C:
			temp = "GPRS";
		break;

		case 0x000D:
			temp = "3G Cellular";
		break;

		case 0xFFFE:
			temp = "other";
		break;
	}

	return temp;
}


void SDP::NAP::parse_SECURITY_DESCRIPTION_PAN(PSECURITY_DESCRIPTION handle)
{
	handle->VALUE.security_value |= handle->VALUE.value[0];
	handle->VALUE.security_value <<= 8;
	handle->VALUE.security_value |= handle->VALUE.value[1];

	handle->VALUE.security_string_value = getSecurityDescriptionString(handle->VALUE.security_value);
}

void SDP::NAP::parse_NET_ACCESS_TYPE_PAN(PNET_ACCESS_TYPE handle)
{
	handle->VALUE.NetAccessType |= handle->VALUE.value[0];
	handle->VALUE.NetAccessType <<= 8;
	handle->VALUE.NetAccessType |= handle->VALUE.value[1];

	handle->VALUE.NetAccessType_value = getNetAccessTypeString(handle->VALUE.NetAccessType);
}

void SDP::NAP::parse_MAX_NET_ACCESS_RATE_PAN(PMAX_NET_ACCESS_RATE handle)
{
	handle->VALUE.Maximum_possible_Network_Access_Data_Rate |= handle->VALUE.value[0];
	handle->VALUE.Maximum_possible_Network_Access_Data_Rate <<= 8;
	handle->VALUE.Maximum_possible_Network_Access_Data_Rate |= handle->VALUE.value[1];
	handle->VALUE.Maximum_possible_Network_Access_Data_Rate <<= 8;
	handle->VALUE.Maximum_possible_Network_Access_Data_Rate |= handle->VALUE.value[2];
	handle->VALUE.Maximum_possible_Network_Access_Data_Rate <<= 8;
	handle->VALUE.Maximum_possible_Network_Access_Data_Rate |= handle->VALUE.value[3];
}



/*********************************************************************************************************************/
/* CLASS NAP_PANU_all_attributes functions */



SDP::NAP::NAP_PANU_class::NAP_PANU_class(IOCTL_S::DEFAULT_DATA& dd, int nap)
{
	// set all objects
	setDefaultObjects(dd);

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.LanguageBaseAttributeIdList == 1)
		language_base_attribute_id_list_handle = new LANGUAGE_BASE_ATTRIBUTE_ID_LIST();

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.ServiceDescription == 1)
		service_description_handle = new SERVICE_DESCRIPTION();

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_NAP.SecurityDescription == 1)
		security_description_handle = new SECURITY_DESCRIPTION();
	
	if (nap == 1)
	{
		nap_flag = 1;

		if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_NAP.NetAccessType == 1)
			net_access_type_handle = new NET_ACCESS_TYPE();

		if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_NAP.MaxNetAccessRate == 1)
			max_net_access_rate_handle = new MAX_NET_ACCESS_RATE();
	}
	else
	{
		nap_flag = 0;
	}
}


void SDP::NAP::NAP_PANU_class::call_ALL_ATTR(DEVICE_DATA_SDP& device_data_sdp, IOCTL_S::DEFAULT_DATA& dd)
{
	callDefaultAttributes(device_data_sdp, dd);

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.LanguageBaseAttributeIdList == 1)
		call_LanguageBaseAttributeIDList(device_data_sdp, dd);

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.ServiceDescription == 1)
		call_ServiceDescription(device_data_sdp, dd);

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_NAP.SecurityDescription == 1)
	{
		call_attr_def<PSECURITY_DESCRIPTION, SECURITY_DESCRIPTION::VV>(device_data_sdp, dd, security_description_handle, SecurityDescription);
	}
	
	if (nap_flag == 1)
	{
		if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_NAP.NetAccessType == 1)
		{
			call_attr_def<PNET_ACCESS_TYPE, NET_ACCESS_TYPE::VV>(device_data_sdp, dd, net_access_type_handle, NetAccessType);
		}

		if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_NAP.MaxNetAccessRate == 1)
		{
			call_attr_def<PMAX_NET_ACCESS_RATE, MAX_NET_ACCESS_RATE::VV>(device_data_sdp, dd, max_net_access_rate_handle, MaxNetAccessrate);
		}
	}
}

void SDP::NAP::NAP_PANU_class::print_ALL_ATTR(IOCTL_S::DEFAULT_DATA& dd)
{
	
	printDefaultData(dd);
	
	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_NAP.SecurityDescription == 1)
		if (security_description_handle != NULL && (dd.sdp_settings.print == 1 || dd.sdp_settings.print_service.print_NAP_attributes.print_security_description == 1))
			security_description_handle->print<SECURITY_DESCRIPTION_S::VV>(security_description_handle->VALUE, dd);

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_NAP.NetAccessType == 1)
		if (net_access_type_handle != NULL && (dd.sdp_settings.print == 1 || dd.sdp_settings.print_service.print_NAP_attributes.print_net_access_type == 1) && 	nap_flag == 1)
			net_access_type_handle->print<NET_ACCESS_TYPE_S::VV>(net_access_type_handle->VALUE, dd);

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_NAP.MaxNetAccessRate == 1)
		if (max_net_access_rate_handle != NULL && (dd.sdp_settings.print == 1 || dd.sdp_settings.print_service.print_NAP_attributes.print_max_net_access_rate == 1) && nap_flag == 1)
			max_net_access_rate_handle->print<MAX_NET_ACCESS_RATE_S::VV>(max_net_access_rate_handle->VALUE, dd);
}



SDP::NAP::PNAP_EXPORT SDP::NAP::NAP_PANU_class::export_ALL_ATTR(IOCTL_S::DEFAULT_DATA& dd)
{
	exp = new NAP_EXPORT();

	exp->default_export = export_default_ATTR(dd);

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_NAP.SecurityDescription == 1)
		if (security_description_handle != NULL)
			exp->security_description_handle_export = security_description_handle;

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_NAP.NetAccessType == 1)
		if (net_access_type_handle != NULL)
			exp->net_access_type_handle_export = net_access_type_handle;

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_NAP.MaxNetAccessRate == 1)
		if (max_net_access_rate_handle != NULL)
			exp->max_net_access_rate_handle_export = max_net_access_rate_handle;

	return exp;
}






