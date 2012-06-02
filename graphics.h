#pragma once
#ifndef RENDER_H
#define RENDER_H


#include <vector>
#include <Windows.h>
#include <d3d9.h>
#pragma warning( disable : 4996 ) // disable deprecated warning 
#include <strsafe.h>
#pragma warning( default : 4996 )



#include "stdafx.h"

/*
	Class helping render DirectX
*/

class Render{
private:
	LPDIRECT3D9 lpD3d;	//Pointer direct
	LPDIRECT3DDEVICE9 lpD3Dev;
	D3DPRESENT_PARAMETERS stD3Dparam;
	HWND hWnd;
	HRESULT hScene;
	HRESULT hResult;

public:
	Render();
	Render(HWND hWnd);
	~Render();
	void initDirectX();
	void renderScene();
	void sethWnd(HWND hWnd);


};


#endif