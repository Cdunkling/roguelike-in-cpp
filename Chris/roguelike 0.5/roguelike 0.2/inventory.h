#include <iostream>
#include <string>
#include <array>

using namespace std;

class inventory {
protected:
	array<string, 10> items;
public:
	// sets up the array so that the slots are empty
	void init();
	void ShowInventory();
	void Get(string name);
};