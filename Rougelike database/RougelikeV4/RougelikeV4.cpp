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
    int getDungeonID(int id){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            //SQL Statement
            cur->set_sql("SELECT dungeonID FROM PLAYER WHERE playerID = ?");
            cur->prepare();
            cur->bind(1, id);
            cur->step();
            return cur->get_int(0);
        }catch(sqlite::exception e){
            cerr<< e.what() << endl;
        }
    }
    int getHP(int id){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            //SQL Statement
            cur->set_sql("SELECT dungeonID FROM PLAYER WHERE playerID = ?");
            cur->prepare();
            cur->bind(1, id);
            cur->step();
            return cur->get_int(0);
        }catch(sqlite::exception e){
            cerr<< e.what() << endl;
        }
    }
    int getScore(int id){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            //SQL Statement
            cur->set_sql("SELECT dungeonID FROM PLAYER WHERE playerID = ?");
            cur->prepare();
            cur->bind(1, id);
            cur->step();
            return cur->get_int(0);
        }catch(sqlite::exception e){
            cerr<< e.what() << endl;
        }
    }
    
    //Player Setter Methods
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
        } catch( sqlite::exception e )      // catch all sql issues
        {
            std::cerr << e.what() << std::endl;
        }
    }
    
    void setPlayerYPos(int id, int yPos)
    {
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            cur->set_sql("UPDATE PLAYER SET xPos = ? WHERE playerID = ?");
            cur->prepare();
            cur->bind(1, yPos);
            cur->bind(2, id);
            cur->step();
        } catch( sqlite::exception e )      // catch all sql issues
        {
            std::cerr << e.what() << std::endl;
        }
    }
    
    void playerSetDungeonID(int id, int xPos)
    {
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            cur->set_sql("UPDATE PLAYER SET dungeonID = ? WHERE playerID = ?");
            cur->prepare();
            cur->bind(1, xPos);
            cur->bind(2, id);
            cur->step();
        } catch( sqlite::exception e )      // catch all sql issues
        {
            std::cerr << e.what() << std::endl;
        }
    }
    
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
        } catch( sqlite::exception e )      // catch all sql issues
        {
            std::cerr << e.what() << std::endl;
        }
    }
    
    void setScore(int id, int score)
    {
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            cur->set_sql("UPDATE PLAYER SET xPos = ? WHERE playerID = ?");
            cur->prepare();
            cur->bind(1, score);
            cur->bind(2, id);
            cur->step();
        } catch( sqlite::exception e )      // catch all sql issues
        {
            std::cerr << e.what() << std::endl;
        }
    }
    
    //Getter methods for map table
    
    string getMapFileName(int id){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            cur->set_sql("SELECT fileName FROM Map WHERE dungeonID = ?");
            cur->prepare();
            cur->bind(1, id);
            cur->step();
            return cur->get_text(0);
        } catch( sqlite::exception e )      // catch all sql issues
        {
            std::cerr << e.what() << std::endl;
        }
    }
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
    void addNewMap(string fileName){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            cur->set_sql("INSERT INTO MAP (fileName) VALUES (?)");
            cur->prepare();
            cur->bind(1, fileName);
            cur->step();
        } catch( sqlite::exception e )      // catch all sql issues
        {
            std::cerr << e.what() << std::endl;
        }
    }
    
    //Getter methods for NPC table
    
    int getXPos(int id){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            //SQL Statement
            cur->set_sql("SELECT xPos FROM NPC WHERE monsterID = ?");
            cur->prepare();
            cur->bind(1, id);
            cur->step();
            return cur->get_int(0);
        }catch(sqlite::exception e){
            cerr<< e.what() << endl;
        }
    }
    int getYPos(int id){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            //SQL Statement
            cur->set_sql("SELECT FROM Npc WHERE monsterID = ?");
            cur->prepare();
            cur->bind(1, id);
            cur->step();
            return cur->get_int(0);
        }catch(sqlite::exception e){
            cerr<< e.what() << endl;
        }
    }
    
    // NPC setter methods
    void setNPCXPos(int id, int xPos)
    {
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            cur->set_sql("UPDATE PLAYER SET xPos = ? WHERE playerID = ?");
            cur->prepare();
            cur->bind(1, xPos);
            cur->bind(2, id);
            cur->step();
        } catch( sqlite::exception e )      // catch all sql issues
        {
            std::cerr << e.what() << std::endl;
        }
    }
    
    void setNPCYPos(int id, int yPos)
    {
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            cur->set_sql("UPDATE PLAYER SET xPos = ? WHERE playerID = ?");
            cur->prepare();
            cur->bind(1, yPos);
            cur->bind(2, id);
            cur->step();
        } catch( sqlite::exception e )      // catch all sql issues
        {
            std::cerr << e.what() << std::endl;
        }
    }
    
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
        } catch( sqlite::exception e )      // catch all sql issues
        {
            std::cerr << e.what() << std::endl;
        }
    }
    
    void printPlayerContents(){
        try{
            sqlite::sqlite db(dbName);
            auto cur = db.get_statement();
            cur->set_sql("SELECT * FROM Player");
            cur->prepare();
            cout << "PLayer Table" << endl;
            while (cur->step()){
                cout << "ID: " << cur->get_int(0) << " XPos: " << cur->get_text(1) << " YPos: "<< cur->get_text(1);
                cout << " DungeonID: " << cur->get_int(0) << " HP: " << cur->get_int(0) << " Score: " << cur->get_int(0)<< endl;
            }
        } catch( sqlite::exception e )      // catch all sql issues
        {
            std::cerr << e.what() << std::endl;
        }
    }
    
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
        } catch( sqlite::exception e )      // catch all sql issues
        {
            std::cerr << e.what() << std::endl;
        }
    }
    
    string getDBName(){
        return dbName;
    }
    
    private:
    string dbName;
    
};

int main(){
    
    Database rougelike("rougelikeV4.db");
    rougelike.printPlayerContents();
    rougelike.printPlayerContents();
    rougelike.printNPCContents();
    rougelike.printMapContents();
    
    return 0;
}