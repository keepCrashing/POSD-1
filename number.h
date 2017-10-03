#ifndef NUMBER_H_INCLUDE
#define NUMBER_H_INCLUDE

#include <string>
using std::string;

class Atom;
class Variable;

class Number {
	public :
		Number ( int n ); 
		int symbol();
		bool value();
		bool match ( Number number );
		bool match ( Atom atom );
		void match ( Variable &variable );
	private :
		const int _symbol;
		const bool _value = true;
};
#endif

