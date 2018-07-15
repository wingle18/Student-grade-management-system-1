#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
//�ĳ���Ӻ�ɾ��,�޸ļ�����Ӻ�ɾ��
//ɾ��ѧ���Ϳγ�ʱͬʱɾ���ɼ�
class Figure	//�����
{
	virtual void Print() = 0;
};
class Tclass
{
protected:
	string major;
	string teach_class;
	int year;
public:
	Tclass(string a, string b, int c) :major(a), teach_class(b), year(c)
	{}
	Tclass(const Tclass &p) :major(p.major), teach_class(p.teach_class), year(p.year)
	{}
	~Tclass()
	{}
	string Get_year()
	{
		stringstream ss;
		ss << year;
		return ss.str();
	}
	string Get_major()
	{
		return major;
	}
	string Get_teach_class()
	{
		return teach_class;
	}
};
class Student : public Figure, public Tclass
{
protected:
	string name;//����
	string num;//ѧ��
	bool sex;//�Ա�
public:
	Student(string a = "N/A", string b = "N/A", int c = 0, string d = "N/A", string e = "N/A", bool f = 0) :name(a), num(b), sex(f), Tclass(d, e, c)
	{}
	Student(const Student &p) :name(p.name), num(p.name), sex(p.sex), Tclass(p)
	{}
	~Student()
	{}
	void Print()
	{
		if (sex == 0)
			std::cout << name << " " << num << " " << "��" << " " << major << " " << teach_class << " " << year << std::endl;
		else
			std::cout << name << " " << num << " " << "Ů" << " " << major << " " << teach_class << " " << year << std::endl;
	}
	bool operator ==(const Student &a)
	{
		return(num == a.num);
	}
	string Get_num()
	{
		return num;
	}
	string Get_name()
	{
		return name;
	}
	string Get_sex()
	{
		stringstream ss;
		ss << sex;
		return ss.str();
	}
};
class Course : public Figure
{
protected:
	string course_num;//�γ̺�
	string course_name;//�γ���
	int course_credit;//�γ�ѧ��
	string course_semester;//�γ�����ѧ��
public:
	Course(string a = "N/A", string b = "N/A", int c = 0, string d = "N/A") :course_num(a), course_name(b), course_credit(c), course_semester(d)
	{}
	Course(const Course &p) :course_num(p.course_num), course_name(p.course_name), course_credit(p.course_credit), course_semester(p.course_semester)
	{}
	~Course()
	{}
	void Print()
	{
		std::cout << course_num << " " << course_name << " " << course_credit << " " << course_semester << std::endl;
	}
	string Get_course_num()
	{
		return course_num;
	}
	string Get_course_name()
	{
		return course_name;
	}
	string Get_course_credit()
	{
		stringstream ss;
		ss << course_credit;
		return ss.str();
	}
	string Get_course_semester()
	{
		return course_semester;
	}
};
class Grade :public Student, public Course
{
protected:
	int score;//�ٷ��Ƴɼ�
	string score_rank;//�ȼ��Ƴɼ�
	double gradepoint;//ѧ�ּ�
public:
	Grade(string a = "N/A", string b = "N/A", int c = 0, string d = "N/A", string e = "N/A", bool f = 0, string a1 = "N/A", string b1 = "N/A", int c1 = 0, string d1 = "N/A", int a2 = 0, string b2 = "N/A", double c2 = 0) :Student(a, b, c, d, e, f), Course(a1, b1, c1, d1), score(a2), score_rank(b2), gradepoint(c2)
	{}
	Grade(const Grade &p) :Student(p), Course(p), score(p.score), score_rank(p.score_rank), gradepoint(p.gradepoint)
	{}
	~Grade()
	{}
	void Print()
	{
		std::cout << name << " " << num << " " << sex << " " << major << " " << teach_class << " " << year << " " << course_num << " " << course_name << " " << course_credit << " " << course_semester << " " << score << " " << score_rank << " " << gradepoint << std::endl;
	}
};
//�½����޸ĵ�ʱ�����ı�,�����������,��ʾ��Ϣ��ʱ������ĺ���
//����Ҫ��ϵͳ����Ƶ������Ŀ������4����ÿ������Ҫ�и��Ե����ԣ�����3�����ͷ���������3��������Ҫ����һ�������࣬
//���ü̳з�ʽ������Щ�ࡣ�����һ�����ؼ̳е������ࡣ�ڳ�������У�����ຯ���Ķ�̬�ԡ���������صȻ��ơ�
void tmain();				//����
void Write_Info(Student *, Course *, Grade *, int, int, int);
void Delete_Info(Student *, Course *, Grade *, int, int, int);
void Read_Info(Student *, Course *, Grade *, int, int, int);
void Write_Student_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{
	system("cls");
	std::cout << "¼��ѧ����Ϣ" << std::endl;
	std::cout << "1.��ʼ¼��ѧ����Ϣ 2.������һ����� 3.����������" << std::endl;
	string i;
	cin >> i;
	if (i == "1")
	{
		system("cls");
		std::cout << "¼��ѧ����Ϣ" << std::endl;
		ofstream of;
		of.open("student.txt", ios_base::_Noreplace);		//�ж��Ƿ��ǵ�һ��¼��
		if (of.fail())
			of.open("student.txt", ios_base::app);
		std::cout << "ѧ������:" << std::endl;
		string a, b, c, d, e, f;
		std::cin >> a;
		std::cout << "ѧ��:" << std::endl;
		std::cin >> b;
		std::cout << "��ѧ���:" << std::endl;
		std::cin >> c;
		std::cout << "רҵ:" << std::endl;
		std::cin >> d;
		std::cout << "��ѧ�༶:" << std::endl;
		std::cin >> e;
		std::cout << "�Ա�, 0Ϊ��, 1ΪŮ" << std::endl;
		std::cin >> f;
		if (f != "0"&&f != "1")
		{
			system("cls");
			std::cout << "�Ա�����Ƿ�,������¼��ѧ����Ϣ!" << std::endl;
			system("pause");
			Write_Student_Info(stu, cou, gra, i0, i1, i2);
		}
		for (int k = 0;k < i0;k++)
		{
			if (stu[k].Get_num() == b)
			{
				system("cls");
				std::cout << "������ͬѧ�ŵ�ѧ��,������¼��ѧ����Ϣ!" << std::endl;
				system("pause");
				Write_Student_Info(stu, cou, gra, i0, i1, i2);
			}
		}
		of << a << " " << b << " " << c << " " << d << " " << e << " " << f << std::endl;
		of.close();
		system("cls");
		std::cout << "ѧ����Ϣ�ѳɹ�¼��!" << std::endl;
		system("pause");
		tmain();
	}
	if (i == "2")
		Write_Info(stu, cou, gra, i0, i1, i2);
	if (i == "3")
		tmain();
	else
	{
		system("cls");
		std::cout << "�������,����������!" << endl;
		system("pause");
		Write_Student_Info(stu, cou, gra, i0, i1, i2);
	}
}
void Write_Course_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{
	system("cls");
	std::cout << "¼��γ���Ϣ" << std::endl;
	std::cout << "1.��ʼ¼��γ���Ϣ 2.������һ����� 3.����������" << std::endl;
	string i;
	cin >> i;
	if (i == "1")
	{
		system("cls");
		std::cout << "¼��γ���Ϣ" << std::endl;
		ofstream of;
		of.open("course.txt", ios_base::_Noreplace);		//�ж��Ƿ��ǵ�һ��¼��
		if (of.fail())
			of.open("course.txt", ios_base::app);
		string a, b, c, d;
		std::cout << "�γ̺�:" << std::endl;
		std::cin >> a;
		std::cout << "�γ���:" << std::endl;
		std::cin >> b;
		std::cout << "�γ�ѧ��(��߲�����15ѧ��):" << std::endl;
		std::cin >> c;
		std::cout << "�γ�����ѧ��:" << std::endl;
		std::cin >> d;
		if (!((c >= "0"&&c <= "9") || (c >= "10"&&c <= "15")))
		{
			system("cls");
			std::cout << "�γ�ѧ�ַǷ�,������¼��γ���Ϣ!" << std::endl;
			system("pause");
			Write_Course_Info(stu, cou, gra, i0, i1, i2);
		}
		for (int k = 0;k < i1;k++)
		{
			if (cou[k].Get_course_num() == a)
			{
				system("cls");
				std::cout << "������ͬ�γ̺ŵĿγ�,������¼��γ���Ϣ!" << std::endl;
				system("pause");
				Write_Course_Info(stu, cou, gra, i0, i1, i2);
			}
		}
		of << a << " " << b << " " << c << " " << d << std::endl;
		of.close();
		system("cls");
		std::cout << "�γ���Ϣ¼��ɹ�!" << std::endl;
		system("pause");
		tmain();
	}
	if (i == "2")
		Write_Info(stu, cou, gra, i0, i1, i2);
	if (i == "3")
		tmain();
	else
	{
		system("cls");
		std::cout << "�������,����������!" << endl;
		system("pause");
		Write_Course_Info(stu, cou, gra, i0, i1, i2);
	}
}
void Write_Grade_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{
	system("cls");
	std::cout << "¼��ɼ���Ϣ" << std::endl;
	std::cout << "1.��ʼ¼��ɼ���Ϣ 2.������һ����� 3.����������" << std::endl;
	string i;
	cin >> i;
	if (i == "1")
	{
		system("cls");
		std::cout << "¼��ɼ���Ϣ" << std::endl;
		ofstream of;
		of.open("grade.txt", ios_base::_Noreplace);	//�ж��Ƿ��һ��¼��
		if (of.fail())
			of.open("grade.txt", ios_base::app);
		string a, b, c, d, e, f, g, h, i, j, _k, l = "N/A", m;
		int k;
		std::cout << "ѧ��ѧ��:" << std::endl;
		std::cin >> b;
		std::cout << "�γ̺�:" << std::endl;
		std::cin >> g;
		std::cout << "�ٷ��Ƴɼ�:" << std::endl;
		std::cin >> k;
		if (k <= 100 && k >= 95)
		{
			l = "A";
			m = "4.0";
		}
		if (k < 95 && k >= 90)
		{
			l = "A-";
			m = "3.7";
		}
		if (k < 90 && k >= 85)
		{
			l = "B+";
			m = "3.3";
		}
		if (k < 85 && k >= 80)
		{
			l = "B";
			m = "3.0";
		}
		if (k < 80 && k >= 77)
		{
			l = "B-";
			m = "2.7";
		}
		if (k < 77 && k >= 73)
		{
			l = "C+";
			m = "2.3";
		}
		if (k < 73 && k >= 70)
		{
			l = "C";
			m = "2.0";
		}
		if (k < 70 && k >= 67)
		{
			l = "C-";
			m = "1.7";
		}
		if (k < 67 && k >= 63)
		{
			l = "D+";
			m = "1.3";
		}
		if (k < 63 && k >= 60)
		{
			l = "D";
			m = "1.0";
		}
		if (k < 60 && k >= 0)
		{
			l = "F";
			m = "0.0";
		}
		stringstream ss;
		ss << k;
		_k = ss.str();
		bool flag0 = 0, flag1 = 0;
		for (int n = 0;n < i0;n++)
		{
			if (stu[n].Get_num() == b)
			{
				flag0 = 1;
				a = stu[n].Get_name();
				c = stu[n].Get_year();
				d = stu[n].Get_major();
				e = stu[n].Get_teach_class();
				f = stu[n].Get_sex();
			}
		}
		for (int n = 0;n < i1;n++)
		{
			if (cou[n].Get_course_num() == g)
			{
				flag1 = 1;
				h = cou[n].Get_course_name();
				i = cou[n].Get_course_credit();
				j = cou[n].Get_course_semester();
			}
		}
		if (l == "N/A")
		{
			system("cls");
			std::cout << "����ɼ��Ƿ�,������¼��ɼ�!" << std::endl;
			system("pause");
			Write_Grade_Info(stu, cou, gra, i0, i1, i2);
		}
		if (flag0 == 0)
		{
			system("cls");
			std::cout << "û�и�ѧ������Ϣ,������¼��ɼ�!" << std::endl;
			system("pause");
			Write_Grade_Info(stu, cou, gra, i0, i1, i2);
		}
		if (flag1 == 0)
		{
			system("cls");
			std::cout << "û�иÿγ̵���Ϣ,������¼��ɼ�!" << std::endl;
			system("pause");
			Write_Grade_Info(stu, cou, gra, i0, i1, i2);
		}
		bool flag2 = 0, flag3 = 0;
		for (int n = 0;n < i2;n++)
			if (gra[n].Get_num() == b)
				flag2 = 1;
		for (int n = 0;n < i2;n++)
			if (gra[n].Get_course_num() == g)
				flag3 = 1;
		if (flag2 == 1 && flag3 == 1)
		{
			system("cls");
			std::cout << "�óɼ��Ѿ�����,������¼��ɼ�!" << std::endl;
			system("pause");
			Write_Grade_Info(stu, cou, gra, i0, i1, i2);
		}
		of << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << " " << i << " " << j << " " << k << " " << l << " " << m << std::endl;
		of.close();
		system("cls");
		std::cout << "�ɼ�¼��ɹ�!" << std::endl;
		system("pause");
		tmain();
	}
	if (i == "2")
		Write_Info(stu, cou, gra, i0, i1, i2);
	if (i == "3")
		tmain();
	else
	{
		system("cls");
		std::cout << "�������,����������!" << endl;
		system("pause");
		Write_Grade_Info(stu, cou, gra, i0, i1, i2);
	}
}
void Delete_Student_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{
	system("cls");
	std::cout << "ɾ��ѧ����Ϣ" << std::endl;
	std::cout << "1.��ʼɾ��ѧ����Ϣ 2.������һ����� 3.����������" << std::endl;
	string i;
	bool flag = 0;
	cin >> i;
	//if(i=="1")
	//{
	//	system("cls");
	//	ifstream inf;
	//	ofstream of;
	//	inf.open("student.txt");
	//	of.open("temp.txt");		//��ʱ����ԭ�����ļ�����
	//	string b,c,d=" ",e;
	//	std::cout<<"������Ҫ�޸�ѧ��������:"<<std::endl;
	//	std::cin>>c;
	//	b+=c;
	//	b+=d;
	//	std::cout<<"������Ҫ�޸�ѧ����ѧ��:"<<std::endl;
	//	std::cin>>c;
	//	b+=c;
	//	b+=d;
	//	std::cout<<"������Ҫ�޸�ѧ������ѧ���:"<<std::endl;
	//	std::cin>>c;
	//	b+=c;
	//	b+=d;
	//	std::cout<<"������Ҫ�޸�ѧ����רҵ:"<<std::endl;
	//	std::cin>>c;
	//	b+=c;
	//	b+=d;
	//	std::cout<<"������Ҫ�޸�ѧ���Ľ�ѧ�༶:"<<std::endl;
	//	std::cin>>c;
	//	b+=c;
	//	b+=d;
	//	std::cout<<"������Ҫ�޸�ѧ�����Ա�:"<<std::endl;
	//	std::cin>>c;
	//	b+=c;
	//	for(;;)
	//	{
	//		getline(inf,e);
	//		if(e=="\0"||inf.eof())
	//			break;
	//		if(e!=b)
	//			of<<e<<std::endl;
	//		else
	//			flag=1;
	//	}
	//	if(flag==0)
	//	{
	//		system("cls");
	//		std::cout<<"Ҫ�޸ĵ�ѧ����Ϣ������!"<<std::endl;
	//		system("pause");
	//		Delete_Student_Info(stu,cou,gra,i0,i1,i2);
	//	}
	//	inf.close();
	//	of.close();
	//	of.open("student.txt");
	//	inf.open("temp.txt");
	//	for(;;)
	//	{
	//		getline(inf,e);
	//		if(e=="\0"||inf.eof())
	//			break;
	//		of<<e<<std::endl;
	//	}
	//	inf.close();
	//	of.close();
	//	system("cls");
	//	std::cout<<"�����������µ���Ϣ:"<<std::endl;
	//	system("pause");
	//	Write_Student_Info(stu,cou,gra,i0,i1,i2);
	//}
	if (i == "1")
	{
		system("cls");
		ifstream inf;
		ofstream of;
		inf.open("student.txt");
		of.open("temp.txt");		//��ʱ����ԭ�����ļ�����
		string b, c, d = " ", e;
		std::cout << "������Ҫɾ��ѧ��������:" << std::endl;
		std::cin >> c;
		b += c;
		b += d;
		std::cout << "������Ҫɾ��ѧ����ѧ��:" << std::endl;
		std::cin >> c;
		b += c;
		b += d;
		std::cout << "������Ҫɾ��ѧ������ѧ���:" << std::endl;
		std::cin >> c;
		b += c;
		b += d;
		std::cout << "������Ҫɾ��ѧ����רҵ:" << std::endl;
		std::cin >> c;
		b += c;
		b += d;
		std::cout << "������Ҫɾ��ѧ���Ľ�ѧ�༶:" << std::endl;
		std::cin >> c;
		b += c;
		b += d;
		std::cout << "������Ҫɾ��ѧ�����Ա�:" << std::endl;
		std::cin >> c;
		b += c;
		for (;;)
		{
			getline(inf, e);
			if (e == "\0" || inf.eof())
				break;
			if (e != b)
				of << e << std::endl;
			else
				flag = 1;
		}
		if (flag == 0)
		{
			system("cls");
			std::cout << "Ҫɾ����ѧ����Ϣ������!" << std::endl;
			system("pause");
			Delete_Student_Info(stu, cou, gra, i0, i1, i2);
		}
		inf.close();
		of.close();
		of.open("student.txt");
		inf.open("temp.txt");
		for (;;)
		{
			getline(inf, e);
			if (e == "\0" || inf.eof())
				break;
			of << e << std::endl;
		}
		inf.close();
		of.close();
		system("cls");
		std::cout << "ɾ��ѧ����Ϣ�ɹ�!" << std::endl;
		system("pause");
		tmain();
	}
	if (i == "2")
		Delete_Info(stu, cou, gra, i0, i1, i2);
	if (i == "3")
		tmain();
	else
	{
		system("cls");
		std::cout << "�������,����������!" << endl;
		system("pause");
		Delete_Student_Info(stu, cou, gra, i0, i1, i2);
	}
}
void Delete_Course_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{
	system("cls");
	std::cout << "ɾ���γ���Ϣ" << std::endl;
	std::cout << "1.��ʼɾ���γ���Ϣ 2.������һ����� 3.����������" << std::endl;
	string i;
	bool flag = 0;
	std::cin >> i;
	if (i == "1")
	{
		system("cls");
		std::cout << "ɾ���γ���Ϣ" << std::endl;
		ifstream inf;
		ofstream of;
		inf.open("course.txt");
		of.open("temp.txt");
		string a, b, c = " ";
		std::cout << "������Ҫɾ���γ̵Ŀγ̺�" << std::endl;
		std::cin >> a;
		b += a;
		b += c;
		std::cout << "������Ҫɾ���γ̵Ŀγ���" << std::endl;
		std::cin >> a;
		b += a;
		b += c;
		std::cout << "������Ҫɾ���γ̵�ѧ��" << std::endl;
		std::cin >> a;
		b += a;
		b += c;
		std::cout << "������Ҫɾ���γ�������ѧ��" << std::endl;
		std::cin >> a;
		b += a;
		for (;;)
		{
			getline(inf, c);
			if (c == "\0" || inf.eof())
				break;
			if (c != b)
				of << c << std::endl;
			else
				flag = 1;
		}
		inf.close();
		of.close();
		if (flag == 0)
		{
			system("cls");
			std::cout << "Ҫɾ���Ŀγ���Ϣ������!" << std::endl;
			system("pause");
			Delete_Course_Info(stu, cou, gra, i0, i1, i2);
		}
		inf.open("temp.txt");
		of.open("course.txt");
		for (;;)
		{
			getline(inf, c);
			if (c == "\0" || inf.eof())
				break;
			of << c << std::endl;
		}
		inf.close();
		of.close();
		system("cls");
		std::cout << "ɾ���γ���Ϣ�ɹ�!" << std::endl;
		system("pause");
		tmain();
	}
	if (i == "2")
		Delete_Info(stu, cou, gra, i0, i1, i2);
	if (i == "3")
		tmain();
	else
	{
		system("cls");
		std::cout << "�������,����������!" << endl;
		system("pause");
		Delete_Course_Info(stu, cou, gra, i0, i1, i2);
	}
}
void Delete_Grade_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{
	system("cls");
	std::cout << "ɾ���ɼ���Ϣ" << std::endl;
	std::cout << "1.��ʼɾ���ɼ���Ϣ 2.������һ����� 3.����������" << std::endl;
	string i;
	bool flag = 0;
	std::cin >> i;
	if (i == "1")
	{
		system("cls");
		std::cout << "ɾ���ɼ���Ϣ" << std::endl;
		ifstream inf;
		ofstream of;
		inf.open("grade.txt");
		of.open("temp.txt");
		string a, b, c = " ";
		int d;
		std::cout << "������Ҫɾ��ѧ��������:" << std::endl;
		std::cin >> a;
		b += a;
		b += c;
		std::cout << "������Ҫɾ��ѧ����ѧ��:" << std::endl;
		std::cin >> a;
		b += a;
		b += c;
		std::cout << "������Ҫɾ��ѧ������ѧ���:" << std::endl;
		std::cin >> a;
		b += a;
		b += c;
		std::cout << "������Ҫɾ��ѧ����רҵ:" << std::endl;
		std::cin >> a;
		b += a;
		b += c;
		std::cout << "������Ҫɾ��ѧ���Ľ�ѧ�༶:" << std::endl;
		std::cin >> a;
		b += a;
		b += c;
		std::cout << "������Ҫɾ��ѧ�����Ա�:" << std::endl;
		std::cin >> a;
		b += a;
		b += c;
		std::cout << "������Ҫɾ���γ̵Ŀγ̺�" << std::endl;
		std::cin >> a;
		b += a;
		b += c;
		std::cout << "������Ҫɾ���γ̵Ŀγ���" << std::endl;
		std::cin >> a;
		b += a;
		b += c;
		std::cout << "������Ҫɾ���γ̵�ѧ��" << std::endl;
		std::cin >> a;
		b += a;
		b += c;
		std::cout << "������Ҫɾ���γ�������ѧ��" << std::endl;
		std::cin >> a;
		b += a;
		b += c;
		std::cout << "������Ҫɾ���γ̵İٷ��Ƴɼ�" << std::endl;
		std::cin >> a;
		b += a;
		b += c;
		stringstream ss, ss0;
		ss0 << a;
		ss0 >> d;
		if (d <= 100 && d >= 95)
			ss << "A 4.0";
		if (d <= 94 && d >= 90)
			ss << "A- 3.7";
		if (d <= 89 && d >= 85)
			ss << "B+ 3.3";
		if (d <= 84 && d >= 80)
			ss << "B 3.0";
		if (d <= 79 && d >= 77)
			ss << "B- 2.7";
		if (d <= 76 && d >= 73)
			ss << "C+ 2.3";
		if (d <= 72 && d >= 70)
			ss << "C 2.0";
		if (d <= 69 && d >= 67)
			ss << "C- 1.7";
		if (d <= 66 && d >= 63)
			ss << "D+ 1.3";
		if (d <= 62 && d >= 60)
			ss << "D 1.0";
		if (d <= 59 && d >= 0)
			ss << "F 0.0";
		a = ss.str();
		b += a;
		for (;;)
		{
			getline(inf, c);
			if (c == "\0" || inf.eof())
				break;
			if (c != b)
				of << c << std::endl;
			else
				flag = 1;
		}
		inf.close();
		of.close();
		if (flag == 0)
		{
			system("cls");
			std::cout << "Ҫɾ���ĳɼ���Ϣ������!" << std::endl;
			system("pause");
			Delete_Grade_Info(stu, cou, gra, i0, i1, i2);
		}
		inf.open("temp.txt");
		of.open("grade.txt");
		for (;;)
		{
			getline(inf, c);
			if (c == "\0" || inf.eof())
				break;
			of << c << std::endl;
		}
		inf.close();
		of.close();
		system("cls");
		std::cout << "ɾ���ɼ���Ϣ�ɹ�!" << std::endl;
		system("pause");
		tmain();
	}
	if (i == "2")
		Delete_Info(stu, cou, gra, i0, i1, i2);
	if (i == "3")
		tmain();
	else
	{
		system("cls");
		std::cout << "�������,����������!" << endl;
		system("pause");
		Delete_Grade_Info(stu, cou, gra, i0, i1, i2);
	}
}
void Read_Student_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{
	system("cls");
	std::cout << "�鿴ѧ����Ϣ" << std::endl;
	std::cout << "1.��ѧ�Ų�ѯѧ����Ϣ 2.������һ����� 3.����������" << std::endl;
	string i;
	cin >> i;
	if (i == "1")
	{
		if (i0 != 0)
		{
			system("cls");
			std::cout << "��ѧ�Ų�ѯѧ����Ϣ" << std::endl;
			string a;
			std::cout << "������Ҫ�鿴ѧ����ѧ��:" << std::endl;
			std::cin >> a;
			bool flag = 0;
			for (int k = 0; k < i0; k++)
				if (stu[k].Get_num() == a)
				{
					system("cls");
					stu[k].Print();
					flag = 1;
				}
			if (flag == 0)
			{
				system("cls");
				std::cout << "δ�ҵ���ѧ�ŵ�ѧ��, ����������" << std::endl;
				system("pause");
				Read_Student_Info(stu, cou, gra, i0, i1, i2);
			}
			system("pause");
			tmain();
		}
		else
		{
			std::cout << "ѧ����ϢΪ��,����¼��ѧ���ɼ�!" << std::endl;
			system("pause");
			tmain();
		}
	}
	if (i == "2")
		Read_Info(stu, cou, gra, i0, i1, i2);
	if (i == "3")
		tmain();
	else
	{
		system("cls");
		std::cout << "�������,����������!" << endl;
		system("pause");
		Read_Student_Info(stu, cou, gra, i0, i1, i2);
	}
}
void Read_Course_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{
	system("cls");
	if (i1 != 0)
	{
		string a;
		std::cout << "������Ҫ�鿴�γ̵Ŀγ̺�:" << std::endl;
		std::cin >> a;
		for (int k = 0;k < i1;k++)
			if (cou[k].Get_course_num() == a)
				cou[k].Print();
		system("pause");
		tmain();
	}
	else
	{
		std::cout << "�γ���ϢΪ��,����¼��γ���Ϣ!" << std::endl;
		system("pause");
		tmain();
	}
}
void Read_Grade_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{
	system("cls");
	if (i2 != 0)
	{
		string a, b;
		std::cout << "������Ҫ�鿴ѧ����ѧ��:" << std::endl;
		std::cin >> a;
		std::cout << "������Ҫ�鿴�γ̵Ŀγ̺�:" << std::endl;
		std::cin >> b;
		for (int k = 0;k < i2;k++)
			if (gra[k].Get_num() == a && gra[k].Get_course_num() == b)
				gra[k].Print();
		system("pause");
		tmain();
	}
	else
	{
		std::cout << "�ɼ���ϢΪ��,����¼��ɼ���Ϣ!" << std::endl;
		system("pause");
		tmain();
	}
}
void Write_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{
	system("cls");
	std::cout << "¼����Ϣ" << std::endl;
	std::cout << "1.¼��ѧ����Ϣ 2. ¼��γ���Ϣ 3. ¼��ɼ� 4. ����������" << std::endl;
	string i;
	std::cin >> i;
	if (i == "1")
		Write_Student_Info(stu, cou, gra, i0, i1, i2);
	if (i == "2")
		Write_Course_Info(stu, cou, gra, i0, i1, i2);
	if (i == "3")
		Write_Grade_Info(stu, cou, gra, i0, i1, i2);
	if (i == "4")
		tmain();
	else
	{
		system("cls");
		std::cout << "�������,����������!" << endl;
		system("pause");
		system("cls");
		Write_Info(stu, cou, gra, i0, i1, i2);
	}
}
void Delete_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{
	system("cls");
	std::cout << "ɾ����Ϣ" << std::endl;
	std::cout << "1.ɾ��ѧ����Ϣ 2. ɾ���γ���Ϣ 3. ɾ���ɼ� 4. ����������" << std::endl;
	string i;
	std::cin >> i;
	if (i == "1")
		Delete_Student_Info(stu, cou, gra, i0, i1, i2);
	if (i == "2")
		Delete_Course_Info(stu, cou, gra, i0, i1, i2);
	if (i == "3")
		Delete_Grade_Info(stu, cou, gra, i0, i1, i2);
	if (i == "4")
		tmain();
	else
	{
		system("cls");
		std::cout << "�������,����������!" << endl;
		system("pause");
		system("cls");
		Delete_Info(stu, cou, gra, i0, i1, i2);
	}
}
void Read_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{
	system("cls");
	std::cout << "�鿴��Ϣ" << endl;
	std::cout << "1.�鿴ѧ����Ϣ 2. �鿴�γ���Ϣ 3. �鿴�ɼ� 4.����������" << std::endl;
	string i;
	std::cin >> i;
	if (i == "1")
		Read_Student_Info(stu, cou, gra, i0, i1, i2);
	if (i == "2")
		Read_Course_Info(stu, cou, gra, i0, i1, i2);
	if (i == "3")
		Read_Grade_Info(stu, cou, gra, i0, i1, i2);
	if (i == "4")
	{
		system("cls");
		tmain();
	}
	else
	{
		system("cls");
		std::cout << "�������,����������!" << endl;
		system("pause");
		system("cls");
		Read_Info(stu, cou, gra, i0, i1, i2);
	}
}
void tmain()
{
	Student *stu = NULL;
	Course *cou = NULL;
	Grade *gra = NULL;
	ifstream inf, inf1;
	int i0 = 0, i1 = 0, i2 = 0;
	inf.open("student.txt");
	if (inf.good())
	{
		char ch0;
		while (!inf.eof())
		{
			ch0 = inf.get();
			if (ch0 == '\n')
				i0++;
		}											//iΪѧ������
		inf.close();
		inf1.open("student.txt");
		stu = new Student[i0];
		for (int k = 0;k < i0;k++)
		{
			string a, b, d, e;
			int c;
			bool f;
			inf1 >> a >> b >> c >> d >> e >> f;
			stu[k] = Student(a, b, c, d, e, f);
		}
		inf1.close();
	}
	inf.open("course.txt");
	if (inf.good())
	{
		char ch1;
		while (!inf.eof())
		{
			ch1 = inf.get();
			if (ch1 == '\n')
				i1++;
		}							//iΪ�γ�����
		inf.close();
		inf1.open("course.txt");
		cou = new Course[i1];
		for (int k = 0;k < i1;k++)
		{
			string a, b, d;
			int c;
			inf1 >> a >> b >> c >> d;
			cou[k] = Course(a, b, c, d);
		}
		inf1.close();
	}
	inf.open("grade.txt");
	if (inf.good())
	{
		char ch2;
		while (!inf.eof())
		{
			ch2 = inf.get();
			if (ch2 == '\n')
				i2++;
		}							//iΪ�γ�����
		inf.close();
		inf1.open("grade.txt");
		gra = new Grade[i2];
		for (int k = 0;k < i2;k++)
		{
			string a, b, d, e, a1, b1, d1, b2;
			int c, c1, a2;
			double c2;
			bool f;
			inf1 >> a >> b >> c >> d >> e >> f >> a1 >> b1 >> c1 >> d1 >> a2 >> b2 >> c2;
			gra[k] = Grade(a, b, c, d, e, f, a1, b1, c1, d1, a2, b2, c2);
		}
		inf1.close();
	}
	system("cls");
	std::cout << "ѧ���ɼ�����ϵͳ" << std::endl;
	std::cout << "1. ¼����Ϣ 2. ɾ����Ϣ 3.�޸���Ϣ 4. �鿴��Ϣ 5.�˳�ϵͳ" << std::endl;
	string i;
	std::cin >> i;
	if (i == "1")
		Write_Info(stu, cou, gra, i0, i1, i2);
	if (i == "2")
		Delete_Info(stu, cou, gra, i0, i1, i2);
	if (i == "4")
		Read_Info(stu, cou, gra, i0, i1, i2);
	if (i == "5")
	{
		system("cls");
		std::cout << "�ѳɹ��˳�ϵͳ!" << endl;
		if (stu != NULL)
			delete[]stu;
		if (cou != NULL)
			delete[]cou;
		if (gra != NULL)
			delete[]gra;
		return;
	}
	else
	{
		system("cls");
		std::cout << "�������,����������!" << endl;
		system("pause");
		system("cls");
		tmain();
	}
}
int main()
{
	tmain();
	system("pause");
	return 0;
}