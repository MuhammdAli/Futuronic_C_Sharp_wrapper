// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//
#pragma comment(lib, "ftrAnsiSdk.lib")
#pragma comment(lib, "ftrScanAPI.lib")
#pragma once
#include "ftrScanAPI.h"
#include "ftrAnsiSDK.h"

#ifndef _WINDOWS
#include <string.h>
#endif

#ifdef _WINDOWS

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
	)
{
	return TRUE;
}

#endif



typedef void *  Object;
extern FTRHANDLE hDevice;
extern int ErrorCode;


#ifdef __cplusplus
extern "C" {
#endif
	
	/*
	* Method:    OpenDevice
	* Signature: ()Z
	*/
	__declspec(dllexport) bool  OpenDevice
		();

	/*
	* Method:    CloseDevice
	* Signature: ()Z
	*/
	__declspec(dllexport) bool  CloseDevice
		();

	/*
	* Method:    getErrorCode
	* Signature: ()I
	*/
	__declspec(dllexport) int  GetErrorCode
		();

	/*
	* Method:    FillImageSize
	* Signature: (I*I*)Z
	*/
	__declspec(dllexport) bool  FillImageSize
		(int *,int *);

	/*
	* Method:    IsFingerPresent
	* Signature: ()Z
	*/
	__declspec(dllexport) bool  IsFingerPresent
		();

	/*
	* Method:    CaptureImage
	* Signature: ([B)Z
	*/
	__declspec(dllexport) bool  CaptureImage
		(byte[]);

	/*
	* Method:    CreateTemplate
	* Signature: (B[B[B[I)Z
	*/
	__declspec(dllexport) bool  CreateTemplate
		(byte, byte[], byte[], int[]);

	
	/*
	* Method:    ConvertAnsiTemplateToIso
	* Signature: ([B[B[I)Z
	*/
	__declspec(dllexport) bool  ConvertAnsiTemplateToIso
		(byte[], byte[], int[]);

	/*
	* Method:    GetMaxTemplateSize
	* Signature: ()I
	*/
	__declspec(dllexport) int  GetMaxTemplateSize
		();

	/*
	* Method:    GetSerialNumber
	* Signature: ([B)Z
	*/
	__declspec(dllexport) bool  GetSerialNumber
		(byte[]);

#ifdef __cplusplus
}
#endif
