#include "mainwindow.h"



mainwindow::mainwindow(const string &a):mark(a)
{
	if (a == "0")	
	{
		header = "学生成绩管理系统";
		menu = { "录入信息","删除信息","修改信息","查看信息","退出系统" };
		flag = 0;
	}
	else if (a == "01")
	{
		header = "录入信息";
		menu = { "录入学生信息","录入课程信息","录入成绩信息","返回主界面" };
		flag = 0;
	}
	else if (a == "02")
	{
		header = "删除信息";
		menu = { "删除学生信息","删除课程信息","删除成绩信息","返回主界面" };
		flag = 0;
	}
	else if (a == "03")
	{
		header = "修改信息";
		menu = { "修改学生信息","修改课程信息","修改成绩信息","返回主界面" };
		flag = 0;
	}
	else if (a == "04")
	{
		header = "查看信息";
		menu = { "查看学生信息","查看课程信息","查看成绩信息","返回主界面" };
		flag = 0;
	}
	else if (a == "05")
	{
		header = "退出系统成功!";
		flag = 1;
	}
	else if (a == "011")
	{
		header = "录入学生信息";
		flag = 1;
	}
	else if (a == "012")
	{
		header = "录入课程信息";
		flag = 1;
	}
	else if (a == "013")
	{
		header = "录入成绩";
		flag = 1;
	}
	else if (a == "014")
	{
		flag = 1;
	}
	else if (a == "021")
	{
		header = "删除学生信息";
		flag = 1;
	}
	else if (a == "022")
	{
		header = "删除课程信息";
		flag = 1;
	}
	else if (a == "023")
	{
		header = "删除成绩";
		flag = 1;
	}
	else if (a == "024")
	{
		flag = 1;
	}
	else if (a == "031")
	{
		header = "修改学生信息";
		flag = 1;
	}
	else if (a == "032")
	{
		header = "修改课程信息";
		flag = 1;
	}
	else if (a == "033")
	{
		header = "修改成绩";
		flag = 1;
	}
	else if (a == "034")
	{
		flag = 1;
	}
	else if (a == "041")
	{
		header = "查看学生信息";
		flag = 1;
	}
	else if (a == "042")
	{
		header = "查看课程信息";
		flag = 1;
	}
	else if (a == "043")
	{
		header = "查看成绩";
		flag = 1;
	}
	else if (a == "044")
	{
		flag = 1;
	}
	else
	{
		flag = 1;
	}
}

mainwindow::mainwindow(const mainwindow & p):UI(p),mark(p.mark)
{
}

mainwindow::~mainwindow()
{
}

void mainwindow::func(vector <Student> &stu, vector <Course> &cou, vector <Grade> &gra)
{
	Display();
	if (flag == 0)
	{
		string s;
		cin >> s;
		if (s.size() != 1)
			Error_Output(stu, cou, gra);
		mainwindow(mark + s).func(stu,cou,gra);
	}
	else
	{
		if (mark == "05")
		{
			system("pause");
			exit(0);
		}
		else if (mark == "011")
		{
			Write(stu,stu, cou, gra);
			mainwindow().func(stu, cou, gra);
		}
		else if (mark == "012")
		{
			Write(cou,stu, cou, gra);
			mainwindow().func(stu, cou, gra);
		}
		else if (mark == "013")
		{
			Write(gra,stu, cou, gra);
			mainwindow().func(stu, cou, gra);
		}
		else if (mark == "014")
		{
			_Back(stu, cou, gra);
		}
		else if (mark == "021")
		{
			Delete(stu, stu, cou, gra);
			mainwindow().func(stu, cou, gra);
		}
		else if (mark == "022")
		{
			Delete(cou, stu, cou, gra);
			mainwindow().func(stu, cou, gra);
		}
		else if (mark == "023")
		{
			Delete(gra, stu, cou, gra);
			mainwindow().func(stu, cou, gra);
		}
		else if (mark == "024")
		{
			_Back(stu, cou, gra);
		}
		else if (mark == "031")
		{
			Change(stu, stu, cou, gra);
			mainwindow().func(stu, cou, gra);
		}
		else if (mark == "032")
		{
			Change(cou, stu, cou, gra);
			mainwindow().func(stu, cou, gra);
		}
		else if (mark == "033")
		{
			Change(gra, stu, cou, gra);
			mainwindow().func(stu, cou, gra);
		}
		else if (mark == "034")
		{
			_Back(stu, cou, gra);
		}
		else if (mark == "041")
		{
			Print(stu, stu, cou, gra);
			mainwindow().func(stu, cou, gra);
		}
		else if (mark == "042")
		{
			Print(cou, stu, cou, gra);
			mainwindow().func(stu, cou, gra);
		}
		else if (mark == "043")
		{
			Print(gra, stu, cou, gra);
			mainwindow().func(stu, cou, gra);
		}
		else if (mark == "044")
		{
			_Back(stu, cou, gra);
		}

		else
		{
			Back(stu, cou, gra);
		}
	}
}

void mainwindow::Error_Output(vector <Student> &stu, vector <Course> &cou, vector <Grade> &gra)
{
	system("cls");
	cout << "输入错误,请重新输入!" << endl;
	system("pause");
	mainwindow(mark).func(stu, cou, gra);
}

void mainwindow::Back(vector<Student>& stu, vector<Course>& cou, vector<Grade>& gra)
{
	string s;
	for (int i = 0;i < mark.size()-1;i++)
	{
		s += mark[i];
	}
	system("cls");
	cout << "输入错误,请重新输入!" << endl;
	system("pause");
	mainwindow(s).func(stu, cou, gra);
}

void mainwindow::_Back(vector<Student>& stu, vector<Course>& cou, vector<Grade>& gra)
{
	string s;
	for (int i = 0;i < mark.size() - 2;i++)
	{
		s += mark[i];
	}
	mainwindow(s).func(stu, cou, gra);
}

