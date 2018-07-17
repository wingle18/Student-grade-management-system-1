#include "Grade.h"




Grade::Grade(const string & a, const string & b, const string & c, const string & d, const string & e, const int & f, const string & g, const string & h, const int & i, const string & j, const int & k, const string & l, const double & m):Student(a,b,c,d,e,f),Course(g,h,i,j),score(k),score_rank(l),gradepoint(m)
{
}

Grade::Grade(const Grade & p):Student(p),Course(p),score(p.score),gradepoint(p.gradepoint)
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
	return(Student::Put_string() + ' ' + Course::Put_string() + ' ' + ss.str() + ' ' + score_rank + ' ' + ss1.str());
}
