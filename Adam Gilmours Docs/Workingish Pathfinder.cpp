//Psuedo Code found at https://en.wikipedia.org/wiki/Dijkstra's_algorithm#Using_a_priority_queue
//
//"http://code.activestate.com/recipes/577457-a-star-shortest-path-algorithm/"
#pragma once

#include <iostream>
#include <queue>
#include <string>
#include <Windows.h>
#include <vector>
using namespace std;


//assigns x and y of grid.
const int n = 20;
const int m = 20;
static char map[n][m];
static int closed_nodes_map[n][m];
static int open_nodes_map[n][m];
static int dir_map[n][m];
//direction that the search algorithm can go in, 4 means up, down, left and right.
const int dir = 4;
//these lists allow the algorithm to check the nodes around it.
static int dx[dir] = { 1,0,-1,0 };
static int dy[dir] = { 0,1,0,-1 };

//create the node and assign it specific values.
class node
{
	int xPos;
	int yPos;
	int cost;

public:
	node(int xp, int yp, int d)
	{
		xPos = xp; yPos = yp; cost = d;
	}

	int getxPos() const { return xPos; }
	int getyPos() const { return yPos; }
	int getcost() const { return cost; }


	void nextCost(const int & i)
	{
		cost += 10;
	}

};
//Determin priority in queue
bool operator<(const node & a, const node & b)
{
	return a.getcost() > b.getcost();
}

//Dijkstras Algorithm
//Return direction of nodes.
string pathFind(const int & xStart, const int & yStart, const int & xFinish, const int & yFinish)
{
	//create list of open nodes, assigning their values.
	static priority_queue<node> pq[2];
	//pq index
	static int pqi = 0;
	static node* n0;
	static node* m0;
	static int i, j, x, y, xdx, ydy;
	static char c;

	for (y = 0; y < m; y++)
	{
		for (x = 0; x < n; x++)
		{
			closed_nodes_map[n][m] = 0;
			open_nodes_map[n][m] = 0;
		}
	}
	//create first node and then put it into queue
	n0 = new node(xStart, yStart, 0);
	pq[pqi].push(*n0);
	open_nodes_map[x][y] = n0->getcost();

	//while queue is not empty, run this
	//The way this works is the queue will never be empty unless it has searched through all the nodes
	//and it finds no path
	//if it does find a path it will return the list.
	//this is the actual algorithm that checks the adjacent nodes and updates their cost
	while (!pq[pqi].empty())
	{
		//create a new node
		n0 = new node(pq[pqi].top().getxPos(), pq[pqi].top().getyPos(),
			pq[pqi].top().getcost());
		//get their x and y position.
		x = n0->getxPos();
		y = n0->getyPos();

		//remove that node from the queue.
		pq[pqi].pop();
		open_nodes_map[x][y] = 0;
		closed_nodes_map[x][y] = 1;
		//Check if the new node matches the goal node.
		if (x == xFinish && y == yFinish)
		{
			// generate the path from finish to start
			// by following the directions
			string path = "";
			while (!(x == xStart && y == yStart))
			{
				j = dir_map[x][y];
				c = '0' + (j + dir / 2) % dir;
				path = c + path;
				x += dx[j];
				y += dy[j];
			}
			while (!pq[pqi].empty()) pq[pqi].pop();
			//return the path that the algorithm took so that we can display it on a graph.
			return path;
		}
		//generate new child node in all possible directions
		for (i = 0; i<dir; i++)
		{
			xdx = x + dx[i]; ydy = y + dy[i];

			if (!(xdx<0 || xdx>n - 1 || ydy<0 || ydy>m - 1 || map[xdx][ydy] == 1
				|| closed_nodes_map[xdx][ydy] == 1))
			{
				// generate a child node
				m0 = new node(xdx, ydy, n0->getcost());
				m0->nextCost(i);

				// if it is not in the open list then add into that
				if (open_nodes_map[xdx][ydy] == 0)
				{
					open_nodes_map[xdx][ydy] = m0->getcost();
					pq[pqi].push(*m0);
					// mark its parent node direction
					dir_map[xdx][ydy] = (i + dir / 2) % dir;
				}
				else if (open_nodes_map[xdx][ydy]>m0->getcost())
				{
					// update the priority info
					open_nodes_map[xdx][ydy] = m0->getcost();
					// update the parent direction info
					dir_map[xdx][ydy] = (i + dir / 2) % dir;

					// replace the node
					// by emptying one pq to the other one
					// except the node to be replaced will be ignored
					// and the new node will be pushed in instead
					while (!(pq[pqi].top().getxPos() == xdx &&
						pq[pqi].top().getyPos() == ydy))
					{
						pq[1 - pqi].push(pq[pqi].top());
						pq[pqi].pop();
					}
					pq[pqi].pop(); // remove the wanted node

								   // empty the larger size pq to the smaller one
					if (pq[pqi].size()>pq[1 - pqi].size()) pqi = 1 - pqi;
					while (!pq[pqi].empty())
					{
						pq[1 - pqi].push(pq[pqi].top());
						pq[pqi].pop();
					}
					pqi = 1 - pqi;
					pq[pqi].push(*m0); // add the better node instead
				}
			}
		}
	}
	return ""; // no route found
}

void SearchGraph()
{
    int startx = 1;
    int starty = 1;
    int endx = 19;
    int endy = 19;

    // create empty map
    for(int y=0;y<m;y++)
    {
        for(int x=0;x<n;x++) map[x][y]=0;
    }

    // fillout the map matrix with a '+' pattern
    for (int y = 1; y < 18; y++)
        {
            for (int x = 5; x < 6; x++)
            {
                map[x][y] = 1;
            }
        }

    string route=pathFind(startx, starty, endx, endy);

    // follow the route on the map and display it
    if(route.length()>0)
    {
        int j; char c;
        for (int i = 0; i < route.length(); i++)
		{
			c = route.at(i);
			j = atoi(&c);
			system("cls");
			startx = startx + dx[j];
			starty = starty + dy[j];
			for (int y = 0; y < n; y++)
			{
				for (int x = 0; x < m; x++)
				{
					map[x][y] = '.';
					for (int y = 1; y < 18; y++)
                    {
                        for (int x = 5; x < 6; x++)
                        {
                            map[x][y] = 'W';
                        }
                    }
					map[startx][starty] = 'S';
					map[endx][endy] = 'E';
					cout << map[x][y];
				}
				cout << endl;
			}

			Sleep(100);
		}
    }
}
