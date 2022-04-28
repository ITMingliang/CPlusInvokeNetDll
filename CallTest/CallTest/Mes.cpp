#include "stdafx.h"
#include "Mes.h"
//String^��char*����
using namespace System;                                                //String^���ļ�
using namespace System::Runtime::InteropServices;                      //Marchal���ļ�



/// <summary>
/// MES ��վ��Ϣ��������
/// </summary>
/// <param name="Sn"></param>
/// <param name="strJson"></param>
/// <param name="strErr"></param>
/// <returns></returns>
bool  MesInterface::BoeMes_Resqust(char* Sn, char* strJson, char* strErr) {
	
	//char*תString^
	String^ CSn = gcnew String(Sn);
	String^ CstrJson = gcnew String(strJson);
	String^ CstrErr = gcnew String(strErr);
	

	MESFUNCTION^ a = gcnew MESFUNCTION();
	bool f = a->GetCommonData(CSn, CstrJson, CstrErr);

	//String^תchar*
	strJson = (char*)(void*)Marshal::StringToHGlobalAnsi(CstrJson);
	strRet_Json = strJson;

	strErr = (char*)(void*)Marshal::StringToHGlobalAnsi(CstrErr);
	strRet_Err = strErr;

	return f;

};


/// <summary>
/// Mes ��վ
/// </summary>
/// <param name="Sn"></param>
/// <param name="result"></param>
/// <param name="ErrorCode"></param>
/// <param name="ErrorMsg"></param>
/// <param name="strErr"></param>
/// <returns></returns>
bool MesInterface::BoeMes_TrackOut(char* Sn, bool result, char* ErrorCode, char* ErrorMsg, char* strErr) {
	
	//char*תString^
	String^ CSn = gcnew String(Sn);
	String^ CErrorCode = gcnew String(ErrorCode);
	String^ CErrorMsg = gcnew String(ErrorMsg);
	String^ CstrErr = gcnew String(strErr);

	MESFUNCTION^ a = gcnew MESFUNCTION();
	bool f = a->SubmitCommonData(CSn, result, CErrorCode, CErrorMsg, CstrErr);

	//String^תchar*
	strErr = (char*)(void*)Marshal::StringToHGlobalAnsi(CstrErr);
	strRet_Err = strErr;
	
	return f;
};



MesInterface::MesInterface() {

};
MesInterface::~MesInterface() {

};

#if 0
////String^��char*����ת������
//char* c = "adsfdasf";
//String^ strd = gcnew String(c);
//char* d = (char*)(void*)Marshal::StringToHGlobalAnsi(strd);
//cout << d << endl;
#endif // 0