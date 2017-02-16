#include "stdafx.h"
#include <conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include <limits>
#include <vector>
#include <iostream>
#include <windows.h>
#include "classes.h"
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
using namespace std;
static vector<vector<char>> level;
static vector<enemy> enemylist;
static player p1;

vector<array<int, 2>> getfree()
{
	vector<array<int, 2>>freespaces;
	array<int, 2>playerpos = p1.getpos();
	vector<array<int, 2>>enemyspawns;
	for (enemy test : enemylist)
	{
		if ((test.isdead() == false))
		{
			enemyspawns.emplace_back(test.getpos());
		}
			
		}
	for (int i = 0; i < level.size(); i++)
	{
		for (int j = 0; j < level[i].size(); j++)
		{
			array<int, 2>pos = { i,j };
			if (level[i][j] == '.'&& pos!=playerpos && !(find(enemyspawns.begin(), enemyspawns.end(), pos) != enemyspawns.end()))
			{
				array<int, 2>space = { i,j };
				freespaces.emplace_back(space);
			}
		}
	}
	return freespaces;
}
void setup(int floor)
{
	ifstream file("map1.txt");
	vector<char> row;
	string rowstring;

	while (getline(file, rowstring)) {
		for (char ascii : rowstring) {
			if (ascii == '\n')
			{
				break;
			}
			row.emplace_back(ascii);
		}
		level .emplace_back(row);
		row.clear();
	}
	array<int, 2> pos = { 3, 30 };
	p1.init(20, pos, 2,0,1);
	for(int i=0;i<3;i++)
	{
		vector<array<int, 2>>freepos = getfree();
		enemy testenemy;
		srand(time(NULL));
		testenemy.init(freepos[rand()%freepos.size()],rand()%(floor*2)+1);
		enemylist.emplace_back(testenemy);

	}
	

}
WORD GetConsoleTextAttribute(HANDLE hCon)
{
	CONSOLE_SCREEN_BUFFER_INFO con_info;
	GetConsoleScreenBufferInfo(hCon, &con_info);
	return con_info.wAttributes;
}
void update(array<int, 2>  pos)
{
	while (true)
	{
		if (p1.getexp() >= p1.getlevel() * 5)
		{
			p1.giveexp(-p1.getlevel() * 5);
			p1.levelup();
			cout << "LEVEL UP!!!" << endl;
			cout << "level increased to " << p1.getlevel() << endl;
		}
		else
		{
			break;
		}
	}
	int j = 0;
	int i = 0;
	bool enemyplaced = false;
	for (int i = 0; i < level.size(); i++)
	{
		for (int j = 0; j <level[i].size(); j++)
		{
			for (enemy test : enemylist)
			{
				if ((i == test.getpos()[0]) && (j == test.getpos()[1]) &&(test.isdead() == false))
				{
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					const int saved_colors = GetConsoleTextAttribute(hConsole);
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout <<test.getchar();
					SetConsoleTextAttribute(hConsole, saved_colors);
					enemyplaced = true;
				}
			}
			if (i == pos[0] && j == pos[1])
			{
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				const int saved_colors = GetConsoleTextAttribute(hConsole);
				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_INTENSITY);
				cout << '@';
				SetConsoleTextAttribute(hConsole, saved_colors);
			}
			else
			{
				if (enemyplaced == false)
				{
				cout << level[i][j];
			}
			}
			enemyplaced = false;
		}
		cout << '\n';
	}
}
bool nocollision(array<int, 2> nextstep,char nextlevelstep)
{
	for (enemy test : enemylist)
	{
		if (nextstep == test.getpos() && test.isdead()==false)
		{
			return false;
		}
	}
	if (nextlevelstep == '-' || nextlevelstep == '|')
	{
		return false;
	}
	else
	{
		return true;
	}
}
void enemymove(array<int,2>playerpos)
{
	for (enemy test : enemylist)
	{
		float diffY = playerpos[0] - test.getpos()[0];
		float diffX = playerpos[1] - test.getpos()[1];
		int distance = sqrt((diffY * diffY) + (diffX * diffX));
		if (distance < 2 && test.isdead() == false)
		{
			p1.takedamage(test.attack());
			cout << "took " << test.attack() << " from " << test.getname() << endl;
			if (p1.gethp() < 1)
			{

				cout << "X-X DED..."<<endl;
				string end;
				cin >> end;
				exit(0);
			}
		}
	}
}
int main()
{
	setup(1);
	update(p1.getpos());
	cout << "\n"<< "\n";
	string dir;
	int x;
	int y;
	while (true)
	{

		cin >> dir;
		char nextstep;
		if (dir == "a")
		{
			nextstep = level[p1.getpos()[0]][p1.getpos()[1] - 1];
			array<int, 2> nextlevelstep = { p1.getpos()[0],p1.getpos()[1] - 1 };
			if (nocollision(nextlevelstep, nextstep) == true)
			{
				cout << "left" << "\n";
				array<int, 2>  pos = p1.left(p1.getpos());
				p1.setpos(pos);
				if (nextstep == '+')
				{
					level[p1.getpos()[0]][p1.getpos()[1] - 1] = '\'';
					cout << "opened a door" << "\n";
				}
			}

		}
		if (dir == "w")
		{
			nextstep = level[p1.getpos()[0] - 1][p1.getpos()[1]];
			array<int, 2> nextlevelstep = { p1.getpos()[0] - 1,p1.getpos()[1] };
			if (nocollision(nextlevelstep,nextstep) == true)
			{
				cout << "up" << "\n";
				array<int, 2>  pos = p1.up(p1.getpos());
				p1.setpos(pos);
				if (nextstep == '+')
				{
					level[p1.getpos()[0] - 1][p1.getpos()[1]] = '\'';
					cout << "opened a door" << "\n";
				}
			}
		}
		if (dir == "s")
		{
			nextstep = level[p1.getpos()[0] + 1][p1.getpos()[1]];
			array<int, 2>nextlevelstep = { p1.getpos()[0] + 1,p1.getpos()[1] };
			if (nocollision(nextlevelstep,nextstep) == true)
			{
				cout << "down" << "\n";
				array<int, 2>  pos = p1.down(p1.getpos());
				p1.setpos(pos);
				if (nextstep == '+')
				{
					level[p1.getpos()[0] + 1][p1.getpos()[1]] = '\'';
					cout << "opened a door" << "\n";
				}
			}
		}
		if (dir == "d")
		{
			nextstep = level[p1.getpos()[0]][p1.getpos()[1] + 1];
			array<int, 2>nextlevelstep = { p1.getpos()[0],p1.getpos()[1]+1 };
			if (nocollision(nextlevelstep , nextstep) == true)
			{
				cout << "right" << "\n";
				array<int, 2>  pos = p1.right(p1.getpos());
				p1.setpos(pos);
				if (nextstep == '+')
				{
					level[p1.getpos()[0]][p1.getpos()[1]] = '\'';
					cout << "opened a door" << "\n";
				}
			}
		}
		if (dir == "f")
		{
			int i = 0;
			bool enemyinrange = false;
			for (enemy e : enemylist)
			{
				float diffY = p1.getpos()[0] - e.getpos()[0];
				float diffX = p1.getpos()[1] - e.getpos()[1];
				int distance = sqrt((diffY * diffY) + (diffX * diffX));
				if (distance < 3 && e.isdead() == false)
				{
					enemyinrange = true;
					enemylist[i].takedamage(p1.attack());
					cout << e.getname() << " took "<< p1.attack() <<" damage" << "\n";
					if (enemylist[i].gethp() < 1)
					{
						enemylist[i].setdead();
						cout << e.getname() << " was slain !" << "\n";
						p1.giveexp(e.getexp());
					}
				}
				i++;
			}
		if(enemyinrange==false)
		{
			cout << "no enemy in range"<<endl;
		}
		}
		if (dir == ">")
		{
			char pos = level[p1.getpos()[0]][p1.getpos()[1]];
				if (pos == '#')
				{
					string temp;
					cout << "\n" "\n""\n""\n""\n"<< "		Conglaturations you're winner!!!               " << "\n";
					cin >> temp;
					return 0;
				}
				else
				{
					cout << "There are no stairs here..." << "\n";
				}
		}
		nextstep = ' ';
		cout << "x: "<<p1.getpos()[0] << "  " << "y: "<<p1.getpos()[1]<< "\n";
		cout << "level: " << p1.getlevel() << "\n";
		cout << "exp: " << p1.getexp() << "\n";
		cout << "health: " << p1.gethp() <<  "\n";
		cout << "damage: " << p1.attack() << "\n";
		enemymove(p1.getpos());
		update(p1.getpos());
		cout << "\n" << "\n";
		}
	return 0;
}
