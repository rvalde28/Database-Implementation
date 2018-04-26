#include "main_menu.h"

void Menu::specify_file() {
	bool fileExist = false;

	while(!fileExist){
		cout << "Specify file to open: ";
		cin >> file_name;

		if (ifstream(file_name)) {
			fileExist = true;
		}
		else {
			cout << "Try again. File does not exist." << endl;
		}
	}
}

void Menu::parse_file() {
	ifstream file;
	string line;
	Database fileDatabase;
	json j;
	ostringstream ss;
	ostringstream sa;
	string temp;
	string temp2;
	vector<string> attributes;
	vector<vector<string>> values;
	int size = 0;
	bool firstLoop = false;
	
	specify_file();
	file.open(file_name);

	for (int i = 0; i < 5; i++) {
		file >> j;
		vector<string> tempString;
		for (json::iterator it = j.begin(); it != j.end(); ++it) {
			//std::cout << it.key() << " : " << it.value() << endl;

			ss << it.key();
			sa << it.value();

			temp = ss.str();
			temp2 = sa.str();

			temp.erase(remove(temp.begin(), temp.end(), '\"'), temp.end());
			temp2.erase(remove(temp2.begin(), temp2.end(), '\"'), temp2.end());


			attributes.push_back(temp);
			tempString.push_back(temp2);

			ss.str("");
			sa.str("");
		}
		size = tempString.size();
		values.push_back(tempString);
	}

	Table databaseTable(attributes);
	for (int i = 0; i <values.size(); i++) {
		Record temp(size);
		for(int j = 0; j < size; j++) {
			temp.set(j, values.at(i).at(j));
		}
		databaseTable.insert_record(temp);
	}
	
	string nameOfFile = file_name;
	nameOfFile.erase(nameOfFile.size() - 5, nameOfFile.size());
	fileDatabase.add_table(nameOfFile, databaseTable);

	databaseContainer.push_back(fileDatabase);
	databaseNames.push_back(nameOfFile);
	cout << "Name: " << nameOfFile << endl;
	cout << "done" << endl;
}

void Menu::runQuery() {

}

void Menu::menuOptions() {
	int menuOption = -1;
	bool doQuit = false;
	while (!doQuit) {
	cout << "MENU" << endl;
	cout << "1) Parse a file" << endl;
	cout << "2) Provide information about users" << endl;
	cout << "3) Provide information about businesses" << endl;
	cout << "4) Run a query" << endl;
	cout << "5) Quit" << endl;
	cout << "6) Check Table" << endl;
	
		cin >> menuOption;
		switch (menuOption) {
			case 1:
				parse_file();
				break;
			case 2:
				userOptions();
				break;
			case 3:
				businessOptions();
				break;
			case 4:
				break;
			case 5:
				doQuit = true;
				break;
			case 6:
				checkTable();
				break;
		}
	}
		
}

void Menu::displayUserInformation() {
	Table userInfo;	//get this with query function
	Database userDatabase;
	string userName;
	string reviewCount;
	string acctMade;
	int indexLocation = -1;
	vector<string> queryAttributes;

	for (int i = 0; i < databaseNames.size(); i++) {
		if (databaseNames.at(i) == "user") {
			indexLocation = i;
		}
	}

	userDatabase = databaseContainer.at(indexLocation);
	
	cout << "Get information for what user? " << endl;
	cin >> userName;

	userInfo = userDatabase.query("*", "user", "name = " + userName);
	queryAttributes = userInfo.get_attributes();

	vector<int> informationLocations;
	vector<string> attrPushed;
	for (int i = 0; i < queryAttributes.size(); i++) {
		if (queryAttributes.at(i) == "review_count") {
			informationLocations.push_back(i);
			attrPushed.push_back("review_count");
		}
		else if (queryAttributes.at(i) == "yelping_since") {
			informationLocations.push_back(i);
			attrPushed.push_back("yelping_since");
		}
		else if (queryAttributes.at(i) == "average_stars") {
			informationLocations.push_back(i);
			attrPushed.push_back("average_stars");
		}
		else if (queryAttributes.at(i) == "fans") {
			informationLocations.push_back(i);
			attrPushed.push_back("fans");
		}
		else {

		}

	}

	Record infoNeeded = userInfo.get_record(0);
	//if user name exists get the information
	cout << "User Name: " << userName << endl;
	cout << "Review Count: ";
	for (int i = 0; i < attrPushed.size(); i++) {
		if (attrPushed.at(i) == "review_count") {
			int index = informationLocations.at(i);
			string value = infoNeeded.get(index);
			cout << value << endl;
		}
	}
	cout << "Yelp Made On: ";
	for (int i = 0; i < attrPushed.size(); i++) {
		if (attrPushed.at(i) == "yelping_since") {
			int index = informationLocations.at(i);
			string value = infoNeeded.get(index);
			cout << value << endl;
		}
	}
	cout << "Average number stars: ";
	for (int i = 0; i < attrPushed.size(); i++) {
		if (attrPushed.at(i) == "average_stars") {
			int index = informationLocations.at(i);
			string value = infoNeeded.get(index);
			cout << value << endl;
		}
	}
	cout << "Number of Fans: ";
	for (int i = 0; i < attrPushed.size(); i++) {
		if (attrPushed.at(i) == "fans") {
			int index = informationLocations.at(i);
			string value = infoNeeded.get(index);
			cout << value << endl;
		}
	}
}

void Menu::displayBusinessInformation() {
	Table businessInfo;	//get this using the query function
	Database businessDatabase;
	int indexLocation = -1;
	string businessName;
	vector<string> queryAttributes;

	for (int i = 0; i < databaseNames.size(); i++) {
		if (databaseNames.at(i) == "business") {
			indexLocation = i;
		}
	}

	businessDatabase = databaseContainer.at(indexLocation);

	cout << "Enter business name: ";
	cin >> businessName;

	businessInfo = businessDatabase.query("review_count", "business", "name = " + businessName);
	cout << "HERE" << endl;
	queryAttributes = businessInfo.get_attributes();

	cout << "HERE" << endl;
	vector<int> informationLocations;
	vector<string> attrPushed;
	for (int i = 0; i < queryAttributes.size(); i++) {
		if (queryAttributes.at(i) == "review_count") {
			informationLocations.push_back(i);
			attrPushed.push_back("review_count");
		}
		else if (queryAttributes.at(i) == "stars") {
			informationLocations.push_back(i);
			attrPushed.push_back("stars");
		}
		else if (queryAttributes.at(i) == "city") {
			informationLocations.push_back(i);
			attrPushed.push_back("city");
		}
		else if (queryAttributes.at(i) == "state") {
			informationLocations.push_back(i);
			attrPushed.push_back("state");
		}
		else if (queryAttributes.at(i) == "address") {
			informationLocations.push_back(i);
			attrPushed.push_back("address");
		}
		else if (queryAttributes.at(i) == "postal_code") {
			informationLocations.push_back(i);
			attrPushed.push_back("postal_code");
		}
		else if (queryAttributes.at(i) == "is_open") {
			informationLocations.push_back(i);
			attrPushed.push_back("is_open");
		}
		else {
			
		}
	
	}

	Record infoNeeded = businessInfo.get_record(0);

	cout << "Business Name: " << businessName<< endl;
	cout << "Review Count: ";
	for (int i = 0; i < attrPushed.size(); i++) {
		if (attrPushed.at(i) == "review_count") {
			int index = informationLocations.at(i);
			string value = infoNeeded.get(index);
			cout << value << endl;			
		}
	}

	cout << "Stars: ";
	for (int i = 0; i < attrPushed.size(); i++) {
		if (attrPushed.at(i) == "stars") {
			int index = informationLocations.at(i);
			string value = infoNeeded.get(index);
			cout << value << endl;
		}
	}
	cout << "City: ";
	for (int i = 0; i < attrPushed.size(); i++) {
		if (attrPushed.at(i) == "city") {
			int index = informationLocations.at(i);
			string value = infoNeeded.get(index);
			cout << value << endl;
		}
	}
	cout << "State: ";
	for (int i = 0; i < attrPushed.size(); i++) {
		if (attrPushed.at(i) == "state") {
			int index = informationLocations.at(i);
			string value = infoNeeded.get(index);
			cout << value << endl;
		}
	}
	cout << "Address: ";
	for (int i = 0; i < attrPushed.size(); i++) {
		if (attrPushed.at(i) == "address") {
			int index = informationLocations.at(i);
			string value = infoNeeded.get(index);
			cout << value << endl;
		}
	}
	cout << "Postal Code";
	for (int i = 0; i < attrPushed.size(); i++) {
		if (attrPushed.at(i) == "postal_code") {
			int index = informationLocations.at(i);
			string value = infoNeeded.get(index);
			cout << value << endl;
		}
	}
	cout << "Currently Open: ";
	for (int i = 0; i < attrPushed.size(); i++) {
		if (attrPushed.at(i) == "is_open") {
			int index = informationLocations.at(i);
			string value = infoNeeded.get(index);
			if (value == "0") {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
	}
	cout << "Hours of Operation: " << endl;

}

void Menu::combineInformation() {

}

void Menu::reviewOptions() {
	int choice = -1;
	cout << "Review options: " << endl;
	cout << "1)Review Count" << endl;
	cout << "2)Get a review by rating" << endl;
	cout << "3)Get an Recent Review" << endl;
	cout << "4)Get an old review" << endl;
	cout << "5)Get reviews from a user" << endl;

	switch (choice) {
	case 1:
		summaryOfReviews();
		break;
	case 2:
		getStarReview();
		break;
	case 3:
		getRecentReview();
		break;
	case 4:
		getOldReview();
		break;
	case 5:
		getUserReview();
		break;
	}
}

void Menu::summaryOfReviews() {
	Database businessData;
	Database reviewData;
	vector<Table> tablesNeeded;
	vector<string> tableNames;

	tablesNeeded = reviewData.get_tables();
	Table reviews = tablesNeeded.at(0);

	Table business;
	vector<int> reviewCount(6);
	string businessName;

	cout << "Enter business Name: ";
	cin >> businessName;
	
	business = businessData.query("business_id", "business", "name = " + businessName);
	
	//gets the business ID
	Record getinfo = business.get_record(0);
	string businessID = getinfo.get(0);

	Table reviewTable = reviewData.query("stars", "review", "business_id = " + businessID);

	for (int i = 0; i < reviewTable.get_size(); i++) {
		Record temp_record = reviewTable.get_record(i);
		string recordValue = temp_record.get(0);
		if(recordValue == "0"){
			reviewCount.at(0) = reviewCount.at(0) + 1;
		}
		if (recordValue == "1") {
			reviewCount.at(1) = reviewCount.at(1) + 1;
		}
		if (recordValue == "2") {
			reviewCount.at(2) = reviewCount.at(2) + 1;
		}
		if (recordValue == "3") {
			reviewCount.at(3) = reviewCount.at(3) + 1;
		}
		if (recordValue == "4") {
			reviewCount.at(4) = reviewCount.at(4) + 1;
		}
		if (recordValue == "5") {
			reviewCount.at(5) = reviewCount.at(5) + 1;
		}
	}

	cout << "Review Count" << endl;
	cout << "5: " << reviewCount.at(5) << endl;
	cout << "4: " << reviewCount.at(4) << endl;
	cout << "3: " << reviewCount.at(3) << endl;
	cout << "2: " << reviewCount.at(2) << endl;
	cout << "1: " << reviewCount.at(1) << endl;
	cout << "0: " << reviewCount.at(0) << endl;
}

void Menu::getStarReview() {
	int starNeeded;
	Database businessData;
	Database reviewData;
	string businessName;
	vector<Table> tablesNeeded;
	vector<string> tableNames;

	tablesNeeded = reviewData.get_tables();
	Table reviews = tablesNeeded.at(0);
	Table business;

	cout << "Enter business Name: ";
	cin >> businessName;

	cout << "Specify number stars of review desired(0-5):";
	cin >> starNeeded;

	//gets the business id of the business
	business = businessData.query("business_id", "business", "name = " + businessName);
	Record getinfo = business.get_record(0);
	string businessID = getinfo.get(0);

	//gets the reviews of the business
	reviews = reviewData.query("*", "review", "business_id = " + businessID);
	Database tempDatabase;
	tempDatabase.add_table("reviews",reviews);

	if (starNeeded == 0) {
		Table zeroTable = tempDatabase.query("text", "reviews", "stars = 0");
		int records = zeroTable.get_size();

		//gets a random record with 0 stars
		int indexRecordToGet;
		srand(time(NULL));
		indexRecordToGet = rand() % records;

		Record recordValue = zeroTable.get_record(indexRecordToGet);
		cout << recordValue.get(0) << endl;

	}
	else if (starNeeded == 1) {
		tempDatabase.query("text", "reviews", "stars = 1");
		Table zeroTable = tempDatabase.query("text", "reviews", "stars = 1");
		int records = zeroTable.get_size();

		//gets a random record with 0 stars
		int indexRecordToGet;
		srand(time(NULL));
		indexRecordToGet = rand() % records;

		Record recordValue = zeroTable.get_record(indexRecordToGet);
		cout << recordValue.get(0) << endl;
	}
	else if (starNeeded == 2) {
		tempDatabase.query("text", "reviews", "stars = 2");
		Table zeroTable = tempDatabase.query("text", "reviews", "stars = 2");
		int records = zeroTable.get_size();

		//gets a random record with 0 stars
		int indexRecordToGet;
		srand(time(NULL));
		indexRecordToGet = rand() % records;

		Record recordValue = zeroTable.get_record(indexRecordToGet);
		cout << recordValue.get(0) << endl;
	}
	else if (starNeeded == 3) {
		tempDatabase.query("text", "reviews", "stars = 3");
		Table zeroTable = tempDatabase.query("text", "reviews", "stars = 3");
		int records = zeroTable.get_size();

		//gets a random record with 0 stars
		int indexRecordToGet;
		srand(time(NULL));
		indexRecordToGet = rand() % records;

		Record recordValue = zeroTable.get_record(indexRecordToGet);
		cout << recordValue.get(0) << endl;
	}
	else if (starNeeded == 4) {
		tempDatabase.query("text", "reviews", "stars = 4");
		Table zeroTable = tempDatabase.query("text", "reviews", "stars = 4");
		int records = zeroTable.get_size();

		//gets a random record with 0 stars
		int indexRecordToGet;
		srand(time(NULL));
		indexRecordToGet = rand() % records;

		Record recordValue = zeroTable.get_record(indexRecordToGet);
		cout << recordValue.get(0) << endl;
	}
	else if (starNeeded == 5) {
		tempDatabase.query("text", "reviews", "stars = 5");
		Table zeroTable = tempDatabase.query("text", "reviews", "stars = 5");
		int records = zeroTable.get_size();

		//gets a random record with 0 stars
		int indexRecordToGet;
		srand(time(NULL));
		indexRecordToGet = rand() % records;

		Record recordValue = zeroTable.get_record(indexRecordToGet);
		cout << recordValue.get(0) << endl;
	}
}


void Menu::getRecentReview() {

}

void Menu::getOldReview() {

}

void Menu::getUserReview() {

}

void Menu::userOptions() {
	int choice = -1;
	bool isDone = false;
	while (!isDone) {
		cout << "Options for User" << endl;
		cout << "1) Get summary for a user" << endl;
		switch (choice) {
		case 1:
			summaryOfUsers();
			break;
		default:
			break;
		}
	}
}


void Menu::summaryOfUsers() {
	string userName;
	cout << "Enter name of user: ";
	cin >> userName;
	Table a;
	Record b;
	a.table_rows.push_back(b);

}

void Menu::businessOptions() {
	int switchChoice;
	bool isDone = false;
	while (!isDone) {
		cout << "Business Options" << endl;
		cout << "1) Summary of business" << endl;
		cout << "2) Quit" << endl;
		cout << "Enter choice: " << endl;
		cin >> switchChoice;
		switch (switchChoice)
		{
		case 1:
			displayBusinessInformation();
			break;
		case 2:
			isDone = true;
			break;
		default:
			break;
		}
	}
}

void Menu::summaryOfBusiness() {

}
void Menu::checkTable() {
	Database a = databaseContainer.at(0);
	vector<Table> tables = a.get_tables();
	Table temp = tables.at(0);
	Record r = temp.get_record(0);
	for (int i = 0; i < r.size(); i++) {
		cout << r.get(i) << endl;
	}
	cout << "Table Name: " << a.names.at(0) << endl;
}