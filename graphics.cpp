
#include "stdafx.h"
#include "graphics.h"

#pragma comment (lib, "d3d9.lib")

Render::Render(HWND hWnd){
	
	if(FAILED(this->lpD3d = Direct3DCreate9 (D3D_SDK_VERSION))){
		MessageBoxA(NULL,("DirectX not initialized"),"DX",MB_OK);
		this->~Render();
	}
	this->hWnd = hWnd;
	this->initDirectX();
}

/*
	Initialize DirectX procedure
*/


void Render::sethWnd(HWND hWnd){
	this->hWnd = hWnd;
}

void Render::initDirectX(){
	D3DPRESENT_PARAMETERS stD3D;
	ZeroMemory(&stD3D,sizeof(D3DPRESENT_PARAMETERS));
	
	//ZeroMemory(&this->stD3Dparam,sizeof(this->stD3Dparam));
	stD3D.Windowed=TRUE; 
	stD3D.SwapEffect = D3DSWAPEFFECT_DISCARD;
	stD3D.BackBufferFormat = D3DFMT_UNKNOWN;
	
	if( FAILED (this->hResult = this->lpD3d->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		this->hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&stD3D,
		&this->lpD3Dev) ) )
		{
		
		MessageBoxA(NULL,"DX9 Device pointer NULL(CreateDevice)","",MB_OK);
		this->~Render();	
	}//this->lpD3Dev NULL Why?

}
/*
	Default constructor
*/
Render::Render(){

}

/*
	Destructor
*/

Render::~Render(){
/*
		delete this->lpD3d;
		delete this->hResult;
		delete this->hScene;
		delete this->hWnd;
		delete this->lpD3Dev;
		delete this->stD3Dparam;
		*/

}


void Render::renderScene(){
	this->lpD3Dev->Clear(
		0,
		NULL,
		D3DCLEAR_TARGET,
		D3DCOLOR_XRGB(00,44,128),
		1.0f,
		0); //Clear scene
	if(SUCCEEDED(this->lpD3Dev->BeginScene())){
		this->lpD3Dev->EndScene();
	}
	this->lpD3Dev->Present(NULL,NULL,NULL,NULL);


}
