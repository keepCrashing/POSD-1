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
		string value ();
		void setAssignable ( bool d );
		void setValue ( string c );
		void match ( Atom atom );
		void match ( Number number );	
	private:
		string _value; 
		bool assignable = true; 
};

#endif
