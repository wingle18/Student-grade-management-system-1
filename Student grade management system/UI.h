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
	bool flag;		//�Ƿ�Ϊת�ӵ����ܵĺ���
public:
	UI(const string &a,const vector <string> &b,const bool &c);
	UI();
	UI(const UI &p);
	~UI();
	void Display();
};