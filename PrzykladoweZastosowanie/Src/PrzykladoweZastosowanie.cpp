// PrzykladoweZastosowanie.cpp: Definiuje punkt wejścia dla aplikacji.
//

#include "stdafx.h"
#include <BibliotekaGraficzna.h>
#include <vector>

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	window_manager plot_w(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
	//    std::vector<POINT> ppoints;
	//    point_fild points(ppoints);
	//    plot_w.add_object(points);
	//    system("pause");
	return 0;
}
