// FutronicWrapper.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

FTRHANDLE hDevice = NULL;
int ErrorCode = 0;



int GetErrorCode()
{
	return ErrorCode;
}

bool  OpenDevice()
{
	if (hDevice == NULL){
		hDevice = ftrScanOpenDevice();
		if (hDevice == NULL)
		{
			ErrorCode = (int)ftrScanGetLastError();
			return false;
		}

	}
		return true;
	
}


bool CloseDevice()
{
	
	if (hDevice != NULL)
	{
		ftrScanCloseDevice(hDevice);
		hDevice = NULL;
		ErrorCode = 0;
	}

	return true;
}

bool FillImageSize(int *ImageWidth, int *ImageHeight)
{
	if (hDevice == NULL)
	{
		ErrorCode = FTR_ERROR_INVALID_PARAMETER;
		return false;
	}

	FTRSCAN_IMAGE_SIZE ImageSize;
	if (!ftrScanGetImageSize(hDevice, &ImageSize))
	{
		ErrorCode =(int)ftrScanGetLastError();
		return false;
	}

	*ImageWidth = ImageSize.nWidth;
	*ImageHeight = ImageSize.nHeight;
	
	return true;
}

bool IsFingerPresent()
{
	
	if (hDevice == NULL)
	{
		ErrorCode =  FTR_ERROR_INVALID_PARAMETER;
		return false;
	}

	if (ftrScanIsFingerPresent(hDevice, NULL))
	{
		return true;
	}
	ErrorCode =  (int)ftrScanGetLastError();
	return false;
}

bool CaptureImage(byte pImage[])
{
	
	if (hDevice == NULL)
	{
		ErrorCode = FTR_ERROR_INVALID_PARAMETER;
		return false;
	}

	bool res = true;

	byte *pJData = pImage;
	if (pJData)
	{
		if (!ftrAnsiSdkCaptureImage(hDevice, pJData))
		{
			ErrorCode = (int)ftrScanGetLastError();
			res = false;
		}

		 pJData = NULL ;
	}
	else
	{
		ErrorCode = (int)FTR_ERROR_NOT_ENOUGH_MEMORY;
		res = false;
	}

	return res;
}

bool CreateTemplate
(byte finger, byte pImage[], byte pTemplate[], int pTemplateSize[])
{
	
	if (hDevice == NULL)
	{
		ErrorCode = FTR_ERROR_INVALID_PARAMETER;
		return false;
	}

	bool res = true;

	byte *img_data = pImage;
	byte *template_data = pTemplate;
	int  *template_size = pTemplateSize;

	if (img_data && template_data && template_size)
	{
		if (!ftrAnsiSdkCreateTemplate(hDevice, finger, img_data, template_data, (int *)template_size))
		{
			ErrorCode = (int)ftrScanGetLastError();
			res = false;
		}
	}
	else
	{
		ErrorCode =(int)FTR_ERROR_NOT_ENOUGH_MEMORY;
		res = false;
	}

	if (img_data)  img_data= NULL ;
	if (template_data) template_data = NULL;
	if (template_size) template_size = NULL;

	return res;
}

bool ConvertAnsiTemplateToIso
(byte pAnsiTmpl[], byte pIsoTmpl[], int pIsoTmplSize[])
{
	bool res = true;

	
	byte *ansi_tmpl = pAnsiTmpl;
	byte *iso_tmpl = pIsoTmpl;
	int *iso_size = pIsoTmplSize;

	int template_size = 0;

	if (ansi_tmpl && iso_tmpl && iso_size)
	{
		if (!ftrAnsiSdkConvertAnsiTemplateToIso(ansi_tmpl, iso_tmpl, (int *)iso_size))
		{
			ErrorCode = (int)ftrScanGetLastError();
			res = false;
		}
	}
	else
	{
		ErrorCode =(int)FTR_ERROR_NOT_ENOUGH_MEMORY;
		res = false;
	}

	if (ansi_tmpl) ansi_tmpl = NULL;
	if (iso_tmpl)iso_tmpl = NULL;
	if (iso_size)iso_size = NULL;

	return res;
}

int GetMaxTemplateSize()
{
	return (int)ftrAnsiSdkGetMaxTemplateSize();
}

bool GetSerialNumber(byte pSerial[])
{
	if (hDevice == NULL)
	{
		ErrorCode = FTR_ERROR_INVALID_PARAMETER;
		return false;
	}

	bool res = true;
    byte *pData = pSerial;

	if (pData)
	{
		if (!ftrScanGetSerialNumber(hDevice, pData))
		{
		    ErrorCode = (int)ftrScanGetLastError();
			res = false;
		}
	}
	else
	{
		ErrorCode = (int)FTR_ERROR_NOT_ENOUGH_MEMORY;
		res = false;
	}
	
	
	if (pData) pData = NULL;

	return res;
}
