// CppDll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "watermark.h"
#include "CppDll.h"


#pragma region CanHIDE

DLL_FUN_EXPORT int add(int a, int b)
{
	return a + b;
}

DLL_FUN_EXPORT int sub(int a, int b)
{
	return a - b;
}


DLL_FUN_EXPORT void UntypedParamShow(void * data, int flag)
{
	if (1 == flag) {
		int a = *(int*)data;
		char buf[10] = { 0 };
		_itoa_s(a, buf, 10);
		::MessageBoxA(NULL, buf, buf, 0);
	}
	else if (2 == flag) {
		char* buf = (char*)data;
		::MessageBoxA(NULL, buf, buf, 0);
	}
}

DLL_FUN_EXPORT void StrReverseA(char * in, char * out)
{
	std::string p = std::string(in);
	std::reverse(p.begin(), p.end());
	memcpy(out, p.c_str(), p.length());
	out[p.length()] = '\0';
}


DLL_FUN_EXPORT void StrReverseW(wchar_t * in, wchar_t * out)
{
	std::wstring p = std::wstring(in);

	std::reverse(p.begin(), p.end());

	wmemcpy(out, p.c_str(), p.length());
	out[p.length()] = L'\0';
}

DLL_FUN_EXPORT wchar_t * GetStringFromHeap()
{
	std::wstring str = std::wstring(L"The quick brown fox jumps over the lazy dog.");

	wchar_t* ret = new wchar_t[str.length() + 1]{ 0 };

	size_t pos = 0;
	std::for_each(str.begin(), str.end(), [=, &pos](wchar_t c) {ret[pos++] = c; });

	return ret;



}

DLL_FUN_EXPORT void FreeStringFromHeap(wchar_t * p)
{
	if (p != NULL) {
		delete[] p;
	}
}

DLL_FUN_EXPORT wchar_t * GetStringFromCOMMem()
{
	int buf_size = 128;
	wchar_t* pBuffer = (wchar_t*)::CoTaskMemAlloc(buf_size);
	if (NULL != pBuffer) {
		wcscpy_s(pBuffer, buf_size / sizeof(wchar_t), L"string allocated from ::CoTaskMemAlloc");
	}
	return pBuffer;
}

DLL_FUN_EXPORT void FillStringFromHeap(const wchar_t * pOrg, wchar_t ** pOut)
{

	if (!pOrg) {
		return;
	}
	int len = wcslen(pOrg) + 1;
	if (!len) {
		return;
	}
	if (!pOut) {
		return;
	}

	wchar_t*& pBufer = *pOut;

	pBufer = (wchar_t*)malloc(len * sizeof(wchar_t));

	wcscpy_s(pBufer, len, pOrg);

	return;



}

DLL_FUN_EXPORT void Free_FillStringFromHeap(wchar_t * pIn)
{
	if (!pIn) {
		return;
	}
	free(pIn);
}

DLL_FUN_EXPORT void FillStringFromComMem(const wchar_t * pOrg, wchar_t ** pOut)
{
	if (!pOrg) {
		return;
	}
	int len = wcslen(pOrg) + 1;
	if (!len) {
		return;
	}
	if (!pOut) {
		return;
	}

	wchar_t*& pBufer = *pOut;

	pBufer = (wchar_t*)::CoTaskMemAlloc(len * sizeof(wchar_t));

	wcscpy_s(pBufer, len, pOrg);

	return;
}

DLL_FUN_EXPORT void ReturnStringArrays(wchar_t ** pArray, int * pSize)
{
	*pSize = 10;

	wchar_t** pBuf = (wchar_t**)::CoTaskMemAlloc(10 * sizeof(wchar_t*));

	// fill random 
	for (int i = 0; i < 10; i++) {
		pBuf[i] = (wchar_t*)::CoTaskMemAlloc(255 * sizeof(wchar_t));
		swprintf_s(pBuf[i], 255, L"this is the %d strings", i);
	}

	*pArray = (wchar_t*)pBuf;
	return;
}

DLL_FUN_EXPORT void FillStruct(PSIMPLESTRUCT pSt)
{
	//print sizeof first
	std::cout << "sizeof(SIMPLESTRUCT) in c++:" << sizeof(SIMPLESTRUCT) << std::endl;

	pSt->byteValue = 0xFF;
	pSt->shortValue = 0x900;
	pSt->intValue = 0x400;
	pSt->int64Value = 0x1000000;
	pSt->boolValue = true;
	pSt->floatValue = 100.003;
	pSt->doubleValue = 200.003;

}



DLL_FUN_EXPORT PSIMPLESTRUCT ReturnStructByNew()
{
	PSIMPLESTRUCT pSt = new SIMPLESTRUCT();

	pSt->byteValue = 0x88;
	pSt->shortValue = 0x53450;
	pSt->intValue = 0x5552;
	pSt->int64Value = 0x144000000;
	pSt->boolValue = true;
	pSt->floatValue = 1030.0043;
	pSt->doubleValue = 2010.003;

	return pSt;
}

DLL_FUN_EXPORT void FreeStructByNewed(PSIMPLESTRUCT pSt)
{
	if (pSt != NULL) {
		delete(pSt);
	}
}


DLL_FUN_EXPORT PSIMPLESTRUCT ReturnStructByComMem()
{
	PSIMPLESTRUCT pSt = (PSIMPLESTRUCT)::CoTaskMemAlloc(sizeof(SIMPLESTRUCT));

	pSt->byteValue = 0x11;
	pSt->shortValue = 0x450;
	pSt->intValue = 0x5252;
	pSt->int64Value = 0x31300000;
	pSt->boolValue = false;
	pSt->floatValue = 0.0043;
	pSt->doubleValue = 23.003;

	return pSt;
}

DLL_FUN_EXPORT void ReturnStructAsParam(PSIMPLESTRUCT * ppSt)
{
	if (ppSt == NULL) {
		return;
	}
	*ppSt = (PSIMPLESTRUCT)::CoTaskMemAlloc(sizeof(SIMPLESTRUCT));

	PSIMPLESTRUCT pSt = *ppSt;

	pSt->byteValue = 0x11;
	pSt->shortValue = 0x450;
	pSt->intValue = 0x5252;
	pSt->int64Value = 0x31300000;
	pSt->boolValue = false;
	pSt->floatValue = 0.0043;
	pSt->doubleValue = 23.003;

}
#pragma endregion


