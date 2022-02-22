#pragma once

namespace SDP
{

	namespace PBAP
	{
		class PBAP_all_attributes : DEFAULT_class
		{
		public:
			
			/* specific */
			SDP::MAP::PGOEPL2CAPPSM goepl2cappsm_handle;
			PSUPPORTED_REPOSITORIES supported_repositories_handle;
			PPBAP_SUPPORTED_FEATURES pbap_supported_features_handle;

			PBAP_all_attributes();

			void call_ALL_ATTR(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd);
			void print_ALL_ATTR(IOCTL_S::DEFAULT_DATA dd);

		private:
			SHORT att_array[8]{
				ServiceRecordHandle,
				ServiceClassIDList,
				ProtocolDescriptorList,
				ServiceName,
				BluetoothProfileDescriptorList,
				MAP::GoepL2capPsm,
				SupportedRepositories,
				PbapSupportedFeatures
			};

		};
		
	};


};