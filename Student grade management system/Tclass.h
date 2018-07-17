#pragma once
#include "string"
using namespace std;
class Tclass
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