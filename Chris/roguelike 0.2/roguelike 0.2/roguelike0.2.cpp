#include "stdafx.h"
#include <conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include <limits>
#include "classes.h"
using namespace std;


static const int WIDTH = 35;
static const int HEIGHT = 6;
static char level[HEIGHT][WIDTH];
static  char orglevel[HEIGHT][WIDTH];
void setup()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			level[i][j] = ' ';
		}
	}
	int j = 0;
	int i = 0;
	ifstream file("map1.txt");
	string row;

	while (getline(file, row,'\0')) {
		for (char ascii : row) {
				level[i][j] = ascii;
				orglevel[i][j] = ascii;
				j++;
		}
	}
}
void update(array<int, 2>  pos)
{
	level[pos[0]][pos[1]] = '@';
	int j = 0;
	int i = 0;
	string row;
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (i == pos[0] && j == pos[1])
			{
				cout << '@';
			}
			else
			{
				cout << orglevel[i][j];
			}
		}
	}
}
int main()
{
	player p1;
	array<int, 2> pos = {3, 21};
	p1.setpos(pos);
	setup();
	update(pos);
	cout << "\n"<< "\n";
	string dir;
	int x;
	int y;
	while (true)
	{

		cin >> dir;
		if (dir == "a")
		{
			if (level[p1.getpos()[0]][p1.getpos()[1] - 1] != '|')
			{
				cout << "left" << "\n";
				array<int, 2>  pos = p1.left(p1.getpos());
				p1.setpos(pos);
			}
		}
		if (dir == "w")
		{
			if (level[p1.getpos()[0] - 1][p1.getpos()[1]] != '-')
			{
				cout << "up" << "\n";
				array<int, 2>  pos = p1.up(p1.getpos());
				p1.setpos(pos);
			}
		}
		if (dir == "s")
		{
			if (level[p1.getpos()[0]+1][p1.getpos()[1]] != '-')
			{
				cout << "down" << "\n";
				array<int, 2>  pos = p1.down(p1.getpos());
				p1.setpos(pos);
			}
		}
		if (dir == "d")
		{
			if (level[p1.getpos()[0]][p1.getpos()[1] + 1] != '|')
			{
				cout << "right" << "\n";
				array<int, 2>  pos = p1.right(p1.getpos());
				p1.setpos(pos);
			}
		}
		cout << p1.getpos()[0] << "  " << p1.getpos()[1]<< "\n";
		update(p1.getpos());
		cout << "\n" << "\n";
		}
	return 0;
}
