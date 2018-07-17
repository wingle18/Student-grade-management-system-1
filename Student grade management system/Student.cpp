#include "Student.h"


Student::Student(const string & a, const string & b, const string & c,const string &d,const string &e,const string &f):stu_name(a),stu_num(b),stu_sex(c),Tclass(d,e,f)
{
}

Student::Student(const Student & p):stu_name(p.stu_name),stu_num(p.stu_num),stu_sex(p.stu_sex),Tclass(p)
{
}

Student::~Student()
{
}

void Student::Print()
{
}
