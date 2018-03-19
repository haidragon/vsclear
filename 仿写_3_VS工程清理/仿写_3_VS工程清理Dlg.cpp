
// ��д_3_VS��������Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��д_3_VS��������.h"
#include "��д_3_VS��������Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// C��д_3_VS��������Dlg �Ի���



C��д_3_VS��������Dlg::C��д_3_VS��������Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C��д_3_VS��������Dlg::IDD, pParent)
	, m_cEdit_DelFilePaths(_T(""))
	, m_cEdit_DelFileTypes(_T("\.db\.obj\.tlog\.lastbuildstate\.idb\.pdb\.pch\.res\.ilk\.sdf\.ipch\.log"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C��д_3_VS��������Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCSHELLTREE1, m_objTree);
	DDX_Control(pDX, IDC_MFCSHELLLIST1, m_objList);
	DDX_Text(pDX, IDC_EDIT1, m_cEdit_DelFilePaths);
	DDX_Text(pDX, IDC_EDIT2, m_cEdit_DelFileTypes);
	DDX_Control(pDX, IDC_EDIT1, m_cstrEdit_DelFilePaths);
}

BEGIN_MESSAGE_MAP(C��д_3_VS��������Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DROPFILES()
	ON_BN_CLICKED(ID_OK, &C��д_3_VS��������Dlg::OnBnClickedOk)
	ON_NOTIFY(NM_DBLCLK, IDC_MFCSHELLTREE1, &C��д_3_VS��������Dlg::OnDblclkMfcshelltree)
	ON_BN_CLICKED(IDC_BUTTON1, &C��д_3_VS��������Dlg::OnBnClickedReset)
END_MESSAGE_MAP()


// C��д_3_VS��������Dlg ��Ϣ�������

BOOL C��д_3_VS��������Dlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	//=============��tree��list====================

	m_objTree.SetRelatedList(&m_objList);


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C��д_3_VS��������Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C��д_3_VS��������Dlg::OnPaint()
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
HCURSOR C��д_3_VS��������Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C��д_3_VS��������Dlg::OnDropFiles(HDROP hDropInfo)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	UpdateData(TRUE);
	OnBnClickedReset();
	TCHAR FileName[MAX_PATH];
	int FileNum = DragQueryFile(hDropInfo, -1, FileName, 0); //�������ļ�����

	for (int i = 0; i < FileNum; i++) {
		DragQueryFile(hDropInfo, i, FileName, 300); //ȡ��ÿ���ļ����ļ���		
		findAllFileTree(FileName, m_cEdit_DelFileTypes);		
	}
	if (FileNum>=1)
	{
		m_objTree.SelectPath(FileName);
		m_selectPath = FileName;
	
	}

	for (int i = 0; i < m_veDelFilePaths.size(); i++)
	{
		m_cEdit_DelFilePaths = m_cEdit_DelFilePaths+m_veDelFilePaths[i] + L"\r\n";
	}
	UpdateData(FALSE);
	CDialogEx::OnDropFiles(hDropInfo);
}

void C��д_3_VS��������Dlg::findAllFileTree(CString path, CString delFileType)
{
	list<FILE_INFO> lstFileInfo;
	m_fileCtrl.GetFileTree(path.GetBuffer(), lstFileInfo, 20);

	for (list<FILE_INFO>::iterator it = lstFileInfo.begin();
		it != lstFileInfo.end(); it++)
	{
		if (it->bIsFolder == TRUE)
		{
			continue;
		}
		CString szFullPath = it->szFullPath;
		int index = szFullPath.ReverseFind(_T('.'));
		szFullPath = szFullPath.Right(szFullPath.GetLength()-index);
		if (delFileType.Find(szFullPath)!=-1)
		{
			m_veDelFilePaths.push_back(it->szFullPath);
		}
	}


}


void C��д_3_VS��������Dlg::OnBnClickedOk()
{
	int resule = MessageBox(TEXT("ɾ��������,ȷ��ɾ��"), TEXT("��ʾ"), MB_OKCANCEL);	
	if (resule==IDOK)
	{
		delAllFile();
		MessageBox(_T("�������"));
	}
}

void C��д_3_VS��������Dlg::OnBnClickedReset()
{
	m_veDelFilePaths.clear();				//��ɾ���������ļ�,����ɾ��
	m_cEdit_DelFilePaths = _T("");			//��ɾ���������ļ�,����չʾ
	m_selectPath = _T("");					//ѡ�е�Ҫɾ����·��
	UpdateData(FALSE);

}
void C��д_3_VS��������Dlg::delAllFile()
{
	
	for (int i = 0; i < m_veDelFilePaths.size(); i++)
	{
		DeleteFile(m_veDelFilePaths[i]);
	}
	m_veDelFilePaths.clear();
}


void C��д_3_VS��������Dlg::OnDblclkMfcshelltree(NMHDR *pNMHDR, LRESULT *pResult)
{
	
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);

	UpdateData(TRUE);
	OnBnClickedReset();
	//��ȡѡ����	
	m_objTree.GetItemPath(m_selectPath, m_objTree.GetSelectedItem());
	findAllFileTree(m_selectPath, m_cEdit_DelFileTypes);
	for (int i = 0; i < m_veDelFilePaths.size(); i++)
	{
		m_cEdit_DelFilePaths = m_cEdit_DelFilePaths + m_veDelFilePaths[i] + L"\r\n";
	}
	UpdateData(FALSE);

	*pResult = 0;
}



