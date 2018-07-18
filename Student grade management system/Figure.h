#pragma once
#include "string"
#include "vector"
using namespace std;
//Ðé»ùÀà
class Student;
class Course;
class Grade;
class Figure
{
public:
	string virtual Put_string() = 0;
	void virtual Inf_Change(ifstream &inf) = 0;
	void virtual Key_Change(vector <Student> &stu, vector <Course> &cou, vector <Grade> &gra) = 0;
	void virtual Num_Change(vector <Student> &stu, vector <Course> &cou, vector <Grade> &gra) = 0;
};