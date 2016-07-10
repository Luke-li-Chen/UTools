// Test_MFCCMD.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Test_MFCCMD.h"
#include "..\UTool_MFC\Lock.h"
#include <vector>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 唯一的应用程序对象

CWinApp theApp;

using namespace std;


//#define ENABLE_MUTEX  
#define ENABLE_CRITICAL_SECTION  


#if defined (ENABLE_MUTEX)  

//创建一个互斥对象类型锁  
Mutex g_Lock;

#elif defined (ENABLE_CRITICAL_SECTION)  

//创建一个临界区类型锁  
CriSection g_Lock;

#endif  

int g_I = 10;
vector<int> v;

void LockCompare(int &iNum)
{
    CMyLock lock1(g_Lock);

    iNum++;
}


//线程函数  
unsigned int __stdcall StartThread(void *pParam)
{
    char *pMsg = (char *)pParam;
    if (!pMsg)
    {
        return (unsigned int)1;
    }

    CMyLock lock2(g_Lock);

    clock_t tStart, tEnd;

    tStart = clock();

    int iNum = 0;
    for (int i = 0; i < 100000; i++)
    {
        LockCompare(iNum);
    }

    tEnd = clock();
#if defined (ENABLE_MUTEX)  

    cout << "The lock type is mutex, time = " << (tEnd - tStart) << " ms." << endl;

#elif defined (ENABLE_CRITICAL_SECTION)  

    cout << "The lock type is critical section, time = " << (tEnd - tStart) << " ms." << endl;

#endif  

    return (unsigned int)0;
}

UINT Therad1(LPVOID pParam)
{
    for (;;)
    {
        CMyLock lock1(g_Lock);
        g_I++;
        //printf("%d\n", g_I);
        //Sleep(1);
        v.push_back(g_I);
    };
}

UINT Therad2(LPVOID pParam)
{
    for (;;)
    {
        CMyLock lock1(g_Lock);
        g_I--;
        v.push_back(g_I);
        printf("%d\n", v.size());
        //Sleep(1);
    };
}

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule == nullptr)
    {
        // 更改错误代码以符合您的需要
        wprintf(L"错误: GetModuleHandle 失败\n");
        nRetCode = 1;

        system("pause");
        return nRetCode;
    }

    // 初始化 MFC 并在失败时显示错误
    if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
    {
        // 更改错误代码以符合您的需要
        wprintf(L"错误: MFC 初始化失败\n");
        nRetCode = 1;

        system("pause");
        return nRetCode;
    }



    // 在此处为应用程序的行为编写代码。
    cout << "hhh" << endl;



    HANDLE hThread1, hThread2;
    unsigned int uiThreadId1, uiThreadId2;

    char *pMsg1 = "First print thread.";
    char *pMsg2 = "Second print thread.";

    //创建两个工作线程，分别打印不同的消息  
    //hThread1 = (HANDLE)_beginthreadex(NULL, 0, &StartThread, (void *)pMsg1, 0, &uiThreadId1);
    //hThread2 = (HANDLE)_beginthreadex(NULL, 0, &StartThread, (void *)pMsg2, 0, &uiThreadId2);
    AfxBeginThread(Therad1, (LPVOID)(0));
    AfxBeginThread(Therad2, (LPVOID)(0));


    ////等待线程结束  
    //DWORD dwRet = WaitForSingleObject(hThread1, INFINITE);
    //if (dwRet == WAIT_TIMEOUT)
    //{
    //    TerminateThread(hThread1, 0);
    //}
    //dwRet = WaitForSingleObject(hThread2, INFINITE);
    //if (dwRet == WAIT_TIMEOUT)
    //{
    //    TerminateThread(hThread2, 0);
    //}

    ////关闭线程句柄，释放资源  
    //::CloseHandle(hThread1);
    //::CloseHandle(hThread2);



    system("pause");
    return nRetCode;
}
