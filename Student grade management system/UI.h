#pragma once
#include "string"
#include "vector"
#include "iostream"
using namespace std;
class UI
{
protected:
	string header;
	vector <string> menu;
public:
	UI(const string &a,const vector <string> &b);
	UI();
	UI(const UI &p);
	~UI();
	void Display();
};