/*
 * Copyright (C), 1988-1999, Xxxxxx Tech. Co., Ltd.
 * FileName: ParamMate.h
 * Description: ParamMate驱动文件
 * Change Logs: 
  |Date          |Author       |Notes     			|version
  |2022-08-03    |满心欢喜     |Initial build     	|1.0.0
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
#define REV_HANDLE					1					/* 是否开启回传数据 */

/* @define PM_MAIN_WINDOW_ID */
#define PM_MAIN_WINDOW_ID			0xFF				/* 主窗口ID */

/* @define PM_MAX_NAME_LEN */
#define PM_MAX_NAME_LEN				32					/* 名称最大字节数 */

/* @define PM_MAX_PARAM */
#define PM_MAX_PARAM				1					/* 最大支持参数控件数 */

/* @define PM_MAX_WAVEFORM */
#define PM_MAX_WAVEFORM				3					/* 最大支持示波控件数 */

/* @define PM_MAX_IMAGE */
#define PM_MAX_IMAGE				2					/* 最大支持图传控件数 */

/* @define PM_MAX_PARAMCANNELS */
#define PM_MAX_PARAMCANNELS			32					/* 参数最大通道数 */

/* @define PM_MAX_WAVEFORMCANNELS */
#define PM_MAX_WAVEFORMCANNELS		8					/* 示波最大通道数 */

/* @define PM_MAX_WIDTH */
#define PM_MAX_WIDTH				188					/* 图像最大宽度 */

/* @define PM_MAX_HEIGHT */
#define PM_MAX_HEIGHT				120					/* 图像最大高度 */



/* @define PM_NULL */
#define PM_NULL						0					/* NULL */

/* @define PM_ERR */
#define PM_EOK           			0 					/* 无错误 */
#define PM_ERROR         			1 					/* 普通错误 */
#define PM_ETIMEOUT      			2 					/* 超时错误 */
#define PM_EFULL         			3 					/* 资源已满 */
#define PM_EINVAL       			4 					/* 非法参数 */
typedef	PM_uint8					PM_err;				/* 错误码 */


/* @enum RWMode_Type */
typedef enum{
	R_Type	=	1,										/* 只读 */
	W_Type	=	2,										/* 只写 */
	RW_Type	=	3,										/* 读写 */
}RWMode_Type;

/* @enum Data_Type */
typedef enum{
	uint8_Type,											/* uint8 型 */
	uint16_Type,										/* uint16 型 */
	uint32_Type,										/* uint32 型 */
	int8_Type,								    		/* int8 型 */
	int16_Type,								    		/* int16 型 */
	int32_Type,								    		/* int32 型 */
	float_Type,								    		/* float 型 */
}Data_Type;

/* @enum SeriesType */
typedef enum{
	LineSeries_Type,									/* 折线图 */
	SplineSeries_Type,									/* 样条线图 */
	BarSeries_Type,										/* 条形图 */
}Series_Type;

/* @enum Image_Type */
typedef enum{
	Binarization_Type,									/* 二值化图 */
	Grayscale_Type,										/* 灰度图 */
	RGB565_Type,										/* RGB565彩图 */
}Image_Type;

/* @struct PM_Param_t */
typedef struct
{
	PM_uint8 ID;										/* ID */
	PM_uint8 Channels;									/* 参数通道数 */
	PM_uint8 DataType[PM_MAX_PARAMCANNELS];				/* 参数数据类型 */
	void* DataAddrList[PM_MAX_PARAMCANNELS];			/* 参数数据地址 */
}PM_Param_t;

/* @struct PM_Waveform_t */
typedef struct
{
	PM_uint8 ID;										/* ID */
	PM_uint8 DataType;									/* 示波数据类型 */
	PM_uint8 Channels;									/* 示波通道数 */
	void* DataAddrList[PM_MAX_WAVEFORMCANNELS];			/* 示波数据地址 */
}PM_Waveform_t;

/* @struct PM_Image_t */
typedef struct
{
	PM_uint8 ID;										/* ID */
	PM_uint8 ImageType;									/* 图像类型 */
	PM_uint8 Height;									/* 图像高度 */
	PM_uint8 Width;										/* 图像宽度 */
	void* DataAddr;										/* 图像数据地址 */
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


