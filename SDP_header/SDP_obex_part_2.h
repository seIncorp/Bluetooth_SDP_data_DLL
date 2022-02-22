#pragma once

namespace SDP
{

	namespace OBEX
	{
		class OBEX_all_attributes : DEFAULT_class
		{
		public:

			/* specific */
			SDP::MAP::PGOEPL2CAPPSM goepl2cappsm_handle;
			PSUPPORTED_FORMATS supported_formats_handle;
			PSERVICE_VERSION service_version_handle;
			


			OBEX_all_attributes();

			void call_ALL_ATTR(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd);
			void print_ALL_ATTR(IOCTL_S::DEFAULT_DATA dd);


		private:
			SHORT att_array[8]{
				ServiceRecordHandle,
				ServiceClassIDList,
				ProtocolDescriptorList,
				ServiceName,
				BluetoothProfileDescriptorList,
				GoepL2capPsm,
				SupportedFormatsList,
				ServiceVersion

			};

		};
	};

};