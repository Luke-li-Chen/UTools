// Test_WinCMD.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"



#include "../UTool_MFC/Cast.h"
#include "../UTool_MFC/FloatingPoint.h"
#include "../UTool_MFC/Logger.h"

#ifdef _DEBUG
#pragma comment(lib, "../debug/UTool_MFC.lib")
#else
#pragma comment(lib, "../release/UTool_MFC.lib")
#endif

#include <math.h>

#include <limits>
using std::numeric_limits;

using namespace UTools::Cast;
using namespace UTools::FloatingPoint;
using std::string;

int _tmain(int argc, _TCHAR* argv[])
{
    clock_t tStart, tEnd;
    double val, val2;

    /*
    tStart = clock();

    for (int i = 0; i < 100000000; i++)
    {
        val = DoubleNaN_STL();
    }

    tEnd = clock();

    cout << "val = " << val << endl;
    printf("%f\n", val);
    cout << "STL time = " << (tEnd - tStart) << " ms." << endl;

    unsigned long long u = *(unsigned long long*)(&val);
    printf("%llx\n", u);

    tStart = clock();

    for (int i = 0; i < 100000000; i++)
    {
        val2 = DoubleNaN();
    }

    tEnd = clock();


    cout << "val = " << val2 << endl;
    printf("%f\n", val2);
    cout << "SELF time = " << (tEnd - tStart) << " ms." << endl;

    cout << "memcmp = " << memcmp(&val, &val2, 8) << endl;
    */

    //val = DoubleNZero();
    //val = numeric_limits<double>::signaling_NaN();

    //val = log((double)-1);  // -1.#IND00

    //int a = 0;
    //int b = 0;
    //scanf("%d", &b);

    //val = 0 / b;

    //printf("%f\n", val);
    //cout << "val = " << val << endl;



    //printf("%d\n", _isnan(val));
    //printf("%d\n", _finite(val));


    //LogFile log;
    //log.print("%d\n%s\n", 12, "asfsadf");
    Logger* log = new LogFile;

    log->print("hhhhhh");

    system("pause");
    return 0;
}

