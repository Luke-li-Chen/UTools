// Test_WinCMD.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "../UTool_MFC/Cast.h"

#pragma comment(lib, "../debug/UTool_MFC.lib")

using namespace UTools::Cast;
using std::string;

int _tmain(int argc, _TCHAR* argv[])
{
    string str = IntToString(16);
    str += "abc";
    printf("%s\n", str.c_str());


    char* p = StringToNewCharArray(str);
    printf("%s\n", p);
    delete[] p;

    //Cast::add()

    system("pause");
    return 0;
}

