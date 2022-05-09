#include "pch.h"

/* only those attributes are used on all services */
void SDP::DEFAULT_class::setDefaultObjects(IOCTL_S::DEFAULT_DATA& dd)
{
	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.ServiceRecord == 1)
		record_handle = new SERVICE_RECORD();

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.ServiceClassIDList == 1)
		class_id_handle = new SERVICE_CLASS_ID_LIST();

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.ProtocolDescriptorList == 1)
		protocol_descriptor_list_handle = new PROTOCOL_DESCRIPTOR_LIST();

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.ServiceName == 1)
		service_name_handle = new SERVICE_NAME();

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.BluetoothProfileDescriptorList == 1)
		bluetooth_profile_descriptor_list_handle = new BLUETOOTH_PROFILE_DESCRIPTOR_LIST();
}


// those functions will call default, for simplicity of use, because only few services use this
void SDP::DEFAULT_class::call_ProviderName(DEVICE_DATA_SDP& device_data_sdp, IOCTL_S::DEFAULT_DATA& dd)
{
	call_DEAFULT_default_attr<PPROVIDER_NAME, PROVIDER_NAME::VV>(device_data_sdp, dd, provider_name_handle, SDP::ProviderName);
}

void SDP::DEFAULT_class::call_LanguageBaseAttributeIDList(DEVICE_DATA_SDP& device_data_sdp, IOCTL_S::DEFAULT_DATA& dd)
{
	call_DEAFULT_default_attr<PLANGUAGE_BASE_ATTRIBUTE_ID_LIST, LANGUAGE_BASE_ATTRIBUTE_ID_LIST::VV>(device_data_sdp, dd, language_base_attribute_id_list_handle, SDP::LanguageBaseAttributeIDList);
}

void SDP::DEFAULT_class::call_ServiceDescription(DEVICE_DATA_SDP& device_data_sdp, IOCTL_S::DEFAULT_DATA& dd)
{
	call_DEAFULT_default_attr<PSERVICE_DESCRIPTION, SERVICE_DESCRIPTION::VV>(device_data_sdp, dd, service_description_handle, SDP::ServiceDescription);
}







void SDP::DEFAULT_class::callDefaultAttributes(DEVICE_DATA_SDP& device_data_sdp, IOCTL_S::DEFAULT_DATA& dd)
{
	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.ServiceRecord == 1)
	{
		call_DEAFULT_default_attr<PSERVICE_RECORD, SERVICE_RECORD_S::VV>(device_data_sdp, dd, record_handle, SDP::ServiceRecordHandle);
	}
	
	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.ServiceClassIDList == 1)
	{
		call_DEAFULT_default_attr<PSERVICE_CLASS_ID_LIST, SERVICE_CLASS_ID_LIST_S::VV>(device_data_sdp, dd, class_id_handle, SDP::ServiceClassIDList);
	}
	
	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.ProtocolDescriptorList == 1)
	{
		call_DEAFULT_default_attr<PPROTOCOL_DESCRIPTOR_LIST, PROTOCOL_DESCRIPTOR_LIST_S::VV>(device_data_sdp, dd, protocol_descriptor_list_handle, SDP::ProtocolDescriptorList);
	}
	
	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.ServiceName == 1)
	{
		call_DEAFULT_default_attr<PSERVICE_NAME, SERVICE_NAME::VV>(device_data_sdp, dd, service_name_handle, SDP::ATTRIBUTE_ID::ServiceName);
	}
	
	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.BluetoothProfileDescriptorList == 1)
	{
		call_DEAFULT_default_attr<PBLUETOOTH_PROFILE_DESCRIPTOR_LIST, BLUETOOTH_PROFILE_DESCRIPTOR_LIST::VV>(device_data_sdp, dd, bluetooth_profile_descriptor_list_handle, SDP::BluetoothProfileDescriptorList);
	}
}

void SDP::DEFAULT_class::printDefaultData(IOCTL_S::DEFAULT_DATA& dd)
{
	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.ServiceRecord == 1)
		if (record_handle != NULL && (dd.sdp_settings.print_service.print_service_record == 1 || dd.sdp_settings.print == 1))
			record_handle->print(record_handle->VALUE, dd);

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.ServiceClassIDList == 1)
		if (class_id_handle != NULL && (dd.sdp_settings.print_service.print_service_class_id_list == 1 || dd.sdp_settings.print == 1))
			class_id_handle->print<SERVICE_CLASS_ID_LIST_S::VV>(class_id_handle->VALUE, dd);

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.ProtocolDescriptorList == 1)
		if (protocol_descriptor_list_handle != NULL && (dd.sdp_settings.print_service.print_protocol_descriptor_list == 1 || dd.sdp_settings.print == 1))
			protocol_descriptor_list_handle->print<PROTOCOL_DESCRIPTOR_LIST_S::VV>(protocol_descriptor_list_handle->VALUE, dd);

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.ServiceName == 1)
		if (service_name_handle != NULL && (dd.sdp_settings.print_service.print_service_name == 1 || dd.sdp_settings.print == 1))
			service_name_handle->print<SERVICE_NAME_S::VV>(service_name_handle->VALUE, dd);

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.ProviderName == 1)
		if (provider_name_handle != NULL && (dd.sdp_settings.print_service.print_provider_name == 1 || dd.sdp_settings.print == 1))
			provider_name_handle->print<PROVIDER_NAME_S::VV>(provider_name_handle->VALUE, dd);

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.BluetoothProfileDescriptorList == 1)
		if (bluetooth_profile_descriptor_list_handle != NULL && (dd.sdp_settings.print_service.print_bluetooth_profile_descriptor_list == 1 || dd.sdp_settings.print == 1))
			bluetooth_profile_descriptor_list_handle->print<BLUETOOTH_PROFILE_DESCRIPTOR_LIST_S::VV>(bluetooth_profile_descriptor_list_handle->VALUE, dd);

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.LanguageBaseAttributeIdList == 1)
		if (language_base_attribute_id_list_handle != NULL && (dd.sdp_settings.print_service.print_language_base_attribute_id_list == 1 || dd.sdp_settings.print == 1))
			language_base_attribute_id_list_handle->print<LANGUAGE_BASE_ATTRIBUTE_ID_LIST_S::VV>(language_base_attribute_id_list_handle->VALUE, dd);

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.ServiceDescription == 1)
		if (service_description_handle != NULL && (dd.sdp_settings.print_service.print_service_description == 1 || dd.sdp_settings.print == 1))
			service_description_handle->print<SERVICE_DESCRIPTION_S::VV>(service_description_handle->VALUE, dd);
}

SDP::PDEFAULT_EXPORT SDP::DEFAULT_class::export_default_ATTR(IOCTL_S::DEFAULT_DATA& dd)
{
	exp = new DEFAULT_EXPORT();

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.ServiceRecord == 1)
		if (record_handle != NULL)
			exp->record_handle_export = record_handle;

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.ServiceClassIDList == 1)
		if (class_id_handle != NULL)
			exp->class_id_handle_export = class_id_handle;

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.ProtocolDescriptorList == 1)
		if (protocol_descriptor_list_handle != NULL)
			exp->protocol_descriptor_list_handle_export = protocol_descriptor_list_handle;

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.ServiceName == 1)
		if (service_name_handle != NULL)
			exp->service_name_handle_export = service_name_handle;

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.ProviderName == 1)
		if (provider_name_handle != NULL)
			exp->provider_name_export = provider_name_handle;

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.BluetoothProfileDescriptorList == 1)
		if (bluetooth_profile_descriptor_list_handle != NULL)
			exp->bluetooth_profile_descriptor_list_handle_export = bluetooth_profile_descriptor_list_handle;

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.LanguageBaseAttributeIdList == 1)
		if (language_base_attribute_id_list_handle != NULL)
			exp->language_base_attribute_id_list_export = language_base_attribute_id_list_handle;

	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.att_DEFAULT.ServiceDescription == 1)
		if (service_description_handle != NULL)
			exp->service_description_export = service_description_handle;

	return exp;
}

