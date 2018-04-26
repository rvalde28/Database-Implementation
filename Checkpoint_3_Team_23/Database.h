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
    vector<Table> database;
    vector<std::string> names_of_table;
public:
    Database();
    Database(const Database &d);
    ~Database();
    void add_table(Table object, std::string name);
    void drop_table(std::string name);
    int size();
    vector<std::string> list_table();
    vector<Table> get_table();
    Table query_command(std::string select, std::string from, std::string where);

    /*Extra Credit Functions*/
    void save_function(string save_file);
    void load_function(string open_file);
    void merge_database(Database d);
  };
}
#endif
