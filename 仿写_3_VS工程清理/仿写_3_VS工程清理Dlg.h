
// 仿写_3_VS工程清理Dlg.h : 头文件
//

#pragma once
#include "afxshelltreectrl.h"
#include "afxshelllistctrl.h"
#include <vector>
#include "FileControl.h"
#include "afxwin.h"
using std::vector;

// C仿写_3_VS工程清理Dlg 对话框
class C仿写_3_VS工程清理Dlg : public CDialogEx
{
// 构造
public:
	C仿写_3_VS工程清理Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD__3_VS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CMFCShellTreeCtrl m_objTree;			//tree控件
	CMFCShellListCtrl m_objList;			//list控件
	CString m_cEdit_DelFilePaths;			//待删除的所有文件,用于展示
	CEdit   m_cstrEdit_DelFilePaths;		//展示控件
	CString m_cEdit_DelFileTypes;			//待删除的文件后缀集合
	vector<CString> m_veDelFilePaths;		//待删除的所有文件,用于删除
	CFileControl m_fileCtrl;				//文件管理类,用于遍历删除等操作
	CString m_selectPath;					//选中的要删除的路径
	
	afx_msg void OnDropFiles(HDROP hDropInfo);

	void findAllFileTree(CString path, CString delFileType);
	void delAllFile();


	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedReset();
	afx_msg void OnDblclkMfcshelltree(NMHDR *pNMHDR, LRESULT *pResult);
};
