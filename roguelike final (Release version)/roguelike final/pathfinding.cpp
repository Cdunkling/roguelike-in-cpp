#include "stdafx.h"
#include<string>
#include<vector>
#include <array>
#include "pathfinding.h"
#include "classes.h"
#include "roguelike0.2.h"
using namespace std;


	void node:: set_position(array<int, 2>pos) { position = pos; }
	array<int, 2> node:: get_position() { return position; }
	int node:: get_count() { return count; }
	void node:: set_count(int c) { count=c+1; }

vector<node> get_adjacent(node inputnode)
{
	vector<node> adjacentcells;
	for (int dx = -1; dx <= 1; ++dx) {
		for (int dy = -1; dy <= 1; ++dy) {
			if (dx != 0 || dy != 0) {
				node n;
				n.set_position({ inputnode.get_position()[0] + dx, inputnode.get_position()[1] + dy});
				n.set_count(inputnode.get_count());
				adjacentcells.emplace_back(n);
			}
		}
	}
	return adjacentcells;
}
vector<node> search(array<int, 2> end, array<int, 2> start, vector<vector<char>> level)
{
	node endnode;
	endnode.set_position(end);
	vector<node>path = { endnode};
	vector<node>adjacentcells;
	for(int j = 0; j != path.size()-1; j++)
	{
		adjacentcells = get_adjacent(path[j]);
		for (int i = 0; i != adjacentcells.size()-1; i++)
		{
			char nextstep = level[adjacentcells[i].get_position()[0]][adjacentcells[i].get_position()[1]];
			array<int, 2> nextlevelstep = { adjacentcells[i].get_position()[0],adjacentcells[i].get_position()[1]};
			if (enemynocollision(nextlevelstep, nextstep) == false)
			{
				swap(adjacentcells[i], adjacentcells.back());
				adjacentcells.pop_back();
			}
			for (int k = 0; k != path.size()-1; k++)
			{
				try {
					if (path[k].get_position() == adjacentcells[i].get_position() && path[k].get_count() <= adjacentcells[i].get_count())
					{
						adjacentcells.erase(adjacentcells.begin() + i);
					}
				}
				catch (exception x)
				{
					break;
				}
			}
		}
		path.reserve(path.size() + adjacentcells.size());
		path.insert(path.end(), adjacentcells.begin(), adjacentcells.end());

	}
	return path;
}


/*Create a list of the four adjacent cells, with a counter variable of the current element's counter variable + 1 (in our example, the four cells are ((2,8,1),(3,7,1),(4,8,1),(3,9,1)))
		Check all cells in each list for the following two conditions :
	If the cell is a wall, remove it from the list
		If there is an element in the main list with the same coordinate and a less than or equal counter, remove it from the cells list
		Add all remaining cells in the list to the end of the main list
		Go to the next item in the list
		*/