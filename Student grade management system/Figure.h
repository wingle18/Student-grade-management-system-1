#pragma once
#include "string"
using namespace std;
//�����
class Figure
{
public:
	string virtual Put_string() = 0;
	void virtual Inf_Change(ifstream &inf) = 0;
};