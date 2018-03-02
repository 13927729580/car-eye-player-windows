

#ifndef __LIB_CAREYE_PLAYER_API_H__
#define __LIB_CAREYE_PLAYER_API_H__

#include <winsock2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ����Ƶ֡��ʶ */
#define CAREYE_SDK_VIDEO_FRAME_FLAG	0x00000001		/* ��Ƶ֡��־ */
#define CAREYE_SDK_AUDIO_FRAME_FLAG	0x00000002		/* ��Ƶ֡��־ */
#define CAREYE_SDK_EVENT_FRAME_FLAG	0x00000004		/* �¼�֡��־ */
#define CAREYE_SDK_RTP_FRAME_FLAG		0x00000008		/* RTP֡��־ */
#define CAREYE_SDK_SDP_FRAME_FLAG		0x00000010		/* SDP֡��־ */
#define CAREYE_SDK_MEDIA_INFO_FLAG		0x00000020		/* ý�����ͱ�־*/
#define CAREYE_SDK_DECODE_VIDEO_FLAG 0x00000040		/* ������Ƶ���ͱ�־*/
#define CAREYE_SDK_DECODE_AUDO_FLAG	 0x00000080		/* ������Ƶ���ͱ�־*/
#define CAREYE_SDK_EVENT_CODEC_ERROR	0x63657272	/* ERROR */
#define CAREYE_SDK_EVENT_CODEC_EXIT	0x65786974	/* EXIT */
#define CAREYE_SDK_EVENT_CODEC_SHOT_START	    0x12001	/* Screen shot start*/
#define CAREYE_SDK_EVENT_CODEC_SLOT_STOP		0x12002	/* Screen shot stop */
#define CAREYE_SDK_EVENT_CODEC_RECORD_START	0x12003	/* Record Start */
#define CAREYE_SDK_EVENT_CODEC_RECORD_STOP	0x12004	/* Record Stop */

#define LIB_CAREYEPLAYER_API __declspec(dllexport)

typedef enum __RENDER_FORMAT
{
	DISPLAY_FORMAT_YV12		=		842094169,
	DISPLAY_FORMAT_YUY2		=		844715353,
	DISPLAY_FORMAT_UYVY		=		1498831189,
	DISPLAY_FORMAT_A8R8G8B8	=		21,
	DISPLAY_FORMAT_X8R8G8B8	=		22,
	DISPLAY_FORMAT_RGB565	=		23,
	DISPLAY_FORMAT_RGB555	=		25,

	DISPLAY_FORMAT_RGB24_GDI=		26
}RENDER_FORMAT;


typedef struct tagCAREYE_PALYER_OSD
{
	char	stOSD[1024];
	DWORD	alpha;		//0-255
	DWORD	color;		//RGB(0xf9,0xf9,0xf9)
	DWORD	shadowcolor;		//RGB(0x4d,0x4d,0x4d) ȫΪ0����͸��
	RECT	rect;		//OSD����ͼ�����Ͻ���ʾ����
	int			size;		//just D3D Support
}CAREYE_PALYER_OSD;

typedef struct tagCAREYE_MEDIA_INFO
{
	unsigned int	video_codec;		/* ����Ƶ��ʽ */
	unsigned char	fps;				/* ��Ƶ֡�� */
	unsigned short	width;				/* ��Ƶ�� */
	unsigned short  height;				/* ��Ƶ�� */

	unsigned int	audio_codec;		/* ����Ƶ��ʽ */
	unsigned int	sample_rate;		/* ��Ƶ������ */
	unsigned int	channels;			/* ��Ƶ������ */
	unsigned int	bits_per_sample;	/* ��Ƶ�������� */

	unsigned int	reserved1;			/* ��������1 */
	unsigned int	reserved2;			/* ��������2 */

}CAREYE_MEDIA_INFO;


/* ֡��Ϣ */
typedef struct 
{
	unsigned int	codec;				/* ����Ƶ��ʽ */

	unsigned int	type;				/* ��Ƶ֡���� */
	unsigned char	fps;				/* ��Ƶ֡�� */
	unsigned short	width;				/* ��Ƶ�� */
	unsigned short  height;				/* ��Ƶ�� */

	unsigned int	reserved1;			/* ��������1 */
	unsigned int	reserved2;			/* ��������2 */

	unsigned int	sample_rate;		/* ��Ƶ������ */
	unsigned int	channels;			/* ��Ƶ������ */
	unsigned int	bits_per_sample;	/* ��Ƶ�������� */

	unsigned int	length;				/* ����Ƶ֡��С */
	unsigned int    timestamp_usec;		/* ʱ���,΢�� */
	unsigned int	timestamp_sec;		/* ʱ��� �� */

	float			bitrate;			/* ������ */
	float			losspacket;			/* ������ */
}CAREYE_RTSP_FRAME_INFO;


typedef int (CALLBACK *MediaSourceCallBack)( int _channelId, int *_channelPtr, int _frameType, char *pBuf, CAREYE_RTSP_FRAME_INFO* _frameInfo);

LIB_CAREYEPLAYER_API int CarEyePlayer_Init(const char* key);
LIB_CAREYEPLAYER_API void CarEyePlayer_Release();

LIB_CAREYEPLAYER_API int CarEyePlayer_OpenStream(const char *url, HWND hWnd, RENDER_FORMAT renderFormat, 
	int rtpovertcp, const char *username, const char *password, MediaSourceCallBack callback=NULL, void *userPtr=NULL, bool bHardDecode=true);
LIB_CAREYEPLAYER_API void CarEyePlayer_CloseStream(int channelId);
LIB_CAREYEPLAYER_API int CarEyePlayer_SetFrameCache(int channelId, int cache);
LIB_CAREYEPLAYER_API int CarEyePlayer_SetShownToScale(int channelId, int shownToScale);
LIB_CAREYEPLAYER_API int CarEyePlayer_SetDecodeType(int channelId, int decodeKeyframeOnly);
LIB_CAREYEPLAYER_API int CarEyePlayer_SetRenderRect(int channelId, LPRECT lpSrcRect);
LIB_CAREYEPLAYER_API int CarEyePlayer_ShowStatisticalInfo(int channelId, int show);
LIB_CAREYEPLAYER_API int CarEyePlayer_ShowOSD(int channelId, int show, CAREYE_PALYER_OSD osd);
LIB_CAREYEPLAYER_API int CarEyePlayer_GetMediaInfo(int channelId, CAREYE_MEDIA_INFO& mediaInfo);

LIB_CAREYEPLAYER_API int CarEyePlayer_SetDragStartPoint(int channelId, POINT pt);
LIB_CAREYEPLAYER_API int CarEyePlayer_SetDragEndPoint(int channelId, POINT pt);
LIB_CAREYEPLAYER_API int CarEyePlayer_ResetDragPoint(int channelId);

LIB_CAREYEPLAYER_API int CarEyePlayer_StartManuRecording(int channelId);
LIB_CAREYEPLAYER_API int CarEyePlayer_StopManuRecording(int channelId);

LIB_CAREYEPLAYER_API int CarEyePlayer_PlaySound(int channelId);
LIB_CAREYEPLAYER_API int CarEyePlayer_StopSound();

LIB_CAREYEPLAYER_API int		CarEyePlayer_SetManuRecordPath(int channelId, const char* recordPath);
LIB_CAREYEPLAYER_API int		CarEyePlayer_SetManuPicShotPath(int channelId, const char* shotPath);

LIB_CAREYEPLAYER_API int		CarEyePlayer_StartManuPicShot(int channelId);//pThread->manuScreenshot
LIB_CAREYEPLAYER_API int		CarEyePlayer_StopManuPicShot(int channelId);

#endif
