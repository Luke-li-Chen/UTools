// UTool_MFC.h : UTool_MFC DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
    #error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"        // ������


// CUTool_MFCApp
// �йش���ʵ�ֵ���Ϣ������� UTool_MFC.cpp
//

class CUTool_MFCApp : public CWinApp
{
public:
    CUTool_MFCApp();

// ��д
public:
    virtual BOOL InitInstance();

    DECLARE_MESSAGE_MAP()
};
