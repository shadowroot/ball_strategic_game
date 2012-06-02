#include "stdafx.h"
#include "vm.h"


vm::vm(){
	MessageBoxA(NULL,"VM Construct","VM",MB_OK);
}

vm::~vm(){
	MessageBoxA(NULL,"VM Destruct","VM",MB_OK);
}