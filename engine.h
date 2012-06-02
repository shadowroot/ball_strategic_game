#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include "stdafx.h"
#include <vector>
#include <Windows.h>
#include <iostream>
#include "graphics.h"
#include "physics.h"
#include "ball.h"
#include "vm.h"

using namespace std;

typedef struct Points{
	float x,y,z;
	Points(){}
	Points(float a,float b,float c):x(a),y(b),z(c){}
}Points;

typedef struct Objects{
	string model;
	double x,y,z;//Positions
	float dx,dy,dz;//Directions

}Objects;

class engine{
private:
	vector<Points> vectors;
	vector<Objects> enemy;
	vector<Objects> friendly;
	string mapFile;
	Render *render;
	HWND hWnd;
	

public:
	engine(HWND hWnd);
	engine();
	~engine();
	void sethWnd(HWND hWnd);
	void InitializeGame();
	void RenderFrame();



};
/*
Struktura pro 3D pozice

*/


#endif