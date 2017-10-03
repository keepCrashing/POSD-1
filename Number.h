#ifndef NUMBER_H_INCLUDE
#define NUMBER_H_INCLUDE

#include <string>
using std::string;

class Atom;
class Variable;

class Number {
	public :
		Number ( int symbol ); 
		int get_symbol();
		bool get_value();
		bool matchToNumber ( Number number );
		bool matchToAtom ( Atom atom );
		void matchToVariable ( Variable &variable );
	private :
		const int _symbol;
		const bool _value = true;
};
#endif

