
#include "Table.h" 

int testTableConstructor(){
    cout << "- - - - Testing Table Constructor - - - -" << endl;
    Table t;
    
    if(t.get_size() != 0){
        cout << "Table Constructor failed. size was not initialized to zero" << endl;
        return 1;
    }
    return 0;
}

int testTableCopyConstructor(){
    cout << "- - - - Testing Table Copy Constructor - - - -" << endl;
    Table orig_table;
    Record r;
    orig_table.add(r);
    Table copy_table(orig_table);
    if(copy_table.size() != orig_table.size()){
        cout << "Failed copy constructor" << endl;
        return 1;
    }
    return 0;
}

int testTableConstructorSize(){
    cout << "- - - - Testing Table Constructor with Size - - - -" << endl;
    Table t(4);
    if(t.get_size() != 4){
        cout << "Table Constructor with setting size failed" << endl;
        return 1;
    }
    return 0;
}

int testTableConstructorAttributeVector(){
    cout << "- - - - Testing Table Constructor with Vector of Attributes - - - -" << endl;
    vector<string> attributeVector;
    string attrOne = "attrOne";
    string attrTwo = "attrTwo";
    attributeVector.push_back(attrOne);
    attributeVector.push_back(attrTwo);
    Table t(attributeVector);
    vector<string> testVector = t.get_attribute_in_order();
    if((testVector.at(0) != "attrOne") || (testVector.at(1) != "attrTwo")){
        cout << "Table Constructor with Setting Attributes Failed" << endl;
        return 1;
    }
    return 0;
}

int testTableAddAttribute(){
    cout << "- - - - Testing Table Add Attribute - - - -" << endl;
    Table t;
    string attr = "attrOne";
    t.add_attribute(attr);
    vector<string> testVector = t.get_attribute_in_order();
    if(testVector.at(0) != "attrOne"){
        cout << "Table Add Attribute Failed" << endl;
        return 1;
    }
    return 0;
}

int testTableDeleteAttribute(){
    cout << "- - - - Testing Table Delete Attribute - - - -" << endl;
    Table t;
    string attr = "attrOne";
    t.add_attribute(attr);
    t.delete_attribute(attr);
    vector<string> testVector = t.get_attribute_in_order();
    if(testVector.size() != 0){
        cout << "Table Delete Attribute Failed" << endl;
        return 1;
    }
    return 0;
}

int testTableGetAttributeInOrder(){
    cout << "- - - - Testing Table Get Attribute in Order - - - -" << endl;
    Table t;
    string attr = "attrOne";
    t.add_attribute(attr);
    vector<string> testVector = t.get_attribute_in_order();
    if(testVector.size() != 1){
        cout << "Testing Table Get Attribute in Order, attribute was not returned after being added or more than one attribute was added" << endl;
        return 1;
    }
    else{
        if(testVector.at(0) != "attrOne"){
            cout << "Testing Table Get Attribute in Order, attribute that was added was not under correct name" << endl;
            return 1;
        }
    }
    return 0;
}

int testTableGetSize(){
    cout << "- - - - Testing Table Get Size - - - -" << endl;
    Table t;
    Record r;
    t.add(r);
    int size = t.get_size();
    if(size != 1){
        cout << "Table Get Size Failed" << endl;
        return 1;
    }
    return 0;
}

int testTableSpecifyKey(){
    cout << "- - - - Testing Table Specify Key - - - -" << endl;
    Table t;
    string attr = "attrOne";
    t.add_attribute(attr);
    t.specify_key(attr);
    vector<string> keys = get_key();
    if(keys.at(0) != attr){
        cout << "Table Specify Key Failed" << endl;
        return 1;
    }
    return 0;
}

int testTableComputeCount(){
    cout << "- - - - Testing Table Compute Count - - - -" << endl;
    Table t;
    string attr = "attrOne";
    t.add_attribute(attr);
    Record r(1);
    t.add(r);
    if(t.compute_count(attr) != 1){
        cout << "Table Compute Count Failed" << endl;
        return 1;
    }
    r.set(0, "hi");
    t.add(r);
    if(t.compute_count(attr) != 1){
        cout << "Table Compute Count Failed" << endl;
        return 1;
    }
    return 0;
}

int testTableComputeMin(){
    cout << "- - - - Testing Table Compute Min - - - -" << endl;
    Table t;
    string attr = "attrOne";
    t.add_attribute(attr);
    Record r(1);
    r.set(0, "2");
    t.add(r);
    if(t.compute_min(attr) != 2){
        cout << "Table Compute Min Failed" << endl;
        return 1;
    }
    Record rr;
    t.add(rr);
    if(t.compute_min(attr) != 2){
        cout << "Table Compute Min Failed" << endl;
        return 1;
    }
    rr.set(0, "1");
    t.add(rr);
    if(t.compute_min(attr) != 1){
        cout << "Table Compute Min Failed" << endl;
        return 1;
    }
    return 0;
}

int testTableComputeMax(){
    cout << "- - - - Testing Table Compute Min - - - -" << endl;
    Table t;
    string attr = "attrOne";
    t.add_attribute(attr);
    Record r(1);
    r.set(0, "1");
    t.add(r);
    if(t.compute_min(attr) != 1){
        cout << "Table Compute Min Failed" << endl;
        return 1;
    }
    Record rr;
    t.add(rr);
    if(t.compute_min(attr) != 1){
        cout << "Table Compute Min Failed" << endl;
        return 1;
    }
    rr.set(0, "2");
    t.add(rr);
    if(t.compute_min(attr) != 2){
        cout << "Table Compute Min Failed" << endl;
        return 1;
    }
    return 0;
}

int testTableAdd(){
    cout << "- - - - Testing Table Add - - - -" << endl;
    Table t;
    Record r;
    t.add(r);
    if(t.get_size() != 1){
        cout << "Table Add Failed" << endl;
        return 1;
    }
    return 0;
}

int testTableCrossJoin(){
    cout << "- - - - Testing Table Cross Join - - - -" << endl;
    vector<string> attributes1 = ["Size", "Weight", "Length"];
    vector<string> attributes2 = ["Date", "Location"];
    Table t1(attributes1);
    Record r1;
    t1.add_record(r1);
    Table t2(attributes2);
    Record r2;
    t2.add_record(r2);
    Table t_out = t1.cross_join(t1, t2);
    vector<string> attributes_out = ["Date", "Length", "Location", "Size", "Weight"];
    if (t_out.get_size() != t1.get_size()+t2.get_size()) {
        cout << "Cross Join Failed" << endl;
        return 1;
    }
    for (int i = 0; i < 5; i++) {
        if (t_out.get_attribute_in_order().at(i) != attributes_out.at(i)) {
            cout << "Cross Join Failed" << endl;
            return 1;
        }
    return 0;
}

int testTableNaturalJoin() {
    cout << "- - - - Testing Table Natural Join - - - -" << endl;
    vector<string> attributes1 = ["Size", "Weight", "Length", "Date"];
    vector<string> attributes2 = ["Date", "Location"];
    Table t1(attributes1);
    Record r1;
    t1.add_record(r1);
    Table t2(attributes2);
    Record r2;
    t2.add_record(r2);
    try {
        Table t_out1 = t1.natural_join(t1, t2);
        cout << "Natural join failed to throw an exception when key is unspecified" << endl;
        return 1;
    }
    catch (...) {
        //Good - threw exception
    }
    t2.specify_key("Date");
    Table t_out2 = t1.natural_join(t1, t2);
    if (t_out2.get_size() != t1.get_size()+t2.get_size()-1) {
        cout << "Natural Join Failed" << endl;
        return 1;
    }
    vector<string> attributes_out = ["Date", "Length", "Location", "Size", "Weight"];
    for (int i = 0; i < 5; i++) {
        if (t_out2.get_attribute_in_order().at(i) != attributes_out.at(i)) {
            cout << "Natural Join Failed" << endl;
            return 1;
        }
    t1.delete_attribute("Date");
    try {
        Table t_out3 = t1.natural_join(t1, t2);
    }
    catch (...) {
        //Good - threw exception
        cout << "Natural join failed to throw an exception when key is not found in first table" << endl;
        return 1;
    }
    return 0;
}

int testTable(){
    int failCount = 0;
    cout << "- - - - Test Table - - - -\n";
    
    if(testTableConstructor() == 1){
        failCount++;
        cout << "  -- CONSTRUCTOR FAILED --\n\n";
    }
    else {
        cout << "  -- CONSTRUCTOR PASSED --\n\n";
    }
    
    if(testTableCopyConstructor() == 1){
        failCount++;
        cout << "  -- COPY CONSTRUCTOR FAILED --\n\n";
    }
    else {
        cout << "  -- COPY CONSTRUCTOR PASSED --\n\n";
    }
    
    if(testTableConstructorSize() == 1){
        failCount++;
        cout << "  -- CONSTRUCTOR SIZE FAILED --\n\n";
    }
    else {
        cout << "  -- CONSTRUCTOR SIZE PASSED --\n\n";
    }
    
    if(testTableConstructorAttributeVector() == 1){
        failCount++;
        cout << "  -- CONTRUCTOR ATTRIBUTE VECTOR FAILED --\n\n";
    }
    else {
        cout << "  -- CONTRUCTOR ATTRIBUTE VECTOR PASSED --\n\n";
    }
    
    if(testTableAddAttribute() == 1){
        failCount++;
        cout << "  -- ADD ATTRIBUTE FAILED --\n\n";
    }
    else {
        cout << "  -- ADD ATTRIBUTE PASSED --\n\n";
    }
    
    if(testTableDeleteAttribute() == 1){
        failCount++;
        cout << "  -- DELETE ATTRIBUTE FAILED --\n\n";
    }
    else {
        cout << "  -- DELETE ATTRIBUTE PASSED --\n\n";
    }
    
    if(testTableGetAttributeInOrder() == 1){
        failCount++;
        cout << "  -- GET ATTRIBUTE IN ORDER FAILED --\n\n";
    }
    else {
        cout << "  -- GET ATTRIBUTE IN ORDER PASSED --\n\n";
    }
    
    if(testTableGetSize() == 1){
        failCount++;
        cout << "  -- GET SIZE FAILED --\n\n";
    }
    else {
        cout << "  -- GET SIZE PASSED --\n\n";
    }
    
    if(testTableComputeCount() == 1){
        failCount++;
        cout << "  -- COMPUTE COUNT FAILED --\n\n";
    }
    else {
        cout << "  -- COMPUTE COUNT PASSED --\n\n";
    }
    
    if(testTableComputeMin() == 1){
        failCount++;
        cout << "  -- COMPUTE MIN FAILED --\n\n";
    }
    else {
        cout << "  -- COMPUTE MIN PASSED --\n\n";
    }
    
    if(testTableComputeMax() == 1){
        failCount++;
        cout << "  -- COMPUTE MAX FAILED --\n\n";
    }
    else {
        cout << "  -- COMPUTE MAX PASSED --\n\n";
    }
    
    if(testTableAdd() == 1){
        failCount++;
        cout << "  -- TABLE ADD FAILED --\n\n";
    }
    else {
        cout << "  -- TABLE ADD PASSED --\n\n";
    }
    
    if(failCount == 0){
        cout << "All Tests Passed!" << endl;
    }
    return failCount;
}