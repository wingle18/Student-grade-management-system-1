#include "UI.h"






UI::UI(const string & a, const vector<string>& b,const bool &c):header(a),menu(b),flag(c)
{
}

UI::UI()
{
}

UI::UI(const UI & p):header(p.header),menu(p.menu),flag(p.flag)
{
}

UI::~UI()
{
}

void UI::Display()
{
	system("cls");
	cout << header << endl;
	if (flag == 0)
	{
		vector <string>::iterator it;
		int i = 1;
		for (it = menu.begin();it != menu.end();it++, i++)
		{
			cout << i << ". " << *it << endl;
		}
	}
}
