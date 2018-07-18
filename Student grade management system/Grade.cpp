#include "Grade.h"




Grade::Grade(const string & a, const string & b, const string & c, const string & d, const string & e, const int & f, const string & g, const string & h, const int & i, const string & j, const int & k, const string & l, const double & m):Student(a,b,c,d,e,f),Course(g,h,i,j),score(k),score_rank(l),gradepoint(m)
{
}

Grade::Grade(const Grade & p):Student(p),Course(p),score(p.score),score_rank(p.score_rank),gradepoint(p.gradepoint)
{
}

Grade::~Grade()
{
}

string Grade::Put_string()
{
	stringstream ss, ss1;
	ss << score;
	ss1 << gradepoint;
	string a = score_rank;
	return(Student::Put_string() + ' ' + Course::Put_string() + ' ' + ss.str() + ' ' + score_rank + ' ' + ss1.str());
}

void Grade::Inf_Change(ifstream & inf)
{
	string a, b, c, d, e, g, h, j, l;
	int f, i, k;
	double m;
	inf >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l >> m;
	stu_name = a;
	stu_num = b;
	stu_sex = c;
	major = d;
	teach_class = e;
	year = f;
	course_num = g;
	course_name = h;
	course_credit = i;
	course_semester = j;
	score = k;
	score_rank = l;
	gradepoint = m;
}

void Grade::TXT_I(ifstream & inf)
{
	inf.open("grade.txt");
}

void Grade::TXT_O(ofstream & of)
{
	of.open("grade.txt");
}

