#include "Grade.h"




Grade::Grade(const string & a, const string & b, const string & c, const string & d, const string & e, const int & f, const string & g, const string & h, const int & i, const string & j, const int & k, const string & l, const double & m):Student(a,b,c,d,e,f),Course(g,h,i,j),score(k),score_rank(l),gradepoint(m)
{
}

Grade::Grade(const Grade & p):Student(p),Course(p),score(p.score),score_rank(p.score_rank),gradepoint(p.gradepoint)
{
}

Grade::Grade(const Student & a, const Course & b, const int & c, const string & d, const double & e):Student(a),Course(b),score(c),score_rank(d),gradepoint(e)
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
	*this = Grade(a, b, c, d, e, f, g, h, i, j, k, l, m);
}

void Grade::TXT_I(ifstream & inf)
{
	inf.open("grade.txt");
}

void Grade::TXT_O(ofstream & of)
{
	of.open("grade.txt");
}

void Grade::Key_Change(vector <Student> &stu, vector <Course> &cou, vector <Grade> &gra,const int &mode)
{
	if (mode == 0)
	{
		string a, b;
		Student A;
		Course B;
		cout << "������ѧ����ѧ��" << endl;
		cin >> a;
		cout << "������γ̵Ŀγ̺�" << endl;
		cin >> b;
		vector <Student>::iterator it;
		for (it = stu.begin();it != stu.end();it++)
			if (*it == a)
				A = *it;
		vector <Course>::iterator it2;
		for (it2 = cou.begin();it2 != cou.end();it2++)
			if (*it2 == b)
				B = *it2;
		int c;
		string d;
		double e;
		cout << "������ٷ��Ƴɼ�:" << endl;
		cin >> c;
		cout << "������ȼ��Ƴɼ�:" << endl;
		cin >> d;
		cout << "������ѧ�ּ�:" << endl;
		cin >> e;
		*this = Grade(A, B, c, d, e);
	}
}

void Grade::Write_Success()
{
	system("cls");
	cout << "�ɼ�����ɹ�" << endl;
	system("pause");
}

void Grade::Delete_Success()
{
	system("cls");
	cout << "ɾ���γ���Ϣ�ɹ�!" << endl;
	system("pause");
}

bool Grade::operator==(const Grade & p)
{
	return ((stu_num == p.stu_num) && (course_num == p.course_num));
}

void Grade::Change_Success()
{
	system("cls");
	cout << "�޸ĳɼ��ɹ�" << endl;
	system("pause");
}

void Grade::Num_Change(vector<Student>& stu, vector<Course>& cou, vector<Grade>& gra)
{
	string a;
	cout << "������ѧ��ѧ��" << endl;
	cin >> a;
	string b;
	cout << "������γ̺�" << endl;
	cin >> b;
	vector <Grade> ::iterator it;
	for (it = gra.begin();it != gra.end();it++)
		if (Student(*it) == a&&Course(*it)==b)
			*this = *it;
}

void Grade::Trans()
{
	if (score == 100)
	{
		score_rank = "A+";
		gradepoint = 4;
	}
	else if (score <= 99 && score >= 95)
	{
		score_rank = "A";
		gradepoint = 4;
	}
	else if (score <= 94 && score >= 90)
	{
		score_rank = "A-";
		gradepoint = 3.7;
	}
	else if (score <= 89 && score >= 85)
	{
		score_rank = "B+";
		gradepoint = 3.3;
	}
	else if (score <= 84 && score >= 80)
	{
		score_rank = "B";
		gradepoint = 3;
	}
	else if (score <= 79 && score >= 77)
	{
		score_rank = "B-";
		gradepoint = 2.7;
	}
	else if (score <= 76 && score >= 73)
	{
		score_rank = "C+";
		gradepoint = 2.3;
	}
	else if (score <= 72 && score >= 70)
	{
		score_rank = "C";
		gradepoint = 2;
	}
	else if (score <= 69 && score >= 67)
	{
		score_rank = "C-";
		gradepoint = 1.7;
	}
	else if (score <= 66 && score >= 63)
	{
		score_rank = "D+";
		gradepoint = 1.3;
	}
	else if (score <= 62 && score >= 60)
	{
		score_rank = "D";
		gradepoint = 1;
	}
	else if (score <= 59 && score >= 0)
	{
		score_rank = "F";
		gradepoint = 0;
	}
}




