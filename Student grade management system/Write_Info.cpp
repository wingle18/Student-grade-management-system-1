#include "Write_Info.h"
void Write_Info(vector<Student>& stu, vector<Course>& cou, vector<Grade>& gra)
{
	system("cls");
	cout << "¼����Ϣ" << endl;
	cout << "1.¼��ѧ����Ϣ 2. ¼��γ���Ϣ 3. ¼��ɼ� 4. ����������" << endl;
	string i;
	cin >> i;
	if (i == "1")
	{
		system("cls");
		cout << "¼��ѧ����Ϣ" << endl;

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
		cout << "�������,����������!" << endl;
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
