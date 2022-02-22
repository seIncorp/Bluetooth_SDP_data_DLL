#pragma once


#ifdef SDP_DATA_EXPORTS
#define SDP_DATA_API __declspec(dllexport)
#else
#define SDP_DATA_API __declspec(dllimport)
#endif


/*
	TODO:
	- BUG: check why app crash when use and call set_all_SDP_service_for_search() with SDPsearch() [FIXED: NOT USING GenericAudio service]
	- ADD: to all services export function


*/
//using namespace SDP;

namespace IOCTL_S
{
	
	
	/* MAIN structure */
	struct SDP_DATA_API DEFAULT_DATA
	{
		struct SDP_services_for_search
		{
			BYTE Headset;
			BYTE Headset_Audio_Gateway;
			BYTE AudioSource;
			BYTE GenericAudio;
			//BYTE AudioSink;
			BYTE Handsfree;
			BYTE HandsfreeAudioGateway;
			BYTE OBEXObjectPush;
			//BYTE OBEXFileTransfer;
			BYTE A_V_RemoteControl;
			BYTE A_V_RemoteControlTarget;
			BYTE A_V_RemoteControlController;
			BYTE PANU;
			BYTE _NAP;
			BYTE Phonebook_Access_PSE;
			//BYTE Phonebook_Access;
			BYTE Message_Access_Server;
			//BYTE Message_Access_Profile;
			BYTE PnPInformation;
		};
		
		struct SDP_exported_data
		{
			BYTE* default_export;
			BYTE* a2dp_export;
			BYTE* avrcp_export;
			BYTE* hfp_export;
			BYTE* hsp_export;
			BYTE* map_export;			// DONE!
			BYTE* nap_export;
			BYTE* obex_export;
			BYTE* pbap_export;
			BYTE* pnpinfo_export;
		};


		HANDLE hDevice;
		BOOL bResult;
		DWORD junk;
		SHORT service_class_id_in_use;
		SDP_services_for_search services_for_search;
		SDP_exported_data exported_data;

		void reset_SDP_service_for_search();
		void set_all_SDP_service_for_search();

	private:
		double vesrion;
		char* author;
	};


	/* LOCAL functions */
	void printErrorMessage(DWORD id);
	int str2ba(const char* straddr, BTH_ADDR* btaddr);



	/* CONNECTION AND DISCONNECTION functions */
	SDP_DATA_API int connectToDevice(const wchar_t* name, DEFAULT_DATA* dd);
	SDP_DATA_API void closeConnectionToDevice(DEFAULT_DATA* dd);

	/* SEARCH AND RETRIVING DATA functions */
	SDP_DATA_API int SDPsearch(DEFAULT_DATA* dd, char address[]);
	SDP_DATA_API int getBthDeviceInfo(DEFAULT_DATA* dd, int print = 1);
	SDP_DATA_API void getLocalBthInfo(DEFAULT_DATA* dd);

	//namespace MAP
	//{
		//struct SDP_DATA_API GOEPL2CAPPSM_S;
	//}


};








/*****************************************/
/* SDP */
#include "SDP_header/SDP.h"

/*****************************************/














