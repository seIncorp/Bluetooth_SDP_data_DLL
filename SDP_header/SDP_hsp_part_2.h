#pragma once


namespace SDP
{

	namespace HSP
	{
		
		class HSP_all_attributes : DEFAULT_class
		{
		public:

			PREMOTE_AUDIO_VOLUME_CONTROL remote_audio_volume_control_handle;

			HSP_all_attributes();

			void call_ALL_ATTR(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd);
			void print_ALL_ATTR(IOCTL_S::DEFAULT_DATA dd);


		private:
			SHORT att_array[6]{
				ServiceRecordHandle,
				ServiceClassIDList,
				ProtocolDescriptorList,
				BluetoothProfileDescriptorList,
				ServiceName,
				RemoteAudioVolumeControl
			};

		};
	};
};