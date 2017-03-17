
//*****************************************************************************
// Title:   classes.cpp
// 
// Author: Christopher Dunkling 
// 
// 
// Purpose: This contains the class code use in Roguelike
//          application  ?????? ....................
// 
//*****************************************************************************

#include "classes.h"

//----------------------------------------------------------------------------
using namespace std;


//*****************************************************************************
// class:   player
// 
// 
// Purpose: player methods
// 
//*****************************************************************************

//----------------------------------------------------------------------------
// Class:   Player
// Method:  init 
// Purpose: initialize the stats of player and position
//----------------------------------------------------------------------------
void player::init(int starthp, array<int, 2> pos, int ebasedamage, int edamage, int pexp = 0, int lvl = 1)
{
	hp = starthp;
	x = pos[0];
	y = pos[1];
	basedamage = ebasedamage;
	damage = edamage;
	exp = pexp;
	level = lvl;
}

//----------------------------------------------------------------------------
// Class:   Player
// Method:  setname
// Purpose: set player's name
//----------------------------------------------------------------------------
void player::setname(string newname)
{
	name = newname;
}

//----------------------------------------------------------------------------
// Class:   Player
// Method:  getname
// Purpose: get player's name
//----------------------------------------------------------------------------
string player::getname(void)
{
	return name;
}

//----------------------------------------------------------------------------
// Class:   Player
// Method:  gethp
// Purpose: get player's hp
//----------------------------------------------------------------------------
int player::gethp(void)
{
	return hp;
}

//----------------------------------------------------------------------------
// Class:   Player
// Method:  takedamage
// Purpose: decrease player's hp
//----------------------------------------------------------------------------
void player::takedamage(int damage)
{
	hp -= damage;
}

//----------------------------------------------------------------------------
// Class:   Player
// Method:  attack
// Purpose: get damage output of player + equipped weapon
//----------------------------------------------------------------------------
int player::attack(void)
{
	return damage;
}

//----------------------------------------------------------------------------
// Class:   Player
// Method:  giveexp
// Purpose: increase player's xp
//----------------------------------------------------------------------------
void player::giveexp(int gexp)
{
	exp += gexp;
}

//----------------------------------------------------------------------------
// Class:   Player
// Method:  getexp
// Purpose: return player's xp amount
//----------------------------------------------------------------------------
int player::getexp(void)
{
	return exp;
}
//----------------------------------------------------------------------------
// Class:   Player
// Method:  getscore
// Purpose: return player's score
//----------------------------------------------------------------------------
int player::getscore()
{
	return score;
}

//----------------------------------------------------------------------------
// Class:   Player
// Method:  increasescore
// Purpose: increase player's score
//----------------------------------------------------------------------------
void player::increasescore(int points)
{
	score += points;
}
//----------------------------------------------------------------------------
// Class:   Player
// Method:  getlevel
// Purpose: get player's level
//----------------------------------------------------------------------------
int player::getlevel(void)
{
	return level;
}

//----------------------------------------------------------------------------
// Class:   Player
// Method:  levelup
// Purpose: increase player's level and stats accordingly
//----------------------------------------------------------------------------
void player::levelup(void)
{
	level += 1;
	hp += level;
	basedamage += level;
	damage += level;
}

//----------------------------------------------------------------------------
// Class:   Player
// Method:  setpos
// Purpose: set player's position
//----------------------------------------------------------------------------
void player::setpos(array<int, 2> pos)
{
	x = pos[0];
	y = pos[1];
}

//----------------------------------------------------------------------------
// Class:   Player
// Method:  getpos
// Purpose: get player's position
//----------------------------------------------------------------------------
array<int, 2> player::getpos(void)
{
	array<int, 2> pos{ x,y };
	return pos;
}

//----------------------------------------------------------------------------
// Class:   Player
// Method:  getbasedamage
// Purpose: get player's damage output
//----------------------------------------------------------------------------
int player::getbasedamage(void)
{
	return basedamage;
}

//----------------------------------------------------------------------------
// Class:   Player
// Method:  setbasedamage
// Purpose: set playerÅfs damage
//----------------------------------------------------------------------------
void player::setbasedamage(int dam)
{
	basedamage = dam + basedamage;
}

//----------------------------------------------------------------------------
// Class:   Player
// Method:  getdamage
// Purpose: get damage output of player + equipped weapon
//----------------------------------------------------------------------------
int player::getdamage(void)
{
	return damage;
}

//----------------------------------------------------------------------------
// Class:   Player
// Method:  setdamage
// Purpose: set damage output of player + equipped weapon
//----------------------------------------------------------------------------
void player::setdamage(int dam)
{
	damage = dam + basedamage;
}

//----------------------------------------------------------------------------
// Class:   Player
// Method:  left
// Purpose: move left
//----------------------------------------------------------------------------
array<int, 2> player::left(array<int, 2> pos)
{
	pos[1] -= 1;
	return pos;
}

//----------------------------------------------------------------------------
// Class:   Player
// Method:  right
// Purpose: move right 
//----------------------------------------------------------------------------
array<int, 2>  player::right(array<int, 2> pos)
{
	pos[1] += 1;
	return pos;
}

//----------------------------------------------------------------------------
// Class:   Player
// Method:  up
// Purpose: move up
//----------------------------------------------------------------------------
array<int, 2> player::up(array<int, 2> pos)
{

	pos[0] -= 1;
	return pos;
}

//----------------------------------------------------------------------------
// Class:   Player
// Method:  down
// Purpose: move down
//----------------------------------------------------------------------------
array<int, 2>player::down(array<int, 2> pos)
{
	pos[0] += 1;
	return pos;
}

//*****************************************************************************
// class:   enemy
// 
//*****************************************************************************

//----------------------------------------------------------------------------
// Class:   enemy
// Method:  setpos 
// Purpose: set enemy position
//----------------------------------------------------------------------------
void enemy::setpos(array<int, 2> pos)
{
	x = pos[0];
	y = pos[1];
}

//----------------------------------------------------------------------------
// Class:   enemy
// Method:  getpos 
// Purpose: get enemy position
//----------------------------------------------------------------------------
array<int, 2> enemy::getpos()
{
	array<int, 2> pos{ x,y };
	return pos;
}

//----------------------------------------------------------------------------
// Class:   enemy
// Method:  sethp 
// Purpose: set enemy position
//----------------------------------------------------------------------------
int enemy::gethp()
{
	return hp;
}

//----------------------------------------------------------------------------
// Class:   enemy
// Method: takedamage 
// Purpose: decrease enemy hp
//----------------------------------------------------------------------------
void enemy::takedamage(int damage)
{
	hp -= damage;
}

//----------------------------------------------------------------------------
// Class:   enemy
// Method:  setdead 
// Purpose: declare enemy dead to not be placed on map anymore
//----------------------------------------------------------------------------
void enemy::setdead()
{
	dead = true;
}

//----------------------------------------------------------------------------
// Class:   enemy
// Method:  isdead 
// Purpose: gets value of whether the enemy is dead or not
//----------------------------------------------------------------------------
bool enemy::isdead()
{
	return dead;
}

//----------------------------------------------------------------------------
// Class:   enemy
// Method:  getxp 
// Purpose: gets the base amount of xp given by this enemy
//----------------------------------------------------------------------------
int enemy::getexp()
{
	return givenexp;
}

//----------------------------------------------------------------------------
// Class:   enemy
// Method:  getname 
// Purpose: get enemyÅfs name
//----------------------------------------------------------------------------
string enemy::getname()
{
	return name;
}

//----------------------------------------------------------------------------
// Class:   enemy
// Method:  attack 
// Purpose: returns damage output of enemy
//----------------------------------------------------------------------------
int enemy::attack()
{
	return damage;
}

//----------------------------------------------------------------------------
// Class:   enemy
// Method:  getchar 
// Purpose: returns enemy char for printing on screen
//----------------------------------------------------------------------------
string enemy::getchar()
{
	return echar;
}

//----------------------------------------------------------------------------
// Class:   enemy
// Method:  init 
// Purpose: set enemy stats and defaults
//----------------------------------------------------------------------------
array<string, 10>names = { "Dogoo", "Pixelvader", "Clione", "WD Head", "Boxer-X", "Plum-met", "Clyde", "Matango", "Boxbird", "R4i-SDHC" };
void enemy::init(array<int, 2> pos, int ilevel)
{
	name = names[rand() % 10];
	level = ilevel;
	hp = level * 5;
	x = pos[0];
	y = pos[1];
	dead = false;
	damage = level;
	givenexp = level;
	echar = name[0];
}

//*****************************************************************************
// class:   item
// 
// 
//*****************************************************************************

//----------------------------------------------------------------------------
// Class:   item
// Method:  getname 
// Purpose: gets name of item
//----------------------------------------------------------------------------
string item::getname()
{
	return name;
}

//----------------------------------------------------------------------------
// Class:   item
// Method:  getpos 
// Purpose: gets itemÅfs position
//----------------------------------------------------------------------------
array<int, 2> item::getpos()
{
	return { x,y };
}

//----------------------------------------------------------------------------
// Class:   item
// Method:  setpos 
// Purpose: sets position of item
//----------------------------------------------------------------------------
void item::setpos(array<int, 2>pos)
{
	x = pos[0];
	y = pos[1];
}

//----------------------------------------------------------------------------
// Class:   item
// Method:  itemgot 
// Purpose: returns if the player has picked up the item
//----------------------------------------------------------------------------
bool item::itemgot()
{
	return isonground;
}

//----------------------------------------------------------------------------
// Class:   item
// Method:  pickedup 
// Purpose: player has picked up item and item is not to be displayed
//----------------------------------------------------------------------------
void item::pickedup()
{
	isonground = false;
}

//----------------------------------------------------------------------------
// Class:   item
// Method:  init 
// Purpose: initializes item stats
//----------------------------------------------------------------------------
void item::init(array<int, 2> pos, string ename)
{
	name = ename;
	x = pos[0];
	y = pos[1];
	isonground = true;
}

//*****************************************************************************
// class:   weapon
// 
//*****************************************************************************

//----------------------------------------------------------------------------
// Class:   weapon
// Method:  init 
// Purpose: initializes weapon stats
//----------------------------------------------------------------------------

array<string, 3>weapons = { "Python", "M3", "MP5" };
void weapon::init(array<int, 2> pos, int level)
{
	name = weapons[level - 1];
	isonground = true;
	x = pos[0];
	y = pos[1];
	damage = level + 1;
}

//----------------------------------------------------------------------------
// Class:   weapon
// Method:  getdamage 
// Purpose: returns damage output of weapon
//----------------------------------------------------------------------------
int weapon::getdamage()
{
	return damage;
}

//============================END_OF_FILE======================================

