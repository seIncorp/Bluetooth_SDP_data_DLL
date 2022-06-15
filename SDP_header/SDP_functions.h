#pragma once


namespace SDP
{
	namespace FUNCTIONS
	{
		namespace SDP_INIT_CONNECT
		{
			/* SET, CONNECT, DISCONNECT FROM SDP DEVICE */
			int init_for_IOCTL_BTH_SDP_CONNECT(char add[], DEVICE_DATA_SDP& device_data_sdp, IOCTL_S::DEFAULT_DATA& dd);
			int call_IOCTL_BTH_SDP_CONNECT(DEVICE_DATA_SDP& device_data_sdp, IOCTL_S::DEFAULT_DATA& dd);
		};

		namespace SDP_SERVICE_SEARCH
		{
			void init_for_IOCTL_BTH_SDP_SERVICE_SEARCH(DEVICE_DATA_SDP& device_data_sdp, IOCTL_S::DEFAULT_DATA& dd);
			int call_IOCTL_BTH_SDP_SERVICE_SEARCH(DEVICE_DATA_SDP& device_data_sdp, IOCTL_S::DEFAULT_DATA& dd);
		};

		namespace SDP_ATTRIBUTE_SEARCH
		{
			BOOL call_IOCTL_BTH_SDP_ATTRIBUTE_SEARCH(BTH_SDP_ATTRIBUTE_SEARCH_REQUEST* bsasr, BYTE bssr_response[], int res_length, IOCTL_S::DEFAULT_DATA& dd);
			BOOL set_and_call_BTH_SDP_ATTRIBUTE_SEARCH(ULONG recordHandle, HANDLE_SDP_TYPE aa, USHORT minAttr, USHORT maxAttr, BYTE res[], int res_length, IOCTL_S::DEFAULT_DATA& dd);
		};

		namespace SDP_INIT_DISCONNECT
		{
			int init_for_IOCTL_BTH_SDP_DISCONNECT(DEVICE_DATA_SDP& device_data_sdp);
			int call_IOCTL_BTH_SDP_DISCONNECT(DEVICE_DATA_SDP& device_data_sdp, IOCTL_S::DEFAULT_DATA& dd);
		};


		void call_and_search_service(DEVICE_DATA_SDP& device_data_sdp, IOCTL_S::DEFAULT_DATA& dd);


		void printResponse(BYTE bssr_response[]);


		int getAndParse_SERVICE_AVAILABILITY(ULONG recordHandle, HANDLE_SDP_TYPE aa, IOCTL_S::DEFAULT_DATA& dd);

	
		template<class A, class B>
		int set_save_ATTRIBUTE_ELEMENT(A id_handle, B res, int res_length) 
		{
			int position = sizeof(BTH_SDP_STREAM_RESPONSE) + 1 + 0;

			SDP::PATTRIBUTE_ID_ELEMENT record_handle_element = new SDP::ATTRIBUTE_ID_ELEMENT();
			record_handle_element = (SDP::PATTRIBUTE_ID_ELEMENT)(res + position);

			id_handle->attr_id = new ATTR_ID();
			id_handle->attr_id->element = new SDP::ATTRIBUTE_ID_ELEMENT();
			id_handle->attr_id->element->element.size = record_handle_element->element.size;
			id_handle->attr_id->element->element.type = record_handle_element->element.type;
			id_handle->attr_id->element->type_value = SDP::SUB_FUNCTIONS::getElementTypeString(id_handle->attr_id->element->element.type);
			

			int temp_size = SDP::SUB_FUNCTIONS::getElementSize(id_handle->attr_id->element->element.size, &(id_handle->attr_id->additional_bits_flag));

			if (id_handle->attr_id->additional_bits_flag)
			{
				id_handle->attr_id->additional_bits_for_size = temp_size;

				// TODO: nadaljuj z branjem dodatnih byte-ov
			}
			else
			{
				id_handle->attr_id->size_bytes = temp_size;
				position++;

				id_handle->attr_id->value = new BYTE[temp_size]();

				memset(id_handle->attr_id->value, 0x00, temp_size);
				
				for (int a = 0; a < temp_size; a++)
				{
					position += a;
					id_handle->attr_id->value[a] = *(res + position);
				}
			}

			position++;

			return position;
		}

		template<class A, class B>
		int set_save_VALUE_ELEMENT(A id_handle, B res, int res_length, int position) 
		{
			SDP::PATTRIBUTE_ID_ELEMENT record_handle_element_2 = new SDP::ATTRIBUTE_ID_ELEMENT();
			record_handle_element_2 = (SDP::PATTRIBUTE_ID_ELEMENT)(res + position);

			id_handle->VALUE.element = new SDP::ATTRIBUTE_ID_ELEMENT();
			id_handle->VALUE.element->element.size = record_handle_element_2->element.size;
			id_handle->VALUE.element->element.type = record_handle_element_2->element.type;
			id_handle->VALUE.element->type_value = SDP::SUB_FUNCTIONS::getElementTypeString(id_handle->VALUE.element->element.type);



			int temp_size_VALUE = SDP::SUB_FUNCTIONS::getElementSize(
										id_handle->VALUE.element->element.size, 
										&(id_handle->VALUE.additional_bits_flag)
									);

			if (id_handle->VALUE.additional_bits_flag)
			{
				id_handle->VALUE.additional_bits_for_size = temp_size_VALUE;

				if (id_handle->VALUE.additional_bits_for_size = 1)
				{
					position++;
					id_handle->VALUE.size_bytes = *(res + position);

					id_handle->VALUE.value = new BYTE[*(res + position)]();

					memset(id_handle->VALUE.value, 0x00, *(res + position));

					position++;
					for (int b = 0; b < id_handle->VALUE.size_bytes; b++)
						id_handle->VALUE.value[b] = *(res + position + b);

				}

				// TODO: naredi se za ostale velikosti 2 in 4
			}
			else
			{
				id_handle->VALUE.size_bytes = temp_size_VALUE;
				position++;

				id_handle->VALUE.value = new BYTE[id_handle->VALUE.size_bytes]();
				memset(id_handle->VALUE.value, 0x00, id_handle->VALUE.size_bytes);
				for (int b = 0; b < id_handle->VALUE.size_bytes; b++)
				{

					id_handle->VALUE.value[b] = *(res + position + b);
				}
			}

			position += id_handle->VALUE.size_bytes;

			return position;
		}


		void parse_SERVICE_CLASS_ID_LIST(PSERVICE_CLASS_ID_LIST handle);
		void parse_PROTOCOL_DESCRIPTOR_LIST(PPROTOCOL_DESCRIPTOR_LIST handle, IOCTL_S::DEFAULT_DATA& dd);
		void parse_SERVICE_NAME(SERVICE_NAME& handle);
		void parse_PROVIDER_NAME(PPROVIDER_NAME handle);
		void parse_BLUETOOTH_PROFILE_DESCRIPTOR_LIST(PBLUETOOTH_PROFILE_DESCRIPTOR_LIST handle);
		void parse_LANGUAGE_BASE_ATTRIBUTE_ID_LIST(PLANGUAGE_BASE_ATTRIBUTE_ID_LIST handle);
		void parse_SERVICE_DESCRIPTION(PSERVICE_DESCRIPTION handle);



		template<class C>
		void parse_by_type(const std::type_info& type, C handle, SHORT current_used_service, IOCTL_S::DEFAULT_DATA& dd)
		{
			const std::type_info& a2 = typeid(DEFAULT_OBJECT_S*);
			const std::type_info& a3 = typeid(SERVICE_CLASS_ID_LIST_S*);
			const std::type_info& a4 = typeid(PROTOCOL_DESCRIPTOR_LIST_S*);
			const std::type_info& a5 = typeid(SERVICE_NAME_S*);
			const std::type_info& a6 = typeid(PROVIDER_NAME_S*);
			const std::type_info& a7 = typeid(BLUETOOTH_PROFILE_DESCRIPTOR_LIST_S*);
			const std::type_info& a8 = typeid(LANGUAGE_BASE_ATTRIBUTE_ID_LIST_S*);
			const std::type_info& a9 = typeid(SERVICE_DESCRIPTION_S*);
			

			// ServiceRecordHandle
			if (type == a2)
			{
				// TODO: naredi se za service record
			}

			// ServiceClassIDList
			if (type == a3)
			{
				parse_SERVICE_CLASS_ID_LIST((PSERVICE_CLASS_ID_LIST)handle);
			}

			// ProtocolDescriptorList
			if (type == a4)
			{
				parse_PROTOCOL_DESCRIPTOR_LIST((PPROTOCOL_DESCRIPTOR_LIST)handle, dd);
			}

			// ServiceName
			if (type == a5)
			{
				//printf("5. --> DO SEM!!!\n");
				parse_SERVICE_NAME((SERVICE_NAME&)*handle);
				//printf("8.2 --> DO SEM!!!\n");
			}

			// ProviderName
			if (type == a6)
			{
				parse_PROVIDER_NAME((PPROVIDER_NAME)handle);
			}

			// BluetoothProfileDescriptorList
			if (type == a7)
			{
				parse_BLUETOOTH_PROFILE_DESCRIPTOR_LIST((PBLUETOOTH_PROFILE_DESCRIPTOR_LIST)handle);
			}

			// LanguageBaseAttributeIDList
			if (type == a8)
			{
				parse_LANGUAGE_BASE_ATTRIBUTE_ID_LIST((PLANGUAGE_BASE_ATTRIBUTE_ID_LIST)handle);
			}

			// ServiceDescription
			if (type == a9)
			{
				parse_SERVICE_DESCRIPTION((PSERVICE_DESCRIPTION)handle);
			}

			if (current_used_service == SDP::_NAP)
			{
				SDP::NAP::parse_by_type_sub_function<C>(type, handle, current_used_service);
			}

			if (current_used_service == SDP::Message_Access_Server)
			{
				SDP::MAP::parse_by_type_sub_function<C>(type, handle, current_used_service);
			}

			if (current_used_service == SDP::Phonebook_Access_PSE)
			{
				SDP::PBAP::parse_by_type_sub_function<C>(type, handle, current_used_service);
			}

			if (current_used_service == SDP::OBEXObjectPush)
			{
				SDP::OBEX::parse_by_type_sub_function<C>(type, handle, current_used_service);
			}

			if (current_used_service == SDP::Handsfree ||
				current_used_service == SDP::HandsfreeAudioGateway
			)
			{
				SDP::HFP::parse_by_type_sub_function<C>(type, handle, current_used_service,dd);
			}

			if (current_used_service == SDP::AudioSource)
			{
				SDP::A2DP::parse_by_type_sub_function<C>(type, handle, current_used_service);
			}

			if (current_used_service == SDP::A_V_RemoteControl ||
				current_used_service == SDP::A_V_RemoteControlTarget ||
				current_used_service == SDP::A_V_RemoteControlController
				)
			{
				SDP::AVRCP::parse_by_type_sub_function<C>(type, handle, current_used_service);
			}

			if (current_used_service == SDP::Headset ||
				current_used_service == SDP::Headset_Audio_Gateway ||
				current_used_service == 0x1131
				)
			{
				SDP::HSP::parse_by_type_sub_function<C>(type, handle, current_used_service);
			}
		}

		template<class C, class D>
		int getAndParse_DEAFULT(ULONG recordHandle, 
			HANDLE_SDP_TYPE aa, 
			C handle, 
			USHORT minAttr, 
			USHORT maxAttr, 
			DEVICE_DATA_SDP& device_data_sdp, 
			IOCTL_S::DEFAULT_DATA& dd, 
			int print_local
		)
		{
			if(dd.sdp_settings.debug == 1)
				printf("\n\n*** getAndParse_DEAFULT ***\n");

			BYTE bssr_response[5000]{ 0 };		// TODO: premisli

			
			BOOL test = SDP::FUNCTIONS::SDP_ATTRIBUTE_SEARCH::set_and_call_BTH_SDP_ATTRIBUTE_SEARCH(recordHandle, aa, minAttr, maxAttr, bssr_response, 5000, dd);
			
			if (test)
			{
				if (dd.sdp_settings.debug == 1)
				{
					printf("IOCTL_BTH_SDP_ATTRIBUTE_SEARCH --> OK\n");
					printResponse(bssr_response);
				}

				int position = set_save_ATTRIBUTE_ELEMENT<C, BYTE[]>(handle, bssr_response, 5000);
				position = set_save_VALUE_ELEMENT<C, BYTE[]>(handle, bssr_response, 5000, position);

				const std::type_info& a1 = typeid(C);
				
				parse_by_type<C>(a1, handle, device_data_sdp.current_used_service, dd);

				return 1;
			}

			return 0;
		}
	};
}