#include "Student.h"


Student::Student(const string & a, const string & b, const string & c,const string &d,const string &e,const int &f):stu_name(a),stu_num(b),stu_sex(c),Tclass(d,e,f)
{
}

Student::Student(const Student & p):stu_name(p.stu_name),stu_num(p.stu_num),stu_sex(p.stu_sex),Tclass(p)
{
}

Student::~Student()
{
}

string Student::Put_string()
{
	stringstream ss;
	ss << year;
	return(stu_name + ' ' + stu_num + ' ' + stu_sex + ' ' + major + ' ' + teach_class+' '+ss.str());
}

void Student::Inf_Change(ifstream & inf)
{
	string a, b, c, d, e;
	int f;
	inf >> a >> b >> c >> d >> e >> f;
	stu_name = a;
	stu_num = b;
	stu_sex = c;
	major = d;
	teach_class = e;
	year = f;
}

void Student::TXT_I(ifstream &inf)
{
	inf.open("student.txt");
}

void Student::TXT_O(ofstream &of)
{
	of.open("student.txt");
}