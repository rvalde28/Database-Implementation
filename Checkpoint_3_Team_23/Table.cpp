#include "Table.h"

Table::Table()
{
	record_container = {};
	attributes = {};
}

Table::Table(const Table& t)
{
	attributes = t.attributes;
	record_container = t.record_container;
	_size = 0;
}

Table::Table(vector<string> value)
{
	for (int iterator = 0; iterator < value.size(); iterator++){
		Attribute a;
		a.attribute = value.at(iterator);
		a.value_attr = "";

		attributes.push_back(a);
		_size++;
	}

	attributes = {};
	record_container = {};
}

Table::Table(int size)
{
	_size = size;
}

void Table::add_attribute(std::string table_attribute)
{
	Attribute a;
	a.attribute = table_attribute;
	a.value_attr = "";
	attributes.push_back(a);
	_size++;
}

void Table::delete_attribute(std::string table_attribute)
{	
	int attributes_index;
	for (int attr_iterator = 0; attr_iterator < attributes.size(); attr_iterator++) {
		if (attributes.at(attr_iterator).attribute == table_attribute) {
			attributes_index = attr_iterator;
		}
	}
	attributes.erase(attributes.begin() + attributes_index);

	return;
}

std::vector<std::string> Table::get_attribute_in_order() {
	vector<string> attribute_values;

	for (int i = 0; i < attributes.size(); i++) {
		attribute_values.push_back(attributes.at(i).attribute);
	}

	return attribute_values;
}

//returns the number of records in the table
int Table::get_size()
{
	return record_container.size();
}

//a way to iterate through the table to get a Record
Record Table::record_iterator(int index) {
	return  record_container.at(index);
}

void Table::specify_key(std::string key_attribute)
{
	for (int i = 0; i < attributes.size(); i++) {
		if (attributes.at(i).attribute == key_attribute) {
			attributes.at(i).value_attr = "Key";
		}
	}
}

//function to implement cross join
Table Table::cross_join(Table a, Table b) {
	Table t;
    
    //for loops to iterate through vector or attributes
	for (int i = 0; i < a.attributes.size(); i++) {
		for (int j = 0; j < b.attributes.size(); j++) {

			t.attributes.push_back(b.attributes.at(j));

		}

		t.attributes.push_back(a.attributes.at(i));

	}

    //for loops to iterate through vector of records
	for (int i = 0; i < a.record_container.size(); i++) {
		for (int j = 0; j < b.record_container.size(); j++) {

			t.record_container.push_back(b.record_container.at(j));

		}

		t.record_container.push_back(a.record_container.at(i));

	}

}

//function to implement natural join
Table Table::natural_join(Table a, Table b) {
	Table t;
    
    //values to identify the locations for matching attributes in tables
	int a_attribute_location;
	int b_attribute_location;
    
    //for loop to iterate through attributes
	for (int i = 0; i < a.attributes.size(); i++) {
		for (int j = 0; j < b.attributes.size(); j++) {
            
            //identifies if location in a matches location in b
			if (a.attributes[i].attribute == b.attributes[j].attribute) {

                //sets the current locations to the matching attribute varaibles
				a_attribute_location = i;
				b_attribute_location = j;

                //pushback the matching attributes into new table
				t.attributes.push_back(a.attributes[i]);

                //pushbacks all attributes in table a (minus the matching)
				for (int k = 0; k < a.attributes.size() && k != a_attribute_location; k++) {

					t.attributes.push_back(a.attributes[k]);

				}
                
                //pushbacks all attributes in table b (minus the matching)
				for (int l = 0; l < b.attributes.size() && l != b_attribute_location; l++) {

					t.attributes.push_back(b.attributes[l]);

				}

				break;
			}
		}
	}

    //assisns the locations for matching attributes in tables to a new varaible
	int a_record_location = a_attribute_location;
	int b_record_location = b_attribute_location;

    //for loop to iterate through records
	for (unsigned int a_record_iterator = 0; a_record_iterator < a.record_container.size(); a_record_iterator++) {
		for (unsigned int b_record_iterator = 0; b_record_iterator < b.record_container.size(); b_record_iterator++) {

            //pushbacks all records in table a (minus the matching)
			for (int i = 0; i < a.record_container.size() && i != a_record_location; i++) {

				t.record_container.push_back(a.record_container[i]);

			}
            
            //pushbacks all records in table b (minus the matching)
			for (int j = 0; j < b.record_container.size() && j != b_record_location; j++) {

				t.record_container.push_back(b.record_container[j]);

			}
		}
	}

}

//computes count
int Table::compute_count(string table_attribute) {

	int count;
	int index_location;
    
    //for loop to find the location of the specified table attribute
	for (int i = 0; i < record_container.size(); i++) {

		if (attributes[i].attribute == table_attribute) {

			index_location = i;
		}
	}

	Record temp_record;
    
    //for loop to count how many times the table attribute appears
	for (int i = 0; record_container.size(); i++) {
		temp_record = record_container.at(i);

		if (temp_record.get(index_location) != "") {
			count++;
		}
	}

	return count;
}

//computes minimum record
string Table::compute_min(string table_attribute) {

	string minimum_value = "";
	int selection_location;

	for (int i = 0; i < attributes.size(); i++) {
		if (attributes[i].attribute == table_attribute) {
			selection_location = i;
		}
		break;
	}

	for (int j = 0; j < record_container.size(); j++) {
		Record temp_record = record_container.at(j);
		
		if (minimum_value == "") {
			minimum_value = temp_record.get(selection_location);
		}
		else if ((temp_record.get(selection_location) < minimum_value) &&
			(temp_record.get(selection_location) != "")){
			minimum_value = temp_record.get(selection_location);
		}
		else {

		}

	}

	return minimum_value;
}

//computes maximum record
string Table::compute_max(string table_attribute) {

	string maximum_value = "";
	int selection_location;

	for (int i = 0; i < attributes.size(); i++) {
		if (attributes[i].attribute == table_attribute) {
			selection_location = i;
		}
		break;
	}

	for (int j = 0; j < record_container.size(); j++) {
		Record temp_record = record_container.at(j);

		if (maximum_value == "") {
			maximum_value = temp_record.get(selection_location);
		}
		else if ((temp_record.get(selection_location) > maximum_value) &&
			(temp_record.get(selection_location) != "")) {
			maximum_value = temp_record.get(selection_location);
		}
		else {

		}

	}

	return maximum_value;
}

void Table::add_record(Record r)
{
	record_container.push_back(r);
}

/*Extra credit functions*/

int Table::get_number_attributes() {
	return attributes.size();
}

void Table::rename_attribute(string find, string replace) {
	for (int find_iterator = 0; find_iterator < attributes.size(); find_iterator++) {
		if (attributes.at(find_iterator).attribute == find) {
			attributes.at(find_iterator).attribute = replace;
			return;
		}
	}
	std::cout << "Attribute not found" << std::endl;

}

void Table::specify_key(vector<string> key_values) {
	for (int i = 0; i < attributes.size(); i++) {
		for (int j = 0; j < key_values.size(); j++) {
			if (attributes.at(i).attribute == key_values.at(j)) {
				attributes.at(i).value_attr = "Key";
			}
		}
	}
}
