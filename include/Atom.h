#ifndef ATOM_H_INCLUDE
#define ATOM_H_INCLUDE

#include <string>
using std::string;

class Number;
class Variable;

class Atom {
	public:
  		Atom ( string atom );
		string get_symbol();
		bool matchToNumber ( Number number );
		void matchToVariable ( Variable &variable );
  	private:
		const string _symbol;
};

#endif
