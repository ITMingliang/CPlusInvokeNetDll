// CallTest.cpp: 主项目文件。

#include "stdafx.h"
#include <iostream>
#include "Mes.h"
using namespace std;


#if 1
int main()
{
    //request
    MesInterface p = MesInterface();
    char* Sn; char* strJson; char* strErr;
    Sn = "123456789";strJson = "";strErr = "";

    bool f1 = p.BoeMes_Resqust(Sn, strJson, strErr);

    cout << "strJson:" << p.strRet_Json << endl;
    cout << "strErr:" <<  p.strRet_Err << endl;

    //trackout
    bool result; char* ErrorCode; char* ErrorMsg; 
    result = f1;
    ErrorCode = "ER10001";
    ErrorMsg = strErr;
    strErr = "";

    bool f2 = p.BoeMes_TrackOut(Sn, result, ErrorCode, ErrorMsg, strErr);
    cout << "strErr:" << p.strRet_Err << endl;


    //测试
    goto Exit_Run;
    cout << "123" << endl;
Exit_Run:
    cout << "456" << endl;

    return 0;
}
#endif // 1


