#include "Write_Info.h"
void Write_Info(vector<Student>& stu, vector<Course>& cou, vector<Grade>& gra)
{
	system("cls");
	cout << "录入信息" << endl;
	cout << "1.录入学生信息 2. 录入课程信息 3. 录入成绩 4. 返回主界面" << endl;
	string i;
	cin >> i;
	if (i == "1")
	{
		system("cls");
		cout << "录入学生信息" << endl;

	}
		Write_Student_Info(stu);
	if (i == "2")
		Write_Course_Info(cou);
	if (i == "3")
		Write_Grade_Info(gra);
	if (i == "4")
		tmain();
	else
	{
		system("cls");
		cout << "输入错误,请重新输入!" << endl;
		system("pause");
		system("cls");
		Write_Info(stu, cou, gra);
	}
}

void Write_Student_Info(vector<Student>& stu)
{
}

void Write_Course_Info(vector<Course>& cou)
{
}

void Write_Grade_Info(vector<Grade>& gra)
{
}
