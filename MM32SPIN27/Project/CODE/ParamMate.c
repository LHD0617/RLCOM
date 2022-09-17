/*
 * Copyright (C), 1988-1999, Xxxxxx Tech. Co., Ltd.
 * FileName: ParamMate.c
 * Description: ParamMate�����ļ�
 * Change Logs: 
  |Date          |Author       |Notes     			|version
  |2022-08-03    |���Ļ�ϲ     |Initial build     	|1.0.0
 */
 
#include "ParamMate.h"
#include "PM_CommProt.h"


/**
	* @name		PM_ResetWindow
	* @brief  	��λ����
	* @param  	void
	* @return 	void
	* @Sample 
  */
void PM_ResetWindow(void)
{
	PM_uint8 dat = 0x01;
	PM_SendMessage(PM_RESETWINDOW_COMM, PM_MAIN_WINDOW_ID, 0x01, &dat);
}

/**
	* @name		PM_InitWindow
	* @brief  	��ʼ������
	* @param  	void
	* @return 	void
	* @Sample 
  */
void PM_InitWindow(void)
{
	PM_uint8 dat = 0x01;
	PM_SendMessage(PM_INITWINDOW_COMM, PM_MAIN_WINDOW_ID, 0x01, &dat);
}

/**
	* @name		PM_CreateParam
	* @brief  	���������ؼ�
	* @param  	ID			�ؼ�ID����֤ȫ��Ψһ�ԣ�
	* @param  	Name		�ؼ����ƣ����⣩
	* @return 	�����ؼ��ṹ��ָ��
	* @Sample 	PM_CreateParam(0x00, "Test_param")
  */
PM_Param_t* PM_CreateParam(PM_uint8 ID, const PM_int8* Name)
{
	PM_uint8 datbuf[PM_MAX_NAME_LEN] = {0};
	PM_Param_t* PM_Param = (PM_Param_t*)malloc(sizeof(PM_Param_t));
	if(PM_Param == PM_NULL)
	{
		return PM_NULL;
	}
	PM_Param -> ID = ID;
	PM_Strcpy(datbuf, Name);
	PM_SendMessage(PM_CREATEPARAM_COMM, ID, sizeof(datbuf), datbuf);
	return PM_Param;
}

/**
	* @name		PM_CreateParamChannels
	* @brief  	��������ͨ��
	* @param  	PM_Param			�����ؼ�ָ��
	* @param  	Name				��������
	* @param  	ModeType			��д����
	* @param  	DataType			��������
	* @param  	DataAddr			���ݵ�ַ
	* @return 	������
	* @Sample 	PM_CreateParamChannels(PM_Param, "Test1",RW_Type, int8_Type, &test1)
  */
PM_err PM_CreateParamChannels(PM_Param_t* PM_Param, const PM_int8* Name, RWMode_Type ModeType,Data_Type DataType, void* DataAddr)
{
	PM_uint8 datbuf[PM_MAX_NAME_LEN + 2] = {0};
	PM_uint8* Dp = datbuf;
	if(PM_Param -> Channels >= PM_MAX_PARAMCANNELS)	return PM_EFULL;
	PM_Param -> DataType[PM_Param -> Channels] = DataType;
	PM_Param -> DataAddrList[PM_Param -> Channels++] = DataAddr;
	*Dp++ = DataType & 0xff;
	*Dp++ = ModeType & 0xff;
	Dp = PM_Strcpy(Dp, Name);
	PM_SendMessage(PM_CREATEPARAMCHANNELS_COMM, PM_Param -> ID, sizeof(datbuf), datbuf);
	return PM_EOK;
}

/**
	* @name		PM_CreateWaveform
	* @brief  	����ʾ���ؼ�
	* @param  	ID			�ؼ�ID����֤ȫ��Ψһ�ԣ�
	* @param  	Name		�ؼ����ƣ����⣩
	* @param  	SeriesType	�ؼ����ͣ����ParamMate.h�ļ�ö������
	* @param  	DataType	��������
	* @return 	ʾ���ؼ��ṹ��ָ��
	* @Sample 	PM_CreateWaveform(0x00, "Test_Waveform", SplineSeries_Type, uint16_Type)
  */
PM_Waveform_t* PM_CreateWaveform(PM_uint8 ID, const PM_int8* Name, Series_Type SeriesType, Data_Type DataType)
{
	PM_uint8 datbuf[PM_MAX_NAME_LEN + 2] = {0};
	PM_uint8* Dp = datbuf;
	PM_Waveform_t* PM_Waveform = (PM_Waveform_t*)malloc(sizeof(PM_Waveform_t));
	if(PM_Waveform == PM_NULL)
	{
		return PM_NULL;
	}
	PM_Waveform -> ID = ID;
	PM_Waveform -> DataType = DataType;
	*Dp++ = SeriesType & 0xff;
	*Dp++ = DataType & 0xff;
	Dp = PM_Strcpy(Dp, Name);
	PM_SendMessage(PM_CREATEWAVEFORM_COMM, ID, sizeof(datbuf), datbuf);
	return PM_Waveform;
}

/**
	* @name		PM_CreateWaveformChannels
	* @brief  	����ʾ��ͨ��
	* @param  	PM_Waveform			ʾ���ؼ�ָ��
	* @param  	Name				��������
	* @param  	DataAddr			���ݵ�ַ
	* @return 	������
	* @Sample 	PM_CreateWaveformChannels(PM_Waveform, "Test", &Test)
  */
PM_err PM_CreateWaveformChannels(PM_Waveform_t* PM_Waveform, const PM_int8* Name, void* DataAddr)
{
	PM_uint8 datbuf[PM_MAX_NAME_LEN] = {0};
	if(PM_Waveform -> Channels >= PM_MAX_WAVEFORMCANNELS)	return PM_EFULL;
	PM_Waveform -> DataAddrList[PM_Waveform -> Channels++] = DataAddr;
	PM_Strcpy(datbuf, Name);
	PM_SendMessage(PM_CREATEWAVEFORMCHANNELS_COMM, PM_Waveform -> ID, sizeof(datbuf), datbuf);
	return PM_EOK;
}

/**
	* @name		PM_CreateImage
	* @brief  	����ͼ���ؼ�
	* @param  	ID			�ؼ�ID����֤ȫ��Ψһ�ԣ�
	* @param  	Name		�ؼ����ƣ����⣩
	* @param  	ImageType	ͼ�����ͣ����ParamMate.h�ļ�ö������
	* @param  	Height		ͼ��߶�
	* @param  	Width		ͼ����
	* @param  	DataAddr	ͼ���ַ
	* @return 	ͼ���ؼ��ṹ��ָ��
	* @Sample 	PM_CreateImage(0x00, "TestImage1", Binarization_Type, 60, 90, image)
  */
PM_Image_t* PM_CreateImage(PM_uint8 ID, const PM_int8* Name, Image_Type ImageType, PM_uint8 Height, PM_uint8 Width, void* DataAddr)
{
	PM_uint8 datbuf[PM_MAX_NAME_LEN + 3] = {0};
	PM_uint8* Dp = datbuf;
	PM_Image_t* PM_Image = (PM_Image_t*)malloc(sizeof(PM_Image_t));
	if(PM_Image == PM_NULL)
	{
		return PM_NULL;
	}
	PM_Image -> ID = ID;
	PM_Image -> ImageType = ImageType;
	PM_Image -> Height = Height;
	PM_Image -> Width = Width;
	PM_Image -> DataAddr = DataAddr;
	*Dp++ = ImageType & 0xff;
	*Dp++ = Height;
	*Dp++ = Width;
	Dp = PM_Strcpy(Dp, Name);
	PM_SendMessage(PM_CREATEIMAGE_COMM, ID, sizeof(datbuf), datbuf);
	return PM_Image;
}

/**
	* @name		PM_SendParamData
	* @brief  	���Ͳ����ؼ�����
	* @param  	PM_Param	�����ؼ��ṹ��
	* @return 	void
	* @Sample 	PM_SendParamData(PM_Param)
  */
void PM_SendParamData(PM_Param_t* PM_Param)
{
	PM_uint8 DataLen = 0;
	PM_uint8* pdatbuf;
	for(PM_uint8 i = 0; i < PM_Param -> Channels; i++)
	{
		if(PM_Param -> DataType[i] == 6)
		{
			DataLen += 4;
		}
		else
		{
			DataLen += 0x01 << (PM_Param -> DataType[i] % 3);
		}
	}
	PM_uint8 datbuf[DataLen];
	pdatbuf = datbuf;
	for(PM_uint8 i = 0; i < PM_Param -> Channels; i++)
	{
		if(PM_Param -> DataType[i] == 6)
		{
			for(PM_uint8 j = 0; j < 4; j++)
			{
				*pdatbuf++ = *((PM_uint8*)PM_Param -> DataAddrList[i] + j);
			}
		}
		else
		{
			for(PM_uint8 j = 0; j < (0x01 << (PM_Param -> DataType[i] % 3)); j++)
			{
				*pdatbuf++ = *((PM_uint8*)PM_Param -> DataAddrList[i] + j);
			}
		}
	}
	PM_SendMessage(PM_SENDPARAM_COMM, PM_Param -> ID, sizeof(datbuf), datbuf);
}

/**
	* @name		PM_SendWaveformData
	* @brief  	����ʾ���ؼ�����
	* @param  	PM_Waveform	ʾ���ؼ��ṹ��
	* @return 	void
	* @Sample 	PM_SendWaveformData(PM_Waveform)
  */
void PM_SendWaveformData(PM_Waveform_t* PM_Waveform)
{
	PM_uint8 UnitChannelSize;
	PM_uint8* pdatbuf;
	if(PM_Waveform -> DataType == float_Type)
		UnitChannelSize = 4;
	else
		UnitChannelSize = 0x01 << (PM_Waveform -> DataType % 3);
	PM_uint8 datbuf[UnitChannelSize * PM_Waveform -> Channels];
	pdatbuf = datbuf;
	for(PM_uint8 i = 0; i < PM_Waveform -> Channels; i++)
	{
		for(PM_uint8 j = 0; j < UnitChannelSize; j++)
		{
			*pdatbuf++ = *((PM_uint8*)PM_Waveform -> DataAddrList[i] + j);
		}
	}
	PM_SendMessage(PM_SENDWAVEFORM_COMM, PM_Waveform -> ID, sizeof(datbuf), datbuf);
}

/**
	* @name		PM_SendImageData
	* @brief  	����ͼ���ؼ�����
	* @param  	PM_Image	ͼ���ؼ��ṹ��
	* @return 	void
	* @Sample 	PM_SendImageData(PM_Image)
  */
void PM_SendImageData(PM_Image_t* PM_Image)
{
	PM_uint16 DataSize;
	if(PM_Image -> ImageType == 0)
	{
		PM_SendBinImage(PM_Image);
	}
	else
	{
		DataSize = PM_Image -> Height * PM_Image -> Width * PM_Image -> ImageType;
		PM_SendMessage(PM_SENDIMAGE_COMM, PM_Image -> ID, DataSize, PM_Image -> DataAddr);
	}
}

/**
	* @name		PM_Strcpy
	* @brief  	�ַ�����������
	* @param  	startaddr	�׵�ַ
	* @param  	strDest		�ַ���
	* @return 	������ַ
	* @Sample 
  */
PM_uint8* PM_Strcpy(PM_uint8 *startaddr, const PM_int8 *strSrc)
{
	PM_uint8 i;
	for(i = 0; i < PM_MAX_NAME_LEN && *strSrc != '\0'; i++)
	{
		*startaddr++ = *strSrc++;
	}
	return startaddr + PM_MAX_NAME_LEN;
}


