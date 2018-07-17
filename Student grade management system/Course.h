#pragma once
#include "Figure.h"
#include "string"
using namespace std;
class Course :
	public Figure
{
	protected:
		string course_num;//课程号
		string course_name;//课程名
		int course_credit;//课程学分
		string course_semester;//课程所属学期
public:
	Course(const string &a,const string &b,const int &c,const string &d);
	Course(const Course &p);
	~Course();
	void Print();
};

