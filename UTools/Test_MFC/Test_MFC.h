
// Test_MFC.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
    #error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CTest_MFCApp:
// �йش����ʵ�֣������ Test_MFC.cpp
//

class CTest_MFCApp : public CWinApp
{
public:
    CTest_MFCApp();

// ��д
public:
    virtual BOOL InitInstance();

// ʵ��

    DECLARE_MESSAGE_MAP()
};

extern CTest_MFCApp theApp;