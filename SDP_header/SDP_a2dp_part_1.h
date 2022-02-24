#pragma once
namespace SDP
{
	namespace A2DP
	{
		// TODO: naredi se za Audio Sink 

		void parse_SUPPORTED_FEATURES_A2DP(PSUPPORTED_FEATURES handle);

		template<class C>
		void parse_by_type_sub_function(const std::type_info& type, C handle, SHORT current_used_service)
		{
			const std::type_info& a10 = typeid(SUPPORTED_FEATURES_S*);


			// SupportedFeatures
			if (type == a10)
			{
				parse_SUPPORTED_FEATURES_A2DP((PSUPPORTED_FEATURES)handle);
			}
		}
	};
};