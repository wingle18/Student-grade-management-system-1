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
	cout << "学生成绩管理系统" << endl;
	cout << "1. 录入信息 2. 删除信息 3.修改信息 4. 查看信息 5.退出系统" << endl;
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
		cout << "已成功退出系统!" << endl;
		return;
	}
	else
	{
		system("cls");
		cout << "输入错误,请重新输入!" << endl;
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