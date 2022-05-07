#pragma once

namespace SDP
{
	namespace PBAP
	{
		// GoepL2CapPsm use from MAP

		void parse_SUPPORTED_REPOSITORIES_PBAP(PSUPPORTED_REPOSITORIES handle);
		void parse_PBAP_SUPPORTED_FEATURES_PBAP(PPBAP_SUPPORTED_FEATURES handle);

		template<class C>
		void parse_by_type_sub_function(const std::type_info& type, C handle, SHORT current_used_service)
		{
			const std::type_info& a10 = typeid(SUPPORTED_REPOSITORIES_S*);
			const std::type_info& a11 = typeid(PBAP_SUPPORTED_FEATURES_S*);
			const std::type_info& a12 = typeid(SDP::MAP::GOEPL2CAPPSM_S*);
			

			// SupportedRepositories
			if (type == a10)
			{
				parse_SUPPORTED_REPOSITORIES_PBAP((PSUPPORTED_REPOSITORIES) handle);
			}

			// PbapSupportedFeatures
			if (type == a11)
			{
				parse_PBAP_SUPPORTED_FEATURES_PBAP((PPBAP_SUPPORTED_FEATURES) handle);
			}

			// GoepL2capPsm
			if (type == a12)
			{
				SDP::MAP::parse_GOEPL2CAPPSM_MAP((SDP::MAP::GOEPL2CAPPSM&)handle);
			}
		}

	};


};