
#include "Database.h"

int failDatabaseConstructor(){
    cout << "- - - - Testing Database Constructor - - - -" << endl;
    Database db;
    if(db.list_table().size() != 0){
        cout << "Table Constructor failed. Size was not initialized to zero" << endl;
        return 1;
    }
    return 0;

}

int failCopyConstructor() {
    cout << "- - - - Testing Database Copy Constructor - - - -" << endl;
    Database db;
    db.add_table(db);
    Database copy_db(db);
    if(copy_db.size() != orig_db.size()){
        cout << "Failed copy constructor" << endl;
        return 1;
    }
    return 0;

}

int failAddTable() {
    cout << "- - - - Testing Table Add - - - -" << endl;
    Database db;
    Table t;
    db.add_table(t, "New Table");
    vector<string> table_list = db.list_table();
    if(table_list.size() < 1 || table_list.at(0) != "New Table"){
        cout << "Table Add Failed" << endl;
        return 1;
    }
    return 0;

}

int failDropTable() {
    cout << "- - - - Testing Drop Table - - - -" << endl;
    Database db;
    Table t;
    db.add_table(t, "New Table");
    db.drop_table("New Table");
    vector<string> table_list = db.list_table();
    if (table_list.size() != 0) {
        cout << "Drop Table Failed" << endl;
        return 1;
    }
    return 0;
}

int failListTable() {
    cout << "- - - - Testing List Table - - - -" << endl;
    Database db;
    Table t;
    db.add_table(t, "New Table");
    db.add_table(t, "New New Table");
    vector<string> table_list = db.list_table();
    if (table_list.size() != 2 || table_list.at(0) != "New Table" || table_list.at(1) != "New New Table") {
        cout << "List Table Failed" << endl;
        return 1;
    }
    return 0;
}

int failGetTable() {
    cout << "- - - - Testing Get Table - - - -" << endl;
    Database db;
    Table t;
    db.add_table(t, "New Table");
    vector<string> table_list = db.get_table();
    if(table_list.size() != 1) {
        cout << "Get Table Failed" << endl;
        return 1;
    }
    return 0;
}

int failQuery() {
    Table t;
    t.add_attribute("number");
    t.add_attribute("word");
    Record r(2);
    r.set(0, "2");
    r.set(1, "howdy");
    t.add(r);
    Record ra(2);
    r.set(0, "3");
    r.set(1, "hello");
    t.add(ra);
    Table s = query_command("number", "t", "");

    Record testOne = s.record_iterator(0);
    if(testOne.get(0) != "2"){
        cout << "Query Part 1 Failed" << endl;
        return 1;
    }
    cout << "Query Part 1 Passed" << endl;

    Table r = query_command("number", "t", "number>2");
    Record testTwo = r.record_iterator(0);
    if(testTwo.get(0) != "3"){
        cout << "Query Part 2 Failed" << endl;
        return 1;
    }
    cout << "Query Part 2 Passed" << endl;

    Table q = query_command("*", "t", "");
    if(q.get_size() != 2){
        cout << "Query Part 3 Failed" << endl;
        return 1;
    }
    cout << "Query Part 3 Passed" << endl;

    Record testThree = q.record_iterator(0);
    if(testThree.get(0) != "2"){
        cout << "Query Part 4 Failed" << endl;
        return 1;
    }
    cout << "Query Part 4 Passed" << endl;

    Table p = query_command("*", "t", "number=2");
    Record testFour = p.record_iterator(0);
    if(testFour.get(1) != "howdy"){
        cout << "Query Part 5 Failed" << endl;
        return 1;
    }
    cout << "Query Part 5 Passed" << endl;

    Table o = query_command("*", "t", "number>=3");
    Record testFive = o.record_iterator(0);
    if(testFive.get(1) != "hello"){
        cout << "Query Part 6 Failed" << endl;
        return 1;
    }
    cout << "Query Part 6 Passed" << endl;

    Table n = query_command("*", "t", "number<2");
    if(n.get_size() != 0){
        cout << "Query Part 7 Failed" << endl;
        return 1;
    }
    cout << "Query Part 7 Passed" << endl;

    Table m = query_command("*", "t", "number<=2");
    Record testSix = m.record_iterator(0);
    if(m.get(0) != "2"){
        cout << "Query Part 8 Failed" << endl;
        return 1;
    }
    cout << "Query Part 8 Passed" << endl;

    Table l = query_command("*", "t", "number<>2");
    Record testSeven = l.record_iterator(0);
    if(l.get(0) != "3"){
        cout << "Query Part 9 Failed" << endl;
        return 1;
    }
    cout << "Query Part 9 Passed" << endl;

    Table k = query_command("*", "t", "(number = 2) AND (word = howdy)");
    if(k.get_size() != 1){
        cout << "Query Part 10 Failed" << endl;
        return 1;
    }
    cout << "Query Part 10 Passed" << endl;

    Table j = query_command("*", "t", "(number = 2) OR (word = hello)");
    (if j.get_size() != 2){
        cout << "Query Part 11 Failed" << endl;
        return 1;
    }
    cout << "Query Part 11 Passed" << endl;

    Table i = query_command("*", "t", "NOT (number = 2)");
    if(i.get_size() != 1){
        cout << "Query Part 12 Failed" << endl;
        return 1;
    }
    cout << "Query Part 12 Passed" << endl;

    Table h = query_command("number word", "t", "");
    Record testThirteen = h.record_iterator(0);
    if(testThirteen.size() != 2){
        cout << "Query Part 13 Failed" << endl;
        return 1;
    }
    cout << "Query Part 13 Passed" << endl;

    return 0;
}

int testDatabase(){
    int failCount = 0;
    cout << "- - - - Test Database - - - -\n";

    if (failDatabaseConstructor()) {
        failCount++;
        cout << "  -- DEFAULT CONSTRUCTOR FAILED --\n\n";
    }
    else {
        cout << "  -- DEFAULT CONSTRUCTOR PASSED --\n\n";
    }
    if (failCopyConstructor()) {
        failCount++;
        cout << "  -- COPY CONSTRUCTOR FAILED --\n\n";
    }
    else {
        cout << "  -- COPY CONSTRUCTOR PASSED --\n\n";
    }
    if (failAddTable()) {
        failCount++;
        cout << "  -- ADD TABLE FAILED --\n\n";
    }
    else {
        cout << "  -- ADD TABLE PASSED --\n\n";
    }
    if (failDropTable()) {
        failCount++;
        cout << "  -- DROP TABLE FAILED --\n\n";
    }
    else {
        cout << "  -- DROP TABLE PASSED --\n\n";
    }
    if (failListTable()) {
        failCount++;
        cout << "  -- LIST TABLE FAILED --\n\n";
    }
    else {
        cout << "  -- LIST TABLE PASSED --\n\n";
    }
    if (failGetTable()) {
        failCount++;
        cout << "  -- GET TABLE FAILED --\n\n";
    }
    else {
        cout << "  -- GET TABLE PASSED --\n\n";
    }
    if (failQuery()) {
        failCount++;
        cout << "  -- QUERY FAILED --\n\n";
    }
    else {
        cout << "  -- QUERY PASSED --\n\n";
    }
    if (!failCount) {
        cout << "- - - - ALL TESTS PASSED - - - -\n\n";
    }
    return failCount;
}
