#pragma once
#include "Figure.h"
#include "sstream"
#include "fstream"
#include "vector"
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
};

