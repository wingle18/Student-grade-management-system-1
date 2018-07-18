#pragma once
#include "UI.h"
#include "Grade.h"
#include "function.h"
class mainwindow :
	public UI
{
protected:
	string mark;
public:
	mainwindow(const string &a = "0");
	mainwindow(const mainwindow &p);
	~mainwindow();
	void func(vector <Student> &stu, vector <Course> &cou, vector <Grade> &gra);
	void Error_Output(vector <Student> &stu, vector <Course> &cou, vector <Grade> &gra);
	void Back(vector <Student> &stu, vector <Course> &cou, vector <Grade> &gra);
	void _Back(vector <Student> &stu, vector <Course> &cou, vector <Grade> &gra);
	void Exit();
};