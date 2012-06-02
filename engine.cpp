
#include "stdafx.h"
#include "engine.h"


engine::engine(HWND hWnd){
	this->hWnd = hWnd;
	this->InitializeGame();
}

void engine::InitializeGame(){
	this->render = new Render(this->hWnd);
	if(this->render == NULL){
		this->render = new Render(this->hWnd);
	}
}

void engine::RenderFrame(){
	this->render->renderScene();
}

void engine::sethWnd(HWND hWnd){
	this->render->sethWnd(hWnd);
}

engine::engine(){
	exit((int)-1);
}


engine::~engine(){

}