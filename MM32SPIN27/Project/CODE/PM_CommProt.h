/*
 * Copyright (C), 1988-1999, Xxxxxx Tech. Co., Ltd.
 * FileName: PM_CommProt.h
 * Description: 通信协议栈
 * Change Logs: 
  |Date          |Author       |Notes     			|version
  |2022-08-03    |满心欢喜     |Initial build     	|1.0.0
 */
 
#ifndef __PM_COMMPORT_H_
#define __PM_COMMPORT_H_

#include "ParamMate.h"
#include "zf_uart.h"

/* @define PM_SendByte */
#define 	PM_SendByte(dat)				uart_putchar(UART1, dat)

/* @define PM_RESETWINDOW_COMM */
#define 	PM_PACKAGEHEAD					0x7A   			/* 数据包帧头 */

/* @define PM_RESETWINDOW_COMM */
#define 	PM_RESETWINDOW_COMM				0xA0   			/* 复位窗口消息类型 */

/* @define PM_RESETWINDOW_COMM */
#define 	PM_INITWINDOW_COMM				0xA1   			/* 初始化窗口消息类型 */

/* @define PM_CREATEPARAM_COMM */
#define 	PM_CREATEPARAM_COMM				0x10   			/* 创建参数控件消息类型 */

/* @define PM_CREATEWAVEFORM_COMM */
#define 	PM_CREATEWAVEFORM_COMM			0x11   			/* 创建示波控件消息类型 */

/* @define PM_RESETWINDOW_COMM */
#define 	PM_CREATEIMAGE_COMM				0x12   			/* 创建图传控件消息类型 */

/* @define PM_CREATEPARAM_COMM */
#define 	PM_CREATEPARAMCHANNELS_COMM		0x20   			/* 创建参数控件消息类型 */

/* @define PM_CREATEWAVEFORM_COMM */
#define 	PM_CREATEWAVEFORMCHANNELS_COMM	0x21   			/* 创建示波控件消息类型 */

/* @define PM_SENDPARAM_COMM */
#define 	PM_SENDPARAM_COMM				0x30   			/* 发送参数数据消息类型 */

/* @define PM_SENDWAVEFORM_COMM */
#define 	PM_SENDWAVEFORM_COMM			0x31   			/* 发送示波数据消息类型 */

/* @define PM_SENDIMAGE_COMM */
#define 	PM_SENDIMAGE_COMM				0x32   			/* 发送图传数据消息类型 */


/* @struct PM_CommMsg_t */
typedef struct
{
	PM_uint8 		Head;
	PM_uint8 		Type;
	PM_uint8		ID;
	PM_uint16		Length;
	void*			DataP;
}PM_CommMsg_t;


/* @struct PM_RevCommMsg_t */
typedef struct
{
	PM_uint8		RevEnd;
	PM_uint8		TranFlag;
	PM_uint8		RevLen;
	PM_uint8 		Head;
	PM_uint8 		Type;
	PM_uint8		ID;
	PM_uint16		Length;
	PM_uint8		DataBuf[5];
}PM_RevCommMsg_t;



/* @Function declarations */
void PM_SendMessage(PM_uint8 Type, PM_uint8 ID, PM_uint16 Length, void* DataP);
void PM_SendPackect(PM_CommMsg_t* PM_CommMsg);
void PM_TranSendByte(PM_uint8 dat);
void PM_SendBinImage(PM_Image_t* PM_Image);
void PM_RevHandle(PM_Param_t* Param, PM_uint8 dat);
void PM_ResetPackage(void);


#endif


