#include "Course.h"


Course::Course(const string & a, const string & b, const int & c, const string & d):course_num(a),course_name(b),course_credit(c),course_semester(d)
{
}

Course::Course(const Course & p):course_num(p.course_num),course_name(p.course_name),course_credit(p.course_credit),course_semester(p.course_semester)
{
}

Course::~Course()
{
}

void Course::Print()
{
}
