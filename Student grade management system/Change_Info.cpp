#include "Change_Info.h"

void Change_Info(vector<Student>& stu, vector<Course>& cou, vector<Grade>& gra)
{
	system("cls");
	cout << "�޸���Ϣ" << endl;
	cout << "1.�޸�ѧ����Ϣ 2. �޸Ŀγ���Ϣ 3. �޸ĳɼ� 4. ����������" << endl;
	string i;
	cin >> i;
	if (i == "1")
		Change_Student_Info(stu, gra);
	if (i == "2")
		Change_Course_Info(cou, gra);
	if (i == "3")
		Change_Grade_Info(gra);
	if (i == "4")
		tmain();
	else
	{
		system("cls");
		cout << "�������,����������!" << endl;
		system("pause");
		system("cls");
		Change_Info(stu, cou, gra);
	}
}

void Change_Student_Info(vector<Student>& stu, vector<Grade>& gra)
{
}

void Change_Course_Info(vector<Course>& cou, vector<Grade>& gra)
{
}

void Change_Grade_Info(vector<Grade>& gra)
{
}
