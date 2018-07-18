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

string Course::Put_string()
{
	stringstream ss;
	ss << course_credit;
	return(course_num + ' ' + course_name + ' ' + ss.str() + ' ' + course_semester);
}

void Course::Inf_Change(ifstream & inf)
{
	string a, b, d;
	int c;
	inf >> a >> b >> c >> d;
	course_num = a;
	course_name = b;
	course_credit = c;
	course_semester = d;
}


void Course::TXT_I(ifstream & inf)
{
	inf.open("course.txt");
}

void Course::TXT_O(ofstream & of)
{
	of.open("course.txt");
}

void Course::Key_Change(vector <Student> &stu, vector <Course> &cou, vector <Grade> &gra)
{
	string a, b, d;
	int c;
	cout << "请输入课程号:" << endl;
	cin >> a;
	cout << "请输入课程名:" << endl;
	cin >> b;
	cout << "请输入课程学分:" << endl;
	cin >> c;
	cout << "请输入课程所属学期:" << endl;
	cin >> d;
	course_num = a;
	course_name = b;
	course_credit = c;
	course_semester = d;
}

string Course::Get_course_num()
{
	return course_num;
}

void Course::Write_Success()
{
	system("cls");
	cout << "课程信息输入成功" << endl;
	system("pause");
}

void Course::Delete_Success()
{
	system("cls");
	cout << "删除课程信息成功!" << endl;
	system("pause");
}

bool Course::operator==(const Course & p)
{
	return (course_num == p.course_num);
}

void Course::Change_Success()
{
	system("cls");
	cout << "修改课程信息成功" << endl;
	system("pause");
}

void Course::Num_Change(vector<Student>& stu, vector<Course>& cou, vector<Grade>& gra)
{
	string a;
	cout << "请输入课程号" << endl;
	cin >> a;
	vector <Course> ::iterator it;
	for (it = cou.begin();it != cou.end();it++)
		if (it->Get_course_num() == a)
			*this = *it;
}

