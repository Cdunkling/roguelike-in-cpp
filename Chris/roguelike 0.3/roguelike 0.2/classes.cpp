#include "classes.h"
using namespace std;

    
//****************************//
//           PLAYER		      //
//****************************//

	void player::init(int starthp, array<int, 2> pos, int edamage,int pexp=0,int lvl=1)
	{
		hp = starthp;
		x = pos[0];
		y = pos[1];
		damage = edamage;
		exp = pexp;
		level = lvl;
	}
	void player::setname(string newname)
	{
		name = newname;
	}
	
	string player::getname()
	{
		return name;
	}
	int player::gethp()
	{
		return hp;
	}
	void player::takedamage(int damage)
	{
		hp -= damage;
	}
	int player::attack()
	{
		return damage;
	}
	void player::giveexp(int gexp)
	{
		exp += gexp;
	}
	int player::getexp()
	{
		return exp;
	}
	int player::getlevel()
	{
		return level;
	}
	void player::levelup()
	{
		level += 1;
		hp += level;
		damage += level;
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

		pos[0] -= 1;
		return pos;
	}
	array<int, 2>player::down(array<int, 2> pos)
	{
		pos[0] += 1;
		return pos;
	}

	//****************************//
	//            ENEMY		      //
	//****************************//

	void enemy::setpos(array<int, 2> pos)
	{
		x = pos[0];
		y = pos[1];
	}
	array<int, 2> enemy::getpos()
	{
		array<int, 2> pos{ x,y };
		return pos;
	}
	int enemy::gethp()
	{
		return hp;
	}
	void enemy::takedamage(int damage)
	{
		hp -= damage;
	}
	void enemy::setdead()
	{
		dead=true;
	}
	bool enemy::isdead()
	{
		return dead;
	}
	int enemy::getexp()
	{
		return givenexp;
	}
	string enemy::getname()
	{
		return name;
	}
	int enemy::attack()
	{
		return damage;
	}
	string enemy::getchar()
	{
		return echar;	
	}
	array<string, 10>names = { "Dogoo","Pixelvader","Clione","WD Head","Boxer-X","Plum-met","Clyde","Matango","Boxbird","R4i-SDHC"};
	void enemy::init(array<int, 2> pos, int ilevel)
	{
		name = names[rand() % 10];
		level = ilevel;
		hp = level * 5;
		x = pos[0];
		y = pos[1];
		dead = false;
		damage = level;
		givenexp = level * 2;
		echar = name[0];
	}