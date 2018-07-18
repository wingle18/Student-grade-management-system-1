#pragma once
#include "Student.h"
#include "Course.h"
class Grade :
	public Student,public Course
{
protected:
	int score;//�ٷ��Ƴɼ�
	string score_rank;//�ȼ��Ƴɼ�
	double gradepoint;//ѧ�ּ�
public:
	Grade(const string &a="0",const string &b="0",const string &c="0",const string &d="0",const string &e="0",const int &f=0,const string &g="0",const string &h="0",const int &i=0,const string &j="0",const int &k=0,const string &l="0",const double &m=0);
	Grade(const Grade &p);
	~Grade();
	string Put_string();
	void Inf_Change(ifstream &inf);
	static void TXT_I(ifstream &inf);
	static void TXT_O(ofstream &of);
};