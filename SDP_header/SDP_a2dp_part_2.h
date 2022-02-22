#pragma once

namespace SDP
{


	namespace A2DP
	{
		class A2DP_class : DEFAULT_class
		{
		public:

			PSUPPORTED_FEATURES supported_features_handle;

			PA2DP_EXPORT exp;

			A2DP_class();

			void call_ALL_ATTR(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd);
			void print_ALL_ATTR(IOCTL_S::DEFAULT_DATA dd);

			PA2DP_EXPORT export_ALL_ATTR();

			
		private:
			SHORT A2DP_source_att_array[11]{
				ServiceRecordHandle,
				ServiceClassIDList,
				ProtocolDescriptorList,
				BluetoothProfileDescriptorList,
				SupportedFeatures,
				ProviderName,
				ServiceName
			};
		};
	};
};