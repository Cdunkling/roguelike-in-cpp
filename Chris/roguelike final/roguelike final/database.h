#ifndef ROGUELIKE_DATABASE_H
#define ROGUELIKE_DATABASE_H

#include <iostream>
#include <string>
using namespace std;

class Database {
private:
	string dbName;
public:
	int getScore(int id);
	int getDungeonID(int id);
	int getPlayerXPos(int id);
	int getPlayerYPos(int id);
	int getHP(int id);
	string getMapFileName(int id);
	int getMapID(string fileName);
	string getDBName();
	void setDBName(string name);
	void setHP(int id, int xPos);
	void setScore(int id, int score);
	void SetDungeonID(int id, int dungeon);
	void setPlayerXPos(int id, int coX);
	void setPlayerYPos(int id, int coY);
	void addNewMap(string fileName);
	int getXPos(int id);
	int getYPos(int id);
	void setNPCXPos(int id, int xPos);
	void setNPCYPos(int id, int yPos);
	void printMapContents();
	void printPlayerContents();
	void printNPCContents();
};
#endif