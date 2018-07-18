#include "UI.h"






UI::UI(const string & a, const vector<string>& b):header(a),menu(b)
{
}

UI::UI()
{
}

UI::UI(const UI & p):header(p.header),menu(p.menu)
{
}

UI::~UI()
{
}

void UI::Display()
{
	system("cls");
	cout << header << endl;
	vector <string>:: iterator it;
	int i = 1;
	for (it = menu.begin();it != menu.end();it++,i++)
	{
		cout << i << ". " << *it<<endl;
	}
}
