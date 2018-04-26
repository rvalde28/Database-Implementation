#include <cstdlib>
#include <fstream>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include "Record.h"
#include "Table.h"
#include "Database.h"
#include "json.hpp"

/* Parser option 1 to handle file size */

using json = nlohmann::json;
using namespace std;

bool no_bracket(std::string str)
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
}

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

void add_nested_tables_to_database(Database db, std::string filename, std::string name_of_table)
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
}

Database construct_table(Database db, std::string filename)
{
  Table table;
  std::ifstream ifs{filename};
  int max = 100;
  int count = 1;
  auto parsed_json = json::parse(ifs);
  while (!ifs.eof() || count != max) {
	  for (json::iterator it = parsed_json.begin(); it != parsed_json.end(); ++it) {
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
			  table.add_attribute(key_str);
			  std::string name_of_nested_table = name_of_table(filename) + "_" + key_str;
			  std::string name_of_json_file = name_of_nested_table + ".json";
			  Record r;
			  r.set(0, name_of_nested_table);
			  table.insert_record(r);
			  std::ofstream ofs{name_of_json_file};
			  ofs << val_str << std::endl;
			  ofs.close();
			  add_nested_tables_to_database(db, name_of_json_file, name_of_nested_table);
		  }
		  count += 1;
	  }
	  filename = filename + std::to_string(count);
	  db.add_table(filename, table);
  }
		  ifs.close();
		  return db;
  }

int main()
{
  Database db;
    db = construct_table(db, "test.json");
  //db = construct_table(db, "user.json");
  //db = construct_table(db, "business.json");
}
