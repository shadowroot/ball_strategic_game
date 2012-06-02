#include "stdafx.h"
#include "ball.h"

ball::ball(){

}

ball::~ball(){

}
/*
BOOL ball::ParseXFile(char *Filename)
{
  IDirectXFile                  *pDXFile = NULL;
  IDirectXFileEnumObject *pDXEnum = NULL;
  IDirectXFileData      *pDXData = NULL;

  // Create the .X file object
  if(FAILED(DirectXFileCreate(&pDXFile)))
        return FALSE;

  // Register the templates in use
  // Use the standard retained mode templates from Direct3D
  if(FAILED(pDXFile->RegisterTemplates((LPVOID)D3DRM_XTEMPLATES, D3DRM_XTEMPLATE_BYTES))) {
        pDXFile->Release();
        return FALSE;
  }

  // Create an enumeration object
  if(FAILED(pDXFile->CreateEnumObject((LPVOID)Filename, DXFILELOAD_FROMFILE, &pDXEnum))) {
        pDXFile->Release();
        return FALSE;
  }

  // Enumerate all top-level templates
  while(SUCCEEDED(pDXEnum->GetNextDataObject(&pDXData))) {
        ParseXFileData(pDXData);
        ReleaseCOM(pDXData);
  }

  // Release objects
  ReleaseCOM(pDXEnum);
  ReleaseCOM(pDXFile);

  // Return a success
  return TRUE;
}

void ParseXFileData(IDirectXFileData *pData)
{
  IDirectXFileObject *pSubObj  = NULL;
  IDirectXFileData   *pSubData = NULL;
  IDirectXFileDataReference *pDataRef = NULL;
  const GUID *pType = NULL;
  char          *pName = NULL;
  DWORD         dwSize;
  char          *pBuffer;
  
  // Get the template type
  if(FAILED(pData->GetType(&pType)))
        return;

  // Get the template name (if any)
  if(FAILED(pData->GetName(NULL, &dwSize)))
        return;
  if(dwSize) {
        if((pName = new char[dwSize]) != NULL)
        pData->GetName(pName, &dwSize);
  }

  // Give template a default name if none found
  if(pName == NULL) {
        if((pName = new char[9]) == NULL)
        return;
        strcpy(pName, "Template");
  }

  // See what the template was and deal with it
  // This is where you'll jump in with your own code

  if(*pType == TID_D3DRMFrame) {
        MessageBox(NULL, pName, "Frame template found", MB_OK);
  }

  if(*pType == TID_D3DRMMesh) {
        MessageBox(NULL, pName, "Mesh template found", MB_OK);
  }

  if(*pType == TID_D3DRMMaterial) {
        MessageBox(NULL, pName, "Material template found", MB_OK);
  }

  if(*pType == TID_D3DRMFrameTransformMatrix) {
        MessageBox(NULL, pName, "Frame transformation matrix template found", MB_OK);

        // Get the template data
        if(FAILED(pData->GetData(NULL, &dwSize, (PVOID*)&pBuffer)))
        return;

        // Do whatever with data. Note that you can cast
        // the pointer to anything. Be sure to copy data 
        // out of buffer before proceeding.
   }

  // Scan for embedded templates
  while(SUCCEEDED(pData->GetNextObject(&pSubObj))) {

        // Process embedded references
        if(SUCCEEDED(pSubObj->QueryInterface(IID_IDirectXFileDataReference, (void**)&pDataRef))) {
        if(SUCCEEDED(pDataRef->Resolve(&pSubData))) {
        ParseXFileData(pSubData);
        ReleaseCOM(pSubData);
        }
        ReleaseCOM(pDataRef);
        }

        // Process non-referenced embedded templates
        if(SUCCEEDED(pSubObj->QueryInterface(IID_IDirectXFileData, (void**)&pSubData))) {
        ParseXFileData(pSubData);
        ReleaseCOM(pSubData);
        }
        ReleaseCOM(pSubObj);
  }

  // Release name buffer
  delete pName;
}
*/