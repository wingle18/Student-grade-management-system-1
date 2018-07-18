#include "mainwindow.h"



mainwindow::mainwindow()
{
	header = "学生成绩管理系统";
	menu = { "录入信息","删除信息","修改信息","查看信息","退出系统" };
}

mainwindow::mainwindow(const mainwindow & p):UI(p)
{
}

mainwindow::~mainwindow()
{
}

void mainwindow::func(vector <Student> &stu, vector <Course> &cou, vector <Grade> &gra)
{
	Display();
	string s;
	cin >> s;
}