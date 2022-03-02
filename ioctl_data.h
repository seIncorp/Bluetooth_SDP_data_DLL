#pragma once


#ifdef SDP_DATA_EXPORTS
#define SDP_DATA_API __declspec(dllexport)
#else
#define SDP_DATA_API __declspec(dllimport)
#endif


/*
	TODO:
	- BUG: check why app crash when use and call set_all_SDP_service_for_search() with SDPsearch() [FIXED: NOT USING GenericAudio service]
	- ADD: debug option
	- ADD: print option



*/



/************************************************************************/
/* ENUMs */

namespace SDP
{
	typedef enum
	{
		// DONE
		Headset = 0x1108,
		AudioSource = 0x110A,
		AudioSink = 0x110B,
		Headset_Audio_Gateway = 0x1112,
		Handsfree = 0x111E,
		OBEXObjectPush = 0x1105,
		OBEXFileTransfer = 0x1106,
		A_V_RemoteControl = 0x110E,
		A_V_RemoteControlTarget = 0x110C,
		A_V_RemoteControlController = 0x110F,
		PANU = 0x1115,
		_NAP = 0x1116,
		HandsfreeAudioGateway = 0x111F,
		Phonebook_Access_PSE = 0x112F,
		Phonebook_Access = 0x1130,
		Message_Access_Server = 0x1132,
		Message_Access_Profile = 0x1134,
		PnPInformation = 0x1200,
		GenericAudio = 0x1203,

		// TODO: 
		Phonebook_Access_PCE = 0x112E,
		Message_Notification_Server = 0x1133

	} SERVICE_CLASS_ID;

	typedef enum
	{
		_Nil = 0,
		_Unsigned_int,
		_Signed_twos_complement_int,
		_UUID,
		_Text_string,
		_Boolean,
		_Data_element_sequence,
		_Data_element_alternative,
		_URL,
		_Reserved

	} DATA_ELEMENT_TYPE_DESCRIPTOR_VALUE;

	typedef enum
	{
		_1_byte = 0,
		_2_bytes,
		_4_bytes,
		_8_bytes,
		_16_bytes,
		_additional_8_bits,		//unsigned integer
		_additional_16_bits,	//unsigned integer
		_additional_32_bits		//unsigned integer

	} DATA_ELEMENT_SIZE_DESCRIPTOR_VALUE;

	typedef enum
	{
		SDP_ERROR_RSP = 1,
		SDP_SERVICE_SEARCH_REQ,
		SDP_SERVICE_SEARCH_RSP,
		SDP_SERVICE_ATTR_REQ,
		SDP_SERVICE_ATTR_RSP,
		SDP_SERVICE_SEARCH_ATTR_REQ,
		SDP_SERVICE_SEARCH_ATTR_RSP

	} PDU_ID;

	typedef enum
	{
		_SDP = 0x0001,
		_UDP = 0x0002,
		_RFCOMM = 0x0003,
		_TCP = 0x0004,
		_TCS_BIN = 0x0005,
		_TCS_AT = 0x0006,
		_ATT = 0x0007,
		_OBEX = 0x0008,
		_IP = 0x0009,
		_FTP = 0x000a,
		_HTTP = 0x000c,
		_WSP = 0x000e,
		_BNEP = 0x000f,
		_UPNP = 0x0010,
		_HIDP = 0x0011,
		_AVCTP = 0x0017,
		_AVDTP = 0x0019,
		_CMTP = 0x001b,
		_L2CAP = 0x0100

	} PROTOCOL_ID;

	typedef enum
	{
		IPv4 = 0x0800,
		ARP = 0x0806,
		FRARP = 0x0808,
		IPv6 = 0x86DD
		// https://www.rfc-editor.org/rfc/pdfrfc/rfc7042.txt.pdf


	} NETWORK_PACKET_TYPE;

	typedef enum
	{
		ServiceRecordHandle = 0x0000,
		ServiceClassIDList = 0x0001,
		ServiceRecordState = 0x0002,
		ServiceID = 0x0003,
		ProtocolDescriptorList = 0x0004,
		BrowseGroupList = 0x0005,
		LanguageBaseAttributeIDList = 0x0006,
		ServiceInfoTimeToLive = 0x0007,
		ServiceAvailability = 0x0008,
		BluetoothProfileDescriptorList = 0x0009,
		DocumentationURL = 0x000A,
		ClientExecutableURL = 0x000B,
		IconURL = 0x000C,
		AdditionalProtocolDescriptorList = 0x000D,
		ServiceName = 0x0100,
		ServiceDescription = 0x0101,
		ProviderName = 0x0102

	} ATTRIBUTE_ID;



	namespace NAP
	{
		typedef enum
		{
			IpSubnet = 0x0200,
			SecurityDescription = 0x030A,
			NetAccessType = 0x030B,
			MaxNetAccessrate = 0x030C,
			IPv4Subnet = 0x030D,		// TODO:
			IPv6Subnet = 0x030E		// TODO:

		} ATTRIBUTE_ID_PAN;
	}

	namespace MAP
	{
		typedef enum
		{
			GoepL2capPsm = 0x0200,
			MASInstanceID = 0x0315,
			SupportedMessageTypes = 0x0316,
			MapSupportedFeatures = 0x0317

		} ATTRIBUTE_ID_MAP;
	}

	namespace PBAP
	{
		typedef enum
		{
			GoepL2capPsm = 0x0200,
			SupportedRepositories = 0x0314,
			PbapSupportedFeatures = 0x0317

		} ATTRIBUTE_ID_PBAP;
	}

	namespace OBEX
	{
		typedef enum
		{
			GoepL2capPsm = 0x0200,
			ServiceVersion = 0x0300,
			SupportedFormatsList = 0x0303

		} ATTRIBUTE_ID_OBEX;
	}

	namespace HFP
	{
		typedef enum
		{
			Network = 0x0301,
			SupportedFeatures = 0x0311

		} ATTRIBUTE_ID_HFP;
	}

	namespace PNPINFO	// PnPInformation
	{
		typedef enum
		{
			SpecificationID = 0x0200,
			VendorID = 0x0201,
			ProductID = 0x0202,
			Version = 0x0203,
			PrimaryRecord = 0x0204,
			VendorIDSource = 0x0205,
			ClientExecutableURL = 0x000B,
			DocumentationURL = 0x000A

		} ATTRIBUTE_ID_DEVICE_SDP;
	}

	namespace A2DP
	{
		typedef enum
		{
			SupportedFeatures = 0x0311

		} ATTRIBUTE_ID_DEVICE_A2DP;
	}

	namespace AVRCP
	{
		typedef enum
		{
			SupportedFeatures = 0x0311

		} ATTRIBUTE_ID_DEVICE_AVRCP;
	}

	namespace HSP
	{
		typedef enum
		{
			RemoteAudioVolumeControl = 0x0302

		} ATTRIBUTE_ID_DEVICE_HSP;
	}
};



/************************************************************************/
/* ACCESS POINT TO DLL */

namespace IOCTL_S
{
	
	
	/* MAIN structure */
	struct SDP_DATA_API DEFAULT_DATA
	{
		struct SDP_services_for_search
		{
			BYTE Headset;
			BYTE Headset_Audio_Gateway;
			BYTE AudioSource;
			BYTE GenericAudio;
			//BYTE AudioSink;
			BYTE Handsfree;
			BYTE HandsfreeAudioGateway;
			BYTE OBEXObjectPush;
			//BYTE OBEXFileTransfer;
			BYTE A_V_RemoteControl;
			BYTE A_V_RemoteControlTarget;
			BYTE A_V_RemoteControlController;
			BYTE PANU;
			BYTE _NAP;
			BYTE Phonebook_Access_PSE;
			//BYTE Phonebook_Access;
			BYTE Message_Access_Server;
			//BYTE Message_Access_Profile;
			BYTE PnPInformation;
		};
		
		struct SDP_exported_data
		{
			BYTE* default_export;
			BYTE* a2dp_export;			// DONE!
			BYTE* avrcp_export;			// DONE!
			BYTE* hfp_export;			// DONE!
			BYTE* hsp_export;			// DONE!
			BYTE* map_export;			// DONE!
			BYTE* nap_export;			// DONE!
			BYTE* obex_export;			// DONE!
			BYTE* pbap_export;			// DONE!
			BYTE* pnpinfo_export;		// 
		};

		struct SDP_settings
		{
			int debug;
			int print;
			int print_info;

			struct SDP_print_service
			{
				/* DEFAULT ATTR. */
				int print_service_record;
				int print_service_class_id_list;
				int print_protocol_descriptor_list;
				int print_service_name;
				int print_provider_name;
				int print_bluetooth_profile_descriptor_list;
				int print_language_base_attribute_id_list;
				int print_service_description;
				//int print_service_availability;

				/* SPECIAL ATTR. */



			};

			SDP_print_service print_service;
		};

		HANDLE hDevice;
		BOOL bResult;
		DWORD junk;
		SHORT service_class_id_in_use;
		SDP_services_for_search services_for_search;
		SDP_exported_data exported_data;
		SDP_settings sdp_settings;

		void reset_SDP_service_for_search();
		void set_all_SDP_service_for_search();

	private:
		double vesrion;
		char* author;
	};


	/* LOCAL functions */
	
	int str2ba(const char* straddr, BTH_ADDR* btaddr);



	/* CONNECTION AND DISCONNECTION functions */
	SDP_DATA_API int connectToDevice(const wchar_t* name, DEFAULT_DATA* dd);
	SDP_DATA_API void closeConnectionToDevice(DEFAULT_DATA* dd);

	/* SEARCH AND RETRIVING DATA functions */
	SDP_DATA_API int SDPsearch(DEFAULT_DATA* dd, char address[]);
	SDP_DATA_API int getBthDeviceInfo(DEFAULT_DATA* dd, int print = 1);
	SDP_DATA_API void getLocalBthInfo(DEFAULT_DATA* dd);

	SDP_DATA_API void printErrorMessage(DWORD id);

};





/************************************************************************/
/* DEFAULTS structures */

namespace SDP
{
	
	typedef struct
	{
		struct
		{
			BYTE size : 3;		// ID for enum
			BYTE type : 5;		// ID for enum
		} element;
	} ATTRIBUTE_ID_ELEMENT, * PATTRIBUTE_ID_ELEMENT;

	typedef struct
	{
		ATTRIBUTE_ID_ELEMENT* element;			// pointer to ATTRIBUTE_ID_ELEMENT
		int additional_bits_flag;				// depricated
		SHORT value;								// UUID of class

	} SERVICE_CLASS, * PSERVICE_CLASS;

	typedef struct
	{
		ATTRIBUTE_ID_ELEMENT* element;

		int server_channel_num;						// for Handsfree, Headset
		SHORT PSM;									// for AudioSource
		SHORT Version;								// for AudioSource

		/* for PANU */
		ATTRIBUTE_ID_ELEMENT* element_PANU;
		int additional_bits_flag_PANU;
		int additional_bits_for_size_PANU;
		int num_of_Supported_Network_Packet_Type_List_PANU;
		SHORT* Supported_Network_Packet_Type_List;

	} PROTOCOL_DESCRIPTOR_SPECIFIC_PARAMETER;

	typedef struct
	{
		ATTRIBUTE_ID_ELEMENT* element;

		int size_bytes;						// size value for element value
		int additional_bits_flag;
		int additional_bits_for_size;		// additional bytes for size value (after this you must read those bytes for real size of element value)

		BYTE* value;

		ATTRIBUTE_ID_ELEMENT* element_protocol;
		SHORT protocol_id;

		int additional_parameters_flag;
		PROTOCOL_DESCRIPTOR_SPECIFIC_PARAMETER* pdsp;

	} PROTOCOL_DESCRIPTOR;

	typedef struct
	{
		ATTRIBUTE_ID_ELEMENT* element;

		int size_bytes;						// size value for element value
		int additional_bits_flag;
		int additional_bits_for_size;		// additional bytes for size value (after this you must read those bytes for real size of element value)

		BYTE* value;

	} BLUETOOTH_PROFILE, * PBLUETOOTH_PROFILE;

	typedef struct ATTR_ID_S
	{
		ATTRIBUTE_ID_ELEMENT* element;

		int size_bytes;						// size value for element value
		int additional_bits_flag;
		int additional_bits_for_size;		// additional bytes for size value (after this you must read those bytes for real size of element value)

		BYTE* value;

	} ATTR_ID;

	typedef struct VALUE_S
	{
		ATTRIBUTE_ID_ELEMENT* element;

		int size_bytes;						// size value for element value
		int additional_bits_flag;
		int additional_bits_for_size;		// additional bytes for size value (after this you must read those bytes for real size of element value)
		ULONG size_bytes_additional;

		BYTE* value;

	} VALUE;


	typedef struct DEVICE_DATA_SDP_S
	{
		// for device
		BTH_ADDR* btaddr;
		BTH_SDP_CONNECT* bsc;
		BOOL bResult;

		// for service
		BTH_SDP_SERVICE_SEARCH_REQUEST* bsssr;
		ULONG buffer_res[1];
		BOOL sdp_service_search_res;
		SHORT current_used_service;

		// for disconnection
		BTH_SDP_DISCONNECT* bsd;
		BOOL disconnection_res;


	} DEVICE_DATA_SDP, * PDEVICE_DATA_SDP;

	namespace SUB_FUNCTIONS
	{
		std::string getElementTypeString(BYTE type);
		int getElementSize(BYTE size, int* add_bits);
		std::string getProtocolTypeString(SHORT type);
		std::string getNetworkPacketTypeString(SHORT type);

	};
	
	
	typedef struct DEFAULT_OBJECT_S
	{
		ATTR_ID* attr_id;

		struct VV : VALUE
		{


		} VALUE;

		void printATTR_ELEMENT()
		{
			printf("ATTRIBUTE ID:\n");
			printf("Type: %s [%d]\n", SDP::SUB_FUNCTIONS::getElementTypeString(attr_id->element->element.type).c_str(), attr_id->element->element.type);

			if (attr_id->additional_bits_flag)
			{
				printf("Additional size: %d\n", attr_id->additional_bits_for_size);
			}
			else
			{
				printf("Size: %d Bytes [%d]\n", attr_id->size_bytes, attr_id->size_bytes);

				printf("Value: 0x");
				for (int a = 0; a < attr_id->size_bytes; a++)
					printf("%02X", attr_id->value[a]);
				printf("\n");
			}
		}

		template<class T>
		void printVALUE_ELEMENT(T v)
		{
			printf("VALUE ELEMENT:\n");
			printf("Type: %s [%d]\n", SDP::SUB_FUNCTIONS::getElementTypeString(v.element->element.type).c_str(), v.element->element.type);
			if (v.additional_bits_flag)
			{
				printf("Additional size: %d\n", v.additional_bits_for_size);
				if (v.additional_bits_for_size == 1)
				{
					printf("Data size: %d\n", v.size_bytes);

					printf("Value: ");
					for (int a = 0; a < v.size_bytes; a++)
						printf("0x%02X ", v.value[a]);
					printf("\n");
				}
			}
			else
			{
				printf("Size: %d Bytes [%d]\n", v.size_bytes, v.size_bytes);

				printf("Value: 0x");
				for (int a = 0; a < v.size_bytes; a++)
					printf("%02X", v.value[a]);
				printf("\n");
			}
		}

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			printf("*************************************************\n");
			printf("RECORD HANDLE: \n");
			printATTR_ELEMENT();

			printVALUE_ELEMENT(v);

			printf("\n");
		}

	} DEFAULT_OBJECT, * PDEFAULT_OBJECT;

	typedef struct SERVICE_CLASS_ID_LIST_S : DEFAULT_OBJECT
	{
		struct VV : VALUE
		{

			int num_classes;
			SERVICE_CLASS* classes;				// pointer to array of SERVICE_CLASS objects
		} VALUE;

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			printf("*************************************************\n");
			printf("CLASS ID: \n");
			printATTR_ELEMENT();

			printVALUE_ELEMENT(v);

			// TODO: naredi tako da se bodo kreirali objekt za vsak class posebej, ker jih je v prihodnosti lahko vec

			for (int a = 0; a < VALUE.num_classes; a++)
				printf("Class ID [%d]: 0x%04X\n", a, VALUE.classes[a].value);

			printf("\n");
		}

	} SERVICE_CLASS_ID_LIST, * PSERVICE_CLASS_ID_LIST;

	typedef struct PROTOCOL_DESCRIPTOR_LIST_S : DEFAULT_OBJECT
	{
		struct VV : VALUE
		{
			int num_protocols;

			PROTOCOL_DESCRIPTOR* protocols;

			int _BNEP_flag;

		} VALUE;

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			printf("*************************************************\n");
			printf("PROTOCOL DESCRIPTOR LIST: \n");
			
			printATTR_ELEMENT();

			printVALUE_ELEMENT(v);

			for (int c = 0; c < VALUE.num_protocols; c++)
			{
				if (VALUE._BNEP_flag == 1 && c < (VALUE.num_protocols - 1))
				{
					/* za vse protokole ki so BNEP  */
					printf("Protocol [%d]:\n", c);

					printf("\tValue: ");
					for (int d = 0; d < VALUE.protocols[c].additional_bits_for_size; d++)
						printf("0x%X ", VALUE.protocols[c].value[d]);
					printf("\n");

					printf("\tID [0x%04X][%s]\n", VALUE.protocols[c].protocol_id, SUB_FUNCTIONS::getProtocolTypeString(VALUE.protocols[c].protocol_id).c_str());
					if (VALUE.protocols[c].additional_parameters_flag)
					{
						if (dd.service_class_id_in_use == Handsfree ||
							dd.service_class_id_in_use == Headset ||
							dd.service_class_id_in_use == Headset_Audio_Gateway ||
							dd.service_class_id_in_use == OBEXObjectPush ||
							dd.service_class_id_in_use == OBEXFileTransfer ||
							dd.service_class_id_in_use == SDP::HandsfreeAudioGateway ||
							dd.service_class_id_in_use == SDP::Phonebook_Access_PSE ||
							dd.service_class_id_in_use == SDP::Phonebook_Access ||
							dd.service_class_id_in_use == SDP::Message_Access_Server ||
							dd.service_class_id_in_use == SDP::Message_Access_Profile ||
							dd.service_class_id_in_use == SDP::GenericAudio
							)
							printf("\tChannel number: %d\n", VALUE.protocols[c].pdsp->server_channel_num);

						if (dd.service_class_id_in_use == AudioSource ||
							dd.service_class_id_in_use == AudioSink ||
							dd.service_class_id_in_use == A_V_RemoteControlTarget ||
							dd.service_class_id_in_use == A_V_RemoteControl ||
							dd.service_class_id_in_use == A_V_RemoteControlController ||
							dd.service_class_id_in_use == PANU ||
							dd.service_class_id_in_use == _NAP
							)
						{
							if (VALUE.protocols[c].protocol_id == _L2CAP)
								printf("\tPSM: 0x%04X\n", VALUE.protocols[c].pdsp->PSM);

							if (VALUE.protocols[c].protocol_id == _AVDTP ||
								VALUE.protocols[c].protocol_id == _AVCTP ||
								VALUE.protocols[c].protocol_id == _BNEP
								)
								printf("\tVersion: 0x%04X\n", VALUE.protocols[c].pdsp->Version);

							if (VALUE.protocols[c].protocol_id == _BNEP)
							{
								printf("\tNumber of supported network packet type: %d\n", VALUE.protocols[c].pdsp->num_of_Supported_Network_Packet_Type_List_PANU);

								for (int aaa = 0; aaa < VALUE.protocols[c].pdsp->num_of_Supported_Network_Packet_Type_List_PANU; aaa++)
								{
									printf("\tnetwork packet type [0x%04X][%s]\n", VALUE.protocols[c].pdsp->Supported_Network_Packet_Type_List[aaa], SUB_FUNCTIONS::getNetworkPacketTypeString(VALUE.protocols[c].pdsp->Supported_Network_Packet_Type_List[aaa]).c_str());
								}
							}

						}
					}
				}
				else if (VALUE._BNEP_flag != 1)
				{
					/* za vse protokole ki niso BNEP */

					printf("Protocol [%d]:\n", c);

					printf("\tValue: ");
					for (int d = 0; d < VALUE.protocols[c].additional_bits_for_size; d++)
						printf("0x%X ", VALUE.protocols[c].value[d]);
					printf("\n");

					printf("\tID [0x%04X][%s]\n", VALUE.protocols[c].protocol_id, SUB_FUNCTIONS::getProtocolTypeString(VALUE.protocols[c].protocol_id).c_str());
					if (VALUE.protocols[c].additional_parameters_flag)
					{
						if (dd.service_class_id_in_use == Handsfree ||
							dd.service_class_id_in_use == Headset ||
							dd.service_class_id_in_use == Headset_Audio_Gateway ||
							dd.service_class_id_in_use == OBEXObjectPush ||
							dd.service_class_id_in_use == OBEXFileTransfer ||
							dd.service_class_id_in_use == SDP::HandsfreeAudioGateway ||
							dd.service_class_id_in_use == SDP::Phonebook_Access_PSE ||
							dd.service_class_id_in_use == SDP::Phonebook_Access ||
							dd.service_class_id_in_use == SDP::Message_Access_Server ||
							dd.service_class_id_in_use == SDP::Message_Access_Profile ||
							dd.service_class_id_in_use == SDP::GenericAudio
							)
							printf("\tChannel number: %d\n", VALUE.protocols[c].pdsp->server_channel_num);

						if (dd.service_class_id_in_use == AudioSource ||
							dd.service_class_id_in_use == AudioSink ||
							dd.service_class_id_in_use == A_V_RemoteControlTarget ||
							dd.service_class_id_in_use == A_V_RemoteControl ||
							dd.service_class_id_in_use == A_V_RemoteControlController ||
							dd.service_class_id_in_use == PANU ||
							dd.service_class_id_in_use == _NAP
							)
						{
							if (VALUE.protocols[c].protocol_id == _L2CAP)
								printf("\tPSM: 0x%04X\n", VALUE.protocols[c].pdsp->PSM);

							if (VALUE.protocols[c].protocol_id == _AVDTP ||
								VALUE.protocols[c].protocol_id == _AVCTP ||
								VALUE.protocols[c].protocol_id == _BNEP
								)
								printf("\tVersion: 0x%04X\n", VALUE.protocols[c].pdsp->Version);
						}
					}
				}
			}

			printf("\n");
		}

	} PROTOCOL_DESCRIPTOR_LIST, * PPROTOCOL_DESCRIPTOR_LIST;

	typedef struct SERVICE_NAME_S : DEFAULT_OBJECT
	{
		struct VV : VALUE
		{
			char* service_name;

		} VALUE;

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			printf("*************************************************\n");
			printf("SERVICE NAME: \n");

			printATTR_ELEMENT();

			printVALUE_ELEMENT(v);

			printf("Service name: %s\n", v.service_name);
			printf("\n");
		}

	} SERVICE_NAME, * PSERVICE_NAME;

	typedef struct PROVIDER_NAME_S : DEFAULT_OBJECT
	{
		struct VV : VALUE
		{
			char* provider_name;

		} VALUE;

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			printf("*************************************************\n");
			printf("PROVIDER NAME: \n");
			
			printATTR_ELEMENT();

			printVALUE_ELEMENT(v);

			printf("Provider name: %s\n", v.provider_name);
			printf("\n");
		}

	} PROVIDER_NAME, * PPROVIDER_NAME;

	typedef struct BLUETOOTH_PROFILE_DESCRIPTOR_LIST_S : DEFAULT_OBJECT
	{
		struct VV : VALUE
		{
			/* PROFILES */

			SHORT profile_UUID;
			SHORT profile_version;

			// samo za vec profilov
			//int num_Profiles_list;
			//BLUETOOTH_PROFILE* pProfile_list;
		} VALUE;

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			printf("*************************************************\n");
			printf("BLUETOOTH PROFILE DESCRIPTOR LIST: \n");

			printATTR_ELEMENT();

			printVALUE_ELEMENT(v);

			printf("Profile UUID: 0x%04X\n", VALUE.profile_UUID);
			printf("Profile version: 0x%04X\n", VALUE.profile_version);
			printf("\n");
		}

	} BLUETOOTH_PROFILE_DESCRIPTOR_LIST, * PBLUETOOTH_PROFILE_DESCRIPTOR_LIST;

	typedef struct LANGUAGE_BASE_ATTRIBUTE_ID_LIST_S : DEFAULT_OBJECT
	{
		struct VV : VALUE
		{
			// TODO: naredi ce je teh tripletov vec kot eden (trenutno je narejeno samo za enega)

			SHORT triplet_id_natural_lang;
			SHORT triplet_id_char_encoding;
			SHORT triplet_attribute_id;
		} VALUE;

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			printf("*************************************************\n");
			printf("LANGUAGE ATTRIBUTE ID LIST: \n");
			printATTR_ELEMENT();

			printVALUE_ELEMENT(v);

			printf("Natural language ID: 0x%04X\n", VALUE.triplet_id_natural_lang);
			printf("Character encoding ID: 0x%04X\n", VALUE.triplet_id_char_encoding);
			printf("Attribute ID: 0x%04X\n", VALUE.triplet_attribute_id);
			printf("\n");
		}

	} LANGUAGE_BASE_ATTRIBUTE_ID_LIST, * PLANGUAGE_BASE_ATTRIBUTE_ID_LIST;

	typedef struct SERVICE_DESCRIPTION_S : DEFAULT_OBJECT
	{
		struct VV : VALUE
		{
			char* description;

		} VALUE;

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			printf("*************************************************\n");
			printf("SERVICE DESCRIPTION: \n");

			printATTR_ELEMENT();

			printVALUE_ELEMENT(v);

			printf("Description: %s\n", v.description);
			printf("\n");
		}

	} SERVICE_DESCRIPTION, * PSERVICE_DESCRIPTION;

	typedef struct DEFAULT_EXPORT_S
	{
		PDEFAULT_OBJECT record_handle_export;
		PSERVICE_CLASS_ID_LIST class_id_handle_export;
		PPROTOCOL_DESCRIPTOR_LIST protocol_descriptor_list_handle_export;
		PSERVICE_NAME service_name_handle_export;
		PPROVIDER_NAME provider_name_export;
		PBLUETOOTH_PROFILE_DESCRIPTOR_LIST bluetooth_profile_descriptor_list_handle_export;
		PLANGUAGE_BASE_ATTRIBUTE_ID_LIST language_base_attribute_id_list_export;
		PSERVICE_DESCRIPTION service_description_export;

	} DEFAULT_EXPORT, * PDEFAULT_EXPORT;

};

/************************************************************************/
/* SERVICE SPECIFIC structures */

namespace SDP
{
	namespace MAP
	{

		struct SUPPORTED_FEATURES_MESSAGES_S
		{
			struct SMT_S
			{
				BYTE a0 : 1;
				BYTE a1 : 1;
				BYTE a2 : 1;
				BYTE a3 : 1;
				BYTE a4 : 1;
				BYTE : 3;
			};

			SMT_S* ttt;


			struct SF_S
			{
				BYTE a0 : 1;
				BYTE a1 : 1;
				BYTE a2 : 1;
				BYTE a3 : 1;
				BYTE a4 : 1;
				BYTE a5 : 1;
				BYTE a6 : 1;
				BYTE a7 : 1;
				BYTE a8 : 1;
				BYTE a9 : 1;
				BYTE a10 : 1;
				BYTE a11 : 1;
				BYTE a12 : 1;
				BYTE a13 : 1;
				BYTE a14 : 1;
				BYTE a15 : 1;
				BYTE a16 : 1;
				BYTE a17 : 1;
				BYTE a18 : 1;
				BYTE a19 : 1;
				BYTE a20 : 1;
				BYTE a21 : 1;
				BYTE a22 : 1;
				BYTE : 6;
				BYTE : 3;
			};

			SF_S* aaa;

			// TODO: bolje preimenuj, da bo bolj razumljivo
			int flag;

			SUPPORTED_FEATURES_MESSAGES_S(BYTE* a) : ttt((SMT_S*)a)
			{
				//printf("FROM STRUCT --> %X\n", *a);
				flag = 0;
			};

			SUPPORTED_FEATURES_MESSAGES_S(DWORD* a) : aaa((SF_S*)a)
			{
				//printf("FROM STRUCT --> %X\n", *a);
				flag = 1;
			};


		};


		std::string getMessageTypesString(SUPPORTED_FEATURES_MESSAGES_S* sfm);
		std::string getSupportedFeaturesString(SUPPORTED_FEATURES_MESSAGES_S* sfm);

		typedef struct GOEPL2CAPPSM_S : DEFAULT_OBJECT
		{
			struct VV : VALUE
			{
				SHORT GoepL2CapPsm_value;

			} VALUE;

			template<class T>
			void print(T v, IOCTL_S::DEFAULT_DATA dd)
			{
				printf("*************************************************\n");
				printf("GOEPL2CAPPSM: \n");

				printATTR_ELEMENT();

				printVALUE_ELEMENT(v);

				printf("GoepL2CapPsm value: 0x%04X\n", v.GoepL2CapPsm_value);

				printf("\n");
			}


		} GOEPL2CAPPSM, * PGOEPL2CAPPSM;

		typedef struct SUPPORTED_MESSAGE_TYPES_S : DEFAULT_OBJECT
		{
			struct VV : VALUE
			{
				SUPPORTED_FEATURES_MESSAGES_S* sfm;

			} VALUE;

			template<class T>
			void print(T v, IOCTL_S::DEFAULT_DATA dd)
			{
				printf("*************************************************\n");
				printf("SUPPORTED MESSAGE TYPES: \n");
				
				printATTR_ELEMENT();

				printVALUE_ELEMENT(v);

				printf("Message types: \n%s\n", getMessageTypesString(VALUE.sfm).c_str());

				printf("\n");
			}


		} SUPPORTED_MESSAGE_TYPES, * PSUPPORTED_MESSAGE_TYPES;

		typedef struct MAS_INSTANCE_ID_S : DEFAULT_OBJECT
		{
			struct VV : VALUE
			{
				BYTE instance_ID;

			} VALUE;

			template<class T>
			void print(T v, IOCTL_S::DEFAULT_DATA dd)
			{
				printf("*************************************************\n");
				printf("MAS INSTACE ID: \n");

				printATTR_ELEMENT();

				printVALUE_ELEMENT(v);

				printf("MAS instance ID: 0x%02X\n", v.instance_ID);

				printf("\n");
			}

		} MAS_INSTANCE_ID, * PMAS_INSTANCE_ID;

		typedef struct MAP_SUPPORTED_FEATURES_S : DEFAULT_OBJECT
		{
			struct VV : VALUE
			{
				SUPPORTED_FEATURES_MESSAGES_S* sfm;

			} VALUE;

			template<class T>
			void print(T v, IOCTL_S::DEFAULT_DATA dd)
			{
				printf("*************************************************\n");
				printf("MAP SUPPORTED FEATURES: \n");
				
				printATTR_ELEMENT();

				printVALUE_ELEMENT(v);

				printf("Features: \n%s\n", getSupportedFeaturesString(v.sfm).c_str());
				printf("\n");
			}

		} MAP_SUPPORTED_FEATURES, * PMAP_SUPPORTED_FEATURES;


		typedef struct MAP_EXPORT_S
		{
			PDEFAULT_EXPORT default_export;

			PGOEPL2CAPPSM goepl2cappsm_handle_export;
			PSUPPORTED_MESSAGE_TYPES supported_message_types_handle;
			PMAS_INSTANCE_ID mas_instance_id_handle;
			PMAP_SUPPORTED_FEATURES map_supported_features_handle;

		} MAP_EXPORT, * PMAP_EXPORT;

	}

	namespace A2DP
	{
		struct SUPPORTED_FEATURES_DATA_S
		{
			struct SR_S
			{
				BYTE a0 : 1;
				BYTE a1 : 1;
				BYTE a2 : 1;
				BYTE a3 : 1;
				BYTE : 4;
				BYTE : 8;
				// TODO: naredi se za RFA
			};

			SR_S* repo;

			SUPPORTED_FEATURES_DATA_S(SHORT* a) : repo((SR_S*)a)
			{
				//printf("FROM STRUCT --> %X\n", *a);
			};

			std::string getSupportedFeaturesString()
			{
				std::string temp = "";

				if (repo->a0)
				{
					temp += "Player\n";
				}

				if (repo->a1)
				{
					temp += "Microphone\n";
				}

				if (repo->a2)
				{
					temp += "Tuner\n";
				}

				if (repo->a3)
				{
					temp += "Mixer\n";
				}

				return temp;
			}

		};

		typedef struct SUPPORTED_FEATURES_S : DEFAULT_OBJECT
		{
			struct VV : VALUE
			{
				SHORT supported_features_value;

				SUPPORTED_FEATURES_DATA_S* sfds;

			} VALUE;

			template<class T>
			void print(T v, IOCTL_S::DEFAULT_DATA dd)
			{
				printf("*************************************************\n");
				printf("SUPORTED FEATURES: \n");
				
				printATTR_ELEMENT();

				printVALUE_ELEMENT(v);


				printf("Supported features: 0x%04X\n", v.supported_features_value);
				printf("%s\n", v.sfds->getSupportedFeaturesString().c_str());

			}

		} SUPPORTED_FEATURES, * PSUPPORTED_FEATURES;


		typedef struct A2DP_EXPORT_S
		{
			PDEFAULT_EXPORT default_export;

			PSUPPORTED_FEATURES supported_features_handle_export;

		} A2DP_EXPORT, * PA2DP_EXPORT;

	}

	namespace AVRCP
	{

		struct SUPPORTED_FEATURES_DATA_S
		{
			struct AVRCT_S
			{
				BYTE a0 : 1;
				BYTE a1 : 1;
				BYTE a2 : 1;
				BYTE a3 : 1;
				BYTE a4 : 1;
				BYTE a5 : 1;
				BYTE a6 : 1;
				BYTE a7 : 1;
				BYTE a8 : 1;
				BYTE : 7;
				// TODO: naredi se za RFA
			};

			struct AVRC_AVRCC_S
			{
				BYTE a0 : 1;
				BYTE a1 : 1;
				BYTE a2 : 1;
				BYTE a3 : 1;
				BYTE : 2;
				BYTE a6 : 1;
				BYTE a7 : 1;
				BYTE a8 : 1;
				BYTE a9 : 1;
				BYTE : 6;
			};

			AVRCT_S* avrct;
			AVRC_AVRCC_S* avrc_avrcc;

			SUPPORTED_FEATURES_DATA_S(SHORT* a, int type) //: avrct((AVRCT_S*)a)
			{
				avrct = NULL;
				avrc_avrcc = NULL;

				if (type == 1)
					avrct = (AVRCT_S*)a;
				else
					avrc_avrcc = (AVRC_AVRCC_S*)a;

				//printf("FROM STRUCT --> %X\n", *a);
			};

			std::string getSupportedFeaturesString_AVRC_AVRCC()
			{
				std::string temp = "";

				if (avrc_avrcc->a0)
				{
					temp += "Category 1\n";
				}

				if (avrc_avrcc->a1)
				{
					temp += "Category 2\n";
				}

				if (avrc_avrcc->a2)
				{
					temp += "Category 3\n";
				}

				if (avrc_avrcc->a3)
				{
					temp += "Category 4\n";
				}

				if (avrc_avrcc->a6)
				{
					temp += "Supports browsing\n";
				}

				if (avrc_avrcc->a7)
				{
					temp += "Supports Cover Art GetImageProperties feature\n";
				}

				if (avrc_avrcc->a8)
				{
					temp += " Supports Cover Art GetImage feature\n";
				}

				if (avrc_avrcc->a9)
				{
					temp += "Supports Cover Art GetLinkedThumbnail feature\n";
				}

				return temp;
			}

			std::string getSupportedFeaturesString_AVRCT()
			{
				std::string temp = "";

				if (avrct->a0)
				{
					temp += "Category 1\n";
				}

				if (avrct->a1)
				{
					temp += "Category 2\n";
				}

				if (avrct->a2)
				{
					temp += "Category 3\n";
				}

				if (avrct->a3)
				{
					temp += "Category 4\n";
				}

				if (avrct->a4)
				{
					temp += "Player Application Settings\n";
				}

				if (avrct->a5)
				{
					temp += "Group Navigation\n";
				}

				if (avrct->a6)
				{
					temp += "Supports browsing\n";
				}

				if (avrct->a7)
				{
					temp += "Supports multiple media player applications\n";
				}

				if (avrct->a8)
				{
					temp += "Supports Cover Art\n";
				}

				return temp;
			}

		};

		typedef struct SUPPORTED_FEATURES_S : DEFAULT_OBJECT
		{
			struct VV : VALUE
			{
				SHORT supported_features_value;

				SUPPORTED_FEATURES_DATA_S* sfds;

			} VALUE;

			template<class T>
			void print(T v, IOCTL_S::DEFAULT_DATA dd)
			{
				printf("*************************************************\n");
				printf("SUPPORTED FEATURES: \n");
				
				printATTR_ELEMENT();

				printVALUE_ELEMENT(v);


				printf("Supported features: 0x%04X\n", v.supported_features_value);

				// TODO: premisli kako bi to naredil da se data pravilno izpise
				if (v.sfds->avrct != NULL)
					printf("%s\n", v.sfds->getSupportedFeaturesString_AVRCT().c_str());

				if (v.sfds->avrc_avrcc != NULL)
					printf("%s\n", v.sfds->getSupportedFeaturesString_AVRC_AVRCC().c_str());
			}

		} SUPPORTED_FEATURES, * PSUPPORTED_FEATURES;



		typedef struct AVRCP_EXPORT_S
		{
			PDEFAULT_EXPORT default_export;

			PSUPPORTED_FEATURES supported_features_handle_export;

		} AVRCP_EXPORT, * PAVRCP_EXPORT;

	}

	namespace HFP
	{
		struct SUPPORTED_FEATURES_DATA_S
		{
			struct SR_S
			{
				BYTE a0 : 1;
				BYTE a1 : 1;
				BYTE a2 : 1;
				BYTE a3 : 1;
				BYTE a4 : 1;
				BYTE a5 : 1;
				BYTE a6 : 1;
				BYTE a7 : 1;
				BYTE : 8;

			};

			SR_S* repo;

			SUPPORTED_FEATURES_DATA_S(SHORT* a) : repo((SR_S*)a)
			{
				//printf("FROM STRUCT --> %X\n", *a);
			};

			std::string getSupportedFeatures_AG_String()
			{
				std::string temp = "";

				if (repo->a0)
				{
					temp += "Three-way calling\n";
				}

				if (repo->a1)
				{
					temp += "EC and/or NR function\n";
				}

				if (repo->a2)
				{
					temp += "Voice recognition function\n";
				}

				if (repo->a3)
				{
					temp += "In-band ring tone capability\n";
				}

				if (repo->a4)
				{
					temp += "Attach a phone number to a voice tag\n";
				}

				if (repo->a5)
				{
					temp += "Wide band speech\n";
				}

				if (repo->a6)
				{
					temp += "Enhanced Voice Recognition Status \n";
				}

				if (repo->a7)
				{
					temp += "Voice Recognition Text\n";
				}

				return temp;
			}

			std::string getSupportedFeaturesString()
			{
				std::string temp = "";

				if (repo->a0)
				{
					temp += "EC and/or NR function\n";
				}

				if (repo->a1)
				{
					temp += "Call waiting or three-way calling\n";
				}

				if (repo->a2)
				{
					temp += "CLI presentation capability\n";
				}

				if (repo->a3)
				{
					temp += "Voice recognition activation\n";
				}

				if (repo->a4)
				{
					temp += "Remote volume control\n";
				}

				if (repo->a5)
				{
					temp += "Wide band speech\n";
				}

				if (repo->a6)
				{
					temp += "Enhanced Voice Recognition Status\n";
				}

				if (repo->a7)
				{
					temp += "Voice Recognition Text\n";
				}

				return temp;
			}
		};

		typedef struct NETWORK_S : DEFAULT_OBJECT
		{
			template<class T>
			void print(T v, IOCTL_S::DEFAULT_DATA dd)
			{
				printf("*************************************************\n");
				printf("NETWORK: \n");

				printATTR_ELEMENT();

				printVALUE_ELEMENT(v);

				printf("Network: %s\n", v.value[0] == 0x01 ? "Ability to reject a call" : "No ability to reject a call");
				printf("\n");
			}

		} NETWORK, * PNETWORK;

		typedef struct SUPPORTED_FEATURES_S : DEFAULT_OBJECT
		{
			struct VV : VALUE
			{
				SHORT supported_features_value;

				SUPPORTED_FEATURES_DATA_S* sfds;

			} VALUE;

			template<class T>
			void print(T v, IOCTL_S::DEFAULT_DATA dd)
			{
				printf("*************************************************\n");
				printf("SUPPORTED FEATURES: \n");
				
				printATTR_ELEMENT();

				printVALUE_ELEMENT(v);

				// TODO: naredi da bo tudi za brez AG (trenutno narejeno samo za AG)
				printf("Supported features: 0x%04X\n", v.supported_features_value);
				printf("%s\n", v.sfds->getSupportedFeatures_AG_String().c_str());
				printf("\n");
			}

		} SUPPORTED_FEATURES, * PSUPPORTED_FEATURES;


		typedef struct HFP_EXPORT_S
		{
			PDEFAULT_EXPORT default_export;

			PNETWORK network_handle_export;
			PSUPPORTED_FEATURES supported_features_handle_export;

		} HFP_EXPORT, * PHFP_EXPORT;
	}

	namespace HSP
	{
		typedef struct REMOTE_AUDIO_VOLUME_CONTROL_S : DEFAULT_OBJECT
		{
			template<class T>
			void print(T v, IOCTL_S::DEFAULT_DATA dd)
			{
				printf("*************************************************\n");
				printf("REMOTE AUDIO VOLUME CONTROL: \n");
				
				printATTR_ELEMENT();

				printVALUE_ELEMENT(v);

				// TODO: najdi primer za parsanje
			}

		} REMOTE_AUDIO_VOLUME_CONTROL, * PREMOTE_AUDIO_VOLUME_CONTROL;


		typedef struct HSP_EXPORT_S
		{
			PDEFAULT_EXPORT default_export;

			PREMOTE_AUDIO_VOLUME_CONTROL remote_audio_volume_control_handle_export;

		} HSP_EXPORT, * PHSP_EXPORT;
	}

	namespace NAP
	{
		std::string getSecurityDescriptionString(SHORT type);
		std::string getNetAccessTypeString(SHORT type);

		typedef struct SECURITY_DESCRIPTION_S : DEFAULT_OBJECT
		{
			struct VV : VALUE
			{
				SHORT security_value;
			} VALUE;

			template<class T>
			void print(T v, IOCTL_S::DEFAULT_DATA dd)
			{
				printf("*************************************************\n");
				printf("SECURITY DESCRIPTION: \n");
				
				printATTR_ELEMENT();

				printVALUE_ELEMENT(v);

				printf("Security Description [0x%04X][%s]\n", VALUE.security_value, getSecurityDescriptionString(VALUE.security_value).c_str());
				printf("\n");

			}

		} SECURITY_DESCRIPTION, * PSECURITY_DESCRIPTION;

		typedef struct NET_ACCESS_TYPE_S : DEFAULT_OBJECT
		{
			struct VV : VALUE
			{
				SHORT NetAccessType;
			} VALUE;

			template<class T>
			void print(T v, IOCTL_S::DEFAULT_DATA dd)
			{
				printf("*************************************************\n");
				printf("NET ACCESS TYPE: \n");
				
				printATTR_ELEMENT();

				printVALUE_ELEMENT(v);

				printf("Type of Network Access Available[0x%04X][%s]\n", VALUE.NetAccessType, getNetAccessTypeString(VALUE.NetAccessType).c_str());
				printf("\n");
			}

		} NET_ACCESS_TYPE, * PNET_ACCESS_TYPE;

		typedef struct MAX_NET_ACCESS_RATE_S : DEFAULT_OBJECT
		{
			struct VV : VALUE
			{
				DWORD Maximum_possible_Network_Access_Data_Rate;
			} VALUE;

			template<class T>
			void print(T v, IOCTL_S::DEFAULT_DATA dd)
			{
				printf("*************************************************\n");
				printf("MAX NET ACCESS RATE: \n");
				
				printATTR_ELEMENT();

				printVALUE_ELEMENT(v);

				printf("Maximum possible Network Access Data Rate: 0x%08X\n", VALUE.Maximum_possible_Network_Access_Data_Rate);
				printf("\n");
			}

		} MAX_NET_ACCESS_RATE, * PMAX_NET_ACCESS_RATE;

		typedef struct NAP_EXPORT_S
		{
			PDEFAULT_EXPORT default_export;

			PSECURITY_DESCRIPTION security_description_handle_export;
			PNET_ACCESS_TYPE net_access_type_handle_export;
			PMAX_NET_ACCESS_RATE max_net_access_rate_handle_export;

		} NAP_EXPORT, * PNAP_EXPORT;
	}

	namespace OBEX
	{
		std::string getSupportedFormatsString(BYTE data[], int size);

		typedef struct SERVICE_VERSION_S : DEFAULT_OBJECT
		{

		} SERVICE_VERSION, * PSERVICE_VERSION;

		typedef struct SUPPORTED_FORMATS_S : DEFAULT_OBJECT
		{
			struct VV : VALUE
			{
				int num_of_formats;
				BYTE* formats;

			} VALUE;

			template<class T>
			void print(T v, IOCTL_S::DEFAULT_DATA dd)
			{
				printf("*************************************************\n");
				printf("SUPPORTED FORMATS: \n");
				
				printATTR_ELEMENT();

				printVALUE_ELEMENT(v);

				printf("Number of supported formats: %d\n", v.num_of_formats);

				printf("Supported formats: \n");
				for (int aa = 0; aa < v.num_of_formats; aa++)
					printf("0x%02X ", v.formats[aa]);
				printf("\n");

				printf("Formats: \n%s\n", getSupportedFormatsString(v.formats, v.num_of_formats).c_str());
			}

		} SUPPORTED_FORMATS, * PSUPPORTED_FORMATS;

		typedef struct OBEX_EXPORT_S
		{
			PDEFAULT_EXPORT default_export;

			SDP::MAP::PGOEPL2CAPPSM goepl2cappsm_handle_export;
			PSERVICE_VERSION service_version_handle_export;
			PSUPPORTED_FORMATS supported_formats_handle_export;

		} OBEX_EXPORT, * POBEX_EXPORT;
	}

	namespace PBAP
	{
		struct SUPPORTED_REPOSITORIES_DATA_S
		{
			struct SR_S
			{
				BYTE a0 : 1;
				BYTE a1 : 1;
				BYTE a2 : 1;
				BYTE a3 : 1;
				BYTE : 4;
			};

			SR_S* repo;

			SUPPORTED_REPOSITORIES_DATA_S(BYTE* a) : repo((SR_S*)a)
			{
				//printf("FROM STRUCT --> %X\n", *a);
			};

			std::string getSupportedRepositoriesString()
			{
				std::string temp = "";

				if (repo->a0)
				{
					temp += "Local Phonebook\n";
				}

				if (repo->a1)
				{
					temp += "SIM card\n";
				}

				if (repo->a2)
				{
					temp += "Speed dial\n";
				}

				if (repo->a3)
				{
					temp += "Favorites\n";
				}

				return temp;
			}
		};


		typedef struct SUPPORTED_REPOSITORIES_S : DEFAULT_OBJECT
		{
			struct VV : VALUE
			{
				SUPPORTED_REPOSITORIES_DATA_S* srs;

			} VALUE;

			template<class T>
			void print(T v, IOCTL_S::DEFAULT_DATA dd)
			{
				printf("*************************************************\n");
				printf("SUPPORTED REPOSITORIES: \n");
				
				printATTR_ELEMENT();

				printVALUE_ELEMENT(v);

				printf("Repositories: \n%s\n", v.srs->getSupportedRepositoriesString().c_str());
			}

		} SUPPORTED_REPOSITORIES, * PSUPPORTED_REPOSITORIES;

		typedef struct PBAP_SUPPORTED_FEATURES_S : DEFAULT_OBJECT
		{
			// TODO: print values
			template<class T>
			void print(T v, IOCTL_S::DEFAULT_DATA dd)
			{
				printf("*************************************************\n");
				printf("PBAP SUPPORTED FEATURES: \n");
				
				printATTR_ELEMENT();

				printVALUE_ELEMENT(v);
			}


		} PBAP_SUPPORTED_FEATURES, * PPBAP_SUPPORTED_FEATURES;

		typedef struct PBAP_EXPORT_S
		{
			PDEFAULT_EXPORT default_export;

			SDP::MAP::PGOEPL2CAPPSM goepl2cappsm_handle_export;
			PSUPPORTED_REPOSITORIES supported_repositories_handle_export;
			PPBAP_SUPPORTED_FEATURES pbap_supported_features_handle_export;

		} PBAP_EXPORT, * PPBAP_EXPORT;
	}

	namespace PNPINFO
	{
		typedef struct INFO_S : DEFAULT_OBJECT
		{
			SHORT SpecificationID;
			SHORT VendorID;
			SHORT ProductID;
			SHORT Version;
			BOOL PrimaryRecord;
			SHORT VendorIDSource;

			template<class A>
			void setIDdata(SHORT id, A data)
			{
				switch (id)
				{
				case ATTRIBUTE_ID_DEVICE_SDP::SpecificationID:
					this->SpecificationID = data;
					break;

				case ATTRIBUTE_ID_DEVICE_SDP::VendorID:
					this->VendorID = data;
					break;

				case ATTRIBUTE_ID_DEVICE_SDP::ProductID:
					this->ProductID = data;
					break;

				case ATTRIBUTE_ID_DEVICE_SDP::Version:
					this->Version = data;
					break;

				case ATTRIBUTE_ID_DEVICE_SDP::PrimaryRecord:
					this->PrimaryRecord = data;
					break;

				case ATTRIBUTE_ID_DEVICE_SDP::VendorIDSource:
					this->VendorIDSource = data;
					break;
				}
			}


			template<class T>
			void print(T v, IOCTL_S::DEFAULT_DATA dd)
			{
				printf("*************************************************\n");
				printf("INFO: \n");
				
				printATTR_ELEMENT();

				printVALUE_ELEMENT(v);

				printf("Specification ID: 0x%04X\n", this->SpecificationID);
				printf("Vendor ID: 0x%04X\n", this->VendorID);
				printf("Product ID: 0x%04X\n", this->ProductID);
				printf("Version: 0x%04X\n", this->Version);
				printf("Primary Record: 0x%02X\n", this->PrimaryRecord);
				printf("Vendor ID Source: 0x%04X\n", this->VendorIDSource);
			}

		} INFO, * PINFO;

		typedef struct INFO_EXPORT_S
		{
			PINFO info_handle_export;

		} INFO_EXPORT, * PINFO_EXPORT;
	}

}







