#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <vector>
#include <map>
#include <iterator>
#include "Parser.cpp"
#include "Record.cpp"

namespace db{
namespace parser {
	/*
	* The parser is used in the Table.
	*/
	class Parser;
}
struct Attribute {
	/*
	* The attribute has the name of the attribute and whether it is a key or not.
	*/
	std::string attribute;
	std::string value_attr;
};

class Table {
	/*
	* The tables will support vectors, adding vectors, removing vectors,
	* the names of the attributes and the records associated with the attributes
	* iterator, and query functions that will help create the Database query and help with parsing. 
	*/
protected:
	int _size;
	std::vector<Record> record_container;
	std::vector<Attribute> attributes;
public:
	Table();
	Table(const Table& t);
	Table(int size);
	Table(vector<std::string> _attributes);
	void add_attribute(std::string table_attribute);
	void delete_attribute(std::string table_attribute);
	std::vector<Attribute> get_attribute_in_order();
	Record record_iterator(int index);
	int get_size();
	int get_attr_size();
	void specify_key(std::string table_key);
	Table cross_join(Table a, Table b);
	Table natural_join(Table a, Table b);
	int compute_count(std::string table_attribute);
	string compute_min(std::string table_attribute);
	string compute_max(std::string table_attribute);
	void add_record(Record r);
	int get_number_attributes();
	void rename_attribute(std::string find, std::string replace);
	void specify_key(std::vector<std::string> key_values);
	Table query(std::vector<std::string> columns, std::string where);
	std::string create_record_string(const Record& r, std::string col) const;
	Record create_Record_in_Table(const Record& r, std::vector<std::string> colNames) const;
	};
}

#endif
