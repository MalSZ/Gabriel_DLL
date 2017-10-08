// BibbliotekaGraficzna.cpp
#include "stdafx.h" 
#include "..\Include\BibliotekaGraficzna.h"
#include "..\Include\Bitmapy.h"
#include <windows.h>

#define WIDTH_  500
#define HEIGHT_ 500

LRESULT CALLBACK Petla(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {

	case WM_CREATE:
		SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)((CREATESTRUCT*)lParam)->lpCreateParams);
		break;

	case WM_KEYDOWN:
		// Klawisz Esc
		if (wParam == 0x1B)
			DestroyWindow(hwnd);
		break;

	case WM_SIZE:
	/*case WM_SIZING:
	{
		window_manager *wndptr = (window_manager*)GetWindowLongPtr(hwnd, GWL_USERDATA);
		wndptr->mem_bmp->redraw(hwnd);
		break;
	}		*/

	case WM_DESTROY:
		PostQuitMessage(0); // wyjcie i zniszczenie okna
		break;

	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}

window_manager::window_manager(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	mem_bmp = new bitmap_manager;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = Petla;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = TEXT("dywan_wnd_class");
	wcex.hIconSm = NULL;
	RegisterClassEx(&wcex);

	hwnd = CreateWindowEx(NULL, wcex.lpszClassName, TEXT("Window"), WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		GetSystemMetrics(SM_CXSCREEN) / 2 - WIDTH_ / 2, GetSystemMetrics(SM_CYSCREEN) / 2 - HEIGHT_ / 2, WIDTH_, HEIGHT_, NULL, NULL, hInstance, this);

	// Pętla wiadomości
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

void window_manager::add_object(abstract_object& obj)
{
	mem_bmp->add_rule(obj);
}

window_manager::~window_manager()
{
	DeleteObject(mem_bmp);
	delete mem_bmp;
}