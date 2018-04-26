#include<string>
#include<vector>

using namespace std;

#ifndef RECORD_H
#define RECORD_H

class Record
{
	public:
		vector<string> records;
		Record(int size);
		Record();
		~Record();
		int size();
		void set(int index, string entry);
		string get(int index);

};

#endif
