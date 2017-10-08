#pragma once

#include <windows.h>

class abstract_object
{
public:
	virtual void apply(BYTE*, long, long) = 0;
	virtual abstract_object* clone() = 0;
	virtual ~abstract_object() {};
};