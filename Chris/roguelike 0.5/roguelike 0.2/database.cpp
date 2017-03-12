#include <iostream>
#include <string>
#include "database.h"
#include "libsqlite.hpp"
using namespace std;

void Database::set_dbname(string name) { dbName = name; }

        string Database:: get_name(int id)
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

        int Database::get_score(int id)
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
        int Database::get_dungeon_level(int id)
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
        int Database::get_coX(int id)
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
        int Database::get_coY(int id)
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
        void Database::set_name(int id, string name)
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

        void Database::set_score(int id, int score)
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
        void Database::set_dungeon(int id, int dungeon)
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
        void Database::set_coX(int id, int coX)
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

        void Database::set_coY(int id, int coY)
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
        void Database::new_entry(string name, int score, int dungeon, int coX, int coY)
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



