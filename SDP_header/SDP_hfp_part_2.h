#pragma once


namespace SDP
{

	namespace HFP
	{
		class HFP_class : public DEFAULT_class
		{
		public:

			/* specific */
			PNETWORK network_handle;
			PSUPPORTED_FEATURES supported_features_handle;

			PHFP_EXPORT exp;

			HFP_class(IOCTL_S::DEFAULT_DATA dd);

			void call_ALL_ATTR(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd);
			void print_ALL_ATTR(IOCTL_S::DEFAULT_DATA dd);

			PHFP_EXPORT export_ALL_ATTR(IOCTL_S::DEFAULT_DATA dd);


			template<class A, class B>
			void call_attr_def(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd, A handle, SHORT attr)
			{
				FUNCTIONS::getAndParse_DEAFULT<A, B>(
					device_data_sdp->buffer_res[0],
					device_data_sdp->bsc->HANDLE_SDP_FIELD_NAME,
					handle,
					attr,
					attr,
					device_data_sdp,
					dd,
					0
				);
			}


		private:
			SHORT att_AG_array[7]{
				ServiceRecordHandle,
				ServiceClassIDList,
				ProtocolDescriptorList,
				BluetoothProfileDescriptorList,
				ServiceName,
				Network,
				SupportedFeatures
			};

		};
	}
};