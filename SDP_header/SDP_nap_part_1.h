#pragma once

namespace SDP
{
	namespace NAP
	{
		void parse_SECURITY_DESCRIPTION_PAN(PSECURITY_DESCRIPTION handle);
		void parse_NET_ACCESS_TYPE_PAN(PNET_ACCESS_TYPE handle);
		void parse_MAX_NET_ACCESS_RATE_PAN(PMAX_NET_ACCESS_RATE handle);


		template<class C>
		void parse_by_type_sub_function(const std::type_info& type, C handle, SHORT current_used_service)
		{
			const std::type_info& a10 = typeid(SECURITY_DESCRIPTION_S*);
			const std::type_info& a11 = typeid(NET_ACCESS_TYPE_S*);
			const std::type_info& a12 = typeid(MAX_NET_ACCESS_RATE_S*);

			// SecurityDescription
			if (type == a10)
			{
				parse_SECURITY_DESCRIPTION_PAN((PSECURITY_DESCRIPTION)handle);
			}

			// NetAccessType
			if (type == a11)
			{
				parse_NET_ACCESS_TYPE_PAN((PNET_ACCESS_TYPE)handle);
			}

			// MaxNetAccessrate
			if (type == a12)
			{
				parse_MAX_NET_ACCESS_RATE_PAN((PMAX_NET_ACCESS_RATE)handle);
			}
		}
	}
}