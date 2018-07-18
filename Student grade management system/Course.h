#pragma once
#include "Figure.h"
#include "sstream"
#include "fstream"
#include "vector"
#include "iostream"
class Student;
class Grade;
class Course :
	virtual public Figure
{
	protected:
		string course_num;//�γ̺�
		string course_name;//�γ���
		int course_credit;//�γ�ѧ��
		string course_semester;//�γ�����ѧ��
public:
	Course(const string &a="0",const string &b="0",const int &c=0,const string &d="0");
	Course(const Course &p);
	~Course();
	string Put_string();
	void Inf_Change (ifstream & inf);
	static void TXT_I(ifstream &inf);
	static void TXT_O(ofstream &of);
	void Key_Change(vector <Student> &stu, vector <Course> &cou, vector <Grade> &gra);
	string Get_course_num();
	static void Write_Success();
	static void Delete_Success();
	bool operator ==(const Course &p);
	static void Change_Success();
};

