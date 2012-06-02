// ball_strategic_game.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "ball_strategic_game.h"

#define MAX_LOADSTRING 100
engine* machine;
// Global Variabldes:

HINSTANCE hInst;								// current instance
	// the main window class name
HWND hWnd;

// Forward declarations of functions included in this code module:

LRESULT CALLBACK	MsgProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE,
                     LPTSTR ,
                     INT)
{
	UNREFERENCED_PARAMETER(hInstance);


	MSG msg;
 	// TODO: Place code here.
	
	WNDCLASSEX wc =
    {
        sizeof( WNDCLASSEX ), CS_CLASSDC, MsgProc, 0L, 0L,
        GetModuleHandle( NULL ), NULL, NULL, NULL, NULL,
        L"D3D", NULL
    };
	RegisterClassEx(&wc);
	
	HWND hWnd = CreateWindow( L"D3D", L"D3D",
                              WS_OVERLAPPEDWINDOW, 100, 100, 300, 300,
                              NULL, NULL, wc.hInstance, NULL );
	// Main message loop:
	
		ShowWindow(hWnd, SW_SHOWDEFAULT);
		UpdateWindow(hWnd);
	
   if(machine == NULL){
		machine = new engine(hWnd);
	}
	
		while (GetMessage(&msg, NULL, 0, 0))
		{
			

				TranslateMessage(&msg);
				DispatchMessage(&msg);
		}
		
	

		
		UnregisterClass(L"D3D",wc.hInstance);

	return 0;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//

	


//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//


//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT WINAPI MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	

	switch (message)
	{
	
	case WM_PAINT:
		/*
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		
		EndPaint(hWnd, &ps);
		*/
		machine->RenderFrame();
		break;
		
	case WM_DESTROY:
		delete machine;
		PostQuitMessage(0);
		
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	
	return 0;
}

// Message handler for about box.

