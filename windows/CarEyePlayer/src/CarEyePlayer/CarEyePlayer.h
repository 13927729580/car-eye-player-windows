
// CarEyePlayer.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������

// get program path for globle use [6/12/2016 SwordTwelve]
// ͨ�ýṹ���� 
struct ModuleFileInfomations
{
	CString		strFullPath;
	CString		strPath;
	CString		strDrive;
	CString		strDir;
	CString		strName;
	CString		strExt;
};
const ModuleFileInfomations&    GetModuleFileInformations();

#define GET_MODULE_FILE_INFO    (GetModuleFileInformations())

// CCarEyePlayerApp:
// �йش����ʵ�֣������ CarEyePlayer.cpp
//

class CCarEyePlayerApp : public CWinApp
{
public:
	CCarEyePlayerApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual int ExitInstance();
};

extern CCarEyePlayerApp theApp;