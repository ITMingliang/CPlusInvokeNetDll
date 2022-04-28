// CallTest.cpp: 主项目文件。

#include "stdafx.h"
#include <iostream>
#include "Mes.h"
#using "..\MesDLL\MesDLL.dll"
#using "..\MesDLL\IMSDLL.dll"
using namespace IMSDLL;
using namespace MesDLL;
using namespace std;


//String^与char*互相
using namespace System;                                                //String^库文件
using namespace System::Runtime::InteropServices;                      //Marchal库文件



#if 0
int main()
{

    //1.整形
    int sum, x, y;
    x = 10;
    y = 22;
    MathTest^ a = gcnew MathTest();
    sum = a->demoAdd(x, y);
    //printf("计算结果： %d", sum);
    cout << "计算结果:" << sum << endl;


    //2.字符串
    System::String^ xx = "x";
    System::String^ yy = "y";
    System::String^ ret = a->demoAddStr(xx, yy);
    char* cret1 = (char*)(void*)Marshal::StringToHGlobalAnsi(ret);
    //printf("计算结果： %s", a->demoAddStr(xx, yy));
    cout << "计算结果:" << cret1 << endl;


    //3.MES DLL
    MESFUNCTION^ ab = gcnew MESFUNCTION();
    //char* Sn, char** strJson, char** strErr;
    //const char* Sn, char** strJson, char** strErr;

    //为了与以前的指针区分开，用^来代替*
    System::String^ Sn = "11111111";
    System::String^ strJson = "";
    System::String^ strErr = "";
    bool f = ab->GetCommonData(Sn, strJson, strErr);
    char* cstrJson = (char*)(void*)Marshal::StringToHGlobalAnsi(strJson);
    char* cstrErr = (char*)(void*)Marshal::StringToHGlobalAnsi(strErr);
    //printf("strJson： %s", strJson);
    //printf("strErr： %s", strErr);
    cout << "strJson:" << cstrJson << endl;
    cout << "strErr:" << cstrErr << endl;


    //4.String^与char*互相转换测试
    char* c = "adsfdasf";
    String^ strd = gcnew String(c);
    char* d = (char*)(void*)Marshal::StringToHGlobalAnsi(strd);
    cout << d << endl;


    return 0;
}
#endif // 0



