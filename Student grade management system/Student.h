#pragma once
#include "Tclass.h"
class Student :
	public Tclass
{
protected:
	string stu_name;
	string stu_num;
	string stu_sex;
public:
	Student(const string&a,const string&b,const string&c,const string&d,const string &e,const int &f);
	Student(const Student&p);
	~Student();
	void Print();
};

