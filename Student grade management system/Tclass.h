#pragma once
#include "Figure.h"
class Tclass :
	public Figure
{
protected:
		string major;
		string teach_class;
		int year;
public:
	Tclass(const string&a, const string&b, const int&c);
	Tclass(const Tclass&p);
	~Tclass();
};