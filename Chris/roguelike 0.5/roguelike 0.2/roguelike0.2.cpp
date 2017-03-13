//===============================================================================================================================================
// rougelike.cpp contains the main functions for the program as well as the main method.
//===============================================================================================================================================
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
#include "inventory.h"
#include "database.h"
#include "pathfinding.h"
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
using namespace std;
static vector<vector<char>> level;
static vector<enemy> enemylist;
static vector<item> itemlist;
static vector<weapon> weaponlist;
static player p1;
static inventory inv;
static Database playerDB;

//searches for free cells in the grid
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
//initialises the map and player.
void setup(int floor, array<int, 2> pos)
{
	inv.init();
	ifstream file;
	if (floor == 1)
	{
		file.open("map1.txt");
		p1.init(10, pos, 2,2, 0, 1);
	}
	if (floor == 2)
	{
		file.open("map2.txt");
		p1.init(p1.gethp(), pos, p1.getbasedamage(),p1.getdamage(), p1.getexp(), p1.getlevel());
	}
	vector<char> row;
	string rowstring;
	level.clear();
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
	for(int i=0;i<3;i++)
	{
		vector<array<int, 2>>freepos = getfree();
		enemy testenemy;
		srand(time(NULL));
		testenemy.init(freepos[rand()%freepos.size()],rand()%(floor*2)+1);
		enemylist.emplace_back(testenemy);

	}

		vector<array<int, 2>>freepos = getfree();
		weapon wep;
		srand(time(NULL));
		wep.init(freepos[rand() % freepos.size()],floor);
		weaponlist.emplace_back(wep);
	

}
//get text color and style
WORD GetConsoleTextAttribute(HANDLE hCon)
{
	CONSOLE_SCREEN_BUFFER_INFO con_info;
	GetConsoleScreenBufferInfo(hCon, &con_info);
	return con_info.wAttributes;
}
//updates player stats and enemy placements
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
	bool itemplaced = false;
	bool weaponplaced = false;
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
			for (item test : itemlist)
			{
				if ((i == test.getpos()[0]) && (j == test.getpos()[1]))
				{
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					const int saved_colors = GetConsoleTextAttribute(hConsole);
						SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_INTENSITY);
						cout << "$";
						SetConsoleTextAttribute(hConsole, saved_colors);
					itemplaced = true;
				}
			}
			for (weapon test : weaponlist)
			{
				if ((i == test.getpos()[0]) && (j == test.getpos()[1]) && (test.itemgot() == true))
				{
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					const int saved_colors = GetConsoleTextAttribute(hConsole);
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "W";
					SetConsoleTextAttribute(hConsole, saved_colors);
					weaponplaced = true;
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
				if (enemyplaced == false && itemplaced==false)
				{
				cout << level[i][j];
			}
			}
			enemyplaced = false;
			itemplaced = false;
			weaponplaced = false;
		}
		cout << '\n';
	}
}
//check space is free
bool nocollision(array<int, 2> nextstep,char nextlevelstep)
{
	for (enemy test : enemylist)
	{
		if (nextstep == test.getpos() && test.isdead()==false)
		{
			return false;
		}
	}
	int i = 0;
	for (item test : itemlist)
	{
		if (nextstep == test.getpos() && test.itemgot() == true)
		{
			itemlist[i].pickedup();
			cout << "picked up a " << test.getname() << endl;
			inv.Get(test.getname());
			return true;
		}
		i++;
	}
	i = 0;
	for (weapon test : weaponlist)
	{
		if (nextstep == test.getpos() && test.itemgot() == true)
		{
			weaponlist[i].pickedup();
			cout << "picked up a " << test.getname() << endl;
			inv.Get(test.getname());
			p1.setdamage(p1.getbasedamage() + weaponlist[i].getdamage());
			return true;
		}
		i++;
	}
	if (nextlevelstep == '#')
	{
		return false;
	}
	else
	{
		return true;
	}
}
/*
bool enemynocollision(array<int, 2> nextstep, char nextlevelstep)
{
	for (enemy test : enemylist)
	{
		if (nextstep == test.getpos() && test.isdead() == false)
		{
			return false;
		}
	}
	int i = 0;
	for (item test : itemlist)
	{
		if (nextstep == test.getpos() && test.itemgot() == true)
		{

			return false;
		}
		i++;
	}
	i = 0;
	for (weapon test : weaponlist)
	{
		if (nextstep == test.getpos() && test.itemgot() == true)
		{

			return false;
		}
		i++;
	}
	if (nextlevelstep == '#'|| nextlevelstep == '+')
	{
		return false;
	}
	else
	{
		return true;
	}
}
*/
//enemy gets distance from player and chooses whether to attack or move
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
		/*else if (distance > 2 && test.isdead() == false)
		{
			test.setpos(search(p1.getpos(),test.getpos(),level)[1].get_position());
		}
		*/
	}
}
int main()
{
	cout << "Welcome to Exodeath" << endl << "1.Start New Game" << endl << "2. Load Game" << endl;
	string choice;
	cin >> choice;
	//new game
	if (choice == "1")
	{
		string name;
		cout << "enter name: ";
		cin >> name;
		playerDB.set_dbname("playerdata.db");
		playerDB.new_entry(name, 0, 1, 3, 30);
		setup(1, { 3, 30 });
	}
	//load game
	else if (choice == "2")
	{
		string name;
		cout << "enter name: ";
		cin >> name;
		playerDB.set_dbname("playerdata.db");
		playerDB.new_entry(name, 0, 1, 3, 30);
		setup(1, { 3, 30 });
	}
	else
	{
		return 0;
	}
	update(p1.getpos());
	cout << "\n" << "\n";
	string dir;
	int x;
	int y;
	while (true)
	{

		cin >> dir;
		system("CLS");//clear screen
		char nextstep;
		//checks which button was pressed and whether there are obstacles in the way
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
			if (nocollision(nextlevelstep, nextstep) == true)
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
			if (nocollision(nextlevelstep, nextstep) == true)
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
			array<int, 2>nextlevelstep = { p1.getpos()[0],p1.getpos()[1] + 1 };
			if (nocollision(nextlevelstep, nextstep) == true)
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
		//attack enemy if they are in range
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
					cout << e.getname() << " took " << p1.attack() << " damage" << "\n";
					if (enemylist[i].gethp() < 1)
					{
						enemylist[i].setdead();
						cout << e.getname() << " was slain !" << "\n";
						p1.giveexp(e.getexp());
					}
				}
				i++;
			}
			if (enemyinrange == false)
			{
				cout << "no enemy in range" << endl;
			}
		}
		//move to next floor if tile is stairs
		if (dir == ">")
		{
			char pos = level[p1.getpos()[0]][p1.getpos()[1]];
			if (pos == '0')
			{
				system("cls");
				setup(2, { 1, 1 });
			}
			else
			{
				cout << "There are no stairs here..." << "\n";
			}
			update(p1.getpos());
			cout << "\n" << "\n";
		}
		//open inventory
		if (dir == "i")
		{
			inv.ShowInventory();
			cout << endl << endl;
		}
		//show stats
		nextstep = ' ';
		cout << "x: "<<p1.getpos()[0] << "  " << "y: "<<p1.getpos()[1]<< "\n";
		cout << "level: " << p1.getlevel() << "\n";
		cout << "exp: " << p1.getexp() << "\n";
		cout << "health: " << p1.gethp() <<  "\n";
		cout << "damage: " << p1.attack() << "\n";
		enemymove(p1.getpos());
		update(p1.getpos());
		}
	return 0;
}
