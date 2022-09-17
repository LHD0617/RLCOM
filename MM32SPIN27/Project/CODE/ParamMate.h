/*
 * Copyright (C), 1988-1999, Xxxxxx Tech. Co., Ltd.
 * FileName: ParamMate.h
 * Description: ParamMate�����ļ�
 * Change Logs: 
  |Date          |Author       |Notes     			|version
  |2022-08-03    |���Ļ�ϲ     |Initial build     	|1.0.0
 */
 
#ifndef __PARAMMATE_H_
#define __PARAMMATE_H_

/*  Include  */
#include <stdlib.h>

/*  Data type  */
typedef unsigned char					PM_uint8;												//  8 bits 
typedef unsigned short int				PM_uint16;												// 16 bits 
typedef unsigned long int				PM_uint32;												// 32 bits 
typedef unsigned long long				PM_uint64;												// 64 bits 
		
typedef char							PM_int8;												//  8 bits 
typedef short int						PM_int16;												// 16 bits 
typedef long  int						PM_int32;												// 32 bits 
typedef long  long						PM_int64;												// 64 bits 

typedef volatile PM_int8				PM_vint8;												//  8 bits 
typedef volatile PM_int16				PM_vint16;												// 16 bits 
typedef volatile PM_int32				PM_vint32;												// 32 bits 
typedef volatile PM_int64				PM_vint64;												// 64 bits 

typedef volatile PM_uint8				PM_vuint8;												//  8 bits 
typedef volatile PM_uint16				PM_vuint16;												// 16 bits 
typedef volatile PM_uint32				PM_vuint32;												// 32 bits 
typedef volatile PM_uint64				PM_vuint64;												// 64 bits 


/* @define REV_HANDLE */
#define REV_HANDLE					1					/* �Ƿ����ش����� */

/* @define PM_MAIN_WINDOW_ID */
#define PM_MAIN_WINDOW_ID			0xFF				/* ������ID */

/* @define PM_MAX_NAME_LEN */
#define PM_MAX_NAME_LEN				32					/* ��������ֽ��� */

/* @define PM_MAX_PARAM */
#define PM_MAX_PARAM				1					/* ���֧�ֲ����ؼ��� */

/* @define PM_MAX_WAVEFORM */
#define PM_MAX_WAVEFORM				3					/* ���֧��ʾ���ؼ��� */

/* @define PM_MAX_IMAGE */
#define PM_MAX_IMAGE				2					/* ���֧��ͼ���ؼ��� */

/* @define PM_MAX_PARAMCANNELS */
#define PM_MAX_PARAMCANNELS			32					/* �������ͨ���� */

/* @define PM_MAX_WAVEFORMCANNELS */
#define PM_MAX_WAVEFORMCANNELS		8					/* ʾ�����ͨ���� */

/* @define PM_MAX_WIDTH */
#define PM_MAX_WIDTH				188					/* ͼ������� */

/* @define PM_MAX_HEIGHT */
#define PM_MAX_HEIGHT				120					/* ͼ�����߶� */



/* @define PM_NULL */
#define PM_NULL						0					/* NULL */

/* @define PM_ERR */
#define PM_EOK           			0 					/* �޴��� */
#define PM_ERROR         			1 					/* ��ͨ���� */
#define PM_ETIMEOUT      			2 					/* ��ʱ���� */
#define PM_EFULL         			3 					/* ��Դ���� */
#define PM_EINVAL       			4 					/* �Ƿ����� */
typedef	PM_uint8					PM_err;				/* ������ */


/* @enum RWMode_Type */
typedef enum{
	R_Type	=	1,										/* ֻ�� */
	W_Type	=	2,										/* ֻд */
	RW_Type	=	3,										/* ��д */
}RWMode_Type;

/* @enum Data_Type */
typedef enum{
	uint8_Type,											/* uint8 �� */
	uint16_Type,										/* uint16 �� */
	uint32_Type,										/* uint32 �� */
	int8_Type,								    		/* int8 �� */
	int16_Type,								    		/* int16 �� */
	int32_Type,								    		/* int32 �� */
	float_Type,								    		/* float �� */
}Data_Type;

/* @enum SeriesType */
typedef enum{
	LineSeries_Type,									/* ����ͼ */
	SplineSeries_Type,									/* ������ͼ */
	BarSeries_Type,										/* ����ͼ */
}Series_Type;

/* @enum Image_Type */
typedef enum{
	Binarization_Type,									/* ��ֵ��ͼ */
	Grayscale_Type,										/* �Ҷ�ͼ */
	RGB565_Type,										/* RGB565��ͼ */
}Image_Type;

/* @struct PM_Param_t */
typedef struct
{
	PM_uint8 ID;										/* ID */
	PM_uint8 Channels;									/* ����ͨ���� */
	PM_uint8 DataType[PM_MAX_PARAMCANNELS];				/* ������������ */
	void* DataAddrList[PM_MAX_PARAMCANNELS];			/* �������ݵ�ַ */
}PM_Param_t;

/* @struct PM_Waveform_t */
typedef struct
{
	PM_uint8 ID;										/* ID */
	PM_uint8 DataType;									/* ʾ���������� */
	PM_uint8 Channels;									/* ʾ��ͨ���� */
	void* DataAddrList[PM_MAX_WAVEFORMCANNELS];			/* ʾ�����ݵ�ַ */
}PM_Waveform_t;

/* @struct PM_Image_t */
typedef struct
{
	PM_uint8 ID;										/* ID */
	PM_uint8 ImageType;									/* ͼ������ */
	PM_uint8 Height;									/* ͼ��߶� */
	PM_uint8 Width;										/* ͼ���� */
	void* DataAddr;										/* ͼ�����ݵ�ַ */
}PM_Image_t;


/* @Function declarations */
void PM_ResetWindow(void);
void PM_InitWindow(void);
PM_Param_t* PM_CreateParam(PM_uint8 ID, const PM_int8* Name);
PM_err PM_CreateParamChannels(PM_Param_t* PM_Param, const PM_int8* Name, RWMode_Type ModeType,Data_Type DataType, void* DataAddr);
PM_Waveform_t* PM_CreateWaveform(PM_uint8 ID, const PM_int8* Name, Series_Type SeriesType, Data_Type DataType);
PM_err PM_CreateWaveformChannels(PM_Waveform_t* PM_Waveform, const PM_int8* Name, void* DataAddr);
PM_Image_t* PM_CreateImage(PM_uint8 ID, const PM_int8* Name, Image_Type ImageType, PM_uint8 Height, PM_uint8 Width, void* DataAddr);
void PM_SendParamData(PM_Param_t* PM_Param);
void PM_SendWaveformData(PM_Waveform_t* PM_Waveform);
void PM_SendImageData(PM_Image_t* PM_Image);
PM_uint8* PM_Strcpy(PM_uint8 *startaddr, const PM_int8 *strSrc);

#endif


