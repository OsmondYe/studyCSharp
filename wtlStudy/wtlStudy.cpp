﻿#include "stdafx.h"
#include "resource.h"

#include "main_ui.h"


CAppModule _Module;

OyeFrameWnd* pMainWnd = NULL;
OverlayChildWnd* pWnd = NULL;


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE /*hPrevInstance*/,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{

	::CoInitializeEx(NULL, COINIT_MULTITHREADED);
	// this resolves ATL window thunking problem when Microsoft Layer for Unicode (MSLU) is used
	::DefWindowProc(NULL, 0, 0, 0L);

	AtlInitCommonControls(ICC_COOL_CLASSES | ICC_BAR_CLASSES);	// add flags to support other controls

	_Module.Init(NULL, hInstance);
	   

	CMessageLoop theLoop;
	_Module.AddMessageLoop(&theLoop);
	
	pMainWnd= new OyeFrameWnd();
	pMainWnd->CreateEx();
	pMainWnd->ShowWindow(nCmdShow);

	

	pWnd =new OverlayChildWnd();
	CRect rc(0, 0, 1000, 400);
	pWnd->Create(NULL,rc);
	
	pWnd->ShowWindow(SW_SHOW);
	pWnd->UpdateWindow();
	pWnd->UpdateOverlay(pMainWnd->m_hWnd);

	_beginthread([](void*) {
		while (1) {
			// 
			pWnd->UpdateOverlay(pMainWnd->m_hWnd);
			::Sleep(2000);
		}
	}, 0, 0);

	
	int nRet = theLoop.Run();

	_Module.RemoveMessageLoop();
	_Module.Term();
	::CoUninitialize();


    return 0;
}
