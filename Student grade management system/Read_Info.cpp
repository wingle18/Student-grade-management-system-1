#include "Read_Info.h"

void Read_Info(vector<Student>& stu, vector<Course>& cou, vector<Grade>& gra)
{
	system("cls");
	cout << "�鿴��Ϣ" << endl;
	cout << "1.�鿴ѧ��������Ϣ 2. �鿴�γ̻�����Ϣ 3. �鿴�ɼ� 4.�鿴���� 5.����������" << endl;
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
		cout << "�������,����������!" << endl;
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
