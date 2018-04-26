#include "Database.h"

namespace db{
Database::Database()
{
	/*
	*initialized the vector
	*/
	database = vector<Table>();
	names_of_table = vector<std::string>();
}

Database::Database(const Database &d)
{
	/*
	*copied database vectors from one to the other
	*/
	database = d.database;
	names_of_table = d.names_of_table;
}

Database::~Database()
{
	/*
	* Remove all the elements of the database
	*/
  for (int i = names_of_table.size(); i >= 0; i--)
  {
      names_of_table.erase(names_of_table.begin() + i);
  }
  for (int i = database.size(); i >= 0; i--)
  {
    database.erase(database.begin()+i);
  }
}

void Database::add_table(Table object, std::string name)
{
	/*
	* Add new table to database and to names of tables.  Allows for copies to be inserted.
	*/
		names_of_table.push_back(name);
		database.push_back(object);
}

void Database::drop_table(std::string name)
{
	/*
	* Remove table from database and from names of tables.
	*/
	for (unsigned int i = 0; i < names_of_table.size(); i++)
	{
		if (names_of_table[i] == name)
		{
      names_of_table.erase(names_of_table.begin() + i);
      database.erase(database.begin() + i);
		}
		else
		{
			continue;
		}
	}
}


vector<std::string> Database::list_table()
{
	/*
	* Return all table names
	*/
  return names_of_table;
}

vector<Table> Database::get_table()
{
	/*
	* Return all tables
	*/
  return database;
}

Table Database::query_command(std::string select, std::string from, std::string where)
{
	/*
	* Query table for select elements, from table, and where definition.  The table
	* created will be returned at the end of the program.
	*/
  Table table;
	std::vector<std::string>attr;
	for (int i = 0; i < database.size(); i++)
	{
  	if (names_of_table[i] == from)
  	{
    	table = database[i];
  	}
	}
	if (select == "*")
  {
  std::vector<Attribute>all_attributes = table.get_attribute_in_order();
		for (int i = 0; i < table.get_attr_size(); i++)
  	{
    	std::string attribute = all_attributes[i].attribute;
    	attr.push_back(attribute);
  	}
	}
		else {
			std::regex reg("[^,\\s]+");
			std::sregex_token_iterator iter(select.begin(), select.end(), reg, 0);
			std::sregex_token_iterator end;
			for (; iter != end; ++iter) {
				std::string attr_name_record = *iter;
				attr.push_back(attr_name_record);
			}
		}
		return table.query(attr, where);
}

/*Extra credit functions*/
//function will save at the specified name the database is a csv file
void Database::save_function(string save_file) {

	//name used to save the file.
	string file_name = save_file + ".csv";
	ofstream outputFile(file_name);

	//get number of tables in the database
	int number_of_tables = database.size();

	vector<int> rows_table;
	vector<int> columns_table;
	bool attributes_set = false;

	//initializes the rows_table and columns_table vectors
	for (int i = 0; i < database.size(); i++) {
		Table tableObj = database.at(i);

		//gets the size of the table's rows and columns
		int rows_size = tableObj.get_size();
		int columns_size = tableObj.get_number_attributes();

		rows_table.push_back(rows_size);
		columns_table.push_back(columns_size);
	}

	//keeps the new file open and keeps adding stuff to the files
	if (outputFile.is_open()) {
		for (int i = 0; i < number_of_tables; i++) {
			Table obj = database.at(i);

			//sets the table name in the csv with a marker ':' to specify that
			//it is a table name
			outputFile << ":" + names_of_table.at(i) + "\n";


			for (int j = 0; j < obj.get_size(); j++) {
				Record temp = obj.record_iterator(j);

				//sets the attributes in the csv with a marker ";" to specify that
				//it is the table attributes
				if (!attributes_set) {
					vector<Attribute> table_attr = obj.get_attribute_in_order();
					vector<string> tableAttributes;
					for (int i = 0; i < table_attr.size(); i++)
					{
						tableAttributes.push_back(table_attr[i].attribute);
					}
					outputFile << ";";
					for (int k = 0; k < obj.get_number_attributes(); k++) {
						outputFile << tableAttributes.at(k) + ",";
					}
					outputFile << "\n";
					attributes_set = true;
				}

				//sets the records in the csv file no marker is needed
				for (int k = 0; k < temp.size(); k++) {

					outputFile << temp.get(k) + ",";
				}
				outputFile << "\n";

			}
			//this marker will state that a table has finished
			outputFile << "New-Table \n";
			attributes_set = false;
		}
	}

	outputFile.close();

}

//loads a csv and creates a database with is using the specified format
//for the title the marker is a ':' in the first cell
//for the attribuets the ';' in the first cell
//and when a new table is specified then "New-Table" is in a new row
void Database::load_function(string target_file) {
	//string used to concatenate characters to it
	string line;
	ifstream inputFile (target_file);

	//opens the target file
	if (inputFile.is_open()) {
		Table t1;

		//gets lines from the cvs file
		while (getline(inputFile, line)) {

			//this sets the title of the table
			if (line[0] == ':') {
				string tableName = line.substr(1, line.size());

				names_of_table.push_back(tableName);

			}
			//this sets the attributes of the table
			else if (line[0] == ';') {
				string tableattr = line.substr(1, line.size());
				string attr;
				int counter = 0;

				//the csv splits the cell in a row by ',' so this loop
				//splits the attributes by ',' and pushes the attribute
				for (int i = 0; i < tableattr.size(); i++) {
					//pushes the attributes into the table
					if (tableattr.at(i) == ',') {
						t1.add_attribute(attr);
						attr = "";
						counter++;
					}
					//concatenates characters into the string
					else {
						attr = attr + tableattr[i];
					}
				}

			}
			//this pushes a new table into the database
			else if (line == "New-Table ") {
				database.push_back(t1);
				t1.~Table();
			}
			//this condition splts the records by ',' and puts them
			//in the record
			else {
				string tokens;
				Record r1;

				//counter to keep track at what index the record is in
				int counter = 0;

				//loop that sets cells in the record by concatenating
				//characters until a ',' is found
				for (int i = 0; i < line.size(); i++) {
					//pushes a token in to the record
					if (line.at(i) == ',') {
						r1.set(counter,tokens);
						tokens = "";
						counter++;
					}
					//concatenates the string
					else {
						tokens = tokens + line[i];
					}
				}
				//adds the record to the table
				t1.add_record(r1);
			}
		}
	}
	inputFile.close();
}

//merges two databases together
void Database::merge_database(Database target_database) {
	//get the names of the table and database tables in a vector
	vector<string> table_names = target_database.list_table();
	vector<Table> database_tables = target_database.get_table();

	//pushes back the names in table_names vector into the current database
	for (int i = 0; i < table_names.size(); i++) {
		names_of_table.push_back(table_names.at(i));
	}

	//pushed back the tables of the target databse into the current database.
	for (int i = 0; i < database_tables.size(); i++) {
		database.push_back(database_tables.at(i));
	}
}

int Database::size()
{
	/*
	* Return number of tables present
	*/
  return database.size();
}
}
