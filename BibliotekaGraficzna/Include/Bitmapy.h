#pragma once

#include <windows.h>
#include <deque>

class abstract_object;

class bitmap_manager
{
public:
	bitmap_manager();
	~bitmap_manager();

	void add_rule(abstract_object&);
	void redraw(HWND);
private:
	std::deque<abstract_object*> objects;
	HBITMAP map;
};