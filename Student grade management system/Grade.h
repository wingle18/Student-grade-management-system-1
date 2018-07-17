#pragma once
#include "Student.h"
#include "Course.h"
class Grade :
	public Student,public Course
{
protected:
	int score;//百分制成绩
	string score_rank;//等级制成绩
	double gradepoint;//学分绩
public:
	Grade(const string &a,const string &b,const string &c,const string &d,const string &e,const string &f,const string &g,const string &h,const int &i,const string &j,const int &k,const string &l,const double &m);
	Grade(const Grade &p);
	~Grade();
	void Print();
};

