#include "stdafx.h"
#include "Mes.h"
//String^与char*互相
using namespace System;                                                //String^库文件
using namespace System::Runtime::InteropServices;                      //Marchal库文件



/// <summary>
/// MES 过站信息请求与检查
/// </summary>
/// <param name="Sn"></param>
/// <param name="strJson"></param>
/// <param name="strErr"></param>
/// <returns></returns>
bool  MesInterface::BoeMes_Resqust(char* Sn, char* strJson, char* strErr) {
	
	//char*转String^
	String^ CSn = gcnew String(Sn);
	String^ CstrJson = gcnew String(strJson);
	String^ CstrErr = gcnew String(strErr);
	

	MESFUNCTION^ a = gcnew MESFUNCTION();
	bool f = a->GetCommonData(CSn, CstrJson, CstrErr);

	//String^转char*
	strJson = (char*)(void*)Marshal::StringToHGlobalAnsi(CstrJson);
	strRet_Json = strJson;

	strErr = (char*)(void*)Marshal::StringToHGlobalAnsi(CstrErr);
	strRet_Err = strErr;

	return f;

};


/// <summary>
/// Mes 过站
/// </summary>
/// <param name="Sn"></param>
/// <param name="result"></param>
/// <param name="ErrorCode"></param>
/// <param name="ErrorMsg"></param>
/// <param name="strErr"></param>
/// <returns></returns>
bool MesInterface::BoeMes_TrackOut(char* Sn, bool result, char* ErrorCode, char* ErrorMsg, char* strErr) {
	
	//char*转String^
	String^ CSn = gcnew String(Sn);
	String^ CErrorCode = gcnew String(ErrorCode);
	String^ CErrorMsg = gcnew String(ErrorMsg);
	String^ CstrErr = gcnew String(strErr);

	MESFUNCTION^ a = gcnew MESFUNCTION();
	bool f = a->SubmitCommonData(CSn, result, CErrorCode, CErrorMsg, CstrErr);

	//String^转char*
	strErr = (char*)(void*)Marshal::StringToHGlobalAnsi(CstrErr);
	strRet_Err = strErr;
	
	return f;
};



MesInterface::MesInterface() {

};
MesInterface::~MesInterface() {

};

#if 0
////String^与char*互相转换测试
//char* c = "adsfdasf";
//String^ strd = gcnew String(c);
//char* d = (char*)(void*)Marshal::StringToHGlobalAnsi(strd);
//cout << d << endl;
#endif // 0