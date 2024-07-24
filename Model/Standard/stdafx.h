#pragma once


#ifdef MODEL_EXPORTS
#define MODEL_API _declspec(dllexport)   
#else
#define MODEL_API  __declspec(dllimport) 
#endif 

#pragma warning(disable:4273)
#pragma warning(disable:4005)