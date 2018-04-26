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

class db::Table {
	/*
	* The tables will support vectors, adding vectors, removing vectors,
	* the names of the attributes and the records associated with the attributes
	* iterator, and query functions that will help create the Database query and help with parsing. 
	*/
protected:
    //size of table
	int _size;
    //vector of records
	std::vector<Record> record_container;
    //vector of attributes
	std::vector<Attribute> attributes;
public:
    //constructor
	Table();
    //copy constructor
	Table(const Table& t);
    //initialize based on size of table
	Table(int size);
    //string for attributes put in table
	Table(vector<std::string> _attributes);
    //add attributes to table
	void add_attribute(std::string table_attribute);
    //remove attributes from table
	void delete_attribute(std::string table_attribute);
    //get_attributes_in_order
    std::vector<Attribute> get_attribute_in_order();
    //find record based on index
	Record record_iterator(int index);
    //get size of table
	int get_size();
    //get all attributes in table
	int get_attr_size();
    //find key basedo n specific string
	void specify_key(std::string table_key);
    //Join two tables using indices
	Table cross_join(Table a, Table b);
    //Join two tables and keep all elements
	Table natural_join(Table a, Table b);
    //compute number of records
	int compute_count(std::string table_attribute);
    //compute minimum attribute
	string compute_min(std::string table_attribute);
    //compute maximum attribute
	string compute_max(std::string table_attribute);
    //add record to table
	void add_record(Record r);
    //get all attributes
	int get_number_attributes();
    //rename specific attribute
	void rename_attribute(std::string find, std::string replace);
    //find key
	void specify_key(std::vector<std::string> key_values);
    //query functions used for finding location in column
	Table query(std::vector<std::string> columns, std::string where);
    //create the record accessed
	std::string create_record_string(const Record& r, std::string col) const;
    //create table
	Record create_Record_in_Table(const Record& r, std::vector<std::string> colNames) const;
	};
}

#endif
