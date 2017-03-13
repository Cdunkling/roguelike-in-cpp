#include "stdafx.h"
#include<string>
#include<vector>
#include <array>

using namespace std;


class node
{
private:
	int count = 0;
	array<int, 2>position;
public:
	void node::set_position(array<int, 2>pos);
	array<int, 2> node::get_position();
	int node::get_count();
	void node::set_count(int c);
};
vector<node> get_adjacent(node inputnode);
vector<node> search(array<int, 2> end, array<int, 2> start, vector<vector<char>> level);