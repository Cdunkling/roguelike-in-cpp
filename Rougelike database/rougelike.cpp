#include <iostream>
#include <string>
using namespace std;
#include "libsqlite.hpp"

int main()
{
//     string database = "rougelike.db";
    sqlite3 *db;
    int connection;
    

    try
    {
        connection = sqlite3_open("rougelike.db", &db);
        
       if( connection ){
          fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
          return(0);
       }else{
          fprintf(stderr, "Opened database successfully\n");
       }
//         sqlite::sqlite db( database );
//         auto cur = db.get_statement();
        
    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}