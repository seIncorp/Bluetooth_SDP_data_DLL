#pragma once
namespace SDP
{
	class DEFAULT_class
	{
	public:
		/* default */
		PSERVICE_RECORD record_handle;
		PSERVICE_CLASS_ID_LIST class_id_handle;
		PPROTOCOL_DESCRIPTOR_LIST protocol_descriptor_list_handle;
		PSERVICE_NAME service_name_handle;
		PPROVIDER_NAME provider_name_handle;
		PBLUETOOTH_PROFILE_DESCRIPTOR_LIST bluetooth_profile_descriptor_list_handle;
		PLANGUAGE_BASE_ATTRIBUTE_ID_LIST language_base_attribute_id_list_handle;
		PSERVICE_DESCRIPTION service_description_handle;

		PDEFAULT_EXPORT exp;


		/* default functions (all att) */
		void setDefaultObjects(IOCTL_S::DEFAULT_DATA& dd);
		void callDefaultAttributes(DEVICE_DATA_SDP& device_data_sdp, IOCTL_S::DEFAULT_DATA& dd);
		void printDefaultData(IOCTL_S::DEFAULT_DATA& dd);

		/* default functions (one att at time) */
		// those functions will call default, for simplicity of use, because only few services use this
		void call_ProviderName(DEVICE_DATA_SDP& device_data_sdp, IOCTL_S::DEFAULT_DATA& dd);
		void call_LanguageBaseAttributeIDList(DEVICE_DATA_SDP& device_data_sdp, IOCTL_S::DEFAULT_DATA& dd);
		void call_ServiceDescription(DEVICE_DATA_SDP& device_data_sdp, IOCTL_S::DEFAULT_DATA& dd);
		
		template<class A, class B>
		void call_DEAFULT_default_attr(DEVICE_DATA_SDP& device_data_sdp, IOCTL_S::DEFAULT_DATA& dd, A handle, SHORT attr)
		{			
			FUNCTIONS::getAndParse_DEAFULT<A, B>(
				device_data_sdp.buffer_res[0],
				device_data_sdp.bsc->HANDLE_SDP_FIELD_NAME,
				handle,
				attr,
				attr,
				device_data_sdp,
				dd,
				0
			);
		}



		PDEFAULT_EXPORT export_default_ATTR(IOCTL_S::DEFAULT_DATA& dd);

	private:

		SHORT list_att[5]{
			ServiceRecordHandle,
			ServiceClassIDList,
			ProtocolDescriptorList,
			ServiceName,
			BluetoothProfileDescriptorList
		};

	};
}
