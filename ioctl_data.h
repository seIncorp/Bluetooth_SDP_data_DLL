#pragma once


#ifdef SDP_DATA_EXPORTS
#define SDP_DATA_API __declspec(dllexport)
#else
#define SDP_DATA_API __declspec(dllimport)
#endif


/*
	TODO:
	- BUG: check why app crash when use and call set_all_SDP_service_for_search() with SDPsearch() [FIXED: NOT USING GenericAudio service]
	- ADD: record attribute and not to use default directly
	- ADD: dodaj se za print only one za outside print function (trenutno se vse sprinta)
	- ADD: dodaj se da se klice samo vnaprej dolocene parametere od dolocenega servica

	- ADD: dodaj se za HandsfreeAudioGateway service	<-- DONE!!!
	- ADD: dodaj se za razlikovanje Handsfree in HandsfreeAG izpis featurjev	<-- DONE!!!
	- DO: popravi in uredi izpis PROTOCOL DESCRIPTOR LIST	<-- DONE!!!
	- ADD: dodaj logiko debug, print, itd. za  PNPINFO	<-- DONE!!!
	- IMPROVE: all specific attributes change printing from print all to printall/print one only, same as for default	<-- DONE!!!


*/

/*************************************************/
/*************************************************/
/* DEFINING TEXT FOR PRINTING */
#define DELIMITER_PRINT "************************************************\n"
#define ATTR_NAME_0		"RECORD HANDLE: \n"
#define ATTR_NAME_1		"CLASS ID: \n"
#define ATTR_NAME_2		"PROTOCOL DESCRIPTOR LIST: \n"
#define ATTR_NAME_3		"SERVICE NAME: \n"
#define ATTR_NAME_4		"PROVIDER NAME: \n"
#define ATTR_NAME_5		"BLUETOOTH PROFILE DESCRIPTOR LIST: \n"
#define ATTR_NAME_6		"LANGUAGE ATTRIBUTE ID LIST: \n"
#define ATTR_NAME_7		"SERVICE DESCRIPTION: \n"
#define ATTR_NAME_8		"GOEPL2CAPPSM: \n"
#define ATTR_NAME_9		"SUPORTED FEATURES: \n"
#define ATTR_NAME_10	"SUPPORTED MESSAGE TYPES: \n"
#define ATTR_NAME_11	"MAS INSTACE ID: \n"
#define ATTR_NAME_12	"MAP SUPPORTED FEATURES: \n"
#define ATTR_NAME_13	"NETWORK: \n"
#define ATTR_NAME_14	"REMOTE AUDIO VOLUME CONTROL: \n"
#define ATTR_NAME_15	"SECURITY DESCRIPTION: \n"
#define ATTR_NAME_16	"NET ACCESS TYPE: \n"
#define ATTR_NAME_17	"MAX NET ACCESS RATE: \n"
#define ATTR_NAME_18	"SUPPORTED FORMATS: \n"
#define ATTR_NAME_19	"SUPPORTED REPOSITORIES: \n"
#define ATTR_NAME_20	"PBAP SUPPORTED FEATURES: \n"
#define ATTR_NAME_21	"INFO: \n"



#define VALUE_1			"VALUE ELEMENT:\n"
#define VALUE_2			"ATTRIBUTE ID:\n"
#define VALUE_3			"Type:"
#define VALUE_4			"Size:"
#define VALUE_5			"Value:"
#define VALUE_6			"Additional size:"
#define VALUE_7			"Supported features:"


/*************************************************/
/*************************************************/
/* DEFINING VALUES */

#define MAX_TEMP_STRING_LENGTH	500

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
/* BTH DEVICES */

namespace COD_PARSER
{
	typedef struct
	{
		struct			// 2 byte
		{
			BYTE format_type : 2;			// 0 - 1 bits
			BYTE minor_device_class : 6;	// 2 - 7 bits
			BYTE major_device_class : 5;	// 8 - 12 bits

			// Major Service Classes
			BYTE a0_1 : 1;	// 13 bit
			BYTE a0_2 : 1;	// 14 bit
			BYTE : 1;		// 15 bit

		} octet1_2;

		struct
		{
			BYTE a1 : 1;	// 16 bit
			BYTE a2 : 1;
			BYTE a3 : 1;
			BYTE a4 : 1;
			BYTE a5 : 1;
			BYTE a6 : 1;
			BYTE a7 : 1;
			BYTE a8 : 1;	// 23 bit
		}octet3;

	} COD_data;

	typedef struct DEVICE_PARSED_COD_DATA_S
	{
		std::vector<char*> major_service_class;
		std::vector<char*> major_device_class;
		std::vector<char*> minor_device_class;

		void print()
		{
			printf("\tDEVICE COD data: \n");

			printf("\t\tMajor service class:\n");
			for (int a = 0; a < major_service_class.size(); a++)
				printf("\t\t\t%s\n", major_service_class.at(a));

			printf("\t\tMajor device class:\n");
			for (int a = 0; a < major_device_class.size(); a++)
				printf("\t\t\t%s\n", major_device_class.at(a));

			printf("\t\tMinor device class:\n");
			for (int a = 0; a < minor_device_class.size(); a++)
				printf("\t\t\t%s\n", minor_device_class.at(a));
			printf("\n");
		}


	} DEVICE_PARSED_COD_DATA, * PDEVICE_PARSED_COD_DATA;
};

namespace BTH_DEVICES
{
	typedef struct CACHED_DEVICE_S
	{
	public:
		CACHED_DEVICE_S(char n[BTH_MAX_NAME_SIZE], BYTE add[6], ULONG fl) : flags{ fl }
		{
			strcpy_s(name, BTH_MAX_NAME_SIZE, n);
			for (int a = 0; a < 6; a++)
				address[a] = add[a];
		};

		void print()
		{
			printf("Name: %s\n", name);
			printf("Flags: %lu\n", flags);
			printf("Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
				address[5],
				address[4],
				address[3],
				address[2],
				address[1],
				address[0]);
			printf("\n");

			// TODO: add flag printing
		};

		char* getName()
		{
			return name;
		}

		ULONG getFlags()
		{
			return flags;
		}

		BYTE* getAddress()
		{
			return address;
		}

	private:
		ULONG flags;
		char name[BTH_MAX_NAME_SIZE];
		BYTE address[6];

	} CACHED_DEVICE, * PCACHED_DEVICE;
	
	typedef struct SEARCHED_CACHED_DEVICES_S
	{
		ULONG numOfDevices;
		std::vector<CACHED_DEVICE> devices;

		void print()
		{
			for (auto d : devices)
				d.print();
		}

	} SEARCHED_CACHED_DEVICES, * PSEARCHED_CACHED_DEVICES;



	typedef struct RADIO_DATA_S
	{
		RADIO_DATA_S(ULONGLONG lsf, USHORT m, USHORT ls, UCHAR lv) :
			LMP_SupportedFeatures{ lsf },
			mfg{ m },
			LMP_minor_version{ ls },
			LMP_major_version{ lv }
		{

		};

		void print()
		{
			printf("\tRADIO DATA:\n");
			printf("\t\tLMP version: %d.%d\n", LMP_major_version, LMP_minor_version);
			printf("\t\tLMP Supported Features: %X\n", LMP_SupportedFeatures);
			printf("\t\tID of the manufacturer: %d\n", mfg);
		}


		ULONGLONG LMP_SupportedFeatures;
		USHORT mfg;
		USHORT LMP_minor_version;
		UCHAR LMP_major_version;

	} RADIO_DATA, * PRADIO_DATA;

	typedef struct DEVICE_DATA_S
	{
		void init(BYTE add[6], ULONG f, char n[BTH_MAX_NAME_SIZE])
		{
			address[0] = add[0];
			address[1] = add[1];
			address[2] = add[2];
			address[3] = add[3];
			address[4] = add[4];
			address[5] = add[5];

			flags = f;

			strcpy_s(name, BTH_MAX_NAME_SIZE, n);
		};

		void print()
		{
			printf("\tDEVICE DATA:\n");
			printf("\t\tName: %s\n", name);
			printf("\t\tAddress: %02X:%02X:%02X:%02X:%02X:%02X\n",
				address[5],
				address[4],
				address[3],
				address[2],
				address[1],
				address[0]);
			printf("\t\tflags: %lu\n", flags);

			cod->print();
		}

		CHAR name[BTH_MAX_NAME_SIZE];
		BYTE address[6];
		ULONG flags;
		COD_PARSER::PDEVICE_PARSED_COD_DATA cod;

	} DEVICE_DATA, * PDEVICE_DATA;

	typedef struct LOCAL_RADIO_DEVICE_DATA_S
	{
		LOCAL_RADIO_DEVICE_DATA_S(
			ULONG flags,
			USHORT hciRevision,
			UCHAR hciVersion)
			:
			flags_{ flags },
			HCI_minor_version_{ hciRevision },
			HCI_major_version_{ hciVersion }
		{

		};

		void print()
		{
			printf("LOCAL DEVICE and RADIO DATA:\n");
			printf("\tFlags: %X\n", flags_);
			printf("\tVersion: %lu.%lu (Major.Minor version HCI)\n",
				HCI_major_version_,
				HCI_minor_version_
			);
			device->print();
			radio->print();
		}

		ULONG flags_;
		USHORT HCI_minor_version_;
		UCHAR HCI_major_version_;

		PDEVICE_DATA device;
		PRADIO_DATA radio;

	} LOCAL_RADIO_DEVICE_DATA, * PLOCAL_RADIO_DEVICE_DATA;

	typedef struct CONNECTED_DEVICE_DATA_S
	{
		PRADIO_DATA radio;


		void print()
		{
			radio->print();
		};

	} CONNECTED_DEVICE_DATA, * PCONNECTED_DEVICE_DATA;

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

		struct ATTRIBUTES_SEARCH_FOR_SERVICE
		{
			int all;

			/* DEFAULT ATTR. */
			int ServiceRecord;
			int ServiceClassIDList;
			int ProtocolDescriptorList;
			int ServiceName;
			int BluetoothProfileDescriptorList;
			int ProviderName;
			int LanguageBaseAttributeIdList;
			int ServiceDescription;

			/***********************************************/
			/* SPECIAL ATTR. */

			/* PNPINFO */
			struct att_search_PNPINFO
			{
				int PnpInfo;
			};
			att_search_PNPINFO att_PNPINFO;

			/* PBAP */
			struct att_search_PBAP
			{
				int Goepl2cappsm;
				int SupportedRepositories;
				int SupportedFeatures;
			};
			att_search_PBAP att_PBAP;
			
			/* OBEX */
			struct att_search_OBEX
			{
				int Goepl2cappsm;
				int SupportedFormats;
				int ServiceVersion;
			};
			att_search_OBEX att_OBEX;
			
			/* NAP */
			int SecurityDescription;
			int NetAccessType;
			int MaxNetAccessRate;
			
			/* HSP */
			int RemoteAudioVolumeControl;
			
			/* HFP */
			int Network;
			
			/* AVRCP */
			struct att_search_AVRCP
			{
				int SupportedFeatures;
			};
			att_search_AVRCP att_AVRCP;
			
			/* A2DP */
			
			/* MAP */
			int SupportedMessageTypes;
			int MasInstanceId;
			int MapSupportedFeatures;
		};

		struct SDP_exported_data
		{
			// SDP services
			BYTE* default_export;
			BYTE* a2dp_export;
			BYTE* avrcp_export;
			BYTE* hfp_export;
			BYTE* hsp_export;
			BYTE* map_export;
			BYTE* nap_export;
			BYTE* obex_export;
			BYTE* pbap_export;
			BYTE* pnpinfo_export;

			// cached bluetooth devices
			BTH_DEVICES::SEARCHED_CACHED_DEVICES_S* devices;

			// local radio data
			BTH_DEVICES::LOCAL_RADIO_DEVICE_DATA_S* local_device_radio;
		};

		struct SDP_settings
		{
			int debug;
			int print;
			int print_info;
			int print_with_outside_funct;

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

				/***********************************************/
				/* SPECIAL ATTR. */
				
				/* PNPINFO */
				struct print_PNPINFO
				{
					int print_pnp_info;
				};
				print_PNPINFO print_PNPINFO_attributes;

				/* PBAP */
				struct print_PBAP
				{
					int print_goepl2cappsm;
					int print_supported_repositories;
					int print_pbap_supported_features;
				};
				print_PBAP print_PBAP_attributes;

				/* OBEX */
				struct print_OBEX
				{
					int print_goepl2cappsm;
					int print_supported_formats;
					int print_service_version;
				};
				print_OBEX print_OBEX_attributes;

				/* NAP */
				struct print_NAP
				{
					int print_security_description;
					int print_net_access_type;
					int print_max_net_access_rate;
				};
				print_NAP print_NAP_attributes;

				/* HSP */
				struct print_HSP
				{
					int print_remote_audio_volume_control;
				};
				print_HSP print_HSP_attributes;

				/* HFP */
				struct print_HFP
				{
					int print_network;
					int print_supported_features;
				};
				print_HFP print_HFP_attributes;

				/* AVRCP */
				struct print_AVRCP
				{
					int print_supported_features;
				};
				print_AVRCP print_AVRCP_attributes;

				/* A2DP */
				struct print_A2DP
				{
					int print_supported_features;
				};
				print_A2DP print_A2DP_attributes;

				/* MAP */
				struct print_MAP
				{
					int print_goepl2cappsm;
					int print_supported_message_types;
					int print_mas_instance_id;
					int print_map_supported_features;
				};
				print_MAP print_MAP_attributes;

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
		ATTRIBUTES_SEARCH_FOR_SERVICE attr_search_for_service;

		void reset_SDP_service_for_search();
		void set_all_SDP_service_for_search();


		// currently only for x64, does not work for x86
		// pointer to outside print function
		void (*outside_print_function) (std::string text, ...);
		BYTE* data_outside_print_function;

		SHORT temp_class_id;	//only for AVRCP!!!!
		SHORT temp_service;		// only for HFP!!!!

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
	SDP_DATA_API void getLocalBthInfo(DEFAULT_DATA* dd, int print = 1);

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
		SHORT avrcp_class_id;	// only for AVRCP service

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

		void printATTR_ELEMENT(IOCTL_S::DEFAULT_DATA dd)
		{
			if (dd.outside_print_function != NULL && dd.sdp_settings.print_with_outside_funct == 1)
			{
				dd.outside_print_function(VALUE_2);

				char test[100]{ 0 };
				sprintf_s(test, "%s %s [%d]\n", VALUE_3, SDP::SUB_FUNCTIONS::getElementTypeString(attr_id->element->element.type).c_str(), attr_id->element->element.type);
				dd.outside_print_function(test);

				if (attr_id->additional_bits_flag)
				{
					sprintf_s(test, "%s %d\n", VALUE_6, attr_id->additional_bits_for_size);
					dd.outside_print_function(test);
				}
				else
				{
					sprintf_s(test, "%s %d Bytes [%d]\n", VALUE_4, attr_id->size_bytes, attr_id->size_bytes);
					dd.outside_print_function(test);

					sprintf_s(test, "%s ", VALUE_5);
					for (int a = 0; a < attr_id->size_bytes; a++)
						sprintf_s(test, "%s0x%02X ", test, attr_id->value[a]);
					
					sprintf_s(test, "%s\n", test);
					dd.outside_print_function(test);
				}
			}
			else
			{
				printf(VALUE_2);
				printf("%s %s [%d]\n", VALUE_3, SDP::SUB_FUNCTIONS::getElementTypeString(attr_id->element->element.type).c_str(), attr_id->element->element.type);

				if (attr_id->additional_bits_flag)
				{
					printf("%s %d\n", VALUE_6, attr_id->additional_bits_for_size);
				}
				else
				{
					printf("%s %d Bytes [%d]\n", VALUE_4, attr_id->size_bytes, attr_id->size_bytes);

					printf("%s 0x", VALUE_5);
					for (int a = 0; a < attr_id->size_bytes; a++)
						printf("%02X", attr_id->value[a]);
					printf("\n");
				}

			}
		}

		template<class T>
		void printVALUE_ELEMENT(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			if (dd.outside_print_function != NULL && dd.sdp_settings.print_with_outside_funct == 1)
			{
				dd.outside_print_function(VALUE_1);

				char test[MAX_TEMP_STRING_LENGTH]{ 0 };

				sprintf_s(test, "%s %s [%d]\n", VALUE_3, SDP::SUB_FUNCTIONS::getElementTypeString(v.element->element.type).c_str(), v.element->element.type);
				dd.outside_print_function(test);

				if (v.additional_bits_flag)
				{
					sprintf_s(test, "%s %d\n", VALUE_6, v.additional_bits_for_size);
					dd.outside_print_function(test);

					if (v.additional_bits_for_size == 1)
					{
						sprintf_s(test, "Data size: %d\n", v.size_bytes);
						dd.outside_print_function(test);

						sprintf_s(test, "%s ", VALUE_5);

						for (int a = 0; a < v.size_bytes; a++)
							sprintf_s(test, "%s0x%02X ", test, v.value[a]);

						sprintf_s(test, "%s\n", test);
						dd.outside_print_function(test);
					}
				}
				else
				{
					sprintf_s(test, "%s %d Bytes [%d]\n", VALUE_4, v.size_bytes, v.size_bytes);
					dd.outside_print_function(test);

					sprintf_s(test, "%s ", VALUE_5);
					for (int a = 0; a < v.size_bytes; a++)
						sprintf_s(test, "%s0x%02X ",test, v.value[a]);

					sprintf_s(test, "%s\n",test);
					dd.outside_print_function(test);
				}
			}
			else
			{
				printf(VALUE_1);
				printf("%s %s [%d]\n", VALUE_3, SDP::SUB_FUNCTIONS::getElementTypeString(v.element->element.type).c_str(), v.element->element.type);

				if (v.additional_bits_flag)
				{
					printf("%s %d\n", VALUE_6, v.additional_bits_for_size);
					if (v.additional_bits_for_size == 1)
					{
						printf("Data size: %d\n", v.size_bytes);

						printf("%s ", VALUE_5);
						for (int a = 0; a < v.size_bytes; a++)
							printf("0x%02X ", v.value[a]);
						printf("\n");
					}
				}
				else
				{
					printf("%s %d Bytes [%d]\n", VALUE_4, v.size_bytes, v.size_bytes);

					printf("%s 0x", VALUE_5);
					for (int a = 0; a < v.size_bytes; a++)
						printf("%02X", v.value[a]);
					printf("\n");
				}
			}
		}

		template<class T>
		void print(T v, IOCTL_S::DEFAULT_DATA dd)
		{
			if (dd.outside_print_function != NULL && dd.sdp_settings.print_with_outside_funct == 1)
			{
				dd.outside_print_function(DELIMITER_PRINT);
				dd.outside_print_function(ATTR_NAME_0);

				printATTR_ELEMENT(dd);

				printVALUE_ELEMENT(v, dd);


				char test[100]{ 0 };
				DWORD temp = 0x00;

				temp |= v.value[0];
				temp <<= 8;
				temp |= v.value[1];
				temp <<= 8;
				temp |= v.value[2];
				temp <<= 8;
				temp |= v.value[3];
				sprintf_s(test, "Record handle: 0x%08X\n", temp);
				dd.outside_print_function(test);
			}
			else
			{
				printf(DELIMITER_PRINT);
				printf(ATTR_NAME_0);
				printATTR_ELEMENT(dd);

				printVALUE_ELEMENT(v, dd);

				printf("\n");
			}
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
			if (dd.outside_print_function != NULL && dd.sdp_settings.print_with_outside_funct == 1)
			{
				dd.outside_print_function(DELIMITER_PRINT);
				dd.outside_print_function(ATTR_NAME_1);

				printATTR_ELEMENT(dd);
				printVALUE_ELEMENT(v, dd);

				char test[MAX_TEMP_STRING_LENGTH]{ 0 };
				for (int a = 0; a < VALUE.num_classes; a++)
					sprintf_s(test, "%sClass ID [%d]: 0x%04X\n", test, a, VALUE.classes[a].value);
				dd.outside_print_function(test);
			}
			else
			{

				printf(DELIMITER_PRINT);
				printf(ATTR_NAME_1);

				printATTR_ELEMENT(dd);
				printVALUE_ELEMENT(v, dd);

				// TODO: naredi tako da se bodo kreirali objekt za vsak class posebej, ker jih je v prihodnosti lahko vec

				for (int a = 0; a < VALUE.num_classes; a++)
					printf("Class ID [%d]: 0x%04X\n", a, VALUE.classes[a].value);

				printf("\n");
			}
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
			if (dd.outside_print_function != NULL && dd.sdp_settings.print_with_outside_funct == 1)
			{
				dd.outside_print_function(DELIMITER_PRINT);
				dd.outside_print_function(ATTR_NAME_2);

				printATTR_ELEMENT(dd);
				printVALUE_ELEMENT(v, dd);

				char test[MAX_TEMP_STRING_LENGTH]{ 0 };

				for (int c = 0; c < VALUE.num_protocols; c++)
				{
					if (VALUE._BNEP_flag == 1 && c < (VALUE.num_protocols - 1))
					{
						/* za vse protokole ki so BNEP  */
						sprintf_s(test, "Protocol [%d]:\n", c);
						dd.outside_print_function(test);

						sprintf_s(test, "\tValue: ");
						for (int d = 0; d < VALUE.protocols[c].additional_bits_for_size; d++)
							sprintf_s(test, "%s0x%X ", test, VALUE.protocols[c].value[d]);
						dd.outside_print_function(test);
						sprintf_s(test, "\n");
						dd.outside_print_function(test);

						sprintf_s(test, "\tID [0x%04X][%s]\n", VALUE.protocols[c].protocol_id, SUB_FUNCTIONS::getProtocolTypeString(VALUE.protocols[c].protocol_id).c_str());
						dd.outside_print_function(test);
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
							{
								sprintf_s(test, "\tChannel number: %d\n", VALUE.protocols[c].pdsp->server_channel_num);
								dd.outside_print_function(test);
							}

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
								{
									sprintf_s(test, "\tPSM: 0x%04X\n", VALUE.protocols[c].pdsp->PSM);
									dd.outside_print_function(test);
								}

								if (VALUE.protocols[c].protocol_id == _AVDTP ||
									VALUE.protocols[c].protocol_id == _AVCTP ||
									VALUE.protocols[c].protocol_id == _BNEP
									)
								{
									sprintf_s(test, "\tVersion: 0x%04X\n", VALUE.protocols[c].pdsp->Version);
									dd.outside_print_function(test);
								}

								if (VALUE.protocols[c].protocol_id == _BNEP)
								{
									sprintf_s(test, "\tNumber of supported network packet type: %d\n", VALUE.protocols[c].pdsp->num_of_Supported_Network_Packet_Type_List_PANU);
									dd.outside_print_function(test);

									for (int aaa = 0; aaa < VALUE.protocols[c].pdsp->num_of_Supported_Network_Packet_Type_List_PANU; aaa++)
									{
										sprintf_s(test, "\tnetwork packet type [0x%04X][%s]\n", VALUE.protocols[c].pdsp->Supported_Network_Packet_Type_List[aaa], SUB_FUNCTIONS::getNetworkPacketTypeString(VALUE.protocols[c].pdsp->Supported_Network_Packet_Type_List[aaa]).c_str());
										dd.outside_print_function(test);
									}
								}

							}
						}
					}
					else if (VALUE._BNEP_flag != 1)
					{
						/* za vse protokole ki niso BNEP */
						sprintf_s(test, "Protocol [%d]:\n", c);
						dd.outside_print_function(test);

						sprintf_s(test, "\tValue: ");
						for (int d = 0; d < VALUE.protocols[c].additional_bits_for_size; d++)
							sprintf_s(test, "%s0x%X ", test, VALUE.protocols[c].value[d]);
						sprintf_s(test, "%s\n",test);
						dd.outside_print_function(test);

						sprintf_s(test, "\tID [0x%04X][%s]\n", VALUE.protocols[c].protocol_id, SUB_FUNCTIONS::getProtocolTypeString(VALUE.protocols[c].protocol_id).c_str());
						dd.outside_print_function(test);
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
							{
								sprintf_s(test, "\tChannel number: %d\n", VALUE.protocols[c].pdsp->server_channel_num);
								dd.outside_print_function(test);
							}

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
								{
									sprintf_s(test, "\tPSM: 0x%04X\n", VALUE.protocols[c].pdsp->PSM);
									dd.outside_print_function(test);
								}

								if (VALUE.protocols[c].protocol_id == _AVDTP ||
									VALUE.protocols[c].protocol_id == _AVCTP ||
									VALUE.protocols[c].protocol_id == _BNEP
									)
								{
									sprintf_s(test, "\tVersion: 0x % 04X\n", VALUE.protocols[c].pdsp->Version);
									dd.outside_print_function(test);
								}
							}
						}
					}
				}

				printf("\n");

			}
			else
			{
				printf(DELIMITER_PRINT);
				printf(ATTR_NAME_2);

				printATTR_ELEMENT(dd);
				printVALUE_ELEMENT(v, dd);

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
			if (dd.outside_print_function != NULL && dd.sdp_settings.print_with_outside_funct == 1)
			{
				dd.outside_print_function(DELIMITER_PRINT);
				dd.outside_print_function(ATTR_NAME_3);

				printATTR_ELEMENT(dd);
				printVALUE_ELEMENT(v, dd);

				char test[MAX_TEMP_STRING_LENGTH]{ 0 };
				sprintf_s(test, "Service name: %s\n", v.service_name);
				dd.outside_print_function(test);
			}
			else
			{
				printf(DELIMITER_PRINT);
				printf(ATTR_NAME_3);

				printATTR_ELEMENT(dd);
				printVALUE_ELEMENT(v, dd);

				printf("Service name: %s\n", v.service_name);
				printf("\n");
			}
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
			if (dd.outside_print_function != NULL && dd.sdp_settings.print_with_outside_funct == 1)
			{
				dd.outside_print_function(DELIMITER_PRINT);
				dd.outside_print_function(ATTR_NAME_4);

				printATTR_ELEMENT(dd);
				printVALUE_ELEMENT(v, dd);

				char test[MAX_TEMP_STRING_LENGTH]{ 0 };
				sprintf_s(test, "Provider name: %s\n", v.provider_name);
				dd.outside_print_function(test);
			}
			else
			{
				printf(DELIMITER_PRINT);
				printf(ATTR_NAME_4);

				printATTR_ELEMENT(dd);
				printVALUE_ELEMENT(v, dd);

				printf("Provider name: %s\n", v.provider_name);
				printf("\n");
			}
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
			if (dd.outside_print_function != NULL && dd.sdp_settings.print_with_outside_funct == 1)
			{
				dd.outside_print_function(DELIMITER_PRINT);
				dd.outside_print_function(ATTR_NAME_5);

				printATTR_ELEMENT(dd);
				printVALUE_ELEMENT(v, dd);

				char test[MAX_TEMP_STRING_LENGTH]{ 0 };
				sprintf_s(test, "Profile UUID: 0x%04X\n", VALUE.profile_UUID);
				dd.outside_print_function(test);
				sprintf_s(test, "Profile version: 0x%04X\n", VALUE.profile_version);
				dd.outside_print_function(test);
			}
			else
			{
				printf(DELIMITER_PRINT);
				printf(ATTR_NAME_5);

				printATTR_ELEMENT(dd);
				printVALUE_ELEMENT(v, dd);

				printf("Profile UUID: 0x%04X\n", VALUE.profile_UUID);
				printf("Profile version: 0x%04X\n", VALUE.profile_version);
				printf("\n");
			}
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
			if (dd.outside_print_function != NULL && dd.sdp_settings.print_with_outside_funct == 1)
			{
				dd.outside_print_function(DELIMITER_PRINT);
				dd.outside_print_function(ATTR_NAME_6);

				printATTR_ELEMENT(dd);
				printVALUE_ELEMENT(v, dd);

				char test[MAX_TEMP_STRING_LENGTH]{ 0 };
				sprintf_s(test, "Natural language ID: 0x%04X\n", VALUE.triplet_id_natural_lang);
				dd.outside_print_function(test);
				sprintf_s(test, "Character encoding ID: 0x%04X\n", VALUE.triplet_id_char_encoding);
				dd.outside_print_function(test);
				sprintf_s(test, "Attribute ID: 0x%04X\n", VALUE.triplet_attribute_id);
				dd.outside_print_function(test);

			}
			else
			{
				printf(DELIMITER_PRINT);
				printf(ATTR_NAME_6);

				printATTR_ELEMENT(dd);
				printVALUE_ELEMENT(v, dd);

				printf("Natural language ID: 0x%04X\n", VALUE.triplet_id_natural_lang);
				printf("Character encoding ID: 0x%04X\n", VALUE.triplet_id_char_encoding);
				printf("Attribute ID: 0x%04X\n", VALUE.triplet_attribute_id);
				printf("\n");
			}
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
			if (dd.outside_print_function != NULL && dd.sdp_settings.print_with_outside_funct == 1)
			{
				dd.outside_print_function(DELIMITER_PRINT);
				dd.outside_print_function(ATTR_NAME_7);

				printATTR_ELEMENT(dd);
				printVALUE_ELEMENT(v, dd);

				char test[MAX_TEMP_STRING_LENGTH]{ 0 };
				sprintf_s(test, "Description: %s\n", v.description);
				dd.outside_print_function(test);
			}
			else
			{
				printf(DELIMITER_PRINT);
				printf(ATTR_NAME_7);

				printATTR_ELEMENT(dd);
				printVALUE_ELEMENT(v, dd);

				printf("Description: %s\n", v.description);
				printf("\n");
			}
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
			DWORD sf_s_value;
			BYTE smt_s_value;

			SUPPORTED_FEATURES_MESSAGES_S(int i, DWORD a1, BYTE a2)
			{
				if (i == 1)
				{
					sf_s_value = a1;

					aaa = (SF_S*)&sf_s_value;
				}
				else
				{
					smt_s_value = a2;
					ttt = (SMT_S*)&smt_s_value;
				}
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
				if (dd.outside_print_function != NULL && dd.sdp_settings.print_with_outside_funct == 1)
				{
					dd.outside_print_function(DELIMITER_PRINT);
					dd.outside_print_function(ATTR_NAME_8);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);

					char test[MAX_TEMP_STRING_LENGTH]{ 0 };
					sprintf_s(test, "GoepL2CapPsm value: 0x%04X\n", v.GoepL2CapPsm_value);
					dd.outside_print_function(test);
				}
				else
				{
					printf(DELIMITER_PRINT);
					printf(ATTR_NAME_8);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);

					printf("GoepL2CapPsm value: 0x%04X\n", v.GoepL2CapPsm_value);

					printf("\n");
				}
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
				if (dd.outside_print_function != NULL && dd.sdp_settings.print_with_outside_funct == 1)
				{
					dd.outside_print_function(DELIMITER_PRINT);
					dd.outside_print_function(ATTR_NAME_10);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);

					std::string temp_s = "Message types: \n";
					temp_s.append(getMessageTypesString(VALUE.sfm));
					temp_s.append("\n");
					dd.outside_print_function(temp_s);
				}
				else
				{
					printf(DELIMITER_PRINT);
					printf(ATTR_NAME_10);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);

					printf("Message types: \n%s\n", getMessageTypesString(VALUE.sfm).c_str());

					printf("\n");
				}
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
				if (dd.outside_print_function != NULL && dd.sdp_settings.print_with_outside_funct == 1)
				{
					dd.outside_print_function(DELIMITER_PRINT);
					dd.outside_print_function(ATTR_NAME_11);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);

					char test[MAX_TEMP_STRING_LENGTH]{ 0 };
					sprintf_s(test, "MAS instance ID: 0x%02X\n", v.instance_ID);
					dd.outside_print_function(test);
				}
				else
				{
					printf(DELIMITER_PRINT);
					printf(ATTR_NAME_11);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);

					printf("MAS instance ID: 0x%02X\n", v.instance_ID);

					printf("\n");
				}
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
				if (dd.outside_print_function != NULL && dd.sdp_settings.print_with_outside_funct == 1)
				{
					dd.outside_print_function(DELIMITER_PRINT);
					dd.outside_print_function(ATTR_NAME_12);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);

					std::string temp_s = "Features: \n";
					temp_s.append(getSupportedFeaturesString(v.sfm));
					temp_s.append("\n");
					dd.outside_print_function(temp_s);
				}
				else
				{
					printf(DELIMITER_PRINT);
					printf(ATTR_NAME_12);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);

					printf("Features: \n%s\n", getSupportedFeaturesString(v.sfm).c_str());
					printf("\n");
				}
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
				if (dd.outside_print_function != NULL && dd.sdp_settings.print_with_outside_funct == 1)
				{
					dd.outside_print_function(DELIMITER_PRINT);
					dd.outside_print_function(ATTR_NAME_9);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);


					char test[100]{ 0 };
					sprintf_s(test, "%s 0x%04X\n", VALUE_7, v.supported_features_value);
					dd.outside_print_function(test);

					sprintf_s(test, "%s\n", v.sfds->getSupportedFeaturesString().c_str());
					dd.outside_print_function(test);
				}
				else
				{
					printf(DELIMITER_PRINT);
					printf(ATTR_NAME_9);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);


					printf("%s 0x%04X\n", VALUE_7, v.supported_features_value);
					printf("%s\n", v.sfds->getSupportedFeaturesString().c_str());
				}
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

			SUPPORTED_FEATURES_DATA_S(SHORT* a, int type)
			{
				avrct = NULL;
				avrc_avrcc = NULL;

				if (type == 1)
				{
					avrct = (AVRCT_S*)a;
				}
				else
				{
					avrc_avrcc = (AVRC_AVRCC_S*)a;
				}
			};

			std::string getSupportedFeaturesString_AVRC_AVRCC()
			{
				std::string temp = "";

				if (avrc_avrcc->a0)
				{
					temp.append("Category 1\n");
				}

				if (avrc_avrcc->a1)
				{
					temp.append("Category 2\n");
				}

				if (avrc_avrcc->a2)
				{
					temp.append("Category 3\n");
				}

				if (avrc_avrcc->a3)
				{
					temp.append("Category 4\n");
				}

				if (avrc_avrcc->a6)
				{
					temp.append("Supports browsing\n");
				}

				if (avrc_avrcc->a7)
				{
					temp.append("Supports Cover Art GetImageProperties feature\n");
				}

				if (avrc_avrcc->a8)
				{
					temp.append("Supports Cover Art GetImage feature\n");
				}

				if (avrc_avrcc->a9)
				{
					temp.append("Supports Cover Art GetLinkedThumbnail feature\n");
				}

				return temp;
			}

			std::string getSupportedFeaturesString_AVRCT()
			{
				std::string temp = "";

				if (avrct->a0)
				{
					temp.append("Category 1\n");
				}

				if (avrct->a1)
				{
					temp.append("Category 2\n");
				}

				if (avrct->a2)
				{
					temp.append("Category 3\n");
				}

				if (avrct->a3)
				{
					temp.append("Category 4\n");
				}

				if (avrct->a4)
				{
					temp.append("Player Application Settings\n");
				}

				if (avrct->a5)
				{
					temp.append("Group Navigation\n");
				}

				if (avrct->a6)
				{
					temp.append("Supports browsing\n");
				}

				if (avrct->a7)
				{
					temp.append("Supports multiple media player applications\n");
				}

				if (avrct->a8)
				{
					temp.append("Supports Cover Art\n");
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
				if (dd.outside_print_function != NULL && dd.sdp_settings.print_with_outside_funct == 1)
				{
					dd.outside_print_function(DELIMITER_PRINT);
					dd.outside_print_function(ATTR_NAME_9);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);

					char test[MAX_TEMP_STRING_LENGTH]{ 0 };
					sprintf_s(test, "%s 0x%04X\n", VALUE_7, v.supported_features_value);
					dd.outside_print_function(test);

					// TODO: najdi boljso resitev, ker se pri klicu printVALUE_ELEMENT() value spremeni na random
					v.sfds->avrct = (SUPPORTED_FEATURES_DATA_S::AVRCT_S*)&v.supported_features_value;

					if (dd.temp_class_id == SDP::A_V_RemoteControlTarget)
					{
						sprintf_s(test, "%s\n", v.sfds->getSupportedFeaturesString_AVRCT().c_str());
						dd.outside_print_function(test);
					}

					if (dd.temp_class_id == SDP::A_V_RemoteControl ||
						dd.temp_class_id == SDP::A_V_RemoteControlController
					)
					{
						sprintf_s(test, "%s\n", v.sfds->getSupportedFeaturesString_AVRC_AVRCC().c_str());
						dd.outside_print_function(test);
					}
				}
				else
				{
					printf(DELIMITER_PRINT);
					printf(ATTR_NAME_9);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);

					printf("%s 0x%04X\n", VALUE_7, v.supported_features_value);

					// TODO: najdi boljso resitev, ker se pri klicu printVALUE_ELEMENT() value spremeni na random
					v.sfds->avrct = (SUPPORTED_FEATURES_DATA_S::AVRCT_S*)&v.supported_features_value;

					if (dd.temp_class_id == SDP::A_V_RemoteControlTarget)
						printf("%s\n", v.sfds->getSupportedFeaturesString_AVRCT().c_str());

					if (dd.temp_class_id == SDP::A_V_RemoteControl ||
						dd.temp_class_id == SDP::A_V_RemoteControlController
						)
						printf("%s\n", v.sfds->getSupportedFeaturesString_AVRC_AVRCC().c_str());
				}
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

			SHORT temp_data;

			SUPPORTED_FEATURES_DATA_S(SHORT a)
			{
				temp_data = a;
				repo = (SR_S*)&temp_data;
			};

			std::string getSupportedFeatures_AG_String()
			{
				std::string temp = "";

				if (repo->a0)
				{
					temp.append("Three-way calling\n");
				}

				if (repo->a1)
				{
					temp.append("EC and/or NR function\n");
				}

				if (repo->a2)
				{
					temp.append("Voice recognition function\n");
				}

				if (repo->a3)
				{
					temp.append("In-band ring tone capability\n");
				}

				if (repo->a4)
				{
					temp.append("Attach a phone number to a voice tag\n");
				}

				if (repo->a5)
				{
					temp.append("Wide band speech\n");
				}

				if (repo->a6)
				{
					temp.append("Enhanced Voice Recognition Status \n");
				}

				if (repo->a7)
				{
					temp.append("Voice Recognition Text\n");
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
				if (dd.outside_print_function != NULL && dd.sdp_settings.print_with_outside_funct == 1)
				{
					dd.outside_print_function(DELIMITER_PRINT);
					dd.outside_print_function(ATTR_NAME_13);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);

					char test[MAX_TEMP_STRING_LENGTH]{ 0 };
					sprintf_s(test, "Network: %s\n", v.value[0] == 0x01 ? "Ability to reject a call" : "No ability to reject a call");
					dd.outside_print_function(test);

					//printf("Network: %s\n", v.value[0] == 0x01 ? "Ability to reject a call" : "No ability to reject a call");
					sprintf_s(test, "\n");
					dd.outside_print_function(test);
					//printf("\n");
				}
				else
				{
					printf(DELIMITER_PRINT);
					printf(ATTR_NAME_13);

					printATTR_ELEMENT(dd);

					printVALUE_ELEMENT(v, dd);

					printf("Network: %s\n", v.value[0] == 0x01 ? "Ability to reject a call" : "No ability to reject a call");
					printf("\n");
				}
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
				
				
				if (dd.outside_print_function != NULL && dd.sdp_settings.print_with_outside_funct == 1)
				{
					dd.outside_print_function(DELIMITER_PRINT);
					dd.outside_print_function(ATTR_NAME_9);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);

					char test[MAX_TEMP_STRING_LENGTH]{ 0 };
					sprintf_s(test, "Supported features: 0x%04X\n", v.supported_features_value);
					dd.outside_print_function(test);

					if (dd.temp_service == SDP::HandsfreeAudioGateway)
					{
						sprintf_s(test, "%s\n", v.sfds->getSupportedFeatures_AG_String().c_str());
						dd.outside_print_function(test);
					}
					else
					{
						sprintf_s(test, "%s\n", v.sfds->getSupportedFeaturesString().c_str());
						dd.outside_print_function(test);
					}
				}
				else
				{
					printf(DELIMITER_PRINT);
					printf(ATTR_NAME_9);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);

					printf("Supported features: 0x%04X\n", v.supported_features_value);

					if (dd.temp_service == SDP::HandsfreeAudioGateway)
						printf("%s\n", v.sfds->getSupportedFeatures_AG_String().c_str());
					else
						printf("%s\n", v.sfds->getSupportedFeaturesString().c_str());
					
					printf("\n");
				}
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
				if (dd.outside_print_function != NULL && dd.sdp_settings.print_with_outside_funct == 1)
				{
					dd.outside_print_function(DELIMITER_PRINT);
					dd.outside_print_function(ATTR_NAME_14);

					printATTR_ELEMENT(dd);

					printVALUE_ELEMENT(v, dd);
				}
				else
				{
					printf(DELIMITER_PRINT);
					printf(ATTR_NAME_14);

					printATTR_ELEMENT(dd);

					printVALUE_ELEMENT(v, dd);
				}
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
				if (dd.outside_print_function != NULL && dd.sdp_settings.print_with_outside_funct == 1)
				{
					dd.outside_print_function(DELIMITER_PRINT);
					dd.outside_print_function(ATTR_NAME_15);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);

					char test[MAX_TEMP_STRING_LENGTH]{ 0 };
					sprintf_s(test, "Security Description [0x%04X][%s]\n", VALUE.security_value, getSecurityDescriptionString(VALUE.security_value).c_str());
					dd.outside_print_function(test);
				}
				else
				{
					printf(DELIMITER_PRINT);
					printf(ATTR_NAME_15);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);

					printf("Security Description [0x%04X][%s]\n", VALUE.security_value, getSecurityDescriptionString(VALUE.security_value).c_str());
					printf("\n");
				}
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
				if (dd.outside_print_function != NULL && dd.sdp_settings.print_with_outside_funct == 1)
				{
					dd.outside_print_function(DELIMITER_PRINT);
					dd.outside_print_function(ATTR_NAME_16);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);

					char test[MAX_TEMP_STRING_LENGTH]{ 0 };
					sprintf_s(test, "Type of Network Access Available[0x%04X][%s]\n", VALUE.NetAccessType, getNetAccessTypeString(VALUE.NetAccessType).c_str());
					dd.outside_print_function(test);
				}
				else
				{

					printf(DELIMITER_PRINT);
					printf(ATTR_NAME_16);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);

					printf("Type of Network Access Available[0x%04X][%s]\n", VALUE.NetAccessType, getNetAccessTypeString(VALUE.NetAccessType).c_str());
					printf("\n");
				}
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
				if (dd.outside_print_function != NULL && dd.sdp_settings.print_with_outside_funct == 1)
				{
					dd.outside_print_function(DELIMITER_PRINT);
					dd.outside_print_function(ATTR_NAME_17);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);

					char test[MAX_TEMP_STRING_LENGTH]{ 0 };
					sprintf_s(test, "Maximum possible Network Access Data Rate: 0x%08X\n", VALUE.Maximum_possible_Network_Access_Data_Rate);
					dd.outside_print_function(test);
				}
				else
				{
					printf(DELIMITER_PRINT);
					printf(ATTR_NAME_17);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);

					printf("Maximum possible Network Access Data Rate: 0x%08X\n", VALUE.Maximum_possible_Network_Access_Data_Rate);
					printf("\n");
				}
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
			// TODO: ko bo default object urejene tako da bo zares default bo v redu, trenutno pa javi kot record handle!!!
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
				if (dd.outside_print_function != NULL && dd.sdp_settings.print_with_outside_funct == 1)
				{
					dd.outside_print_function(DELIMITER_PRINT);
					dd.outside_print_function(ATTR_NAME_18);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);

					char test[MAX_TEMP_STRING_LENGTH]{ 0 };
					sprintf_s(test, "Number of supported formats: %d\n", v.num_of_formats);
					dd.outside_print_function(test);

					sprintf_s(test, "Supported formats: \n");
					dd.outside_print_function(test);

					sprintf_s(test, "");
					for (int aa = 0; aa < v.num_of_formats; aa++)
						sprintf_s(test, "%s0x%02X ", test, v.formats[aa]);
					dd.outside_print_function(test);


					sprintf_s(test, "Formats: \n%s\n", getSupportedFormatsString(v.formats, v.num_of_formats).c_str());
					dd.outside_print_function(test);
				}
				else
				{

					printf(DELIMITER_PRINT);
					printf(ATTR_NAME_18);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);

					printf("Number of supported formats: %d\n", v.num_of_formats);

					printf("Supported formats: \n");
					for (int aa = 0; aa < v.num_of_formats; aa++)
						printf("0x%02X ", v.formats[aa]);
					printf("\n");

					printf("Formats: \n%s\n", getSupportedFormatsString(v.formats, v.num_of_formats).c_str());
				}
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
				if (dd.outside_print_function != NULL && dd.sdp_settings.print_with_outside_funct == 1)
				{
					dd.outside_print_function(DELIMITER_PRINT);
					dd.outside_print_function(ATTR_NAME_19);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);

					char test[MAX_TEMP_STRING_LENGTH]{ 0 };
					sprintf_s(test, "Repositories: \n%s\n", v.srs->getSupportedRepositoriesString().c_str());
					dd.outside_print_function(test);
				}
				else
				{
					printf(DELIMITER_PRINT);
					printf(ATTR_NAME_19);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);

					printf("Repositories: \n%s\n", v.srs->getSupportedRepositoriesString().c_str());
				}
			}

		} SUPPORTED_REPOSITORIES, * PSUPPORTED_REPOSITORIES;

		typedef struct PBAP_SUPPORTED_FEATURES_S : DEFAULT_OBJECT
		{
			// TODO: print values
			template<class T>
			void print(T v, IOCTL_S::DEFAULT_DATA dd)
			{
				if (dd.outside_print_function != NULL && dd.sdp_settings.print_with_outside_funct == 1)
				{
					dd.outside_print_function(DELIMITER_PRINT);
					dd.outside_print_function(ATTR_NAME_20);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);
				}
				else
				{
					printf(DELIMITER_PRINT);
					printf(ATTR_NAME_20);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);
				}
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
				if (dd.outside_print_function != NULL && dd.sdp_settings.print_with_outside_funct == 1)
				{
					dd.outside_print_function(DELIMITER_PRINT);
					dd.outside_print_function(ATTR_NAME_21);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);

					char test[MAX_TEMP_STRING_LENGTH]{ 0 };
					sprintf_s(test, "Specification ID: 0x%04X\n", this->SpecificationID);
					dd.outside_print_function(test);

					sprintf_s(test, "Vendor ID: 0x%04X\n", this->VendorID);
					dd.outside_print_function(test);

					sprintf_s(test, "Product ID: 0x%04X\n", this->ProductID);
					dd.outside_print_function(test);

					sprintf_s(test, "Version: 0x%04X\n", this->Version);
					dd.outside_print_function(test);

					sprintf_s(test, "Primary Record: 0x%02X\n", this->PrimaryRecord);
					dd.outside_print_function(test);

					sprintf_s(test, "Vendor ID Source: 0x%04X\n", this->VendorIDSource);
					dd.outside_print_function(test);
				}
				else
				{
					printf(DELIMITER_PRINT);
					printf(ATTR_NAME_21);

					printATTR_ELEMENT(dd);
					printVALUE_ELEMENT(v, dd);

					printf("Specification ID: 0x%04X\n", this->SpecificationID);
					printf("Vendor ID: 0x%04X\n", this->VendorID);
					printf("Product ID: 0x%04X\n", this->ProductID);
					printf("Version: 0x%04X\n", this->Version);
					printf("Primary Record: 0x%02X\n", this->PrimaryRecord);
					printf("Vendor ID Source: 0x%04X\n", this->VendorIDSource);
				}
			}

		} INFO, * PINFO;

		typedef struct INFO_EXPORT_S
		{
			PINFO info_handle_export;

		} INFO_EXPORT, * PINFO_EXPORT;
	}

}







