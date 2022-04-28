#pragma once

#include "stdafx.h"
#include <iostream>
#using "..\MesDLL\IMSDLL.dll"
using namespace IMSDLL;

class MesInterface
{
public:
	MesInterface();
	~MesInterface();
public:
	//C#:   bool GetCommonData(string strSN, ref string strJson, ref string strErr);
	bool  BoeMes_Resqust(char* Sn, char* strJson, char* strErr);
	//C#:   bool SubmitCommonData(string strSN, bool result,  string ErrorCode, string ErrorMsg, ref string strErr);
	bool  BoeMes_TrackOut(char* Sn ,bool result, char* ErrorCode, char* ErrorMsg, char* strErr);
public:
	char* strRet_Json;
	char* strRet_Err;
	
};
