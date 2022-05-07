#pragma once

namespace SDP
{
	namespace MAP
	{
		void parse_GOEPL2CAPPSM_MAP(GOEPL2CAPPSM& handle);
		void parse_SUPPORTED_MESSAGE_TYPES_MAP(SUPPORTED_MESSAGE_TYPES& handle);
		void parse_MAS_INSTANCE_ID_MAP(MAS_INSTANCE_ID& handle);
		void parse_MAP_SUPPORTED_FEATURES_MAP(MAP_SUPPORTED_FEATURES& handle);


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
				parse_GOEPL2CAPPSM_MAP((GOEPL2CAPPSM&)*handle);
			}

			// SupportedMessageTypes
			if (type == a11)
			{
				parse_SUPPORTED_MESSAGE_TYPES_MAP((SUPPORTED_MESSAGE_TYPES&)*handle);
			}

			// MASInstanceID
			if (type == a12)
			{
				parse_MAS_INSTANCE_ID_MAP((MAS_INSTANCE_ID&)*handle);
			}

			// MapSupportedFeatures
			if (type == a13)
			{
				parse_MAP_SUPPORTED_FEATURES_MAP((MAP_SUPPORTED_FEATURES&)*handle);
			}
		}
	}
}