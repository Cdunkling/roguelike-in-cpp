//Psuedo Code found at https://en.wikipedia.org/wiki/Dijkstra's_algorithm#Using_a_priority_queue
//
//The main search algorithm is based on the A* algorithm found at "http://code.activestate.com/recipes/577457-a-star-shortest-path-algorithm/"
//the code has been edited by me and reworked to use Dijkstra's algorithm instead of A* and the final part of the code has been completely rewritten to work with
//a graph.
#pragma once

#include <iostream>
#include <queue>
#include <string>
#include <Windows.h>
#include <vector>
#include "grid.h"
using namespace std;


static int closed_nodes_map[n][m];
static int open_nodes_map[n][m];
static int dir_map[n][m];
//direction that the search algorithm can go in, 4 means up, down, left and right.
const int dir = 4;
//these lists allow the algorithm to check the nodes around it.
static int dx[dir] = { 1,0,-1,0 };
static int dy[dir] = { 0,1,0,-1 };

//my code, based upon the fact that each point in a grid needs to be an object with the attributes xPos, yPos and Cost.
//class Database{
//    public:
//    Database(string name){
//        dbName = name;
//    }
//    int getNPCXPos(int id){
//        try{
//            sqlite::sqlite db(dbName);
//            auto cur = db.get_statement();
//            //SQL Statement
//            cur->set_sql("SELECT xPos FROM Npc WHERE npcID = ?");
//            cur->prepare();
//            cur->bind(1, id);
//            cur->step();
//            return cur->get_int(0);
//        }catch(sqlite::exception e){
//            cerr<< e.what() << endl;
//        }
//
//    int getNPCYPos(int id){
//        try{
//            sqlite::sqlite db(dbName);
//            auto cur = db.get_statement();
//            //SQL Statement
//            cur->set_sql("SELECT yPos FROM Npc WHERE npcID = ?");
//            cur->prepare();
//            cur->bind(1, id);
//            cur->step();
//            return cur->get_int(0);
//        }catch(sqlite::exception e){
//            cerr<< e.what() << endl;
//        }
//}
//}



//};
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

	//When each node is created return their attributes.
    int getxPos() const { return xPos; }
	int getyPos() const { return yPos; }
	int getcost() const { return cost; }


    //for every node away from the first their cost increases by 10.
	void nextCost(const int & i)
	{
		cost += 10;
	}

};
//finds out what node to use next based on their cost.
bool operator<(const node & a, const node & b)
{
	return a.getcost() > b.getcost();
}

//Dijkstra's Algorithm using priority queue.
//Return direction of nodes.
//not my code, but some of it has been changed by me for it to work the way I want it to work.
string pathFind(int xStart, int yStart, int xFinish, int yFinish)
{
	//create list of open nodes, assigning their values.
	static priority_queue<node> pq[2];
	//pq index, allows us to refer to items already in the priority queue.
	//how else are we meant to check for something in the queue?
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
	open_nodes_map[x][y] = n0->getcost();//my code

	//while the priority queue is not empty run the search.
	//hand written by me, but the whole idea is based of another's off the internet; link is at top of code.
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
		if (x == xFinish-1 && y == yFinish || x == xFinish+1 && y == yFinish || x == xFinish && y == yFinish-1 || x == xFinish && y == yFinish+1)
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

			if (!(xdx<0 || xdx>n - 1 || ydy<0 || ydy>m - 1 || mapArray2d[xdx][ydy] != "."
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
	delete m0;
	delete n0;
	return ""; // no route found
}
//FROM THIS POINT ON IT IS ALL MY OWN CODE.
//int getXpos()
//{
//    int xPos;
//    Database db ("RougelikeV5.db")
//    db.getNPCXPos(1) == xPos;
//    return xPos;
//}



void doAlgorithm()
{
    int startX = 2;
    int startY = 2;
    int newendX = 17;
    int newendY = 17;
    int oldX = 2;
    int oldY = 2;
        MapGenerator map1;
    map1.createMap(20, 20 , 5);
//    map1.printMap();
//    map1.saveToTxt("map2.txt");
    map1.saveToTxt("map2.txt");
    map1.TxtFileToArray("map2.txt");

    string route = pathFind(startX, startY, newendX, newendY);
    if (route.length()>0)
    {
        int j; char c;
        for (int i = 0; i<route.length(); i++)
        {
            c = route.at(i);
            j = atoi(&c);
            system("cls");
            startX = startX + dx[j];
            startY = startY + dy[j];
            oldX = startX - dx[j];
            oldY = startY - dy[j];
            map1.print2DArray();
            for (int y = 0; y < 20; y++)
            {
                for(int x = 0; x < 20; x++)
                {
                    mapArray2d[startX][startY] = "S";
                    mapArray2d[oldX][oldY] = ".";
                    mapArray2d[newendX][newendY] = "E";
                    cout << mapArray2d[y][x];
                }
                cout << endl;
            }
            Sleep(250);
        }
    }
    if (route=="")
    {
        for(int y = 0; y < 20; y++)
        {
            for(int x = 0; x < 20; x++)
            {
                mapArray2d[startX][startY] = "S";
                mapArray2d[x][y];
                cout << mapArray2d[y][x];
            }
            cout << endl;
        }
    }

}

string test(int sx, int sy, int ex, int ey, int walls)
{
    int startX = sx;
    int startY = sy;
    int endX = ex;
    int endY = ey;
    int wall = walls;
    if (wall == 1)
    {
        for (int y = 0; y < m; y++)
        {
            for (int x = 0; x<n; x++)
            {
                mapArray2d[x][y] = ".";
            }
        }
    }
    else if(wall == 2)
    {
        for (int y = 0; y < m; y++)
        {
            for (int x = 0; x<n; x++)
            {
                mapArray2d[x][y] = ".";
            }
        }
        for (int y = 4; y < m-4; y++)
        {
            for (int x = n/2; x<=n/2; x++)
            {
                mapArray2d[x][y] = "W";
            }
        }
    }
    else if(wall == 3)
    {
        for (int y = 0; y < m; y++)
        {
            for (int x = 0; x<n; x++)
            {
                mapArray2d[x][y] = ".";
            }
        }
        for (int y = 0; y < m; y++)
        {
            for (int x = n/2; x<=n/2; x++)
            {
                mapArray2d[x][y] = "W";
            }
        }
    }
    string route = pathFind(startX, startY, endX, endY);
    if (route == "")
    {
        return "PASSED";
    }
    else if (route.length() > 0)
    {
        return "PASSED";
    }
    else
    {
        return "FAILED";
    }
}

void doTest()
{
    int countPass = 0;
    int countFail = 0;
    int numTest1 = 4;
    int numTest2 = 3;
    int Xarray[numTest1] = {3,4,4,4};
    int Yarray[numTest1] = {3,4,4,4};
    int eXarray[numTest1] = {18,19,19,19};
    int eYarray[numTest1] = {18,19,19,19};
    int wall[numTest2] = {1,2,3};
    for (int j = 0; j<numTest2; j++)
    {
        int newWall = wall[j];
        if (newWall == 1)
        {
            cout << endl;
            cout << "TEST WITH NO WALLS" << endl;
            for (int i =0; i < numTest1; i++)
        {
            int sx = Xarray[i];
            int sy = Yarray[i];
            int ex = eXarray[i];
            int ey = eYarray[i];
            if (test(sx, sy, ex, ey, newWall) == "PASSED")
            {
                int x = i+1;
                int y = j+1;
                cout << "Test " << x << " of " << y << " has PASSED"<< endl;
                countPass += 1;
            }
            else if(test(sx, sy, ex, ey, newWall) == "FAILED")
            {
                cout << "Test 1 FAILED" << endl;
                countFail += 1;
            }
        }
        }
        else if (newWall == 2)
        {
            cout << endl;
            cout << "TEST WITH WALLS" << endl;
            for (int i =0; i < numTest1; i++)
            {
                int sx = Xarray[i];
                int sy = Yarray[i];
                int eX = eXarray[i];
                int eY = eYarray[i];
                if (test(sx, sy, eX, eY, newWall) == "PASSED")
                {
                    int x = i+1;
                    int y = j+1;
                    cout << "Test " << x << " of " << y << " has PASSED"<< endl;
                    countPass += 1;
                }
                else if(test(sx, sy, eX, eY, newWall) == "FAILED")
                {
                    cout << "Test 1 FAILED" << endl;
                    countFail += 1;
                }
            }
        }
        else if (newWall == 3)
        {
            cout << endl;
            cout << "TEST FOR BLOCKING WALLS" << endl;
            for (int i =0; i < numTest1; i++)
            {
                int sx = Xarray[i];
                int sy = Yarray[i];
                int eX = eXarray[i];
                int eY = eYarray[i];
                if (test(sx, sy, eX, eY, newWall) == "PASSED")
                {
                    int x = i+1;
                    int y = j+1;
                    cout << "Test " << x << " of " << y << " has PASSED"<< endl;
                    countPass += 1;
                }
                else
                {
                    cout << "Test 3 FAILED" << endl;
                    countFail += 1;
                }
            }
        }
    }
    cout << endl;
    if (countPass == 12)
    {
        cout << countPass << " of " << (numTest1 * numTest2) << " tests have PASSED. ";
    }
    else
    {
        cout << countFail << " of " << (numTest1 * numTest2) << " have FAILED.";
    }
}
