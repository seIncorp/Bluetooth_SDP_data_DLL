#pragma once



namespace SDP
{

	namespace AVRCP
	{
		class AVRCP_class : DEFAULT_class
		{
		public:
			
			PSUPPORTED_FEATURES supported_features_handle;

			DEVICE_DATA_SDP* dds;

			PAVRCP_EXPORT exp;

			AVRCP_class();

			void call_ALL_ATTR(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd);
			void print_ALL_ATTR(IOCTL_S::DEFAULT_DATA dd);

			PAVRCP_EXPORT export_ALL_ATTR();


		private:
			SHORT avrcp_att_array[8]{
				ServiceRecordHandle,
				ServiceClassIDList,
				ProtocolDescriptorList,
				AdditionalProtocolDescriptorList,
				BluetoothProfileDescriptorList,
				SupportedFeatures,
				ProviderName,
				ServiceName
			};
		};

	};

};