#include <iostream>
#include <string>
using namespace std;
#include "libsqlite.hpp"
// When compiling make sure to add -sqlite3 at the end.
// e.g. g++ --std=c++11 rougelike.cpp - 0 rougelike -sqlite3
class Database{
    
    public:
        string dbName;
        //Getters
        string get_name(int id)
        {
            try{
                //Connect to Database
                sqlite::sqlite db(dbName);
                auto cur = db.get_statement();
                //SQL Statement
                cur->set_sql("select name from player where id = ?");
                cur->prepare();
                cur->bind(1, id);
                cur->step();
                return cur->get_text(0);
            }catch(sqlite::exception e){
                cerr<< e.what() << endl;
            }
            
        }

        int get_score(int id)
        {
            try{
                sqlite::sqlite db(dbName);
                auto cur = db.get_statement();
                cur->set_sql("select score from player where id = ?");
                cur->prepare();
                cur->bind(1, id);
                cur->step();
                return cur->get_int(0);
            }catch (sqlite::exception e){
                cerr << e.what() << endl;
            }
            
        }
        int get_dungeon_level(int id)
        {
            try{
               sqlite::sqlite db(dbName);
                auto cur = db.get_statement();
                cur->set_sql("select dungeon from player where id = ?");
                cur->prepare();
                cur->bind(1, id);
                cur->step();
                return cur->get_int(0); 
            }catch (sqlite::exception e){
                cerr << e.what() << endl;
            }
            
        }
        int get_coX(int id)
        {
            try{
                sqlite::sqlite db(dbName);
                auto cur = db.get_statement();
                cur->set_sql("select CoX from player where id = ?");
                cur->prepare();
                cur->bind(1, id);
                cur->step();
                return cur->get_int(0);
            }catch(sqlite::exception e){
                cerr << e.what() << endl;
            }
            
        }
        int get_coY(int id)
        {
            try{
                sqlite::sqlite db(dbName);
                auto cur = db.get_statement();
                cur->set_sql("select CoY from player where id = ?");
                cur->prepare();
                cur->bind(1, id);
                cur->step();
                return cur->get_int(0);
            }catch(sqlite::exception e){
                cerr << e.what() << endl;
            }

        }
    
        //setters
        void set_name(int id, string name)
        {
            try{
                sqlite::sqlite db(dbName);
                auto cur = db.get_statement();
                cur->set_sql("update player set name = ? where id = ?");
                cur->prepare();
                cur->bind(1, name);
                cur->bind(2, id);
                cur->step();
            } catch( sqlite::exception e )      // catch all sql issues
            {
                std::cerr << e.what() << std::endl;
            }
        }

        void set_score(int id, int score)
        {
            try{
                sqlite::sqlite db(dbName);
                auto cur = db.get_statement();
                cur->set_sql("update player set score = ? where id = ?");
                cur->prepare();
                cur->bind(1, score);
                cur->bind(2, id);
                cur->step();
            } catch( sqlite::exception e )      // catch all sql issues
            {
                std::cerr << e.what() << std::endl;
            }
        }
        void set_dungeon(int id, int dungeon)
        {
            try{
                sqlite::sqlite db(dbName);
                auto cur = db.get_statement();
                cur->set_sql("update player set name = ? where id = ?");
                cur->prepare();
                cur->bind(1, dungeon);
                cur->bind(2, id);
                cur->step();
            } catch( sqlite::exception e )      // catch all sql issues
            {
                std::cerr << e.what() << std::endl;
            }
        }
        void set_coX(int id, int coX)
        {
            try{
                sqlite::sqlite db(dbName);
                auto cur = db.get_statement();
                cur->set_sql("update player set CoX = ? where id = ?");
                cur->prepare();
                cur->bind(1, coX);
                cur->bind(2, id);
                cur->step();
            } catch( sqlite::exception e )      // catch all sql issues
            {
                std::cerr << e.what() << std::endl;
            }
        }

        void set_coY(int id, int coY)
        {
            try{
                sqlite::sqlite db(dbName);
                auto cur = db.get_statement();
                cur->set_sql("update player set CoY = ? where id = ?");
                cur->prepare();
                cur->bind(1, coY);
                cur->bind(2, id);
                cur->step();
            } catch( sqlite::exception e )      // catch all sql issues
            {
                std::cerr << e.what() << std::endl;
            }
        }
        void new_entry(string name, int score, int dungeon, int coX, int coY)
        {
            try{
                sqlite::sqlite db (dbName);
                auto cur = db.get_statement();
                cur->set_sql("INSERT INTO PLAYER (Name, Score, Dungeon, CoX, CoY) VALUES (?,?,?,?,?)");
                cur->prepare();
                cur->bind(1,name);
                cur->bind(2, score);
                cur->bind(3, dungeon);
                cur->bind(4, coX);
                cur->bind(5, coY);
                cur->step();
            }catch (sqlite:: exception e){
                cerr << e.what() << endl;
            }
        }
};


int main(){
    Database playerDB;
    playerDB.dbName = "rougelikeV2.db";
    cout << playerDB.get_name(1) << endl;
    
}