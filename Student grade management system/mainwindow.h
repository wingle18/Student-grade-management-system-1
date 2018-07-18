#pragma once
#include "UI.h"
#include "Grade.h"
class mainwindow :
	public UI
{
public:
	mainwindow();
	mainwindow(const mainwindow &p);
	~mainwindow();
	void func(vector <Student> &stu, vector <Course> &cou, vector <Grade> &gra);
};