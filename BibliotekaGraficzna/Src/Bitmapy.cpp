#include "stdafx.h"
#include <windows.h>
#include "..\Include\Bitmapy.h"
#include "..\Include\Obiekt.h"

bitmap_manager::bitmap_manager() : map(nullptr) {}

bitmap_manager::~bitmap_manager() {}

void bitmap_manager::add_rule(abstract_object& obj)
{
	objects.push_back(obj.clone());
}

void bitmap_manager::redraw(HWND hwnd)
{
	if (map != nullptr)
		DeleteObject(map);

	RECT rect;
	GetWindowRect(hwnd, &rect);
	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;

	HDC comp_hdc = CreateCompatibleDC(GetDC(hwnd));

	BITMAPINFOHEADER bi;
	memset(&bi, 0, sizeof(BITMAPINFOHEADER));
	bi.biSize = sizeof(BITMAPINFOHEADER); // Rozmiar tej struktury
	bi.biWidth = width; // Szerokosc bitmapy
	bi.biHeight = height - 100; // Wysokosc bitmapy
	bi.biPlanes = 1; // Musi byc równe 1
	bi.biBitCount = 24; // Ilosc bitów na piksel
	bi.biCompression = BI_RGB;

	BYTE* pixele_bitmapy;
	map = CreateDIBSection(comp_hdc, (BITMAPINFO*)&bi, DIB_RGB_COLORS, (void**)&pixele_bitmapy, NULL, 0);

	for (auto* obj : objects)
		obj->apply(pixele_bitmapy, bi.biWidth, bi.biHeight);

	SelectObject(comp_hdc, map);
	BitBlt(GetDC(hwnd), 0, 0, bi.biWidth, bi.biHeight, comp_hdc, 0, 0, SRCCOPY);
	DeleteObject(comp_hdc);
}