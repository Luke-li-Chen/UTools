// UTool_MFC.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "UTool_MFC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//      ��Ӵ� DLL �������κε���
//      MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//      �ú�������ǰ�档
//
//      ����:
//
//      extern "C" BOOL PASCAL EXPORT ExportedFunction()
//      {
//          AFX_MANAGE_STATE(AfxGetStaticModuleState());
//          // �˴�Ϊ��ͨ������
//      }
//
//      �˺������κ� MFC ����
//      ������ÿ��������ʮ����Ҫ������ζ��
//      ��������Ϊ�����еĵ�һ�����
//      ���֣������������ж������������
//      ������Ϊ���ǵĹ��캯���������� MFC
//      DLL ���á�
//
//      �й�������ϸ��Ϣ��
//      ����� MFC ����˵�� 33 �� 58��
//

// CUTool_MFCApp

BEGIN_MESSAGE_MAP(CUTool_MFCApp, CWinApp)
END_MESSAGE_MAP()


// CUTool_MFCApp ����

CUTool_MFCApp::CUTool_MFCApp()
{
    // TODO: �ڴ˴���ӹ�����룬
    // ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CUTool_MFCApp ����

CUTool_MFCApp theApp;


// CUTool_MFCApp ��ʼ��

BOOL CUTool_MFCApp::InitInstance()
{
    CWinApp::InitInstance();

    return TRUE;
}
