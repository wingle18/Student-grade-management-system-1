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

void Student::Key_Change(vector <Student> &stu, vector <Course> &cou, vector <Grade> &gra)
{
	string a, b, c, d, e;
	int f;
	cout << "请输入姓名:" << endl;
	cin >> a;
	cout << "请输入学号:" << endl;
	cin >> b;
	cout << "请输入性别:" << endl;
	cin >> c;
	cout << "请输入专业:" << endl;
	cin >> d;
	cout << "请输入教学班级:" << endl;
	cin >> e;
	cout << "请输入入学年份:" << endl;
	cin >> f;
	stu_name = a;
	stu_num = b;
	stu_sex = c;
	major = d;
	teach_class = e;
	year = f;
}

string Student::Get_stu_num()
{
	return stu_num;
}

void Student::Write_Success()
{
	system("cls");
	cout << "学生信息输入成功" << endl;
	system("pause");
}

void Student::Delete_Success()
{
	system("cls");
	cout << "删除学生信息成功!" << endl;
	system("pause");
}

bool Student::operator==(const Student &p)
{
	return (stu_num == p.stu_num);
}

void Student::Change_Success()
{
	system("cls");
	cout << "修改学生信息成功" << endl;
	system("pause");
}

void Student::Num_Change(vector<Student>& stu, vector<Course>& cou, vector<Grade>& gra)
{
	string a;
	cout << "请输入学号" << endl;
	cin >> a;
	vector <Student> ::iterator it;
	for (it = stu.begin();it != stu.end();it++)
		if (it->Get_stu_num() == a)
			*this = *it;
}
