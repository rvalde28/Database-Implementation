#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <functional>

using namespace std;

namespace db{
class Record{
protected:
  //Arbitrary size of Record
    int vector_size;
    std::vector<string> record_container;
public:
    Record();
    Record(int size);
    Record(const Record& r);
    Record(std::vector<std::string> record_vec);
    ~Record();

    int size();
    //entries into the record
    //get the record string
    string get(unsigned int str);
    void set(int index, string name);
};
}

#endif
