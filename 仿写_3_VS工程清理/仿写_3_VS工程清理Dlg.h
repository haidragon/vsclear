
// ��д_3_VS��������Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxshelltreectrl.h"
#include "afxshelllistctrl.h"
#include <vector>
#include "FileControl.h"
#include "afxwin.h"
using std::vector;

// C��д_3_VS��������Dlg �Ի���
class C��д_3_VS��������Dlg : public CDialogEx
{
// ����
public:
	C��д_3_VS��������Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD__3_VS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CMFCShellTreeCtrl m_objTree;			//tree�ؼ�
	CMFCShellListCtrl m_objList;			//list�ؼ�
	CString m_cEdit_DelFilePaths;			//��ɾ���������ļ�,����չʾ
	CEdit   m_cstrEdit_DelFilePaths;		//չʾ�ؼ�
	CString m_cEdit_DelFileTypes;			//��ɾ�����ļ���׺����
	vector<CString> m_veDelFilePaths;		//��ɾ���������ļ�,����ɾ��
	CFileControl m_fileCtrl;				//�ļ�������,���ڱ���ɾ���Ȳ���
	CString m_selectPath;					//ѡ�е�Ҫɾ����·��
	
	afx_msg void OnDropFiles(HDROP hDropInfo);

	void findAllFileTree(CString path, CString delFileType);
	void delAllFile();


	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedReset();
	afx_msg void OnDblclkMfcshelltree(NMHDR *pNMHDR, LRESULT *pResult);
};
