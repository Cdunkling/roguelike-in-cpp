#include <iostream>
#include <vector>
#include <array>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

class MapGenerator{
public:

    vector <vector<string> > gameMap;

    //Used to generate the random map
    //x = width
    // y = height
    //numberOfDoors = number of doors to be randomly placed
    void createMap(int x, int y,  int numberOfDoors){
        for (int i = 0; i < y; i ++){
            vector<string> temp;
            for (int j = 0; j < x; j++){
                if ( j == 0 || j == x - 1){
                    temp.push_back("|");
                }else if(i == 0 || i == y -1){
                    temp.push_back("-");
                }else{
                    temp.push_back(".");
                }
            }
        gameMap.push_back(temp);
        }
        int randX, randY;
        srand(time(0));
        while (numberOfDoors > 0){
            randX = rand() % x;
            randY = rand() % y;
            if (gameMap[randY][randX] == "."){
                gameMap[randY][randX] = "+";
                numberOfDoors--;
            }
        }


        //randomly places three vertical walls or length 3
        int i = 0;
        while(i < 3){
            randX = rand() % x;
            randY = rand() % y;

            if (gameMap[randY][randX] == "." && gameMap[randY + 1][randX] == "." && gameMap[randY + 2 ][randX] == "."){
                gameMap[randY][randX] = "W";
                gameMap[randY + 1][randX] = "W";
                gameMap[randY + 2][randX] = "W";
                i++;
            }
        }

        //randomly places three horizontal walls of length 3
        int j = 0;
        while(j < 3){
            randX = rand() % x;
            randY = rand() % y;

            if (gameMap[randY][randX] == "." && gameMap[randY][randX+1] == "." && gameMap[randY][randX+2] == "."){
                gameMap[randY][randX] = "W";
                gameMap[randY][randX + 1] = "W";
                gameMap[randY][randX + 2] = "W";
                j++;
            }
        }



    }

    //print the map to the console
    void printMap(){
        for (int i = 0; i < gameMap.size(); i++){
            for (int j = 0; j < gameMap[i].size(); j++){
                cout << gameMap[i][j];
            }
            cout << endl;
        }
    }




    //save the map to txt file
    void saveToTxt(string fileName){
        ofstream fileOutput;
        fileOutput.open(fileName);
        for (int i = 0; i < gameMap.size(); i++){
            for(int j = 0; j < gameMap[i].size(); j++){
                fileOutput << gameMap[i][j];
            }
            fileOutput << endl;
        }
        fileOutput.close();
    }
};

int main()
{
    MapGenerator map1;
    map1.createMap(20, 20 , 5);
    map1.printMap();
    map1.saveToTxt("map1.txt");
    return 0;
}
