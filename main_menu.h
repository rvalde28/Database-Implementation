#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "json.hpp"
#include "Database.h"
#include "json.hpp"
#include <time.h>

using json = nlohmann::json;
using namespace std;

class Menu {
private:
	string file_name;
	
	//stores the databases
	vector<Database> databaseContainer;	
	vector<string> databaseNames;


public:
	void specify_file();
	void parse_file();
	void runQuery();

	//menu options
	void menuOptions();
	void displayUserInformation();
	void displayBusinessInformation();
	void combineInformation();

	//functions for Review of businesss	
	void reviewOptions();
	void summaryOfReviews();
	void getStarReview();
	void getRecentReview();
	void getOldReview();
	void getUserReview();
	
	//functions for User
	void userOptions();
	void summaryOfUsers();


	//functions for business
	void businessOptions();
	void summaryOfBusiness();

	//check functions
	void checkTable();
};