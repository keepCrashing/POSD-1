#ifndef NUMBER_H_INCLUDE
#define NUMBER_H_INCLUDE

#include <string>
using std::string;

class Atom;
class Variable;

class Number {
	public :
		Number ( int n ); 
		int getSymbol();
		bool getValue();
		bool match ( Number number );
		bool match ( Atom atom );
		void match ( Variable &variable );
	private :
		const int symbol;
		const bool value = true;
};
#endif

