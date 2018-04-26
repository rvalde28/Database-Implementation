#include <string>
#include <regex>
#include <map>
#include <stdexcept>
#include <iostream>

#ifndef PARSER
#define PARSER

namespace db {

	class Table;
	class Record;

namespace parser {

	enum Equiv {EQ='=', NEQ='!',
	LEQ='l', GEQ='g',
	LT='<', GT='>',
	LPAREN='(', RPAREN=')',
	AND='&', OR='|', NOT = 'n',
	VAL='v', IN = 'i', ALL = 'a',
	ANY = 'y', EXISTS = 'e', ENDL=';'};

	class Character {
	/*
	* The character goes through each character of the stream.
	* The types of characters are checked to see which is the one needed.
	*/
	public:
		Character()
		{
		};
		Character(std::string str);
		Equiv type;
		std::string val;
	};

	class CharacterStream {
		/*
		* The input is handled, and the character is handled.
		*
		*/
	public:
		CharacterStream() {
		};
		CharacterStream(std::string str);
		Character find_char();
		void push(Character t);
		std::vector<Character>getCharacters() const;
		bool empty() const;
		int size() const;
	private:
		bool full;
		Character buffer;
		std::vector<Character> Characters;
	};

	class Parser {
	/*
	* The parser returns the Record (of type string) that is used for the table
	*/
	public:
		Parser(Table* t, std::string str)
			: tab(t), stream(str), character_stream(str) {}
		bool check_expr(Record* r);
		private:
		bool output_expr();
		bool cond();
		bool check(std::string attr_name, Character op, std::string val);
		std::string stream;
		CharacterStream character_stream;
		Record *rec;
		Table *tab;
	};
	}
}
#endif
