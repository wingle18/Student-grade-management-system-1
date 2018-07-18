#pragma once
#include "Grade.h"
#include "vector"
#include "iostream"
#include "fstream"
template<typename T>
void sync_in(vector<T> &vec)
{
	ifstream inf;
	T::TXT_I(inf);
	if (inf.good())
	{
		for (;;)
		{
			Figure *f;
			T a;
			f = &a;
			f->Inf_Change(inf);
			vec.push_back(a);
			if (inf.eof())
				break;
		}
		inf.close();
	}
}
template <typename T>
void sync_out(vector<T> &vec)
{
	ofstream of;
	T::TXT_O(of);
	for (int i=0;i<vec.size();i++)
	{
		Figure *f = &(vec[i]);
		of << endl;
		string a = f->Put_string();
		of << f->Put_string();
	}
	of.close();
}