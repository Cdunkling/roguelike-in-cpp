
/****************************************************************************
*Title:   classes.h
*
*Author: Christopher Dunkling *
*
*Purpose: This include file contains the class declarations use in Roguelike
*
*
******************************************************************************/


#ifndef _ROGUELIKE_CLASSES_H
#define _ROGUELIKE_CLASSES_H

//----------------------------------------------------------------------------
#include "stdafx.h"
#include <conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include <limits>
#include <array>

//----------------------------------------------------------------------------
using namespace std;

/******************************************************************************
*class:   player
*
*
******************************************************************************/
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
	int score;

public:
	void init(int starthp, array<int, 2> pos, int basedamage, int damage, int pexp, int lvl);
	void setname(string newname);
	int  gethp(void);
	void levelup(void);
	int getexp(void);
	int getlevel(void);
	void giveexp(int gexp);
	void takedamage(int damage);
	int attack(void);
	int getscore();
	string getname(void);
	void increasescore(int points);
	void setpos(array<int, 2> pos);
	int player::getdamage(void);
	void player::setbasedamage(int dam);
	int player::getbasedamage(void);
	void player::setdamage(int dam);
	array<int, 2> getpos(void);
	array<int, 2> left(array<int, 2> pos);
	array<int, 2> right(array<int, 2> pos);
	array<int, 2> up(array<int, 2> pos);
	array<int, 2> down(array<int, 2> pos);
};

/******************************************************************************
*class:   enemy
*
*
******************************************************************************/
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
	string getname(void);
	void setpos(array<int, 2> pos);
	array<int, 2> getpos(void);
	int  gethp(void);
	int  getexp(void);
	int attack(void);
	void takedamage(int damage);
	void setdead(void);
	bool isdead(void);
	string enemy::getchar(void);
	void enemy::init(array<int, 2> pos, int ilevel);
};

/******************************************************************************
*class:   enemy
*
*
*Purpose: Class enemy contains the class declarations use in Roguelike
*         application code ?????? ....................
*
******************************************************************************/
class item
{
protected:
	int x, y;
	string name;
	bool isonground;

public:
	string getname(void);
	void setpos(array<int, 2> pos);
	array<int, 2> getpos(void);
	void pickedup(void);
	bool itemgot(void);
	void init(array<int, 2> pos, string ename);
};

/******************************************************************************
*class:   weapon (inherits methods from item with 1 override method)
*
*
*
******************************************************************************/
class weapon : public item
{
protected:
	int damage;

public:
	int getdamage(void);
	void init(array<int, 2> pos, int level);
};

//----------------------------------------------------------------------------
#endif //End _ROGUELIKE_CLASSES_H

//============================END_OF_FILE======================================
