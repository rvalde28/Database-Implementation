#include "Record.h"

namespace db{
//Record default constructors intialized Record variables
Record::Record()
{
	record_container = std::vector<string>();
	vector_size = 0;
}

//Record copy constructor
Record::Record(const Record& record_object)
{
	//initialize the Record vector
	vector_size = record_object.vector_size;
	record_container = record_object.record_container;
}

//Record constructor given a set size for the record container
Record::Record(int size)
{
	//cant initialize a vector if a negative size is given
	if (size < 0) {
		cout << "Size of record has to be 0 or greater. Size inputed is "
			 << size
			 << "." << endl;
		return;
	}

	//initialize the record given the specified size
	for (int initialize_iterator = 0; initialize_iterator < size; initialize_iterator++) {
		record_container.push_back("");
	}
}

//Record deconstructor, clears the variables used
Record::~Record()
{
	record_container.clear();
	vector_size = 0;
}

//returns the size of the record container
int Record::size()
{
	return record_container.size();
}

//returns the string in the record container at the specified index
std::string Record::get(unsigned int index)
{
	//checks to see if the index is accessible to return the value
	if (record_container.size() >= index) {
		return record_container.at(index);
	}
	else {
		cout << "THe location you are looking for does not exist" << endl;
	}
}

//sets a string at the specified index in the record container
void Record::set(int index, std::string name)
{
	//resizes the size of the container if the
	//index cant be accessed then sets the string
	//at that index
	if (record_container.size() <= index) {
		record_container.resize(index+1);
		record_container.at(index) = name;
	}
	else {
		record_container.at(index) = name;
	}
}

Record::Record(std::vector<std::string> record_vec)
{
	/*
	* Records created for vector of records.
	*/
	for (int i = 0; i < record_vec.size(); i++)
	{
		record_container.push_back(record_vec[i]);
	}
}
}
