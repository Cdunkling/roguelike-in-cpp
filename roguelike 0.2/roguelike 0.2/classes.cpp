#include "stdafx.h"
#include <conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include <limits>
#include <array>
using namespace std;

class player
{
private:
	string name;
	int x, y;
public:
	void setname(string newname)
	{
		name = newname;
	}
	string getname()
	{
		return name;
	}
	void setpos(array<int, 2> pos)
	{
		x = pos[0];
		y = pos[1];
	}
	array<int, 2> getpos()
	{
		array<int, 2> pos{x,y};
		return pos;
	}
	array<int, 2> left(array<int, 2> pos)
	{
		pos[1] -= 1;
		return pos;
	}
	array<int, 2> right(array<int, 2> pos)
	{
		pos[1] += 1;
		return pos;
	}
	array<int, 2> up(array<int, 2> pos)
	{
		pos[0] -= 1;
		return pos;
	}
	array<int, 2> down(array<int, 2> pos)
	{
		pos[0] += 1;
		return pos;
	}

};