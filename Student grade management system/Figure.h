#pragma once
#include "string"
using namespace std;
//Ðé»ùÀà
class Figure
{
public:
	string virtual Put_string() = 0;
	void virtual Inf_Change(ifstream &inf) = 0;
};