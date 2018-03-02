#pragma once

#include "MainVideoWnd.h"
#include "CarEyePlayerManager.h"

#define WM_TIMER_START_ID 1001
#define WM_TIMER_CONFIG_ID 1002

// CarEyePlayerWebActiveXCtrl.h : CCarEyePlayerWebActiveXCtrl ActiveX �ؼ����������

// CCarEyePlayerWebActiveXCtrl : �й�ʵ�ֵ���Ϣ������� CarEyePlayerWebActiveXCtrl.cpp��

class CCarEyePlayerWebActiveXCtrl : public COleControl
{
	DECLARE_DYNCREATE(CCarEyePlayerWebActiveXCtrl)

// ���캯��
public:
	CCarEyePlayerWebActiveXCtrl();

// ��д
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// ʵ��
protected:
	~CCarEyePlayerWebActiveXCtrl();

	BEGIN_OLEFACTORY(CCarEyePlayerWebActiveXCtrl)        // �๤���� guid
		virtual BOOL VerifyUserLicense();
		virtual BOOL GetLicenseKey(DWORD, BSTR *);
	END_OLEFACTORY(CCarEyePlayerWebActiveXCtrl)

	DECLARE_OLETYPELIB(CCarEyePlayerWebActiveXCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CCarEyePlayerWebActiveXCtrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(CCarEyePlayerWebActiveXCtrl)		// �������ƺ�����״̬

// ��Ϣӳ��
	DECLARE_MESSAGE_MAP()

// ����ӳ��
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// �¼�ӳ��
	DECLARE_EVENT_MAP()

// ���Ⱥ��¼� ID
public:
	enum {
		eventidOnPlayEvent = 1L,
		dispidSetOSD = 4L,
		dispidClose = 3L,
		dispidConfig = 2L,
		dispidStart = 1L
	};

	CMainVideoWnd m_pActiveDlg; 
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
protected:
	LONG Start(LPCTSTR sURL, LPCTSTR sRenderFormat, LPCTSTR sUserName, LPCTSTR sPassword, LPCTSTR sHardDecord);
	void Config(LPCTSTR sFrameCache, LPCTSTR sPlaySound, LPCTSTR sShowToScale, LPCTSTR sShowStatisticInfo);
	void SetOSD(LPCTSTR show, LPCTSTR alpha, LPCTSTR red, LPCTSTR green, LPCTSTR blue, LPCTSTR left, LPCTSTR top, LPCTSTR right, LPCTSTR bottom, LPCTSTR strOSD);
	void Close(void);
	static int CALLBACK CarEyePlayerCallBack( int _channelId, int *_channelPtr, int _frameType, char *pBuf, CAREYE_RTSP_FRAME_INFO* _frameInfo);

private:
	CarEyePlayerManager m_player;
	bool m_bInit;

	char szURL[512] ;
	char szUserName[128] ;
	char szPassword[128] ;

	int nHardDecode;
    RENDER_FORMAT eRenderFormat;

	int	   nFrameCache ;
	BOOL bPlaySound ;
	BOOL bShowToScale ;
	BOOL bShowStatisticInfo ;

public:
	virtual void OnSetClientSite();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	void OnPlayEvent(LPCTSTR sPlayerErrorString)
	{
		FireEvent(eventidOnPlayEvent, EVENT_PARAM(VTS_BSTR), sPlayerErrorString);
	}
};

