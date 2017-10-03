#ifndef ATOM_H_INCLUDE
#define ATOM_H_INCLUDE

#include <string>
using std::string;

class Number;
class Variable;

class Atom {
	public:
  		Atom ( string a );
		string getSymbol();
		bool match ( Number number );
		void match ( Variable &variable );
  	private:
		const string symbol;
};

#endif
