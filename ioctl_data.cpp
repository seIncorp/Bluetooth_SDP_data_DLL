#include "pch.h"

void IOCTL_S::DEFAULT_DATA::reset_SDP_service_for_search()
{
	services_for_search.Headset = 0x00;
	services_for_search.AudioSource = 0x00;
	//temp->AudioSink = 0x00;
	services_for_search.Headset_Audio_Gateway = 0x00;
	services_for_search.Handsfree = 0x00;
	services_for_search.OBEXObjectPush = 0x00;
	//temp->OBEXFileTransfer = 0x00;
	services_for_search.A_V_RemoteControl = 0x00;
	services_for_search.A_V_RemoteControlTarget = 0x00;
	services_for_search.A_V_RemoteControlController = 0x00;
	services_for_search.PANU = 0x00;
	services_for_search._NAP = 0x00;
	services_for_search.HandsfreeAudioGateway = 0x00;
	services_for_search.Phonebook_Access_PSE = 0x00;
	//temp->Phonebook_Access = 0x00;
	services_for_search.Message_Access_Server = 0x00;
	//temp->Message_Access_Profile = 0x00;
	services_for_search.PnPInformation = 0x00;
	services_for_search.GenericAudio = 0x00;
}

void IOCTL_S::DEFAULT_DATA::set_all_SDP_service_for_search()
{
	services_for_search.Headset = 0x01;
	services_for_search.AudioSource = 0x01;
	//temp->AudioSink = 0x01;
	services_for_search.Headset_Audio_Gateway = 0x01;
	services_for_search.Handsfree = 0x01;
	services_for_search.OBEXObjectPush = 0x01;
	//temp->OBEXFileTransfer = 0x01;
	services_for_search.A_V_RemoteControl = 0x01;
	services_for_search.A_V_RemoteControlTarget = 0x01;
	services_for_search.A_V_RemoteControlController = 0x01;
	services_for_search.PANU = 0x01;
	services_for_search._NAP = 0x01;
	services_for_search.HandsfreeAudioGateway = 0x01;
	services_for_search.Phonebook_Access_PSE = 0x01;
	//temp->Phonebook_Access = 0x01;
	services_for_search.Message_Access_Server = 0x01;
	//temp->Message_Access_Profile = 0x01;
	services_for_search.PnPInformation = 0x01;
	services_for_search.GenericAudio = 0x01;
}

void IOCTL_S::DEFAULT_DATA::reset_attr_search_for_service()
{
	attr_search_for_service.all = 0;

	attr_search_for_service.ServiceRecord = 0;
	attr_search_for_service.ServiceClassIDList = 0;
	attr_search_for_service.ProtocolDescriptorList = 0;
	attr_search_for_service.ServiceName = 0;
	attr_search_for_service.BluetoothProfileDescriptorList = 0;
	attr_search_for_service.ProviderName = 0;
	attr_search_for_service.LanguageBaseAttributeIdList = 0;
	attr_search_for_service.ServiceDescription = 0;

	attr_search_for_service.att_PNPINFO.PnpInfo = 0;

	attr_search_for_service.att_PBAP.Goepl2cappsm = 0;
	attr_search_for_service.att_PBAP.SupportedRepositories = 0;
	attr_search_for_service.att_PBAP.SupportedFeatures = 0;
	
	attr_search_for_service.att_OBEX.Goepl2cappsm = 0;
	attr_search_for_service.att_OBEX.SupportedFormats = 0;
	attr_search_for_service.att_OBEX.ServiceVersion = 0;

	attr_search_for_service.att_NAP.SecurityDescription = 0;
	attr_search_for_service.att_NAP.NetAccessType = 0;
	attr_search_for_service.att_NAP.MaxNetAccessRate = 0;

	attr_search_for_service.att_HSP.RemoteAudioVolumeControl = 0;

	attr_search_for_service.att_HFP.Network = 0;
	attr_search_for_service.att_HFP.SupportedFeatures = 0;

	attr_search_for_service.att_AVRCP.SupportedFeatures = 0;

	attr_search_for_service.att_A2DP.SupportedFeatures = 0;

	attr_search_for_service.att_MAP.Goepl2cappsm = 0;
	attr_search_for_service.att_MAP.SupportedMessageTypes = 0;
	attr_search_for_service.att_MAP.MasInstanceId = 0;
	attr_search_for_service.att_MAP.MapSupportedFeatures = 0;
}



void IOCTL_S::printErrorMessage(DWORD id)
{
	if (id != 0x00)
		switch (id)
		{
			case 0x00:
				printf("ERROR [0x%X - %d] [OK]\n", id, id);
			break;

			case 0x01:
				printf("ERROR [0x%X - %d] [ERROR_INVALID_FUNCTION]\n", id, id);
			break;

			case 0x02:
				printf("ERROR [0x%X - %d] [ERROR_FILE_NOT_FOUND]\n", id, id);
			break;

			case 0x3A:
				printf("ERROR [0x%X - %d] [ERROR_BAD_NET_RESP]\n", id, id);
			break;

			case 0x57:
				printf("ERROR [0x%X - %d] [ERROR_INVALID_PARAMETER]\n", id, id);
			break;

			case 0x79:
				printf("ERROR [0x%X - %d] [ERROR_SEM_TIMEOUT]\n", id, id);
			break;

			case 0x7A:
				printf("ERROR [0x%X - %d] [ERROR_INSUFFICIENT_BUFFER]\n", id, id);
			break;

			case 0x7B:
				printf("ERROR [0x%X - %d] [ERROR_INVALID_NAME]\n", id, id);
			break;

			case 0x32:
				printf("ERROR [0x%X - %d] [ERROR_NOT_SUPPORTED]\n", id, id);
			break;

			case 0x522:
				printf("ERROR [0x%X - %d] [ERROR_PRIVILEGE_NOT_HELD]\n", id, id);
			break;

			case 0x48F:
				printf("ERROR [0x%X - %d] [ERROR_DEVICE_NOT_CONNECTED]\n", id, id);
			break;

			case 0x6F8:
				printf("ERROR [0x%X - %d] [ERROR_INVALID_USER_BUFFER]\n", id, id);
			break;

			default:
				printf("ERROR [0x%X - %d] [????]\n", id, id);
			break;
		}
}

int IOCTL_S::connectToDevice(const wchar_t* name, DEFAULT_DATA* dd)
{
	
	dd->hDevice = CreateFileW(
		name,//DEFAULT_DEVICE,							// drive to open
		//GENERIC_READ | GENERIC_WRITE,			// no access to the drive
		FILE_READ_DATA | FILE_WRITE_DATA,			// no access to the drive
		FILE_SHARE_READ | FILE_SHARE_WRITE,		// share mode
		NULL,									// default security attributes
		OPEN_EXISTING,							// disposition
		0,										// file attributes
		NULL);									// do not copy file attributes

	if (dd->hDevice == INVALID_HANDLE_VALUE)
	{
		printErrorMessage(GetLastError());

		return 0;
	}

	return 1;
}

void IOCTL_S::closeConnectionToDevice(DEFAULT_DATA* dd)
{
	if (CloseHandle(dd->hDevice) == 0)
		printErrorMessage(GetLastError());
	else
	{
		if(dd->sdp_settings.print_info == 1)
			printf("CONNECTION TO DEVICE CLOSED!\n");
	}
}

int IOCTL_S::str2ba(const char* straddr, BTH_ADDR* btaddr)
{
	int i;
	unsigned int aaddr[6];
	BTH_ADDR tmpaddr = 0;

	if (sscanf_s(straddr, "%02x:%02x:%02x:%02x:%02x:%02x",
		&aaddr[0], &aaddr[1], &aaddr[2],
		&aaddr[3], &aaddr[4], &aaddr[5]) != 6)
		return 1;
	*btaddr = 0;
	for (i = 0; i < 6; i++) {
		tmpaddr = (BTH_ADDR)(aaddr[i] & 0xff);
		*btaddr = ((*btaddr) << 8) + tmpaddr;
	}
	return 0;
}

// LIST OF CACHED BTH SEARCHED DEVICES
int IOCTL_S::getBthDeviceInfo(DEFAULT_DATA* dd, int print)
{
	BYTE data[sizeof(BTH_DEVICE_INFO_LIST) + (MAX_SEARCHED_SHOWED_DEVICE - 1) * sizeof(BTH_DEVICE_INFO)]{ 0 };

	dd->bResult = DeviceIoControl(
		dd->hDevice,						// device to be queried
		IOCTL_BTH_GET_DEVICE_INFO,			// operation to perform
		NULL, 0,							// no input buffer
		data, sizeof(data),					// output buffer
		&dd->junk,							// # bytes returned
		(LPOVERLAPPED)NULL);				// synchronous I/O

	printErrorMessage(GetLastError());

	if (dd->bResult)
	{
		BTH_DEVICE_INFO_LIST* bdil = (BTH_DEVICE_INFO_LIST*)data;
		BTH_DEVICE_INFO* bdi = bdil->deviceList;

		dd->exported_data.devices = new BTH_DEVICES::SEARCHED_CACHED_DEVICES();
		dd->exported_data.devices->numOfDevices = bdil->numOfDevices;

		for (int a = 0; a < bdil->numOfDevices; a++)
		{
			BLUETOOTH_ADDRESS_STRUCT* bas = (BLUETOOTH_ADDRESS_STRUCT*)&((bdi + a)->address);

			BTH_DEVICES::CACHED_DEVICE_S temp{ (bdi + a)->name, bas->rgBytes, (bdi + a)->flags };

			dd->exported_data.devices->devices.push_back(temp);
		}

		if (print == 1)
			dd->exported_data.devices->print();

		return 1;
	}
	else
		return 0;
}

// information about the local Bluetooth system and radio
void IOCTL_S::getLocalBthInfo(DEFAULT_DATA* dd, int print)
{
	BTH_LOCAL_RADIO_INFO blri{ 0 };

	dd->bResult = DeviceIoControl(
		dd->hDevice,					// device to be queried
		IOCTL_BTH_GET_LOCAL_INFO,		// operation to perform
		NULL, 0,						// no input buffer
		&blri, sizeof(blri),			// output buffer
		&dd->junk,						// # bytes returned
		(LPOVERLAPPED)NULL);			// synchronous I/O

	printErrorMessage(GetLastError());

	if (dd->bResult)
	{
		BTH_DEVICE_INFO bdi = blri.localInfo;
		BTH_RADIO_INFO* bri = &blri.radioInfo;

		dd->exported_data.local_device_radio = new BTH_DEVICES::LOCAL_RADIO_DEVICE_DATA(
			blri.flags,
			blri.hciRevision,
			blri.hciVersion
		);

		BTH_DEVICES::DEVICE_DATA_S temp_d;

		dd->exported_data.local_device_radio->device = new BTH_DEVICES::DEVICE_DATA();

		dd->exported_data.local_device_radio->device->init(
			((BLUETOOTH_ADDRESS_STRUCT*)(&bdi.address))->rgBytes,
			bdi.flags,
			bdi.name
		);
		
		COD_PARSER::PDEVICE_PARSED_COD_DATA cod_temp = new COD_PARSER::DEVICE_PARSED_COD_DATA();
		parseCODdata((COD_PARSER::COD_data*)&bdi.classOfDevice, cod_temp);
		dd->exported_data.local_device_radio->device->cod = cod_temp;

		dd->exported_data.local_device_radio->radio = new BTH_DEVICES::RADIO_DATA{ bri->lmpSupportedFeatures ,bri->mfg,bri->lmpSubversion, bri->lmpVersion };

		// TODO: preveri tezavo s prikazom zunaj
		if(print == 1)
			dd->exported_data.local_device_radio->print();
	}
}




int IOCTL_S::SDPsearch(DEFAULT_DATA* dd, char address[])	// TODO: preimenuj v pravo ime
{
	/********************************************************************/
	/* INIT */

	SDP::DEVICE_DATA_SDP* device_data_sdp = new SDP::DEVICE_DATA_SDP();
	
	SDP::FUNCTIONS::SDP_INIT_CONNECT::init_for_IOCTL_BTH_SDP_CONNECT(address, device_data_sdp, *dd);

	/********************************************************************/
	/* CONNECT TO DEVICE */

	if (SDP::FUNCTIONS::SDP_INIT_CONNECT::call_IOCTL_BTH_SDP_CONNECT(device_data_sdp, *dd))
	{
		if(dd->sdp_settings.print_info == 1)
			printf("DEVICE CONNECTED!!\n");

		/******************************************/
		/* SERVICE SEARCH */

		// TODO: naredi se za ostale service (trenutno je samo za enega)


		if (dd->services_for_search.Headset == 0x01)
		{
			device_data_sdp->current_used_service = SDP::Headset;
			SDP::FUNCTIONS::call_and_search_service(device_data_sdp, dd);
		}

		if (dd->services_for_search.Headset_Audio_Gateway == 0x01)
		{
			device_data_sdp->current_used_service = SDP::Headset_Audio_Gateway;
			SDP::FUNCTIONS::call_and_search_service(device_data_sdp, dd);
		}

		if (dd->services_for_search.AudioSource == 0x01)
		{
			device_data_sdp->current_used_service = SDP::AudioSource;
			SDP::FUNCTIONS::call_and_search_service(device_data_sdp, dd);
		}

		if (dd->services_for_search.GenericAudio == 0x01)
		{
			device_data_sdp->current_used_service = SDP::GenericAudio;
			SDP::FUNCTIONS::call_and_search_service(device_data_sdp, dd);
		}

		if (dd->services_for_search.Handsfree == 0x01)
		{
			device_data_sdp->current_used_service = SDP::Handsfree;
			SDP::FUNCTIONS::call_and_search_service(device_data_sdp, dd);
		}

		if (dd->services_for_search.HandsfreeAudioGateway == 0x01)
		{
			device_data_sdp->current_used_service = SDP::HandsfreeAudioGateway;
			SDP::FUNCTIONS::call_and_search_service(device_data_sdp, dd);
		}

		if (dd->services_for_search.OBEXObjectPush == 0x01)
		{
			device_data_sdp->current_used_service = SDP::OBEXObjectPush;
			SDP::FUNCTIONS::call_and_search_service(device_data_sdp, dd);
		}

		if (dd->services_for_search.A_V_RemoteControl == 0x01)
		{
			device_data_sdp->current_used_service = SDP::A_V_RemoteControl;
			SDP::FUNCTIONS::call_and_search_service(device_data_sdp, dd);
		}

		if (dd->services_for_search.A_V_RemoteControlTarget == 0x01)
		{
			device_data_sdp->current_used_service = SDP::A_V_RemoteControlTarget;
			SDP::FUNCTIONS::call_and_search_service(device_data_sdp, dd);
		}

		if (dd->services_for_search.A_V_RemoteControlController == 0x01)
		{
			device_data_sdp->current_used_service = SDP::A_V_RemoteControlController;
			SDP::FUNCTIONS::call_and_search_service(device_data_sdp, dd);
		}

		if (dd->services_for_search.PANU == 0x01)
		{
			device_data_sdp->current_used_service = SDP::PANU;
			SDP::FUNCTIONS::call_and_search_service(device_data_sdp, dd);
		}

		if (dd->services_for_search._NAP == 0x01)
		{
			device_data_sdp->current_used_service = SDP::_NAP;
			SDP::FUNCTIONS::call_and_search_service(device_data_sdp, dd);
		}

		if (dd->services_for_search.Phonebook_Access_PSE == 0x01)
		{
			device_data_sdp->current_used_service = SDP::Phonebook_Access_PSE;
			SDP::FUNCTIONS::call_and_search_service(device_data_sdp, dd);
		}

		if (dd->services_for_search.Message_Access_Server == 0x01)
		{
			device_data_sdp->current_used_service = SDP::Message_Access_Server;
			SDP::FUNCTIONS::call_and_search_service(device_data_sdp, dd);
		}

		if (dd->services_for_search.PnPInformation == 0x01)
		{
			device_data_sdp->current_used_service = SDP::PnPInformation;
			SDP::FUNCTIONS::call_and_search_service(device_data_sdp, dd);
		}



		/******************************************/
		/* DISCONNECTION FROM DEVICE (IMPORTANT!!!) */

		SDP::FUNCTIONS::SDP_INIT_DISCONNECT::init_for_IOCTL_BTH_SDP_DISCONNECT(device_data_sdp);

		return SDP::FUNCTIONS::SDP_INIT_DISCONNECT::call_IOCTL_BTH_SDP_DISCONNECT(device_data_sdp, *dd);
	}

	return 0;
}



