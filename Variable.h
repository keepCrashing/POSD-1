#ifndef VARIABLE_H_INCLUDE
#define VARIABLE_H_INCLUDE

#include <string>
using std::string;

class Atom;
class Number;

class Variable{
	public:
  		Variable ( string v );
		bool getAssignable ();
		string getSymbol ();
		void setAssignable ( bool d );
		void setSymbol ( string c );
		void match ( Atom atom );
		void match ( Number number );	
	private:
		string symbol; 
		bool assignable = true; 
};

#endif
