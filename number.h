#ifndef NUMBER_H
#define NUMBER_H

#include <string>
using std::string;

//class Atom;
//class Variable;

class Number {
	public :
		Number ( int n ); 
		int symbol();
		int value();
		bool match ( Number number );
		//bool match ( Atom atom );
		//bool match ( Variable &variable );
	private :
		int const _symbol;
};
#endif

