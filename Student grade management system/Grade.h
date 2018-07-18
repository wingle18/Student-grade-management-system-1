#pragma once
#include "Student.h"
#include "Course.h"
class Student;
class Grade :
	public Student,public Course
{
protected:
	int score;//百分制成绩
	string score_rank;//等级制成绩
	double gradepoint;//学分绩
public:
	Grade(const string &a="0",const string &b="0",const string &c="0",const string &d="0",const string &e="0",const int &f=0,const string &g="0",const string &h="0",const int &i=0,const string &j="0",const int &k=0,const string &l="0",const double &m=0);
	Grade(const Grade &p);
	Grade(const Student &a, const Course &b, const int &c, const string &d, const double &e);
	~Grade();
	string Put_string();
	void Inf_Change(ifstream &inf);
	static void TXT_I(ifstream &inf);
	static void TXT_O(ofstream &of);
	void Key_Change(vector <Student> &stu, vector <Course> &cou, vector <Grade> &gra);
	static void Write_Success();
	static void Delete_Success();
	bool operator ==(const Grade &p);
	static void Change_Success();
};