#pragma once
namespace SDP
{
	namespace HSP
	{

		typedef struct REMOTE_AUDIO_VOLUME_CONTROL_S : DEFAULT_OBJECT
		{
			template<class T>
			void print(T v, IOCTL_S::DEFAULT_DATA dd)
			{
				printATTR_ELEMENT();

				printVALUE_ELEMENT(v);

				// TODO: najdi primer za parsanje
			}

		} REMOTE_AUDIO_VOLUME_CONTROL, * PREMOTE_AUDIO_VOLUME_CONTROL;

		typedef struct HSP_EXPORT_S
		{
			PREMOTE_AUDIO_VOLUME_CONTROL remote_audio_volume_control_handle_export;

		} HSP_EXPORT, * PHSP_EXPORT;

		void parse_REMOTE_AUDIO_VOLUME_CONTROL_HSP(PREMOTE_AUDIO_VOLUME_CONTROL handle);

		template<class C>
		void parse_by_type_sub_function(const std::type_info& type, C handle, SHORT current_used_service)
		{
			const std::type_info& a10 = typeid(REMOTE_AUDIO_VOLUME_CONTROL_S*);

			// RemoteAudioVolumeControl
			if (type == a10)
			{
				parse_REMOTE_AUDIO_VOLUME_CONTROL_HSP((PREMOTE_AUDIO_VOLUME_CONTROL)handle);
			}
		}
	};
};