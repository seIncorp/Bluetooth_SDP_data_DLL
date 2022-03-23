#pragma once

namespace SDP
{

	namespace MAP
	{
		// TODO: preveri ce se pravilno pokazejo supported features
		// TODO: naredi se za MNS

		class MAP_class : public DEFAULT_class
		{
			public:

				/* specific */
				PGOEPL2CAPPSM goepl2cappsm_handle;
				PSUPPORTED_MESSAGE_TYPES supported_message_types_handle;
				PMAS_INSTANCE_ID mas_instance_id_handle;
				PMAP_SUPPORTED_FEATURES map_supported_features_handle;

				PMAP_EXPORT exp;


				MAP_class(IOCTL_S::DEFAULT_DATA dd);

				void call_ALL_ATTR(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd);
				void print_ALL_ATTR(IOCTL_S::DEFAULT_DATA dd);

				PMAP_EXPORT export_ALL_ATTR(IOCTL_S::DEFAULT_DATA dd);

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
				SHORT att_array[9]{
					ServiceRecordHandle,
					ServiceClassIDList,
					ProtocolDescriptorList,
					ServiceName,
					BluetoothProfileDescriptorList,
					MAP::GoepL2capPsm,
					MAP::MASInstanceID,
					MAP::SupportedMessageTypes,
					MAP::MapSupportedFeatures
				};

		};
	};

};