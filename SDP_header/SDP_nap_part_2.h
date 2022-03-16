#pragma once

namespace SDP
{

	/* USED ONLY IN NAP and PANU */
	namespace NAP
	{

		class NAP_PANU_class : public DEFAULT_class
		{
		public:

			/* specific */
			PSECURITY_DESCRIPTION security_description_handle;
			PNET_ACCESS_TYPE net_access_type_handle;
			PMAX_NET_ACCESS_RATE max_net_access_rate_handle;
			
			PNAP_EXPORT exp;

			int nap_flag;

			NAP_PANU_class(IOCTL_S::DEFAULT_DATA dd, int nap = 1);

			void call_ALL_ATTR(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd);
			void print_ALL_ATTR(IOCTL_S::DEFAULT_DATA dd);

			void call_LanguageBaseAttributeIDList(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd);
			void call_ServiceDescription(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd);
			void call_SecurityDescription(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd);
			void call_NetAccessType(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd);
			void call_MaxNetAccessrate(DEVICE_DATA_SDP* device_data_sdp, IOCTL_S::DEFAULT_DATA dd);

			PNAP_EXPORT export_ALL_ATTR(IOCTL_S::DEFAULT_DATA dd);


		private:
			SHORT nap_att_array[11]{
				ServiceRecordHandle,
				ServiceClassIDList,
				ProtocolDescriptorList,
				LanguageBaseAttributeIDList,
				ServiceAvailability,
				BluetoothProfileDescriptorList,
				ServiceName,
				ServiceDescription,
				SecurityDescription,
				NetAccessType,
				MaxNetAccessrate
				// TODO: naredi se za IPv4Subnet in IPv6Subnet
			};

			SHORT panu_att_array[9]{
				ServiceRecordHandle,
				ServiceClassIDList,
				ProtocolDescriptorList,
				LanguageBaseAttributeIDList,
				ServiceAvailability,
				BluetoothProfileDescriptorList,
				ServiceName,
				ServiceDescription,
				SecurityDescription
			};

		};
	};
};