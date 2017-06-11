// IP2LOC-dll.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "IP2LOC-dll.h"
#include <string.h>
#include "IP2Location.h"
#pragma comment(lib, "E:\\Projects\\cpp\\IP2LOC-dll\\IP2LOC-dll\\IP2Location.lib")

// ���ǵ���������һ��ʾ��
IP2LOCDLL_API int nIP2LOCdll=0;

// ���ǵ���������һ��ʾ����
IP2LOCDLL_API int fnIP2LOCdll(void)
{
    return 42;
}

IP2Location *IP2LocationObj;
IP2LocationRecord *record;

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� IP2LOC-dll.h
CIP2LOCdll::CIP2LOCdll()
{
	IP2LocationObj = NULL;
	record = NULL;
    return;
}


bool CIP2LOCdll::init(char* binPath)
{
	IP2LocationObj = IP2Location_open(binPath);
	if (IP2LocationObj == NULL) return false;
	else return true;
	if (IP2Location_open_mem(IP2LocationObj, IP2LOCATION_SHARED_MEMORY) == -1) return false;
}

char* CIP2LOCdll::Query(char* ipStr)
{
	memset(resultStr, 0, 800);
	record = IP2Location_get_all(IP2LocationObj, ipStr);
	if (record == NULL) return "";
	strcat_s(resultStr, 800,record->country_long);
	strcat_s(resultStr, 800, "\t");
	strcat_s(resultStr, 800, record->country_short);
	strcat_s(resultStr, 800, "\t");
	strcat_s(resultStr, 800, record->city);
	strcat_s(resultStr, 800, "\t");
	strcat_s(resultStr, 800, record->domain);
	strcat_s(resultStr, 800, "\t");
	strcat_s(resultStr, 800, record->isp);
	strcat_s(resultStr, 800, "\t");
	char latStr[20];
	sprintf(latStr, "%f", record->latitude);
	strcat_s(resultStr, 800, latStr);
	strcat_s(resultStr, 800, "\t");
	char lonStr[20];
	sprintf(lonStr, "%f", record->longitude);
	strcat_s(resultStr, 800, lonStr);
	IP2Location_free_record(record);
	return resultStr;
}

CIP2LOCdll::~CIP2LOCdll()
{
	if (IP2LocationObj != NULL)
	{
		IP2Location_close(IP2LocationObj);
	}
	return;
}