#include <string>
#include <iostream>

using namespace std;

#ifndef EXPR_H
#define EXPR_H

class Expression{
	string expression;
	public:
	Expression(string expr);
	string expr_from_sstream(string expression);
	string oprtr_from_sstream(string expression);
	bool evaluate_expression(string expression);
};

#endif
