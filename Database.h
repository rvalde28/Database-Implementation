#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <regex>
#include "Table.cpp"

namespace db{
class Database{
  /*
  * Database provides functionality of storing tables, adding and dropping tables,
  * querying tables for records, and returning the size of the database.
  */
    //Database of tables and the names of the tables
    vector<Table> database;
    vector<std::string> names_of_table;
public:
    //constructor
    Database();
    //copy constructor
    Database(const Database &d);
    //destructor
    ~Database();
    //add table to database
    void add_table(Table object, std::string name);
    //remove table from database
    void drop_table(std::string name);
    //get size of database
    int size();
    //get list of all names of tables
    vector<std::string> list_table();
    //get all tables
    vector<Table> get_table();
    //find the table of interest
    Table query_command(std::string select, std::string from, std::string where);

    /*Extra Credit Functions*/
    //save database
    void save_function(string save_file);
    //load database from memory
    void load_function(string open_file);
    //merge databases
    void merge_database(Database d);
  };
}
#endif
