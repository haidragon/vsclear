
// ��д_3_VS��������.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C��д_3_VS��������App: 
// �йش����ʵ�֣������ ��д_3_VS��������.cpp
//

class C��д_3_VS��������App : public CWinApp
{
public:
	C��д_3_VS��������App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C��д_3_VS��������App theApp;