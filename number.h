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
		int value();
		bool match ( Number number );
		bool match ( Atom atom );
		bool match ( Variable &variable );
	private :
		const int _symbol;
};
#endif

