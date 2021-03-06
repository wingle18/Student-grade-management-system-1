#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
void tmain();				//声明
void Write_Info(Student *, Course *, Grade *, int, int, int);
void Delete_Info(Student *, Course *, Grade *, int, int, int);
void Read_Info(Student *, Course *, Grade *, int, int, int);
inline double GPA(Student *, Course *, Grade *, int, int, int, Student&);
inline int Class_Rank(Student *, Course *, Grade *, int, int, int, Student&);
inline int Major_Rank(Student *, Course *, Grade *, int, int, int, Student&);
void Write_Student_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{
	system("cls");
	std::cout << "录入学生信息" << std::endl;
	std::cout << "1.开始录入学生信息 2.返回上一层界面 3.返回主界面" << std::endl;
	string i;
	cin >> i;
	if (i == "1")
	{
		system("cls");
		std::cout << "录入学生信息" << std::endl;
		ofstream of;
		of.open("student.txt", ios_base::_Noreplace);		//判断是否是第一次录入
		if (of.fail())
			of.open("student.txt", ios_base::app);
		std::cout << "学生姓名:" << std::endl;
		string a, b, c, d, e, f;
		std::cin >> a;
		std::cout << "学号:" << std::endl;
		std::cin >> b;
		std::cout << "入学年份:" << std::endl;
		std::cin >> c;
		std::cout << "专业:" << std::endl;
		std::cin >> d;
		std::cout << "教学班级:" << std::endl;
		std::cin >> e;
		std::cout << "性别, 0为男, 1为女" << std::endl;
		std::cin >> f;
		if (f != "0"&&f != "1")
		{
			system("cls");
			std::cout << "性别输入非法,请重新录入学生信息!" << std::endl;
			system("pause");
			Write_Student_Info(stu, cou, gra, i0, i1, i2);
		}
		for (int k = 0;k < i0;k++)
		{
			if (stu[k].Get_num() == b)
			{
				system("cls");
				std::cout << "存在相同学号的学生,请重新录入学生信息!" << std::endl;
				system("pause");
				Write_Student_Info(stu, cou, gra, i0, i1, i2);
			}
		}
		of << a << " " << b << " " << c << " " << d << " " << e << " " << f << std::endl;
		of.close();
		system("cls");
		std::cout << "学生信息已成功录入!" << std::endl;
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
		std::cout << "输入错误,请重新输入!" << endl;
		system("pause");
		Write_Student_Info(stu, cou, gra, i0, i1, i2);
	}
}
void Write_Course_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{
	system("cls");
	std::cout << "录入课程信息" << std::endl;
	std::cout << "1.开始录入课程信息 2.返回上一层界面 3.返回主界面" << std::endl;
	string i;
	cin >> i;
	if (i == "1")
	{
		system("cls");
		std::cout << "录入课程信息" << std::endl;
		ofstream of;
		of.open("course.txt", ios_base::_Noreplace);		//判断是否是第一次录入
		if (of.fail())
			of.open("course.txt", ios_base::app);
		string a, b, c, d;
		std::cout << "课程号:" << std::endl;
		std::cin >> a;
		std::cout << "课程名:" << std::endl;
		std::cin >> b;
		std::cout << "课程学分(最高不超过15学分):" << std::endl;
		std::cin >> c;
		std::cout << "课程所属学期:" << std::endl;
		std::cin >> d;
		if (!((c >= "0"&&c <= "9") || (c >= "10"&&c <= "15")))
		{
			system("cls");
			std::cout << "课程学分非法,请重新录入课程信息!" << std::endl;
			system("pause");
			Write_Course_Info(stu, cou, gra, i0, i1, i2);
		}
		for (int k = 0;k < i1;k++)
		{
			if (cou[k].Get_course_num() == a)
			{
				system("cls");
				std::cout << "存在相同课程号的课程,请重新录入课程信息!" << std::endl;
				system("pause");
				Write_Course_Info(stu, cou, gra, i0, i1, i2);
			}
		}
		of << a << " " << b << " " << c << " " << d << std::endl;
		of.close();
		system("cls");
		std::cout << "课程信息录入成功!" << std::endl;
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
		std::cout << "输入错误,请重新输入!" << endl;
		system("pause");
		Write_Course_Info(stu, cou, gra, i0, i1, i2);
	}
}
void Write_Grade_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{
	system("cls");
	std::cout << "录入成绩信息" << std::endl;
	std::cout << "1.开始录入成绩信息 2.返回上一层界面 3.返回主界面" << std::endl;
	string i;
	cin >> i;
	if (i == "1")
	{
		system("cls");
		std::cout << "录入成绩信息" << std::endl;
		ofstream of;
		of.open("grade.txt", ios_base::_Noreplace);	//判断是否第一次录入
		if (of.fail())
			of.open("grade.txt", ios_base::app);
		string a, b, c, d, e, f, g, h, i, j, _k, l = "N/A", m;
		int k;
		std::cout << "学生学号:" << std::endl;
		std::cin >> b;
		std::cout << "课程号:" << std::endl;
		std::cin >> g;
		std::cout << "百分制成绩:" << std::endl;
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
			std::cout << "输入成绩非法,请重新录入成绩!" << std::endl;
			system("pause");
			Write_Grade_Info(stu, cou, gra, i0, i1, i2);
		}
		if (flag0 == 0)
		{
			system("cls");
			std::cout << "没有该学生的信息,请重新录入成绩!" << std::endl;
			system("pause");
			Write_Grade_Info(stu, cou, gra, i0, i1, i2);
		}
		if (flag1 == 0)
		{
			system("cls");
			std::cout << "没有该课程的信息,请重新录入成绩!" << std::endl;
			system("pause");
			Write_Grade_Info(stu, cou, gra, i0, i1, i2);
		}
		bool flag = 0;
		for (int n = 0;n < i2;n++)
		{
			if (gra[n].Get_num() == b && gra[n].Get_course_num() == g)
				flag = 1;
		}
		if (flag == 1)
		{
			system("cls");
			std::cout << "该成绩已经存在,请重新录入成绩!" << std::endl;
			system("pause");
			Write_Grade_Info(stu, cou, gra, i0, i1, i2);
		}
		of << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << " " << i << " " << j << " " << k << " " << l << " " << m << std::endl;
		of.close();
		system("cls");
		std::cout << "成绩录入成功!" << std::endl;
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
		std::cout << "输入错误,请重新输入!" << endl;
		system("pause");
		Write_Grade_Info(stu, cou, gra, i0, i1, i2);
	}
}
void Delete_Student_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{
	system("cls");
	std::cout << "删除学生信息" << std::endl;
	std::cout << "1.开始删除学生信息 2.返回上一层界面 3.返回主界面" << std::endl;
	string i;
	bool flag = 0;
	cin >> i;
	if (i == "1")
	{
		system("cls");
		ifstream inf;
		ofstream of;
		inf.open("student.txt");
		of.open("temp.txt");		//临时保存原来的文件内容
		string a, b, c, d = " ", e;
		std::cout << "请注意! 删除学生的同时会删除该学生相应的成绩, 该操作不可逆!" << std::endl;
		std::cout << "请输入要删除学生的姓名:" << std::endl;
		std::cin >> c;
		b += c;
		b += d;
		std::cout << "请输入要删除学生的学号:" << std::endl;
		std::cin >> c;
		a = c;
		b += c;
		b += d;
		std::cout << "请输入要删除学生的入学年份:" << std::endl;
		std::cin >> c;
		b += c;
		b += d;
		std::cout << "请输入要删除学生的专业:" << std::endl;
		std::cin >> c;
		b += c;
		b += d;
		std::cout << "请输入要删除学生的教学班级:" << std::endl;
		std::cin >> c;
		b += c;
		b += d;
		std::cout << "请输入要删除学生的性别:" << std::endl;
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
			std::cout << "要删除的学生信息不存在!" << std::endl;
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
		inf.open("grade.txt");
		of.open("temp.txt");
		for (int i = 0;i < i2;i++)
		{
			if (gra[i].Get_num() != a)
			{
				getline(inf, e);
				of << e << std::endl;
			}
			else
				getline(inf, e);
		}
		inf.close();
		of.close();
		inf.open("temp.txt");
		of.open("grade.txt");
		for (;;)
		{
			getline(inf, e);
			if (e == "\0" || inf.eof())
				break;
			of << e << std::endl;
		}
		system("cls");
		std::cout << "删除学生信息成功!" << std::endl;
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
		std::cout << "输入错误,请重新输入!" << endl;
		system("pause");
		Delete_Student_Info(stu, cou, gra, i0, i1, i2);
	}
}
void Delete_Course_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{
	system("cls");
	std::cout << "删除课程信息" << std::endl;
	std::cout << "1.开始删除课程信息 2.返回上一层界面 3.返回主界面" << std::endl;
	string i;
	bool flag = 0;
	std::cin >> i;
	if (i == "1")
	{
		system("cls");
		std::cout << "请注意! 删除课程信息的同时会删去该课程的所有成绩, 该操作不可逆!" << std::endl;
		ifstream inf;
		ofstream of;
		inf.open("course.txt");
		of.open("temp.txt");
		string a, b, c = " ",d;
		std::cout << "请输入要删除课程的课程号" << std::endl;
		std::cin >> a;
		b += a;
		b += c;
		std::cout << "请输入要删除课程的课程名" << std::endl;
		std::cin >> a;
		b += a;
		b += c;
		std::cout << "请输入要删除课程的学分" << std::endl;
		std::cin >> a;
		d = a;
		b += a;
		b += c;
		std::cout << "请输入要删除课程所属的学期" << std::endl;
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
			std::cout << "要删除的课程信息不存在!" << std::endl;
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
		inf.open("grade.txt");
		of.open("temp.txt");
		for (int i = 0;i < i2;i++)
		{
			if (gra[i].Get_course_num() != d)
			{
				getline(inf, c);
				of << c << std::endl;
			}
			else
				getline(inf, c);
		}
		inf.close();
		of.close();
		inf.open("temp.txt");
		of.open("grade.txt");
		for (;;)
		{
			getline(inf, c);
			if (c == "\0" || inf.eof())
				break;
			of << c << std::endl;
		}
		system("cls");
		std::cout << "删除课程信息成功!" << std::endl;
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
		std::cout << "输入错误,请重新输入!" << endl;
		system("pause");
		Delete_Course_Info(stu, cou, gra, i0, i1, i2);
	}
}
void Delete_Grade_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{
	system("cls");
	std::cout << "删除成绩信息" << std::endl;
	std::cout << "1.开始删除成绩信息 2.返回上一层界面 3.返回主界面" << std::endl;
	string i;
	bool flag = 0;
	std::cin >> i;
	if (i == "1")
	{
		system("cls");
		std::cout << "删除成绩信息" << std::endl;
		ifstream inf;
		ofstream of;
		inf.open("grade.txt");
		of.open("temp.txt");
		string a, b, c = " ";
		int d;
		std::cout << "请输入要删除学生的姓名:" << std::endl;
		std::cin >> a;
		b += a;
		b += c;
		std::cout << "请输入要删除学生的学号:" << std::endl;
		std::cin >> a;
		b += a;
		b += c;
		std::cout << "请输入要删除学生的入学年份:" << std::endl;
		std::cin >> a;
		b += a;
		b += c;
		std::cout << "请输入要删除学生的专业:" << std::endl;
		std::cin >> a;
		b += a;
		b += c;
		std::cout << "请输入要删除学生的教学班级:" << std::endl;
		std::cin >> a;
		b += a;
		b += c;
		std::cout << "请输入要删除学生的性别:" << std::endl;
		std::cin >> a;
		b += a;
		b += c;
		std::cout << "请输入要删除课程的课程号" << std::endl;
		std::cin >> a;
		b += a;
		b += c;
		std::cout << "请输入要删除课程的课程名" << std::endl;
		std::cin >> a;
		b += a;
		b += c;
		std::cout << "请输入要删除课程的学分" << std::endl;
		std::cin >> a;
		b += a;
		b += c;
		std::cout << "请输入要删除课程所属的学期" << std::endl;
		std::cin >> a;
		b += a;
		b += c;
		std::cout << "请输入要删除课程的百分制成绩" << std::endl;
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
			std::cout << "要删除的成绩信息不存在!" << std::endl;
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
		std::cout << "删除成绩信息成功!" << std::endl;
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
		std::cout << "输入错误,请重新输入!" << endl;
		system("pause");
		Delete_Grade_Info(stu, cou, gra, i0, i1, i2);
	}
}
void Change_Student_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{

}
void Change_Course_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{

}
void Change_Grade_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{

}
void Read_Student_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{
	system("cls");
	std::cout << "查看学生信息" << std::endl;
	std::cout << "1.按学号查询学生基本信息 2.查看学生所有课的成绩(打印成绩单) 3.返回上一层界面 4.返回主界面" << std::endl;
	string i;
	cin >> i;
	if (i == "1")
	{
		if (i0 != 0)
		{
			system("cls");
			std::cout << "按学号查询学生信息" << std::endl;
			string a;
			std::cout << "请输入要查看学生的学号:" << std::endl;
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
				std::cout << "未找到该学号的学生, 请重新输入" << std::endl;
				system("pause");
				Read_Student_Info(stu, cou, gra, i0, i1, i2);
			}
			system("pause");
			tmain();
		}
		else
		{
			std::cout << "学生信息为空,请先录入学生成绩!" << std::endl;
			system("pause");
			tmain();
		}
	}
	if (i == "2")
	{
		system("cls");
		std::cout << "查看学生所有课的成绩(打印成绩单)" << std::endl;
		std::cout << "请输入要查看学生的学号:" << std::endl;
		string a;
		Student b;
		std::cin >> a;
		bool flag = 0;
		for (int k = 0; k < i0; k++)
			if (stu[k].Get_num() == a)
			{
				b = stu[k];
				flag = 1;
			}
		system("cls");
		if (flag == 0)
		{
			system("cls");
			std::cout << "未找到该学号的学生, 请重新输入" << std::endl;
			system("pause");
			Read_Student_Info(stu, cou, gra, i0, i1, i2);
		}
		for (int i = 0;i < i2;i++)
			if (gra[i].Get_num() == b.Get_num())
				gra[i].Print();
		system("pause");
		tmain();
	}
	if (i == "3")
		Read_Info(stu, cou, gra, i0, i1, i2);
	if (i == "4")
		tmain();
	else
	{
		system("cls");
		std::cout << "输入错误,请重新输入!" << endl;
		system("pause");
		Read_Student_Info(stu, cou, gra, i0, i1, i2);
	}
}
void Read_Course_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{
	system("cls");
	std::cout << "查看课程信息" << std::endl;
	std::cout << "1.按课程号查询课程基本信息 2.按课程号查看该课程所有学生的成绩 3.返回上一层界面 4.返回主界面" << std::endl;
	string i;
	cin >> i;
	bool flag = 0;
	if (i == "1")
	{
		if (i1 != 0)
		{
			system("cls");
			std::cout << "按课程号查询课程信息" << std::endl;
			string a;
			std::cout << "请输入要查看课程的课程号:" << std::endl;
			std::cin >> a;
			system("cls");
			for (int k = 0;k < i1;k++)
				if (cou[k].Get_course_num() == a)
				{
					cou[k].Print();
					flag = 1;
				}
			if (flag == 0)
			{
				system("cls");
				std::cout << "未找到该课程号的课程, 请重新输入" << std::endl;
				system("pause");
				Read_Course_Info(stu, cou, gra, i0, i1, i2);
			}
			system("pause");
			tmain();
		}
		else
		{
			std::cout << "课程信息为空,请先录入课程信息!" << std::endl;
			system("pause");
			tmain();
		}
	}
	if (i == "2")
	{
		system("cls");
		std::cout << "按课程号查看该课程所有学生的成绩" << std::endl;
		string a;
		std::cout << "请输入要查看课程的课程号:" << std::endl;
		std::cin >> a;
		Course b;
		system("cls");
		for (int k = 0;k < i1;k++)
			if (cou[k].Get_course_num() == a)
			{
				b = cou[k];
				flag = 1;
			}
		if (flag == 0)
		{
			system("cls");
			std::cout << "未找到该课程号的课程, 请重新输入" << std::endl;
			system("pause");
			Read_Course_Info(stu, cou, gra, i0, i1, i2);
		}
		for (int i = 0;i < i2;i++)
			if (gra[i].Get_course_num() == b.Get_course_num())
				gra[i].Print();
		system("pause");
		tmain();
	}
	if (i == "3")
		Read_Info(stu, cou, gra, i0, i1, i2);
	if (i == "4")
		tmain();
	else
	{
		system("cls");
		std::cout << "输入错误,请重新输入!" << endl;
		system("pause");
		Read_Course_Info(stu, cou, gra, i0, i1, i2);
	}
}
void Read_Grade_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{
	system("cls");
	std::cout << "查看成绩信息" << std::endl;
	std::cout << "1.按学号和课程号查询课程信息 2.返回上一层界面 3.返回主界面" << std::endl;
	string i;
	cin >> i;
	bool flag = 0;
	if (i == "1")
	{
		if (i2 != 0)
		{
			system("cls");
			std::cout << "按学号和课程号查询课程信息" << std::endl;
			string a, b;
			std::cout << "请输入要查看学生的学号:" << std::endl;
			std::cin >> a;
			std::cout << "请输入要查看课程的课程号:" << std::endl;
			std::cin >> b;
			system("cls");
			for (int k = 0;k < i2;k++)
				if (gra[k].Get_num() == a && gra[k].Get_course_num() == b)
				{
					gra[k].Print();
					flag = 1;
				}
			if (flag == 0)
			{
				system("cls");
				std::cout << "未找到相应的成绩, 请重新输入" << std::endl;
				system("pause");
				Read_Grade_Info(stu, cou, gra, i0, i1, i2);
			}
			system("pause");
			tmain();
		}
		else
		{
			std::cout << "成绩信息为空,请先录入成绩信息!" << std::endl;
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
		std::cout << "输入错误,请重新输入!" << endl;
		system("pause");
		Read_Grade_Info(stu, cou, gra, i0, i1, i2);
	}
}
void Read_Rank_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{
	system("cls");
	std::cout << "查看排名" << std::endl;
	std::cout << "1.查看单个学生的排名 2.查看整个班级的排名 3.查看整个专业的排名 4.返回上一层界面 5.返回主界面" << std::endl;
	string i;
	cin >> i;
	if (i == "1")
	{
		system("cls");
		std::cout << "查看单个学生的排名" << std::endl;
		std::cout << "请输入要查看学生的学号:" << std::endl;
		string a;
		Student b;
		std::cin >> a;
		bool flag = 0;
		for (int k = 0; k < i0; k++)
			if (stu[k].Get_num() == a)
			{
				b = stu[k];
				flag = 1;
			}
		system("cls");
		if (flag == 0)
		{
			system("cls");
			std::cout << "未找到该学号的学生, 请重新输入" << std::endl;
			system("pause");
			Read_Rank_Info(stu, cou, gra, i0, i1, i2);
		}
		std::cout << "班级排名: " << Class_Rank(stu, cou, gra, i0, i1, i2, b) << std::endl;
		std::cout << "专业排名: " << Major_Rank(stu, cou, gra, i0, i1, i2, b) << std::endl;
		system("pause");
		tmain();
	}
	if (i == "2")
	{
		system("cls");
		string a;
		std::cout << "查看整个班级的排名" << std::endl;
		std::cout << "请输入班级的名称:" << std::endl;
		std::cin >> a;
	}
	if (i == "3")
	{
		system("cls");
		string a, b;
		std::cout << "查看整个专业的排名" << std::endl;
		std::cout << "请输入专业的名称:" << std::endl;
		std::cin >> a;
		std::cout << "请输入入学年份" << std::endl;
		std::cin >> b;
	}
	if (i == "4")
		Read_Info(stu, cou, gra, i0, i1, i2);
	if (i == "5")
		tmain();
	else
	{
		system("cls");
		std::cout << "输入错误,请重新输入!" << endl;
		system("pause");
		Read_Rank_Info(stu, cou, gra, i0, i1, i2);
	}
}
void Write_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{
	system("cls");
	std::cout << "录入信息" << std::endl;
	std::cout << "1.录入学生信息 2. 录入课程信息 3. 录入成绩 4. 返回主界面" << std::endl;
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
		std::cout << "输入错误,请重新输入!" << endl;
		system("pause");
		system("cls");
		Write_Info(stu, cou, gra, i0, i1, i2);
	}
}
void Delete_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{
	system("cls");
	std::cout << "删除信息" << std::endl;
	std::cout << "1.删除学生信息 2. 删除课程信息 3. 删除成绩 4. 返回主界面" << std::endl;
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
		std::cout << "输入错误,请重新输入!" << endl;
		system("pause");
		system("cls");
		Delete_Info(stu, cou, gra, i0, i1, i2);
	}
}
void Change_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{

}
void Read_Info(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2)
{
	system("cls");
	std::cout << "查看信息" << endl;
	std::cout << "1.查看学生信息 2. 查看课程信息 3. 查看成绩 4.查看排名 5.返回主界面" << std::endl;
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
		Read_Rank_Info(stu, cou, gra, i0, i1, i2);
	}
	if (i == "5")
	{
		system("cls");
		tmain();
	}
	else
	{
		system("cls");
		std::cout << "输入错误,请重新输入!" << endl;
		system("pause");
		system("cls");
		Read_Info(stu, cou, gra, i0, i1, i2);
	}
}
inline double GPA(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2, Student &a)
{
	double grade = 0;
	int credit = 0;
	double gpa = 0;
	for (int i = 0;i < i2;i++)
	{
		if (gra[i].Get_num() == a.Get_num())
		{
			grade += gra[i].Get_gradepoint()*gra[i].Get_course_credit(1);
			credit += gra[i].Get_course_credit(1);
		}
	}
	gpa = grade / credit;
	return gpa;
}
inline int Class_Rank(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2, Student &a)
{
	int rank = 1;
	for (int i = 0;i < i0; i++)
		if (stu[i].Get_teach_class() == a.Get_teach_class() && GPA(stu, cou, gra, i0, i1, i2, stu[i]) > GPA(stu, cou, gra, i0, i1, i2, a))
			rank++;
	return rank;
}
inline int Major_Rank(Student *stu, Course *cou, Grade *gra, int i0, int i1, int i2, Student &a)
{
	int rank = 1;
	for (int i = 0;i < i0; i++)
		if (stu[i].Get_major() == a.Get_major() && stu[i].Get_year() == a.Get_year() && GPA(stu, cou, gra, i0, i1, i2, stu[i]) > GPA(stu, cou, gra, i0, i1, i2, a))
			rank++;
	return rank;
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
		}											//i为学生数量
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
		}							//i为课程数量
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
		}							//i为课程数量
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
	std::cout << "学生成绩管理系统" << std::endl;
	std::cout << "1. 录入信息 2. 删除信息 3.修改信息 4. 查看信息 5.退出系统" << std::endl;
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
		std::cout << "已成功退出系统!" << endl;
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
		std::cout << "输入错误,请重新输入!" << endl;
		system("pause");
		system("cls");
		tmain();
	}
}