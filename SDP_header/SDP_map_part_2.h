#pragma once

namespace SDP
{

	namespace MAP
	{
		// TODO: preveri ce se pravilno pokazejo supported features
		// TODO: naredi se za MNS

		class MAP_class : DEFAULT_class
		{
			public:

				/* specific */
				PGOEPL2CAPPSM goepl2cappsm_handle;
				PSUPPORTED_MESSAGE_TYPES supported_message_types_handle;
				PMAS_INSTANCE_ID mas_instance_id_handle;
				PMAP_SUPPORTED_FEATURES map_supported_features_handle;

				PMAP_EXPORT exp;


				MAP_class();

				void call_ALL_ATTR(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd);
				void print_ALL_ATTR(IOCTL_S::DEFAULT_DATA dd);

				PMAP_EXPORT export_ALL_ATTR();

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