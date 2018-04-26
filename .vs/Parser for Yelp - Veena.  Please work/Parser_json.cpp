#include <cstdlib>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <typeinfo>
#include <algorithm>
#include <iterator>
#include "Record.h"
#include "Table.h"
#include "Database.h"
#include "json.hpp"

/* Parser option 1 to handle file size */

using json = nlohmann::json;
using namespace std;

/*bool no_bracket(std::string str)
{
	std::size_t found = str.find("{");
    if (found < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}*/

/*void add_nested_tables_to_database(Database db, std::string filename, std::string name_of_table)
{
	Table table;
	std::ifstream ifs{filename};
	std::string s = ".json";
	std::string::size_type i = filename.find(s);
	if (i != std::string::npos)
	{
		filename.erase(i, s.length());
	}
	filename = filename;
	auto parsed_json = json::parse(ifs);
	for (json::iterator it = parsed_json.begin(); it != parsed_json.end(); ++it) {
		auto key = it.key();
		std::string key_str = key.c_str();
		auto val_str = parsed_json[key_str].get<std::string>();
		if (no_bracket(val_str) == true)
		{
			table.add_attribute(key_str);
			Record r;
			r.set(0, val_str);
			table.insert_record(r);
		}
		else
		{
			table.add_attribute(key_str);
			std::string name_of_nested_table = filename + "_" + key_str;
			std::string name_of_json_file = name_of_nested_table + ".json";
			Record r;
			r.set(0, name_of_nested_table);
			table.insert_record(r);
			json j = it.value();
			std::ofstream ofs(name_of_json_file, std::ofstream::out);
			ofs << val_str << std::endl;
			ofs.close();
			add_nested_tables_to_database(db, name_of_json_file, name_of_nested_table);
		}
	}
	db.add_table(name_of_table, table);
	return;
}*/

std::string name_of_table(std::string filename)
{
  std::string s = ".json";
  std::string::size_type i = filename.find(s);
  if (i != std::string::npos)
  {
	  filename.erase(i, s.length());
  }
  return filename;
}

void construct_table(std::string filename)
{
  std::string name_of_nested_table = name_of_table(filename);
  //Table table;
  //vector<Table>tables_for_db;
  ifstream file(filename);
  //tables_for_db.push_back(table);
  const int lines_count = std::count(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), '\n');
  std::string line;
  int max;
  int count = 0;
  int max_records_per_table = 100;
  if (lines_count > max_records_per_table)
  {
	  max = max_records_per_table;
  }
  else
  {
	  max = lines_count;
  }
  vector<std::string>json_obj;
  for (int i = max; std::getline(file, line); i--)
  {
	  std::istringstream ss(line);
	  std::string token;
	  while(std::getline(ss, token, ','))
	  {
		  json_obj.push_back(token);
	  }
  }
  for (int i = 0; i < json_obj.size(); i++)
  {
	  std::string json_str = json_obj[i];
	  int pos = json_str.find_first_of(':');
	  std::string key_str = json_str.substr(0, pos);
	  std::string val_str = 
  }
     /*auto parsed_json = json::parse(ifs);
	while (!ifs.eof()) {
	  for (json::iterator it = parsed_json.begin(); it != parsed_json.end(); ) {
		  auto key = it.key();
		  std::string key_str = key.c_str();
		  auto val = it.value();
		  std::string val_str = val.get<std::string>();
		  if (no_bracket(val_str) == true)
		  {
			  table.add_attribute(key_str);
			  Record r;
			  r.set(0, val_str);
			  table.insert_record(r);
		  }
		  else
		  {
			 // std::cout<<key_str<<std::endl;
			  table.add_attribute(key_str);
			  std::string name_of_nested_table = filename + "_" + key_str;
			  std::string name_of_json_file = name_of_nested_table + ".json";
			  Record r;
			  r.set(0, name_of_nested_table);
			  table.insert_record(r);
			  //json j = it.value();
			  std::ofstream ofs{name_of_json_file};
			  ofs << val_str << std::endl;
			  ofs.close();
			  add_nested_tables_to_database(db, name_of_json_file, name_of_nested_table);
		  }
		  count += 1;
	  //std::cout<<typeid(it.key()).name()<<" "<<typeid(it.value()).name()<<std::endl;
	  //}
	  //filename = filename + std::to_string(count);
	  //db.add_table(filename, table);
		 // ifs.close();
		  //return db;
		  file.close();
		//  return tables_for_db;*/
  }

int main()
{
	 //Database db;
	construct_table("test.json");
	/* for (int i = 0; i < tables_for_db.size(); i++)
	 {
		 db.add_table(tables_for_db(i));
	 }*/
}
