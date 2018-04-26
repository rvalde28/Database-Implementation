#include <iostream>
#include "Parser.h"

namespace db{
namespace parser{

Character::Character(std::string str) {
	/*
	* Replaces characters in the string with equivalent characters of type equiv that is used in switch cases.
	*/
	std::map<std::string, Equiv> types;
	types.insert(std::pair<std::string, Equiv>("==", EQ));
	types.insert(std::pair<std::string, Equiv>("<>", NEQ));
	types.insert(std::pair<std::string, Equiv>("<=", LEQ));
	types.insert(std::pair<std::string, Equiv>(">=", GEQ));
	types.insert(std::pair<std::string, Equiv>("<", LT));
	types.insert(std::pair<std::string, Equiv>(">", GT));
	types.insert(std::pair<std::string, Equiv>("(", LPAREN));
	types.insert(std::pair<std::string, Equiv>(")", RPAREN));
	types.insert(std::pair<std::string, Equiv>("AND", AND));
	types.insert(std::pair<std::string, Equiv>("OR", OR));
	types.insert(std::pair<std::string, Equiv>("NOT", NOT));
	types.insert(std::pair<std::string, Equiv>("EXISTS", EXISTS));
	types.insert(std::pair<std::string, Equiv>("IN", IN));
	types.insert(std::pair<std::string, Equiv>("ANY", ANY));
	types.insert(std::pair<std::string, Equiv>("ALL", ALL));
	types.insert(std::pair<std::string, Equiv>(";", ENDL));
	if(types.find(str) != types.end())
	{
		type = types[str];
	}
	else
	{
		type = VAL;
	}
	val = str;
}

CharacterStream::CharacterStream(std::string str)
	: full(false) {
		/*
		* If the character stream is not handling another command, it handles these commands.
		*/
	std::regex r("==|<>|<=|>=|<|>|\\(|\\)|AND|OR|NOT|EXISTS|ALL|ANY|IN"
	"[^\\s\"=!<>\\(\\)]+|\"([^\"]*)\"");
	std::vector<int>iter_vec;
	iter_vec.push_back(0);
	iter_vec.push_back(1);
	std::sregex_token_iterator iter(str.begin(), str.end(), r, iter_vec);
	std::sregex_token_iterator end;
	for( ; iter != end; ++iter) {
		std::string s = *iter;
		if(s != "" && s[0] != '"') {
			Character t(s);
			Characters.push_back(t);
		}
	}
}


Character CharacterStream::find_char() {
	/*
	* Checks characters for the type
	*/
	if(full) {
		full = false;
		return buffer;
	}
	if(empty()) {
		return Character(";");
	}
	Character t = Characters[0];
	Characters.erase(Characters.begin());
	return t;
}

void CharacterStream::push(Character t) {
	/*
	* Add the character handled to buffer
	*/
	if(full)
	{
	}
	buffer = t;
	full = true;
}

bool CharacterStream::empty() const {
	/*
	* Check size of buffer.  Return full otherwise.
	*/
	return (Characters.size() == 0);
}

int CharacterStream::size() const {
	/*
	* Check size of the buffer.
	*/
	return Characters.size();
}

bool Parser::check_expr(Record* r) {
	/*
	* Check for the Record that is in the Table that matches the select, from, and where.
	*/
	character_stream = CharacterStream(stream);
	rec = r;
	return output_expr();
}

bool Parser::output_expr() {
	/*
	* Switch cases between different characters.  The cases AND, OR, NOT, are not handled.
	*/
	bool left = cond();
	bool right;
	Character t = character_stream.find_char();
	while(true) {
		switch(t.type) {
			case AND:
				right = cond();
				left = left && right;
				t = character_stream.find_char();
				break;
			case OR:
				right = cond();
				left = left || right;
				t = character_stream.find_char();
				break;
			case NOT:
				right = cond();
				left |= right;
				t = character_stream.find_char();
				break;
			case ANY:
				right = cond();
				left = right;
				t = character_stream.find_char();
				break;
			case ALL:
				right = cond();
				left = right;
				t = character_stream.find_char();
				break;
		 	case EXISTS:
				right = cond();
				left = right;
				t = character_stream.find_char();
				break;
		 case RPAREN:
		 case ENDL:
				character_stream.push(t);
				return left;
		default:
				return 1;
		}
	}
}


bool Parser::cond() {
	/*
	* The parenthesis and cases are handled at this level.
	*/
	Character t = character_stream.find_char();
	bool left;
	std::string attr_name;
	Character op;
	std::string val;
	switch(t.type) {
		case LPAREN:
			left = output_expr();
			t = character_stream.find_char();
			if(t.type != RPAREN){
				return 1;
			}
			return left;
		case VAL:
			attr_name = t.val;
			if(!character_stream.empty())
			{
				op = character_stream.find_char();
			}
			else
			{
				return 1;
			}
			if(!character_stream.empty())
			{
				t = character_stream.find_char();
			}
			else
			{
				return 1;
			}
			val = t.val;
			return check(attr_name, op, val);
		default:
			break;
	}
}

bool Parser::check(std::string str, Character op, std::string val) {
	/*
	* The check makes sure that the equivalency statements between the strings works well.
	*/
	switch(op.type) {
		case EQ:
			return str == val;
		case IN:
			if (std::size_t pos = str.find(val)) return str == val;
		case NEQ:
			return str != val;
		case LEQ:
			return str <= val;
		case GEQ:
			return str >= val;
		case LT:
			return str < val;
		case GT:
			return str > val;
		default:
			return 1;
		}
	}
	}
}
