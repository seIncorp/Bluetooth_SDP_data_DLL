#pragma once




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


		void parse_GOEPL2CAPPSM_MAP(PGOEPL2CAPPSM handle);
		void parse_SUPPORTED_MESSAGE_TYPES_MAP(PSUPPORTED_MESSAGE_TYPES handle);
		void parse_MAS_INSTANCE_ID_MAP(PMAS_INSTANCE_ID handle);
		void parse_MAP_SUPPORTED_FEATURES_MAP(PMAP_SUPPORTED_FEATURES handle);


		template<class C>
		void parse_by_type_sub_function(const std::type_info& type, C handle, SHORT current_used_service)
		{
			const std::type_info& a10 = typeid(GOEPL2CAPPSM_S*);
			const std::type_info& a11 = typeid(SUPPORTED_MESSAGE_TYPES_S*);
			const std::type_info& a12 = typeid(MAS_INSTANCE_ID_S*);
			const std::type_info& a13 = typeid(MAP_SUPPORTED_FEATURES_S*);

			// GoepL2capPsm
			if (type == a10)
			{
				parse_GOEPL2CAPPSM_MAP((PGOEPL2CAPPSM)handle);
			}

			// SupportedMessageTypes
			if (type == a11)
			{
				parse_SUPPORTED_MESSAGE_TYPES_MAP((PSUPPORTED_MESSAGE_TYPES)handle);
			}

			// MASInstanceID
			if (type == a12)
			{
				parse_MAS_INSTANCE_ID_MAP((PMAS_INSTANCE_ID)handle);
			}

			// MapSupportedFeatures
			if (type == a13)
			{
				parse_MAP_SUPPORTED_FEATURES_MAP((PMAP_SUPPORTED_FEATURES)handle);
			}
		}
	}
}