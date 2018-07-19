#pragma once
#include "Grade.h"
#include "vector"
#include "sync.h"


template <typename T> 
void Write(vector <T> &vec, vector <Student> &stu, vector <Course> &cou, vector <Grade> &gra)
{
	Figure *f;
	T a;
	f = &a;
	f->Key_Change(stu, cou, gra,0);
	vec.push_back(a);
	sync_out(vec);
	T::Write_Success();
}

template <typename T>
void Delete(vector <T> &vec, vector <Student> &stu, vector <Course> &cou, vector <Grade> &gra)
{
	Figure *f;
	T a;
	f = &a;
	f->Key_Change(stu, cou, gra,1);
	int i;
	for (i = 0;i < vec.size();i++)
	{
		if (vec[i] == a)
		{
			for (;i < vec.size() - 1;i++)
				vec[i] = vec[i + 1];
		}
	}
	vec.pop_back();
	sync_out(vec);
	T::Delete_Success();
}

template<typename T>
void Change(vector <T> &vec, vector <Student> &stu, vector <Course> &cou, vector <Grade> &gra)
{
	Figure *f1,*f2;
	T a,b;
	f1 = &a;
	f2 = &b;
	cout << "请输入原始信息" << endl;
	f1->Key_Change(stu,cou,gra,1);
	system("cls");
	cout << "请输入新的信息" << endl;
	f2->Key_Change(stu,cou,gra,0);
	system("cls");
	int i;
	for (i = 0;i < vec.size();i++)
	{
		if (vec[i] == a)
			vec[i] = b;
	}
	sync_out(vec);
	T::Change_Success();
}

template<typename T>
void Print(vector <T> &vec, vector <Student> &stu, vector <Course> &cou, vector <Grade> &gra)
{
	Figure *f;
	T a;
	f = &a;
}