#include "Table.h"
#include "Record.h"
#include "Expression.h"
#include <vector>

#ifndef DB_H
#define DB_H

class Database{
	vector<string> names;
	vector<Table> tables;
	public:
	Database();
	Database(const Database & db);
	~Database();
	int add_table(string name, Table add_table);
	int drop_table(string drop_table);
	vector<string> list_tables();
	vector<Table> get_tables();
	Table query(string SELECT, string FROM, string WHERE);
};

#endif
