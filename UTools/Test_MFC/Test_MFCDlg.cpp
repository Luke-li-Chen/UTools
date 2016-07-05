
// Test_MFCDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Test_MFC.h"
#include "Test_MFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "../UTool_MFC/Cast.h"
#include "../UTool_MFC/IniFile.h"

//#pragma comment(lib, "../debug/UTool_MFC.lib")
#ifdef _WIN64
#pragma message("Is 64bit Program")
#ifdef _DEBUG
#pragma comment(lib, "../x64/debug/UTool_MFC.lib")
#else
#pragma comment(lib, "../x64/release/UTool_MFC.lib")
#endif
#else
#pragma message("Is 32bit Program")
#ifdef _DEBUG
#pragma comment(lib, "../debug/UTool_MFC.lib")
#else
#pragma comment(lib, "../release/UTool_MFC.lib")
#endif
#endif

using namespace UTools::Cast;
using UTools::IniFile;
using std::string;

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
    CAboutDlg();

// �Ի�������
    enum { IDD = IDD_ABOUTBOX };

    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
    DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTest_MFCDlg �Ի���




CTest_MFCDlg::CTest_MFCDlg(CWnd* pParent /*=NULL*/)
    : CDialogEx(CTest_MFCDlg::IDD, pParent)
    , m_csTest(_T(""))
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTest_MFCDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT_TEST, m_csTest);
}

BEGIN_MESSAGE_MAP(CTest_MFCDlg, CDialogEx)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON_TEST, &CTest_MFCDlg::OnBnClickedButtonTest)
END_MESSAGE_MAP()


// CTest_MFCDlg ��Ϣ�������

BOOL CTest_MFCDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // ��������...���˵�����ӵ�ϵͳ�˵��С�

    // IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
    ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
    ASSERT(IDM_ABOUTBOX < 0xF000);

    CMenu* pSysMenu = GetSystemMenu(FALSE);
    if (pSysMenu != NULL)
    {
        BOOL bNameValid;
        CString strAboutMenu;
        bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
        ASSERT(bNameValid);
        if (!strAboutMenu.IsEmpty())
        {
            pSysMenu->AppendMenu(MF_SEPARATOR);
            pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
        }
    }

    // ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
    //  ִ�д˲���
    SetIcon(m_hIcon, TRUE);            // ���ô�ͼ��
    SetIcon(m_hIcon, FALSE);        // ����Сͼ��

    // TODO: �ڴ���Ӷ���ĳ�ʼ������

    return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CTest_MFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
    if ((nID & 0xFFF0) == IDM_ABOUTBOX)
    {
        CAboutDlg dlgAbout;
        dlgAbout.DoModal();
    }
    else
    {
        CDialogEx::OnSysCommand(nID, lParam);
    }
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTest_MFCDlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this); // ���ڻ��Ƶ��豸������

        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        // ʹͼ���ڹ����������о���
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // ����ͼ��
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialogEx::OnPaint();
    }
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTest_MFCDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}



void CTest_MFCDlg::OnBnClickedButtonTest()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������

    //string a = Cast::int2string(2);

    //CString cs = "Hello";
    ////CString cs2;
    //m_csTest = Cast::add(cs);
    //UpdateData(FALSE);
    //AfxMessageBox(cs2);

    /*
    IniFile f;

    char s[5];
    f.GetPchar(nullptr, nullptr, 100000, s);
    */

    CString s("Hello!");
    char sz[50];
    CStringAToCharArray(s, sz, 3);
    TRACE("%s\n", sz);

}
