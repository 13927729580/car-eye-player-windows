// CarEyePlayerWebActiveXPropPage.cpp : CCarEyePlayerWebActiveXPropPage ����ҳ���ʵ�֡�

#include "stdafx.h"
#include "CarEyePlayerWebActiveX.h"
#include "CarEyePlayerWebActiveXPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CCarEyePlayerWebActiveXPropPage, COlePropertyPage)



// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CCarEyePlayerWebActiveXPropPage, COlePropertyPage)
END_MESSAGE_MAP()



// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CCarEyePlayerWebActiveXPropPage, "CarEyePLAYERWEBA.CarEyePlayerWebAPropPage.1",
	0xf594479c, 0x1a17, 0x49c7, 0xae, 0xf8, 0x86, 0x7a, 0x93, 0x2c, 0x20, 0xa2)



// CCarEyePlayerWebActiveXPropPage::CCarEyePlayerWebActiveXPropPageFactory::UpdateRegistry -
// ��ӻ��Ƴ� CCarEyePlayerWebActiveXPropPage ��ϵͳע�����

BOOL CCarEyePlayerWebActiveXPropPage::CCarEyePlayerWebActiveXPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_CarEyePLAYERWEBACTIVEX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CCarEyePlayerWebActiveXPropPage::CCarEyePlayerWebActiveXPropPage - ���캯��

CCarEyePlayerWebActiveXPropPage::CCarEyePlayerWebActiveXPropPage() :
	COlePropertyPage(IDD, IDS_CarEyePLAYERWEBACTIVEX_PPG_CAPTION)
{
}



// CCarEyePlayerWebActiveXPropPage::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CCarEyePlayerWebActiveXPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}



// CCarEyePlayerWebActiveXPropPage ��Ϣ�������
