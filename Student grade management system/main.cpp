#include "main.h"
int main()
{
	vector <Student> stu;
	vector <Course> cou;
	vector <Grade> gra;
	sync_in(stu);
	sync_in(cou);
	sync_in(gra);
	mainwindow().func(stu,cou,gra);
	return 0;
}