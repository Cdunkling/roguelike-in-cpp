#include <iostream>
#include <string>
#include "libsqlite.hpp"
using namespace std;

class Database{
    public:
    Database(string name){
        dbName = name;
    }

    //Player Getter Methods

    //Get the name of the player
    //Required input: playerID
    
    string getPlayerName(int id){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            //SQL Statement
            cur->set_sql("SELECT name FROM PLAYER WHERE playerID = ?");
            cur->prepare();
            cur->bind(1, id);
            cur->step();
            return cur->get_text(0);
        }catch(sqlite::exception e){ 
            cerr<< e.what() << endl;
        }
    }
    
    //Get the xPos of the player
    //Required input: playerID
    //
    int getPlayerXPos(int id){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            //SQL Statement
            cur->set_sql("SELECT xPos FROM PLAYER WHERE playerID = ?");
            cur->prepare();
            cur->bind(1, id);
            cur->step();
            return cur->get_int(0);
        }catch(sqlite::exception e){
            cerr<< e.what() << endl;
        }
    }
    
    //Get the yPos of the player
    //Required input: playerID
    
    int getPlayerYPos(int id){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            //SQL Statement
            cur->set_sql("SELECT yPos FROM PLAYER WHERE playerID = ?");
            cur->prepare();
            cur->bind(1, id);
            cur->step();
            return cur->get_int(0);
        }catch(sqlite::exception e){
            cerr<< e.what() << endl;
        }
    }
    //Get the dungeonLevel of the player
    //Required input: playerID
    
    int getPlayerDungeonLevel(int id){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            //SQL Statement
            cur->set_sql("SELECT dungeonLevel FROM PLAYER WHERE playerID = ?");
            cur->prepare();
            cur->bind(1, id);
            cur->step();
            return cur->get_int(0);
        }catch(sqlite::exception e){
            cerr<< e.what() << endl;
        }
    }
    //Get the hp level of the player
    //Required input: playerID
    
    int getPlayerHP(int id){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            //SQL Statement
            cur->set_sql("SELECT hp FROM PLAYER WHERE playerID = ?");
            cur->prepare();
            cur->bind(1, id);
            cur->step();
            return cur->get_int(0);
        }catch(sqlite::exception e){
            cerr<< e.what() << endl;
        }
    }
    //Get the score of the player
    //Required input: playerID
    
    int getPlayerScore(int id){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            //SQL Statement
            cur->set_sql("SELECT score FROM PLAYER WHERE playerID = ?");
            cur->prepare();
            cur->bind(1, id);
            cur->step();
            return cur->get_int(0);
        }catch(sqlite::exception e){
            cerr<< e.what() << endl;
        }
    }

    //Get the itemID of the player
    //Required input: playerID
    
    int getPlayerItemID(int id){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            //SQL Statement
            cur->set_sql("SELECT equippedItem FROM PLAYER WHERE playerID = ?");
            cur->prepare();
            cur->bind(1, id);
            cur->step();
            return cur->get_int(0);
        }catch(sqlite::exception e){
            cerr<< e.what() << endl;
        }
    }

    //Player Setter Methods
    
    //Add a new player to the player table
    //Required input: name, xPos, yPos, dungeonLevel, hp, score, equippedItem
    
    void addPlayerEntry(string name, int xPos, int yPos, int dungeonLevel, int hp, int score, int equippedItem){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            //SQL Statement
            cur->set_sql("INSERT INTO PLAYER (name,xPos, yPos, dungeonLevel, hp, score, equippedItem) VALUES (?,?,?,?,?,?,?)");
            cur->prepare();
            cur->bind(1, name);
            cur->bind(2, xPos);
            cur->bind(3, yPos);
            cur->bind(4, dungeonLevel);
            cur->bind(5, hp);
            cur->bind(6, score);
            cur->bind(7, equippedItem);
            cur->step();
        }catch(sqlite::exception e){
            cerr<< e.what() << endl;
        }
    }
    //Set the name of an existing player
    //Required input: playerID, new name
    void setPlayerName(int id, string name)
    {
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            cur->set_sql("UPDATE PLAYER SET name = ? WHERE playerID = ?");
            cur->prepare();
            cur->bind(1, name);
            cur->bind(2, id);
            cur->step();
        } catch( sqlite::exception e )       
        {
            std::cerr << e.what() << std::endl;
        }
    }
    //Set the xPos of an existing player
    //Required input: playerID, new xPos
    void setPlayerXPos(int id, int xPos)
    {
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            cur->set_sql("UPDATE PLAYER SET xPos = ? WHERE playerID = ?");
            cur->prepare();
            cur->bind(1, xPos);
            cur->bind(2, id);
            cur->step();
        } catch( sqlite::exception e )       
        {
            std::cerr << e.what() << std::endl;
        }
    }
    
    //Set the yPos of an existing player
    //Required input: playerID, new yPos
    void setPlayerYPos(int id, int yPos)
    {
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            cur->set_sql("UPDATE PLAYER SET yPos = ? WHERE playerID = ?");
            cur->prepare();
            cur->bind(1, yPos);
            cur->bind(2, id);
            cur->step();
        } catch( sqlite::exception e )       
        {
            std::cerr << e.what() << std::endl;
        }
    }
    //Set the dungeonLevel of an existing player
    //Required input: playerID, new dungeonLevel
    void playerSetDungeonLevel(int id, int xPos)
    {
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            cur->set_sql("UPDATE PLAYER SET dungeonLevel = ? WHERE playerID = ?");
            cur->prepare();
            cur->bind(1, xPos);
            cur->bind(2, id);
            cur->step();
        } catch( sqlite::exception e )       
        {
            std::cerr << e.what() << std::endl;
        }
    }
    //Set the hp level of an existing player
    //Required input: playerID, new hp level
    void setHP(int id, int xPos)
    {
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            cur->set_sql("UPDATE PLAYER SET hp = ? WHERE playerID = ?");
            cur->prepare();
            cur->bind(1, xPos);
            cur->bind(2, id);
            cur->step();
        } catch( sqlite::exception e )       
        {
            std::cerr << e.what() << std::endl;
        }
    }
    
    //Set the score of an existing player
    //Required input: playerID, new score

    void setScore(int id, int score)
    {
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            cur->set_sql("UPDATE PLAYER SET score = ? WHERE playerID = ?");
            cur->prepare();
            cur->bind(1, score);
            cur->bind(2, id);
            cur->step();
        } catch( sqlite::exception e )       
        {
            std::cerr << e.what() << std::endl;
        }
    }

    //Getter methods for map table
    
    //Get the fileName of a map
    //Required input: mapID
    string getMapFileName(int id){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            cur->set_sql("SELECT fileName FROM Map WHERE dungeonID = ?");
            cur->prepare();
            cur->bind(1, id);
            cur->step();
            return cur->get_text(0);
        } catch( sqlite::exception e )       
        {
            std::cerr << e.what() << std::endl;
        }
    }
    //Get the ID of a map 
    //Required input: fileName

    int getMapID(string fileName){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            cur->set_sql("SELECT dungeonID FROM Map WHERE fileName = ?");
            cur->prepare();
            cur->bind(1, fileName);
            cur->step();
            return cur->get_int(0);
        }catch(sqlite::exception e){
            cerr << e.what() << endl;
        }
    }

    //Setter methods for map table
    
    //Add a new map to the database
    //Required input: fileName
    void addNewMapEntry(string fileName){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            cur->set_sql("INSERT INTO MAP (fileName) VALUES (?)");
            cur->prepare();
            cur->bind(1, fileName);
            cur->step();
        } catch( sqlite::exception e )       
        {
            std::cerr << e.what() << std::endl;
        }
    }
    
    //Change the fileName of a Map
    //Required input: mapID, new fileName
     void setMapName(int id, string fileName){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            cur->set_sql("UPDATE Map set fileName = ? WHERE dungeonID = ?");
            cur->prepare();
            cur->bind(1, fileName);
            cur->bind(1, id);
            cur->step();
        } catch( sqlite::exception e )       
        {
            std::cerr << e.what() << std::endl;
        }
    }

    //Getter methods for NPC table
    
    //Get the xPos of an NPC
    //Required input: npcID
    int getNPCXPos(int id){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            //SQL Statement
            cur->set_sql("SELECT xPos FROM Npc WHERE npcID = ?");
            cur->prepare();
            cur->bind(1, id);
            cur->step();
            return cur->get_int(0);
        }catch(sqlite::exception e){
            cerr<< e.what() << endl;
        }
    }
    //Get the yPos of an NPC
    //Required input: npcID
    int getNPCYPos(int id){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            //SQL Statement
            cur->set_sql("SELECT yPos FROM Npc WHERE npcID = ?");
            cur->prepare();
            cur->bind(1, id);
            cur->step();
            return cur->get_int(0);
        }catch(sqlite::exception e){
            cerr<< e.what() << endl;
        }
    }
    //Get the hp level of an NPC
    //Required input: npcID
    int getNPCHp(int id){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            //SQL Statement
            cur->set_sql("SELECT hp FROM Npc WHERE npcID = ?");
            cur->prepare();
            cur->bind(1, id);
            cur->step();
            return cur->get_int(0);
        }catch(sqlite::exception e){
            cerr<< e.what() << endl;
        }
    }

    // NPC setter methods
    
    //Add a new NPC to the database
    //Required input: xPos, yPos, hp level
    void addNPCEntry(int xPos, int yPos, int hp){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            //SQL Statement
            cur->set_sql("INSERT INTO NPC (xPos, yPos, hp) VALUES (?,?,?)");
            cur->prepare();
            cur->bind(1, xPos);
            cur->bind(2, yPos);
            cur->bind(3, hp);
            cur->step();
        }catch(sqlite::exception e){
            cerr<< e.what() << endl;
        }
    }
    //Set the xPos of an NPC
    //Required input: npcID, new xPos
    void setNPCXPos(int id, int xPos)
    {
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            cur->set_sql("UPDATE Npc SET xPos = ? WHERE npcID = ?");
            cur->prepare();
            cur->bind(1, xPos);
            cur->bind(2, id);
            cur->step();
        } catch( sqlite::exception e )       
        {
            std::cerr << e.what() << std::endl;
        }
    }
    
    //Set the yPos of an NPC
    //Required input: npcID, new yPos
    void setNPCYPos(int id, int yPos)
    {
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            cur->set_sql("UPDATE Npc SET yPos = ? WHERE npcID = ?");
            cur->prepare();
            cur->bind(1, yPos);
            cur->bind(2, id);
            cur->step();
        } catch( sqlite::exception e )       
        {
            std::cerr << e.what() << std::endl;
        }
    }
    //Set the hp level of an NPC
    //Required input: npcID, new hp level

     void setNPCHp(int id, int hp)
    {
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            cur->set_sql("UPDATE Npc SET hp = ? WHERE npcID = ?");
            cur->prepare();
            cur->bind(1, hp);
            cur->bind(2, id);
            cur->step();
        } catch( sqlite::exception e )       
        {
            std::cerr << e.what() << std::endl;
        }
    }

    //Items getter methods
    //Get the name of an Item
    //Required input: itemID
    string getItemName(int id){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            //SQL Statement
            cur->set_sql("SELECT name FROM Items WHERE itemID = ?");
            cur->prepare();
            cur->bind(1, id);
            cur->step();
            return cur->get_text(0);
        }catch(sqlite::exception e){
            cerr<< e.what() << endl;
        }
    }
    
    //Get the damageLevel of an Item
    //Required input: itemID

    int getItemDamageLevel(int id){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            //SQL Statement
            cur->set_sql("SELECT damageLevel FROM Items WHERE itemID = ?");
            cur->prepare();
            cur->bind(1, id);
            cur->step();
            return cur->get_int(0);
        }catch(sqlite::exception e){
            cerr<< e.what() << endl;
        }
    }

    //Items setter methods
    
    //Add a new item to the database
    //Required input: name of item, damageLevel
    void addItemEntry(string name, int damageLevel){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            //SQL Statement
            cur->set_sql("INSERT INTO Items (name, damageLevel) VALUES (?,?)");
            cur->prepare();
            cur->bind(1, name);
            cur->bind(2, damageLevel);
            cur->step();
        }catch(sqlite::exception e){
            cerr<< e.what() << endl;
        }
    }
    
    //Change name of an Item
    //Required input: itemID, new item name
    void setItemName(int id, string itemName)
    {
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            cur->set_sql("UPDATE Items SET itemName = ? WHERE itemID = ?");
            cur->prepare();
            cur->bind(1, itemName);
            cur->bind(2, id);
            cur->step();
        } catch( sqlite::exception e )       
        {
            std::cerr << e.what() << std::endl;
        }
    }
    //Change the damageLevel of an Item
    //Required input: itemID, damageLevel
    
    void setItemDamageLevel(int id, int damageLevel){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            cur->set_sql("UPDATE Items SET damageLevel = ? WHERE itemID = ?");
            cur->prepare();
            cur->bind(1, damageLevel);
            cur->bind(2, id);
            cur->step();
        } catch( sqlite::exception e )       
        {
            std::cerr << e.what() << std::endl;
        }
    }



    //Testing methods
    //Prints the contents of the map table
    void printMapContents(){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            cur->set_sql("SELECT * FROM MAP");
            cur->prepare();
            cout << "Map Table" << endl;
            while (cur->step()){
                cout << cur->get_int(0) << " " << cur->get_text(1) << endl;
            }
        } catch( sqlite::exception e )       
        {
            std::cerr << e.what() << std::endl;
        }
    }
    
    //Prints the contents of the player table
    void printPlayerContents(){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            cur->set_sql("SELECT * FROM Player");
            cur->prepare();
            cout << "PLayer Table" << endl;
            while (cur->step()){
                cout << "ID: " << cur->get_int(0) << "Name: " << cur->get_text(1) << " XPos: " << cur->get_int(2) << " YPos: "<< cur->get_int(3);
                cout << " DungeonID: " << cur->get_int(4) << " HP: " << cur->get_int(5) << " Score: " << cur->get_int(6)<< " Item ID: " << cur->get_int(7) << endl;
            }
        } catch( sqlite::exception e )       
        {
            std::cerr << e.what() << std::endl;
        }
    }
    //Prints the contents of the NPC table
    void printNPCContents(){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            cur->set_sql("SELECT * FROM Npc");
            cur->prepare();
            cout << "NPC Table" << endl;
            while (cur->step()){
                cout << "ID: " << cur-> get_int(0) << " xPos: " << cur->get_int(1) << " yPos: " << cur->get_int(2) <<endl;
            }
        } catch( sqlite::exception e )       
        {
            std::cerr << e.what() << std::endl;
        }
    }
    
    //Returns the name of the DB
    string getDBName(){
        return dbName;
    }

    private:
    //Variable used to store the name of the database
    string dbName;

};

//Function that tests the player table
// ** EMPTY DATABASE REQUIRED**

void testPlayerTable(){
    Database db("RougelikeV5.db");
    string playerNames[3] = {"Jack", "John", "Dave"};
    int playerXPos[3] = {5, 12, 32};
    int playerYPos[3] = {32, 12, 12};
    int playerDungeonLevel[3] = {4, 5, 1};
    int playerHp[3] = {100, 21, 34};
    int playerScore[3] = {54, 12 ,34};
    int playerItem[3] = {5, 3 ,2};
    
    for (int i = 0; i < 3; i++){
        db.addPlayerEntry(playerNames[i], playerXPos[i], playerYPos[i], playerDungeonLevel[i], playerHp[i], playerScore[i], playerItem[i]);
        if(i == 0){
            if(db.getPlayerName(i+1) == playerNames[i]
               && db.getPlayerXPos(i+1) == playerXPos[i]
               && db.getPlayerYPos(i+1) == playerYPos[i]
               && db.getPlayerDungeonLevel(i+1) == playerDungeonLevel[i]
               && db.getPlayerHP(i+1) == playerHp[i]
               && db.getPlayerScore(i+1) == playerScore[i]
               && db.getPlayerItemID(i+1) == playerItem[i]){
                cout << "TEST 10: Passed" << endl;
            }else{
                cout << "TEST 10: Failed" << endl;
            }
        }else if (i == 1){
            if(db.getPlayerName(i+1) == playerNames[i]
                   && db.getPlayerXPos(i+1) == playerXPos[i]
                   && db.getPlayerYPos(i+1) == playerYPos[i]
                   && db.getPlayerDungeonLevel(i+1) == playerDungeonLevel[i]
                   && db.getPlayerHP(i+1) == playerHp[i]
                   && db.getPlayerScore(i+1) == playerScore[i]
                   && db.getPlayerItemID(i+1) == playerItem[i]){
                    cout << "TEST 11: Passed" << endl;
                }else{
                    cout << "TEST 11: Failed" << endl;
                }
        }else{
            if(db.getPlayerName(i+1) == playerNames[i]
               && db.getPlayerXPos(i+1) == playerXPos[i]
               && db.getPlayerYPos(i+1) == playerYPos[i]
               && db.getPlayerDungeonLevel(i+1) == playerDungeonLevel[i]
               && db.getPlayerHP(i+1) == playerHp[i]
               && db.getPlayerScore(i+1) == playerScore[i]
               && db.getPlayerItemID(i+1) == playerItem[i]){
                cout << "TEST 12: Passed" << endl;
            }else{
                cout << "TEST 12: Failed" << endl;
            }
        }
    }
}

//Function that tests the Items table
//// ** EMPTY DATABASE REQUIRED**
void testItemsTable(){
    Database db("RougelikeV5.db");
    string itemNames[3] = {"Pickaxe", "Shovel", "Laser"};
    int damageLevels[3] = {5, 2, 9000};
    
    for (int i = 0; i < 3; i++){
        db.addItemEntry(itemNames[i], damageLevels[i]);
        if(i == 0){
            if(db.getItemName(i+1) == itemNames[i]
               && db.getItemDamageLevel(i+1) == damageLevels[i]){
                cout << "TEST 1: Passed" << endl;
            }else{
                cout << "TEST 1: Failed" << endl;
            }
        }else if(i == 1){
            if(db.getItemName(i+1) == itemNames[i]
               && db.getItemDamageLevel(i+1) == damageLevels[i]){
                cout << "TEST 2: Passed" << endl;
            }else{
                cout << "TEST 2: Failed" << endl;
            }
        }else{
            if(db.getItemName(i+1) == itemNames[i]
               && db.getItemDamageLevel(i+1) == damageLevels[i]){
                cout << "TEST 3: Passed" << endl;
            }else{
                cout << "TEST 3: Failed" << endl;
            }
        }
    }
}
//Function that tests the map table
//// ** EMPTY DATABASE REQUIRED**
void testMapTable(){
    Database db ("RougelikeV5.db");
    string mapNames[3] = {"Map1.txt", "Map2.txt", "Map3.txt"};
    string newMapNames[3] = {"testMap1.txt", "testMap2.txt", "testMap3.txt"};
    for(int i = 0; i < 3; i++){
        db.addNewMapEntry(mapNames[i]);
        if(i == 0){
            if(db.getMapFileName(i+1) ==  mapNames[i]){
                cout << "Test 4: Passed" << endl;
            }else{
                cout << "Test 4: Failed" << endl;
            }
        }else if(i == 1){
            if(db.getMapFileName(i + 1) == mapNames[i]){
                cout << "Test 5: Passed" << endl;
            }else{
                cout << "Test 5 Failed" << endl;
            }
        }else{
            if(db.getMapFileName(i+1) == mapNames[i]){
                cout << "Test 6: Passed" << endl;
            }else{
                cout << "Test 6 Failed" << endl;
            }
        }
    }
}
//function that tests the NPC table
//// ** EMPTY DATABASE REQUIRED**
void testNPCTable(){
    Database db ("RougelikeV5.db");
    int xPos[3] = {12,54,90000};
    int yPos[3] = {23,54,89891};
    int hp[3] = {32,12,343};
    
    for (int i = 0; i < 3; i++){
        db.addNPCEntry(xPos[i],yPos[i],hp[i]);
        if(i == 0 ){
            if(db.getNPCXPos(i+1) == xPos[i]
              && db.getNPCYPos(i+1) == yPos[i]
              && db.getNPCHp(i+1) == hp[i]){
                cout << "Test 7: Passed" << endl;
            }else{
                cout << "Test 7: Failed" << endl;
            }
        }else if (i == 1){
            if(db.getNPCXPos(i+1) == xPos[i]
              && db.getNPCYPos(i+1) == yPos[i]
              && db.getNPCHp(i+1) == hp[i]){
                cout << "Test 8: Passed" << endl;
            }else{
                cout << "Test 8: Failed" << endl;
            }
        }else{
            if(db.getNPCXPos(i+1) == xPos[i]
              && db.getNPCYPos(i+1) == yPos[i]
              && db.getNPCHp(i+1) == hp[i]){
                cout << "Test 9: Passed" << endl;
            }else{
                cout << "Test 9: Failed" << endl;
            }
        }
    }
}



int main(){
    Database db("RougelikeV5.db");
//     db.addPlayerEntry("Jack", 12,12,12,12,12,12);
//     testingItemsTable();
//     testingMapTable();
//     db.addNewMapEntry("Map1.txt");
//     db.printMapContents();
//     db.getMapFileName(1);
    testItemsTable();
    testMapTable();
    testNPCTable();
    testPlayerTable();
    return 0;
}
