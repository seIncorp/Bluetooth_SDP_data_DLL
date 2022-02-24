#pragma once

namespace SDP
{

	namespace HFP
	{
		void parse_NETWORK_HFP(PNETWORK handle);
		void parse_SUPPORTED_FEATURES_HFP(PSUPPORTED_FEATURES handle);


		template<class C>
		void parse_by_type_sub_function(const std::type_info& type, C handle, SHORT current_used_service)
		{
			const std::type_info& a10 = typeid(NETWORK_S*);
			const std::type_info& a11 = typeid(SUPPORTED_FEATURES_S*);

			// Network
			if (type == a10)
			{
				parse_NETWORK_HFP((PNETWORK) handle);
			}

			// SupportedFeatures
			if (type == a11)
			{
				parse_SUPPORTED_FEATURES_HFP((PSUPPORTED_FEATURES) handle);
			}
		}
	}
};