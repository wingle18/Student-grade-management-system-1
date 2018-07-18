#pragma once
#include "Tclass.h"
#include "sstream"
#include "Figure.h"
#include "fstream"
#include "vector"
class Student :
	public Tclass, virtual public Figure
{
protected:
	string stu_name;
	string stu_num;
	string stu_sex;
public:
	Student(const string&a="0",const string&b="0",const string&c="0",const string&d="0",const string &e="0",const int &f=0);
	Student(const Student&p);
	~Student();
	string Put_string();
	void Inf_Change (ifstream &inf);
	static void TXT_I(ifstream &inf);
	static void TXT_O(ofstream &of);
};