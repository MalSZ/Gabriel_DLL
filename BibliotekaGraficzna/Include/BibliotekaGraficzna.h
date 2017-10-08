// BibliotekaGraficzna.h
#pragma once

#ifdef BIBLIOTEKAGRAFICZNA_EXPORTS  
#define BIBLIOTEKAGRAFICZNA_API __declspec(dllexport)   
#else  
#define BIBLIOTEKAGRAFICZNA_API __declspec(dllimport)   
#endif  

#include <windows.h>

class bitmap_manager;
class abstract_object;

class BIBLIOTEKAGRAFICZNA_API window_manager
{
public:
	window_manager(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
	~window_manager();

	void add_object(abstract_object&);
private:
	friend LRESULT CALLBACK Petla(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	HWND hwnd;
	WNDCLASSEX wcex;
	bitmap_manager* mem_bmp;
	MSG msg;
};