
// 仿写_3_VS工程清理Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "仿写_3_VS工程清理.h"
#include "仿写_3_VS工程清理Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// C仿写_3_VS工程清理Dlg 对话框



C仿写_3_VS工程清理Dlg::C仿写_3_VS工程清理Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C仿写_3_VS工程清理Dlg::IDD, pParent)
	, m_cEdit_DelFilePaths(_T(""))
	, m_cEdit_DelFileTypes(_T("\.db\.obj\.tlog\.lastbuildstate\.idb\.pdb\.pch\.res\.ilk\.sdf\.ipch\.log"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C仿写_3_VS工程清理Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCSHELLTREE1, m_objTree);
	DDX_Control(pDX, IDC_MFCSHELLLIST1, m_objList);
	DDX_Text(pDX, IDC_EDIT1, m_cEdit_DelFilePaths);
	DDX_Text(pDX, IDC_EDIT2, m_cEdit_DelFileTypes);
	DDX_Control(pDX, IDC_EDIT1, m_cstrEdit_DelFilePaths);
}

BEGIN_MESSAGE_MAP(C仿写_3_VS工程清理Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DROPFILES()
	ON_BN_CLICKED(ID_OK, &C仿写_3_VS工程清理Dlg::OnBnClickedOk)
	ON_NOTIFY(NM_DBLCLK, IDC_MFCSHELLTREE1, &C仿写_3_VS工程清理Dlg::OnDblclkMfcshelltree)
	ON_BN_CLICKED(IDC_BUTTON1, &C仿写_3_VS工程清理Dlg::OnBnClickedReset)
END_MESSAGE_MAP()


// C仿写_3_VS工程清理Dlg 消息处理程序

BOOL C仿写_3_VS工程清理Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	//=============绑定tree跟list====================

	m_objTree.SetRelatedList(&m_objList);


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C仿写_3_VS工程清理Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C仿写_3_VS工程清理Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C仿写_3_VS工程清理Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C仿写_3_VS工程清理Dlg::OnDropFiles(HDROP hDropInfo)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	
	UpdateData(TRUE);
	OnBnClickedReset();
	TCHAR FileName[MAX_PATH];
	int FileNum = DragQueryFile(hDropInfo, -1, FileName, 0); //拖拉的文件个数

	for (int i = 0; i < FileNum; i++) {
		DragQueryFile(hDropInfo, i, FileName, 300); //取得每个文件的文件名		
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

void C仿写_3_VS工程清理Dlg::findAllFileTree(CString path, CString delFileType)
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


void C仿写_3_VS工程清理Dlg::OnBnClickedOk()
{
	int resule = MessageBox(TEXT("删除不可逆,确定删除"), TEXT("提示"), MB_OKCANCEL);	
	if (resule==IDOK)
	{
		delAllFile();
		MessageBox(_T("清理完毕"));
	}
}

void C仿写_3_VS工程清理Dlg::OnBnClickedReset()
{
	m_veDelFilePaths.clear();				//待删除的所有文件,用于删除
	m_cEdit_DelFilePaths = _T("");			//待删除的所有文件,用于展示
	m_selectPath = _T("");					//选中的要删除的路径
	UpdateData(FALSE);

}
void C仿写_3_VS工程清理Dlg::delAllFile()
{
	
	for (int i = 0; i < m_veDelFilePaths.size(); i++)
	{
		DeleteFile(m_veDelFilePaths[i]);
	}
	m_veDelFilePaths.clear();
}


void C仿写_3_VS工程清理Dlg::OnDblclkMfcshelltree(NMHDR *pNMHDR, LRESULT *pResult)
{
	
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);

	UpdateData(TRUE);
	OnBnClickedReset();
	//获取选中项	
	m_objTree.GetItemPath(m_selectPath, m_objTree.GetSelectedItem());
	findAllFileTree(m_selectPath, m_cEdit_DelFileTypes);
	for (int i = 0; i < m_veDelFilePaths.size(); i++)
	{
		m_cEdit_DelFilePaths = m_cEdit_DelFilePaths + m_veDelFilePaths[i] + L"\r\n";
	}
	UpdateData(FALSE);

	*pResult = 0;
}



