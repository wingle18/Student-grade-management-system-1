#pragma once
#include "Figure.h"
#include "string"
using namespace std;
class Course :
	public Figure
{
	protected:
		string course_num;//�γ̺�
		string course_name;//�γ���
		int course_credit;//�γ�ѧ��
		string course_semester;//�γ�����ѧ��
public:
	Course(const string &a,const string &b,const int &c,const string &d);
	Course(const Course &p);
	~Course();
	void Print();
};

