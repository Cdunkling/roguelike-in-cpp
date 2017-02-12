#include "classes.h"
using namespace std;

    void player::setname(string newname)
	{
		name = newname;
	}
	string player::getname()
	{
		return name;
	}
	void player::setpos(array<int, 2> pos)
	{
		x = pos[0];
		y = pos[1];
	}
	array<int, 2> player::getpos()
	{
		array<int, 2> pos{x,y};
		return pos;
	}
	array<int, 2> player::left(array<int, 2> pos)
	{
		pos[1] -= 1;
		return pos;
	}
	array<int, 2>  player:: right(array<int, 2> pos)
	{
		pos[1] += 1;
		return pos;
	}
	array<int, 2> player::up(array<int, 2> pos)
	{

		pos = { pos[0] -1,pos[1]+1};
		return pos;
	}
	array<int, 2>player::down(array<int, 2> pos)
	{
		pos = { pos[0] + 1,pos[1]-1};
		return pos;
	}