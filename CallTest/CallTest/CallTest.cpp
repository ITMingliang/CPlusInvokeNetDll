// CallTest.cpp: ����Ŀ�ļ���

#include "stdafx.h"
#include <iostream>
#include "Mes.h"
#using "..\MesDLL\MesDLL.dll"
#using "..\MesDLL\IMSDLL.dll"
using namespace IMSDLL;
using namespace MesDLL;
using namespace std;


//String^��char*����
using namespace System;                                                //String^���ļ�
using namespace System::Runtime::InteropServices;                      //Marchal���ļ�



#if 0
int main()
{

    //1.����
    int sum, x, y;
    x = 10;
    y = 22;
    MathTest^ a = gcnew MathTest();
    sum = a->demoAdd(x, y);
    //printf("�������� %d", sum);
    cout << "������:" << sum << endl;


    //2.�ַ���
    System::String^ xx = "x";
    System::String^ yy = "y";
    System::String^ ret = a->demoAddStr(xx, yy);
    char* cret1 = (char*)(void*)Marshal::StringToHGlobalAnsi(ret);
    //printf("�������� %s", a->demoAddStr(xx, yy));
    cout << "������:" << cret1 << endl;


    //3.MES DLL
    MESFUNCTION^ ab = gcnew MESFUNCTION();
    //char* Sn, char** strJson, char** strErr;
    //const char* Sn, char** strJson, char** strErr;

    //Ϊ������ǰ��ָ�����ֿ�����^������*
    System::String^ Sn = "11111111";
    System::String^ strJson = "";
    System::String^ strErr = "";
    bool f = ab->GetCommonData(Sn, strJson, strErr);
    char* cstrJson = (char*)(void*)Marshal::StringToHGlobalAnsi(strJson);
    char* cstrErr = (char*)(void*)Marshal::StringToHGlobalAnsi(strErr);
    //printf("strJson�� %s", strJson);
    //printf("strErr�� %s", strErr);
    cout << "strJson:" << cstrJson << endl;
    cout << "strErr:" << cstrErr << endl;


    //4.String^��char*����ת������
    char* c = "adsfdasf";
    String^ strd = gcnew String(c);
    char* d = (char*)(void*)Marshal::StringToHGlobalAnsi(strd);
    cout << d << endl;


    return 0;
}
#endif // 0



