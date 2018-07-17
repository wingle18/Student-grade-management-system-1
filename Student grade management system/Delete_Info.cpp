#include "Delete_Info.h"

void Delete_Info(vector<Student>& stu, vector<Course>& cou, vector<Grade>& gra)
{
	system("cls");
	cout << "删除信息" << endl;
	cout << "1.删除学生信息 2. 删除课程信息 3. 删除成绩 4. 返回主界面" << endl;
	string i;
	cin >> i;
	if (i == "1")
		Delete_Student_Info(stu, gra);
	if (i == "2")
		Delete_Course_Info(cou, gra);
	if (i == "3")
		Delete_Grade_Info(gra);
	if (i == "4")
		tmain();
	else
	{
		system("cls");
		cout << "输入错误,请重新输入!" << endl;
		system("pause");
		system("cls");
		Delete_Info(stu, cou, gra);
	}
}

void Delete_Student_Info(vector<Student>& stu, vector<Grade>& gra)
{
}

void Delete_Course_Info(vector<Course>& cou, vector<Grade>& gra)
{
}

void Delete_Grade_Info(vector<Grade>& gra)
{
}
