#include "mainwindow.h"



mainwindow::mainwindow()
{
	header = "ѧ���ɼ�����ϵͳ";
	menu = { "¼����Ϣ","ɾ����Ϣ","�޸���Ϣ","�鿴��Ϣ","�˳�ϵͳ" };
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