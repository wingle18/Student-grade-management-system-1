#include "main.h"
void tmain()
{
	vector <Student> stu;
	vector <Course> cou;
	vector <Grade> gra;
	sync_in(stu);
	sync_in(cou);
	sync_in(gra);
	sync_out(stu);
	sync_out(cou);
	sync_out(gra);
	system("cls");
	cout << "ѧ���ɼ�����ϵͳ" << endl;
	cout << "1. ¼����Ϣ 2. ɾ����Ϣ 3.�޸���Ϣ 4. �鿴��Ϣ 5.�˳�ϵͳ" << endl;
	string i;
	cin >> i;
	if (i == "1")
		Write_Info(stu, cou, gra);
	if (i == "2")
		Delete_Info(stu, cou, gra);
	if (i == "3")
		Change_Info(stu, cou, gra);
	if (i == "4")
		Read_Info(stu, cou, gra);
	if (i == "5")
	{
		system("cls");
		cout << "�ѳɹ��˳�ϵͳ!" << endl;
		return;
	}
	else
	{
		system("cls");
		cout << "�������,����������!" << endl;
		system("pause");
		system("cls");
		tmain();
	}
}
int main()
{
	tmain();
	system("pause");
	return 0;
}