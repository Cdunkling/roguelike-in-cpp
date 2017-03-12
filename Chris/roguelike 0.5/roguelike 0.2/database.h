#include <iostream>
#include <string>
using namespace std;

class Database {
private:
	string dbName;
public:
	string get_name(int id);
	int get_score(int id);
	int get_dungeon_level(int id);
	int get_coX(int id);
	int get_coY(int id);
	void set_dbname(string name);
	void set_name(int id, string name);
	void set_score(int id, int score);
	void set_dungeon(int id, int dungeon);
	void set_coX(int id, int coX);
	void set_coY(int id, int coY);
	void new_entry(string name, int score, int dungeon, int coX, int coY);
};