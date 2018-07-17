#pragma once
#include "Tclass.h"
#include "string"
using namespace std;
class Student :
	public Tclass
{
protected:
	string stu_name;
	string stu_num;
	string stu_sex;
public:
	Student(const string&a,const string&b,const string&c,const string&d,const string &e,const string &f);
	Student(const Student&p);
	~Student();
	void Print();
};

