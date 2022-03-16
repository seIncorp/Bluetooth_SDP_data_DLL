#include "pch.h"

/* only those attributes are used on all services */
void SDP::DEFAULT_class::setDefaultObjects()
{
	record_handle = new DEFAULT_OBJECT();
	class_id_handle = new SERVICE_CLASS_ID_LIST();
	protocol_descriptor_list_handle = new PROTOCOL_DESCRIPTOR_LIST();
	service_name_handle = new SERVICE_NAME();
	bluetooth_profile_descriptor_list_handle = new BLUETOOTH_PROFILE_DESCRIPTOR_LIST();
}


void SDP::DEFAULT_class::call_ServiceRecordHandle(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd)
{
	FUNCTIONS::getAndParse_DEAFULT<PDEFAULT_OBJECT, DEFAULT_OBJECT_S::VV>(
		device_data_sdp->buffer_res[0],
		device_data_sdp->bsc->HANDLE_SDP_FIELD_NAME,
		record_handle,
		SDP::ServiceRecordHandle,
		SDP::ServiceRecordHandle,
		device_data_sdp,
		dd,
		0
		);
}

void SDP::DEFAULT_class::call_ServiceClassIDList(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd)
{
	FUNCTIONS::getAndParse_DEAFULT<PSERVICE_CLASS_ID_LIST, SERVICE_CLASS_ID_LIST_S::VV>(
		device_data_sdp->buffer_res[0],
		device_data_sdp->bsc->HANDLE_SDP_FIELD_NAME,
		class_id_handle,
		SDP::ServiceClassIDList,
		SDP::ServiceClassIDList,
		device_data_sdp,
		dd,
		0
	);
}

void SDP::DEFAULT_class::call_ProtocolDescriptorList(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd)
{
	FUNCTIONS::getAndParse_DEAFULT<PPROTOCOL_DESCRIPTOR_LIST, PROTOCOL_DESCRIPTOR_LIST_S::VV>(
		device_data_sdp->buffer_res[0],
		device_data_sdp->bsc->HANDLE_SDP_FIELD_NAME,
		protocol_descriptor_list_handle,
		SDP::ProtocolDescriptorList,
		SDP::ProtocolDescriptorList,
		device_data_sdp,
		dd,
		0
	);
}

void SDP::DEFAULT_class::call_ServiceName(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd)
{
	FUNCTIONS::getAndParse_DEAFULT<PSERVICE_NAME, SERVICE_NAME::VV>(
		device_data_sdp->buffer_res[0],
		device_data_sdp->bsc->HANDLE_SDP_FIELD_NAME,
		service_name_handle,
		SDP::ServiceName,
		SDP::ServiceName,
		device_data_sdp,
		dd,
		0
	);
}

void SDP::DEFAULT_class::call_BluetoothProfileDescriptorList(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd)
{
	FUNCTIONS::getAndParse_DEAFULT<PBLUETOOTH_PROFILE_DESCRIPTOR_LIST, BLUETOOTH_PROFILE_DESCRIPTOR_LIST::VV>(
		device_data_sdp->buffer_res[0],
		device_data_sdp->bsc->HANDLE_SDP_FIELD_NAME,
		bluetooth_profile_descriptor_list_handle,
		SDP::BluetoothProfileDescriptorList,
		SDP::BluetoothProfileDescriptorList,
		device_data_sdp,
		dd,
		0
	);
}



void SDP::DEFAULT_class::callDefaultAttributes(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd)
{
	if(dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.ServiceRecord == 1)
		call_ServiceRecordHandle(device_data_sdp, dd);
	
	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.ServiceClassIDList == 1)
		call_ServiceClassIDList(device_data_sdp, dd);
	
	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.ProtocolDescriptorList == 1)
		call_ProtocolDescriptorList(device_data_sdp, dd);
	
	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.ServiceName == 1)
		call_ServiceName(device_data_sdp, dd);
	
	if (dd.attr_search_for_service.all == 1 || dd.attr_search_for_service.BluetoothProfileDescriptorList == 1)
		call_BluetoothProfileDescriptorList(device_data_sdp, dd);
}

void SDP::DEFAULT_class::printDefaultData(IOCTL_S::DEFAULT_DATA dd)
{
	if (record_handle != NULL && (dd.sdp_settings.print_service.print_service_record == 1 || dd.sdp_settings.print == 1))
		record_handle->print(record_handle->VALUE, dd);

	if (class_id_handle != NULL && (dd.sdp_settings.print_service.print_service_class_id_list == 1 || dd.sdp_settings.print == 1))
		class_id_handle->print<SERVICE_CLASS_ID_LIST_S::VV>(class_id_handle->VALUE, dd);

	if (protocol_descriptor_list_handle != NULL && (dd.sdp_settings.print_service.print_protocol_descriptor_list == 1 || dd.sdp_settings.print == 1))
		protocol_descriptor_list_handle->print<PROTOCOL_DESCRIPTOR_LIST_S::VV>(protocol_descriptor_list_handle->VALUE, dd);

	if (service_name_handle != NULL && (dd.sdp_settings.print_service.print_service_name == 1 || dd.sdp_settings.print == 1))
		service_name_handle->print<SERVICE_NAME_S::VV>(service_name_handle->VALUE, dd);

	if (provider_name_handle != NULL && (dd.sdp_settings.print_service.print_provider_name == 1 || dd.sdp_settings.print == 1))
		provider_name_handle->print<PROVIDER_NAME_S::VV>(provider_name_handle->VALUE, dd);

	if (bluetooth_profile_descriptor_list_handle != NULL && (dd.sdp_settings.print_service.print_bluetooth_profile_descriptor_list == 1 || dd.sdp_settings.print == 1))
		bluetooth_profile_descriptor_list_handle->print<BLUETOOTH_PROFILE_DESCRIPTOR_LIST_S::VV>(bluetooth_profile_descriptor_list_handle->VALUE, dd);

	if (language_base_attribute_id_list_handle != NULL && (dd.sdp_settings.print_service.print_language_base_attribute_id_list == 1 || dd.sdp_settings.print == 1))
		language_base_attribute_id_list_handle->print<LANGUAGE_BASE_ATTRIBUTE_ID_LIST_S::VV>(language_base_attribute_id_list_handle->VALUE, dd);

	if (service_description_handle != NULL && (dd.sdp_settings.print_service.print_service_description == 1 || dd.sdp_settings.print == 1))
		service_description_handle->print<SERVICE_DESCRIPTION_S::VV>(service_description_handle->VALUE, dd);
}

SDP::PDEFAULT_EXPORT SDP::DEFAULT_class::export_default_ATTR()
{
	exp = new DEFAULT_EXPORT();

	if (record_handle != NULL)
		exp->record_handle_export = record_handle;

	if (class_id_handle != NULL)
		exp->class_id_handle_export = class_id_handle;

	if (protocol_descriptor_list_handle != NULL)
		exp->protocol_descriptor_list_handle_export = protocol_descriptor_list_handle;

	if (service_name_handle != NULL)
		exp->service_name_handle_export = service_name_handle;

	if (provider_name_handle != NULL)
		exp->provider_name_export = provider_name_handle;

	if (bluetooth_profile_descriptor_list_handle != NULL)
		exp->bluetooth_profile_descriptor_list_handle_export = bluetooth_profile_descriptor_list_handle;

	if (language_base_attribute_id_list_handle != NULL)
		exp->language_base_attribute_id_list_export = language_base_attribute_id_list_handle;

	if (service_description_handle != NULL)
		exp->service_description_export = service_description_handle;

	return exp;
}

