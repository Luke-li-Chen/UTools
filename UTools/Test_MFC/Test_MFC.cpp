
// Test_MFC.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "Test_MFC.h"
#include "Test_MFCDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTest_MFCApp

BEGIN_MESSAGE_MAP(CTest_MFCApp, CWinApp)
    ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CTest_MFCApp ����

CTest_MFCApp::CTest_MFCApp()
{
    // ֧����������������
    m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

    // TODO: �ڴ˴���ӹ�����룬
    // ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CTest_MFCApp ����

CTest_MFCApp theApp;


// CTest_MFCApp ��ʼ��

BOOL CTest_MFCApp::InitInstance()
{
    // ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
    // ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
    //����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
    INITCOMMONCONTROLSEX InitCtrls;
    InitCtrls.dwSize = sizeof(InitCtrls);
    // ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
    // �����ؼ��ࡣ
    InitCtrls.dwICC = ICC_WIN95_CLASSES;
    InitCommonControlsEx(&InitCtrls);

    CWinApp::InitInstance();

    if (!AfxSocketInit())
    {
        AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
        return FALSE;
    }


    AfxEnableControlContainer();

    // ���� shell ���������Է��Ի������
    // �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
    CShellManager *pShellManager = new CShellManager;

    // ��׼��ʼ��
    // ���δʹ����Щ���ܲ�ϣ����С
    // ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
    // ����Ҫ���ض���ʼ������
    // �������ڴ洢���õ�ע�����
    // TODO: Ӧ�ʵ��޸ĸ��ַ�����
    // �����޸�Ϊ��˾����֯��
    SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

    CTest_MFCDlg dlg;
    m_pMainWnd = &dlg;
    INT_PTR nResponse = dlg.DoModal();
    if (nResponse == IDOK)
    {
        // TODO: �ڴ˷��ô����ʱ��
        //  ��ȷ�������رնԻ���Ĵ���
    }
    else if (nResponse == IDCANCEL)
    {
        // TODO: �ڴ˷��ô����ʱ��
        //  ��ȡ�������رնԻ���Ĵ���
    }

    // ɾ�����洴���� shell ��������
    if (pShellManager != NULL)
    {
        delete pShellManager;
    }

    // ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
    //  ����������Ӧ�ó������Ϣ�á�
    return FALSE;
}

