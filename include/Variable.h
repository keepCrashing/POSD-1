#ifndef VARIABLE_H_INCLUDE
#define VARIABLE_H_INCLUDE

#include <string>
using std::string;

class Atom;
class Number;

class Variable{
	public:
  		Variable ( string variable );
		bool get_assignable ();
		string get_symbol ();
		void set_assignable ( bool decide );
		void set_symbol ( string changeForm );
		void matchToAtom ( Atom atom );
		void matchToNumber ( Number number );	
	private:
		string _symbol; 
		bool _assignable = true; 
};

#endif
