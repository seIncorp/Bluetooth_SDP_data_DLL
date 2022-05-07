#pragma once

namespace SDP
{
	namespace PNPINFO
	{
		class PNPINFO_class : public DEFAULT_class
		{
		public:
			PINFO info_handle;

			PINFO_EXPORT exp;

			PINFO_EXPORT export_ALL_ATTR();



			PNPINFO_class();


			void call_ATTR(SHORT attr,ULONG recordHandle, HANDLE_SDP_TYPE aa, IOCTL_S::DEFAULT_DATA& dd);
			void call_ALL_ATTR(ULONG recordHandle, HANDLE_SDP_TYPE aa, IOCTL_S::DEFAULT_DATA& dd);
			void print_ALL_ATTR(IOCTL_S::DEFAULT_DATA& dd);

		};
	};
};