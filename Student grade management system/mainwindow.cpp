#include "mainwindow.h"



mainwindow::mainwindow(const string &a):mark(a)
{
	if (a == "0")	
	{
		header = "ѧ���ɼ�����ϵͳ";
		menu = { "¼����Ϣ","ɾ����Ϣ","�޸���Ϣ","�鿴��Ϣ","�˳�ϵͳ" };
		flag = 0;
	}
	else if (a == "01")
	{
		header = "¼����Ϣ";
		menu = { "¼��ѧ����Ϣ","¼��γ���Ϣ","¼��ɼ���Ϣ","����������" };
		flag = 0;
	}
	else if (a == "02")
	{
		header = "ɾ����Ϣ";
		menu = { "ɾ��ѧ����Ϣ","ɾ���γ���Ϣ","ɾ���ɼ���Ϣ","����������" };
		flag = 0;
	}
	else if (a == "03")
	{
		header = "�޸���Ϣ";
		menu = { "�޸�ѧ����Ϣ","�޸Ŀγ���Ϣ","�޸ĳɼ���Ϣ","����������" };
		flag = 0;
	}
	else if (a == "04")
	{
		header = "�鿴��Ϣ";
		menu = { "�鿴ѧ����Ϣ","�鿴�γ���Ϣ","�鿴�ɼ���Ϣ","����������" };
		flag = 0;
	}
	else if (a == "05")
	{
		header = "�˳�ϵͳ�ɹ�!";
		flag = 1;
	}
	else if (a == "011")
	{
		header = "¼��ѧ����Ϣ";
		flag = 1;
	}
	else if (a == "012")
	{
		header = "¼��γ���Ϣ";
		flag = 1;
	}
	else if (a == "013")
	{
		header = "¼��ɼ�";
		flag = 1;
	}
	else if (a == "014")
	{
		flag = 1;
	}
	else if (a == "021")
	{
		header = "ɾ��ѧ����Ϣ";
		flag = 1;
	}
	else if (a == "022")
	{
		header = "ɾ���γ���Ϣ";
		flag = 1;
	}
	else if (a == "023")
	{
		header = "ɾ���ɼ�";
		flag = 1;
	}
	else if (a == "024")
	{
		flag = 1;
	}
	else if (a == "031")
	{
		header = "�޸�ѧ����Ϣ";
		flag = 1;
	}
	else if (a == "032")
	{
		header = "�޸Ŀγ���Ϣ";
		flag = 1;
	}
	else if (a == "033")
	{
		header = "�޸ĳɼ�";
		flag = 1;
	}
	else if (a == "034")
	{
		flag = 1;
	}
	else if (a == "041")
	{
		header = "�鿴ѧ����Ϣ";
		flag = 1;
	}
	else if (a == "042")
	{
		header = "�鿴�γ���Ϣ";
		flag = 1;
	}
	else if (a == "043")
	{
		header = "�鿴�ɼ�";
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
	cout << "�������,����������!" << endl;
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
	cout << "�������,����������!" << endl;
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

