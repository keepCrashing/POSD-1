#ifndef NUMBER_H_INCLUDE
#define NUMBER_H_INCLUDE

#include <string>
using std::string;

class Atom;
class Variable;

class Number {
	public :
		Number ( string symbol , string value ); 
		string get_symbol();
		string get_value();
		bool matchToNumber ( Number number );
		bool matchToAtom ( Atom atom );
		void matchToVariable ( Variable &variable );
	private :
		const string _symbol;
		const string _value;
};
#endif

