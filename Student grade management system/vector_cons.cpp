#include "vector_cons.h"
void stu_cons(vector <Student> &stu)
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

void cou_cons(vector <Course> &cou)
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

void gra_cons(vector <Grade> &gra)
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
