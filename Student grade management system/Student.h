#pragma once
#include "Tclass.h"
#include "sstream"
#include "Figure.h"
class Student :
	public Tclass, virtual public Figure
{
protected:
	string stu_name;
	string stu_num;
	string stu_sex;
public:
	Student(const string&a,const string&b,const string&c,const string&d,const string &e,const int &f);
	Student(const Student&p);
	~Student();
	string Put_string();
};