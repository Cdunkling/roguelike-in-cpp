#include <iostream>
#include <string>
#include "libsqlite.hpp"
#include "database.h"
using namespace std;

	//Player Getter Methods
	int Database :: getPlayerXPos(int id) {
		try {
			sqlite::sqlite db(dbName);
			auto cur = db.get_statement();
			//SQL Statement
			cur->set_sql("SELECT xPos FROM PLAYER WHERE playerID = ?");
			cur->prepare();
			cur->bind(1, id);
			cur->step();
			return cur->get_int(0);
		}
		catch (sqlite::exception e) {
			cout << "";
			return 0;
		}
	}
	int Database::getPlayerYPos(int id) {
		try {
			sqlite::sqlite db(dbName);
			auto cur = db.get_statement();
			//SQL Statement
			cur->set_sql("SELECT yPos FROM PLAYER WHERE playerID = ?");
			cur->prepare();
			cur->bind(1, id);
			cur->step();
			return cur->get_int(0);
		}
		catch (sqlite::exception e) {
			cout << "";
			return 0;
		}
	}
	int Database::getDungeonID(int id) {
		try {
			sqlite::sqlite db(dbName);
			auto cur = db.get_statement();
			//SQL Statement
			cur->set_sql("SELECT dungeonID FROM PLAYER WHERE playerID = ?");
			cur->prepare();
			cur->bind(1, id);
			cur->step();
			return cur->get_int(0);
		}
		catch (sqlite::exception e) {
			cout << "";
			return 0;
		}
	}
	int Database::getHP(int id) {
		try {
			sqlite::sqlite db(dbName);
			auto cur = db.get_statement();
			//SQL Statement
			cur->set_sql("SELECT dungeonID FROM PLAYER WHERE playerID = ?");
			cur->prepare();
			cur->bind(1, id);
			cur->step();
			return cur->get_int(0);
		}
		catch (sqlite::exception e) {
			cerr << e.what() << endl;
			return 0;
		}
	}
	int Database::getScore(int id) {
		try {
			sqlite::sqlite db(dbName);
			auto cur = db.get_statement();
			//SQL Statement
			cur->set_sql("SELECT dungeonID FROM PLAYER WHERE playerID = ?");
			cur->prepare();
			cur->bind(1, id);
			cur->step();
			return cur->get_int(0);
		}
		catch (sqlite::exception e) {
			cerr << e.what() << endl;
			return 0;
		}
	}

	//Player Setter Methods
	void Database::setPlayerXPos(int id, int xPos)
	{
		try {
			sqlite::sqlite db(dbName);
			auto cur = db.get_statement();
			cur->set_sql("UPDATE PLAYER SET xPos = ? WHERE playerID = ?");
			cur->prepare();
			cur->bind(1, xPos);
			cur->bind(2, id);
			cur->step();
		}
		catch (sqlite::exception e)      // catch all sql issues
		{
			cout << "";

		}
	}

	void Database::setPlayerYPos(int id, int yPos)
	{
		try {
			sqlite::sqlite db(dbName);
			auto cur = db.get_statement();
			cur->set_sql("UPDATE PLAYER SET xPos = ? WHERE playerID = ?");
			cur->prepare();
			cur->bind(1, yPos);
			cur->bind(2, id);
			cur->step();
		}
		catch (sqlite::exception e)      // catch all sql issues
		{
			cout << "";
		}
	}

	void Database::SetDungeonID(int id, int xPos)
	{
		try {
			sqlite::sqlite db(dbName);
			auto cur = db.get_statement();
			cur->set_sql("UPDATE PLAYER SET dungeonID = ? WHERE playerID = ?");
			cur->prepare();
			cur->bind(1, xPos);
			cur->bind(2, id);
			cur->step();
		}
		catch (sqlite::exception e)      // catch all sql issues
		{
			cout << "";
		}
	}

	void Database::setHP(int id, int xPos)
	{
		try {
			sqlite::sqlite db(dbName);
			auto cur = db.get_statement();
			cur->set_sql("UPDATE PLAYER SET hp = ? WHERE playerID = ?");
			cur->prepare();
			cur->bind(1, xPos);
			cur->bind(2, id);
			cur->step();
		}
		catch (sqlite::exception e)      // catch all sql issues
		{
			cout << "";
		}
	}

	void Database::setScore(int id, int score)
	{
		try {
			sqlite::sqlite db(dbName);
			auto cur = db.get_statement();
			cur->set_sql("UPDATE PLAYER SET xPos = ? WHERE playerID = ?");
			cur->prepare();
			cur->bind(1, score);
			cur->bind(2, id);
			cur->step();
		}
		catch (sqlite::exception e)      // catch all sql issues
		{
			cout << "";

		}
	}

	//Getter methods for map table

	string Database::getMapFileName(int id) {
		try {
			sqlite::sqlite db(dbName);
			auto cur = db.get_statement();
			cur->set_sql("SELECT fileName FROM Map WHERE dungeonID = ?");
			cur->prepare();
			cur->bind(1, id);
			cur->step();
			return cur->get_text(0);
		}
		catch (sqlite::exception e)      // catch all sql issues
		{
			cout << "";
			return 0;
		}
	}
	int Database::getMapID(string fileName) {
		try {
			sqlite::sqlite db(dbName);
			auto cur = db.get_statement();
			cur->set_sql("SELECT dungeonID FROM Map WHERE fileName = ?");
			cur->prepare();
			cur->bind(1, fileName);
			cur->step();
			return cur->get_int(0);
		}
		catch (sqlite::exception e) {
			cerr << e.what() << endl;
			return 0;
		}



	}

	//Setter methods for map table
	void Database::addNewMap(string fileName) {
		try {
			sqlite::sqlite db(dbName);
			auto cur = db.get_statement();
			cur->set_sql("INSERT INTO MAP (fileName) VALUES (?)");
			cur->prepare();
			cur->bind(1, fileName);
			cur->step();
		}
		catch (sqlite::exception e)      // catch all sql issues
		{
			cout << "";
		}
	}

	//Getter methods for NPC table

	int Database::getXPos(int id) {
		try {
			sqlite::sqlite db(dbName);
			auto cur = db.get_statement();
			//SQL Statement
			cur->set_sql("SELECT xPos FROM NPC WHERE monsterID = ?");
			cur->prepare();
			cur->bind(1, id);
			cur->step();
			return cur->get_int(0);
		}
		catch (sqlite::exception e) {
			cerr << e.what() << endl;
			return 0;
		}
	}
	int Database::getYPos(int id) {
		try {
			sqlite::sqlite db(dbName);
			auto cur = db.get_statement();
			//SQL Statement
			cur->set_sql("SELECT FROM Npc WHERE monsterID = ?");
			cur->prepare();
			cur->bind(1, id);
			cur->step();
			return cur->get_int(0);
		}
		catch (sqlite::exception e) {
			cerr << e.what() << endl;
			return 0;
		}
	}

	// NPC setter methods
	void Database::setNPCXPos(int id, int xPos)
	{
		try {
			sqlite::sqlite db(dbName);
			auto cur = db.get_statement();
			cur->set_sql("UPDATE PLAYER SET xPos = ? WHERE playerID = ?");
			cur->prepare();
			cur->bind(1, xPos);
			cur->bind(2, id);
			cur->step();
		}
		catch (sqlite::exception e)      // catch all sql issues
		{
			cout << "";
		}
	}

	void Database::setNPCYPos(int id, int yPos)
	{
		try {
			sqlite::sqlite db(dbName);
			auto cur = db.get_statement();
			cur->set_sql("UPDATE PLAYER SET xPos = ? WHERE playerID = ?");
			cur->prepare();
			cur->bind(1, yPos);
			cur->bind(2, id);
			cur->step();
		}
		catch (sqlite::exception e)      // catch all sql issues
		{
			cout << "";
		}
	}

	void Database::printMapContents() {
		try {
			sqlite::sqlite db(dbName);
			auto cur = db.get_statement();
			cur->set_sql("SELECT * FROM MAP");
			cur->prepare();
			cout << "Map Table" << endl;
			while (cur->step()) {
				cout << cur->get_int(0) << " " << cur->get_text(1) << endl;
			}
		}
		catch (sqlite::exception e)      // catch all sql issues
		{
			cout << "";
		}
	}

	void Database::printPlayerContents() {
		try {
			sqlite::sqlite db(dbName);
			auto cur = db.get_statement();
			cur->set_sql("SELECT * FROM Player");
			cur->prepare();
			cout << "PLayer Table" << endl;
			while (cur->step()) {
				cout << "ID: " << cur->get_int(0) << " XPos: " << cur->get_text(1) << " YPos: " << cur->get_text(1);
				cout << " DungeonID: " << cur->get_int(0) << " HP: " << cur->get_int(0) << " Score: " << cur->get_int(0) << endl;
			}
		}
		catch (sqlite::exception e)      // catch all sql issues
		{
			cout << "";
		}
	}

	void Database::printNPCContents() {
		try {
			sqlite::sqlite db(dbName);
			auto cur = db.get_statement();
			cur->set_sql("SELECT * FROM Npc");
			cur->prepare();
			cout << "NPC Table" << endl;
			while (cur->step()) {
				cout << "ID: " << cur->get_int(0) << " xPos: " << cur->get_int(1) << " yPos: " << cur->get_int(2) << endl;
			}
		}
		catch (sqlite::exception e)      // catch all sql issues
		{
			cout << "";
		}
	}

	string Database::getDBName() {
		return dbName;
	}
	void Database::setDBName(string name) {
		name = dbName;
	}
