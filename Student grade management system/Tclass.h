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
	Tclass(const string&a=0, const string&b=0, const int&c=0);
	Tclass(const Tclass&p);
	~Tclass();
};