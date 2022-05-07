#pragma once

namespace SDP
{
	namespace OBEX
	{
		// GoepL2CapPsm use from MAP

		void parse_SERVICE_VERSION_OBEX(PSERVICE_VERSION handle);
		void parse_SUPPORTED_FORMATS_LIST_OBEX(PSUPPORTED_FORMATS handle);


		template<class C>
		void parse_by_type_sub_function(const std::type_info& type, C handle, SHORT current_used_service)
		{
			const std::type_info& a10 = typeid(SERVICE_VERSION_S*);
			const std::type_info& a11 = typeid(SUPPORTED_FORMATS_S*);
			const std::type_info& a12 = typeid(SDP::MAP::GOEPL2CAPPSM_S*);
			

			// ServiceVersion
			if (type == a10)
			{
				parse_SERVICE_VERSION_OBEX((PSERVICE_VERSION) handle);
			}

			// SupportedFormatsList
			if (type == a11)
			{
				parse_SUPPORTED_FORMATS_LIST_OBEX((PSUPPORTED_FORMATS) handle);
			}

			// GoepL2capPsm
			if (type == a12)
			{
				SDP::MAP::parse_GOEPL2CAPPSM_MAP(((SDP::MAP::GOEPL2CAPPSM&) *handle));
			}
		}
	};
};