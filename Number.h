#ifndef NUMBER_H_INCLUDE
#define NUMBER_H_INCLUDE

#include <string>
using std::string;

class Atom;
class Variable;

class Number {
	public :
		Number ( string symbol , int value ); 
		string get_symbol();
		int get_value();
		bool matchToNumber ( Number number );
		bool matchToAtom ( Atom atom );
		void matchToVariable ( Variable &variable );
	private :
		const string _symbol;
		const int _value;
};
#endif

