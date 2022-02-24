#pragma once
namespace SDP
{

	namespace AVRCP
	{
		// TODO: naredi se za A_V_RemoteControlController (drugo strukturo ker je vec bit-ov in druga razlaga)(AVRCP_v1.6.2.pdf)


		void parse_SUPPORTED_FEATURES_AVRCP(PSUPPORTED_FEATURES handle, SHORT current_used_service);

		template<class C>
		void parse_by_type_sub_function(const std::type_info& type, C handle, SHORT current_used_service)
		{
			const std::type_info& a10 = typeid(SUPPORTED_FEATURES_S*);
			
			// SupportedFeatures
			if (type == a10)
			{
				parse_SUPPORTED_FEATURES_AVRCP((PSUPPORTED_FEATURES) handle, current_used_service);
			}
		}
	};

};