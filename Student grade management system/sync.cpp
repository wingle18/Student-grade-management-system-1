#include "sync.h"
void sync_in(vector <Student> &stu)
{
	ifstream inf;
	inf.open("student.txt");
	if (inf.good())
	{
		for (;;)
		{
			string a, b, c, d, e;
			int f;
			inf >> a >> b >> c >> d >> e >> f;						//先回车一次
			stu.push_back(Student(a, b, c, d, e, f));
			if (inf.eof())
				break;
		}
		inf.close();
	}
}

void sync_in(vector <Course> &cou)
{
	ifstream inf;
	inf.open("course.txt");
	if (inf.good())
	{
		for (;;)
		{
			string a, b, d;
			int c;
			inf >> a >> b >> c >> d;					//先回车一次
			cou.push_back(Course(a, b, c, d));
			if (inf.eof())
				break;
		}
		inf.close();
	}
}

void sync_in(vector <Grade> &gra)
{
	ifstream inf;
	inf.open("grade.txt");
	if (inf.good())
	{
		for (;;)
		{
			string a,b,c,d,e,g,h,j,l;
			int f,i,k;
			double m;
			inf >> a >> b >> c >> d>>e>>f>>g>>h>>i>>j>>k>>l>>m;					//先回车一次
			gra.push_back(Grade(a, b, c, d, e, f, g, h, i, j, k, l, m));
			if (inf.eof())
				break;
		}
		inf.close();
	}
}

void sync_out(vector<Student>& stu)
{
	ofstream of;
	of.open("student.txt");
	sync_out_core(stu,of);
}

void sync_out(vector <Course> &cou)
{
	ofstream of;
	of.open("course.txt");
	sync_out_core(cou,of);
}

void sync_out(vector <Grade> &gra)
{
	ofstream of;
	of.open("grade.txt");
	sync_out_core(gra,of);
}