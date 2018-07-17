#include "Read_Info.h"

void Read_Info(vector<Student>& stu, vector<Course>& cou, vector<Grade>& gra)
{
	system("cls");
	cout << "查看信息" << endl;
	cout << "1.查看学生基本信息 2. 查看课程基本信息 3. 查看成绩 4.查看排名 5.返回主界面" << endl;
	string i;
	cin >> i;
	if (i == "1")
		Read_Student_Info(stu);
	if (i == "2")
		Read_Course_Info(cou);
	if (i == "3")
		Read_Grade_Info(stu, cou, gra);
	if (i == "4")
	{
		Read_Rank_Info(stu, cou, gra);
	}
	if (i == "5")
	{
		system("cls");
		tmain();
	}
	else
	{
		system("cls");
		cout << "输入错误,请重新输入!" << endl;
		system("pause");
		system("cls");
		Read_Info(stu, cou, gra);
	}
}

void Read_Student_Info(vector<Student>& stu)
{
}

void Read_Course_Info(vector<Course>& cou)
{
}

void Read_Grade_Info(vector <Student> &stu, vector <Course> &cou, vector <Grade> &gra)
{
}

void Read_Rank_Info(vector<Student>& stu, vector<Course>& cou, vector<Grade>& gra)
{
}
