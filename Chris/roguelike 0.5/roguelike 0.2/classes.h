

#ifndef ROGUELIKE_CLASSES_H
#define ROGUELIKE_CLASSES_H

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
	int hp;
	int basedamage;
	int damage;
	int level;
	string name;
	int exp;
	int x, y;
public:
	void init(int starthp, array<int, 2> pos, int basedamage,int damage,int pexp,int lvl);
	void setname(string newname);
	int  gethp();
	void levelup();
	int getexp();
	int getlevel();
	void giveexp(int gexp);
	void takedamage(int damage);
	int attack();
	string getname();
	void setpos(array<int, 2> pos);
	int player::getdamage();
	void player::setbasedamage(int dam);
	int player::getbasedamage();
	void player::setdamage(int dam);
	array<int, 2> getpos();
	array<int, 2> left(array<int, 2> pos);
	array<int, 2> right(array<int, 2> pos);
	array<int, 2> up(array<int, 2> pos);
	array<int, 2> down(array<int, 2> pos);

};

class enemy
{
protected:
	int hp;
	int damage;
	int givenexp;
	int x, y;
	string name;
	bool dead;
	string echar;
	int level;
public:
	string getname();
	void setpos(array<int, 2> pos);
	array<int, 2> getpos();
	int  gethp();
	int  getexp();
	int attack();
	void takedamage(int damage);
	void setdead();
	bool isdead();
	string enemy::getchar();
	void enemy::init(array<int, 2> pos, int ilevel);

};

class item
{
protected:
	int x, y;
	string name;
	bool isonground;
public:
	string getname();
	void setpos(array<int, 2> pos);
	array<int, 2> getpos();
	void pickedup();
	bool itemgot();
	void init(array<int, 2> pos,string ename);

};

class weapon: public item
{
protected:
	int damage;
public:
	int getdamage();
	void init(array<int, 2> pos,int level);
};
#endif //ROGUELIKE_CLASSES_H