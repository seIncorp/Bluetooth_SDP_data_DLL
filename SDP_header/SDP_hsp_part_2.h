#pragma once


namespace SDP
{

	namespace HSP
	{
		
		class HSP_class : public DEFAULT_class
		{
		public:

			PREMOTE_AUDIO_VOLUME_CONTROL remote_audio_volume_control_handle;

			PHSP_EXPORT exp;

			HSP_class(IOCTL_S::DEFAULT_DATA dd);

			void call_ALL_ATTR(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd);
			void print_ALL_ATTR(IOCTL_S::DEFAULT_DATA dd);

			PHSP_EXPORT export_ALL_ATTR(IOCTL_S::DEFAULT_DATA dd);

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