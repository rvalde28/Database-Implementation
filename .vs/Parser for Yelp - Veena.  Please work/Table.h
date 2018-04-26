#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <regex>
#include "Record.h"

using namespace std;

#ifndef TABLE_H
#define TABLE_H

class Table
{
    public:
	vector <Record> table_rows;	
	vector <string> attributes;
	map <string, vector <string> > map_table;
	int key_index;
	int key_specified = 0;
	
	Table();
	Table(Record r);
	Table(vector <string> attributes);
	Table(string key, Record r);
	~Table();
	Table(const Table &t);
	
	int get_size();
	Record get_record(int i);
	int delete_record(string key);
	int delete_attribute(string a);
	void insert_record(Record r);
	void add_attribute(string a);
	vector <string> get_attributes();
	void specifyKey(string key);
	Table cross_join(Table t);
	Table natural_join(Table t);
	int count(string a);
	int max(string a);
	int min(string a);
	vector <int> get_indices(smatch matches);
				
};

#endif
