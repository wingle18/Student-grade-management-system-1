#pragma once
#include "Grade.h"
#include "vector"
#include "iostream"
#include "fstream"
void sync_in(vector <Student> &stu);
void sync_in(vector <Course> &cou);
void sync_in(vector <Grade> &gra);
void sync_out(vector <Student> &stu);
void sync_out(vector <Course> &cou);
void sync_out(vector <Grade> &gra);
template <typename T>
void sync_out_core(vector<T> &vec,ofstream &of)
{
	for (int i=0;i<vec.size();i++)
	{
		Figure *f = &(vec[i]);
		of << endl;
		of << f->Put_string();
	}
	of.close();
}