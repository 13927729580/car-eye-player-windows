#pragma once

// CarEyePlayerWebActiveXPropPage.h : CCarEyePlayerWebActiveXPropPage ����ҳ���������


// CCarEyePlayerWebActiveXPropPage : �й�ʵ�ֵ���Ϣ������� CarEyePlayerWebActiveXPropPage.cpp��

class CCarEyePlayerWebActiveXPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CCarEyePlayerWebActiveXPropPage)
	DECLARE_OLECREATE_EX(CCarEyePlayerWebActiveXPropPage)

// ���캯��
public:
	CCarEyePlayerWebActiveXPropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_CarEyePLAYERWEBACTIVEX };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};

