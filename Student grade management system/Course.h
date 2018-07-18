#pragma once
#include "Figure.h"
#include "sstream"
#include "fstream"
#include "vector"
class Course :
	virtual public Figure
{
	protected:
		string course_num;//课程号
		string course_name;//课程名
		int course_credit;//课程学分
		string course_semester;//课程所属学期
public:
	Course(const string &a="0",const string &b="0",const int &c=0,const string &d="0");
	Course(const Course &p);
	~Course();
	string Put_string();
	void Inf_Change (ifstream & inf);
	static void TXT_I(ifstream &inf);
	static void TXT_O(ofstream &of);
};

