#include <iostream>
#include <climits>
#include "Record.h"

using namespace std;


int failDefaultConstructor() {
    cout << "- - - - Test Default Contructor - - - -\n";
    Record record;
    if (record.size() != 0) {
        return 1;
    }
    return 0;
}

int failSizeConstructor() {
    cout << "- - - - Test Size Constructor - - - -\n";
    // FIXME: Prototype test negative - don't know how they will handle this, so not sure how to test
    try {
        Record recordNeg(-1);
        cout << "Failed to catch negative size\n";
        return 1;
    }
    catch (...) {
        //pass
    }
    Record record0(0);
    if (record0.size() != 0) {
        cout << "Failed to initialize to 0\n";
        return 1;
    }
    Record record3(3);
    if (record3.size() != 3) {
        cout << "Failed to initialize to 3\n";
        return 1;
    }
    Record recordMAX(INT_MAX);
    if (recordMAX.size() != INT_MAX) {
        cout << "Failed to initialize to int max\n";
        return 1;
    }
    return 0;
}

int failCopyConstructor() {
    cout << "- - - - Test Copy Constructor - - - -\n";
    Record original_record_empty;
    Record copy_record_empty(original_record_empty);
    if (copy_record_empty.size() != original_record_empty.size()) {
        cout << "Failed copy constructor\n";
        return 1;
    }
    Record original_record(4);
    original_record.set(0, "Element 0");
    original_record.set(1, "Element 1");
    original_record.set(2, "Element 2");
    original_record.set(3, "Element 3");
    Record copy_record(original_record);
    if (copy_record.size() != original_record.size()) {
        cout << "Failed copy constructor\n";
        return 1;
    }
    for (int i = 0; i < copy_record.size(); i++) {
        if (copy_record.get(i) != original_record.get(i)) {
            cout << "Failed copy constructor\n";
            return 1;
        }
    }
    return 0;
}

int failSize() {
    cout << "- - - - Test Size  - - - -\n";
    Record record0(0);
    if (record0.size() != 0) {
        cout << "Size failed\n";
        return 1;
    }
    Record record25(25);
    if (record25.size() != 25) {
        cout << "Size failed\n";
        return 1;
    }
    Record recordMAX(INT_MAX);
    if (recordMAX.size() != INT_MAX) {
        cout << "Size failed\n";
        return 1;
    }
    return 0;
}

int failGet() {
    cout << "- - - - Test Get  - - - -\n";
    Record record(3);
    record.set(0, "Element 0");
    if (record.get(0) != "Element 0") {
        cout << "Get failed to return 'Element 0'\n";
        return 1;
    }
    if (record.get(1) != "") {
        cout << "Get failed to return NULL\n";
        return 1;
    }
    record.set(2, "Element 2");
    if (record.get(2) != "Element 2") {
        cout << "Get failed to return 'Element 2'\n";
        return 1;
    }
    return 0;
}

int failSet() {
    cout << "- - - - Test Set  - - - -\n";
    Record record(3);
    record.set(0, "Element 0");
    if (record.get(0) != "Element 0") {
        cout << "Set failed to insert 'Element 0'\n";
        return 1;
    }
    record.set(2, "Element 2");
    if (record.get(2) != "Element 2") {
        cout << "Set failed to insert 'Element 2'\n";
        return 1;
    }
    return 0;
}

int testRecord() {
    int failCount = 0;
    cout << "- - - - Test Record - - - -\n";
    if (failDefaultConstructor()) {
        failCount++;
        cout << "  -- DEFAULT CONSTRUCTOR FAILED --\n\n";
    }
    else {
        cout << "  -- DEFAULT CONSTRUCTOR PASSED --\n\n";
    }
    if (failSizeConstructor()) {
        failCount++;
        cout << "  -- SIZE CONSTRUCTOR FAILED --\n\n";
    }
    else {
        cout << "  -- SIZE CONSTRUCTOR PASSED --\n\n";
    }
    if (failCopyConstructor()) {
        failCount++;
        cout << "  -- COPY CONSTRUCTOR FAILED --\n\n";
    }
    else {
        cout << "  -- COPY CONSTRUCTOR PASSED --\n\n";
    }
    if (failSize()) {
        failCount++;
        cout << "  -- SIZE FAILED --\n\n";
    }
    else {
        cout << "  -- SIZE PASSED --\n\n";
    }
    if (failGet()) {
        failCount++;
        cout << "  -- GET FAILED --\n\n";
    }
    else {
        cout << "  -- GET PASSED --\n\n";
    }
    if (failSet()) {
        failCount++;
        cout << "  -- SET FAILED --\n\n";
    }
    else {
        cout << "  -- SET PASSED --\n\n";
    }
    if (!failCount) {
        cout << "- - - - ALL TESTS PASSED - - - -\n\n";
    }
    return failCount;
}