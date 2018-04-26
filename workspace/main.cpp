#include<iostream>
//#include "testRecord.cpp"
//#include "testTable.cpp"
//#include "testRecord.cpp"

using namespace std;

int testDatabase() {
    cout << "- - - - Test Database - - - -\n";
    return 4;
}

int testTable() {
    cout << "- - - - Test Table - - - -\n";
    return 4;
}

int testRecord() {
    cout << "- - - - Test Record - - - -\n";
    return 4;
}

int main() {
    //Database databaseOne;
    cout << "A: Test Database" << endl;
    cout << "B: Test Table" << endl;
    cout << "C: Test Record" << endl;
    cout << "D: Test All" << endl << endl;
    cout << "Choose an option: ";
    char option;
    while(cin >> option) {
        switch(option) {
        case 'A':
            cout << "Selected A" << endl;
            cout << "TESTS FAILED: " << testDatabase() << endl << endl;
            break;
        case 'B':
            cout << "Selected B" << endl;
            cout << "TESTS FAILED: " << testTable() << endl << endl;
            break;
        case 'C':
            cout << "Selected C" << endl;
            cout << "TESTS FAILED: " << testRecord() << endl << endl;
            break;
        case 'D':
            cout << "Selected E" << endl;
            cout << "TESTS FAILED: " << (testDatabase() + testTable() + testRecord()) << endl << endl;
            break;
        default: cout << "Invalid selection" << endl;
        }
        
        cout << "A: Test Database" << endl;
        cout << "B: Test Table" << endl;
        cout << "C: Test Record" << endl;
        cout << "D: Test All" << endl << endl;
        cout << "Choose an option: ";
    }
    
    
}