#include <string>
#include "variable.h"
#include "number.h"
#include "atom.h"

using std :: string;

Variable :: Variable ( string v ) : _value ( v ) {}

bool Variable :: getAssignable () { return assignable; }

string Variable :: value () { return _value; } 

void Variable :: setAssignable ( bool d ) { assignable = d; }

void Variable :: setValue ( string c ) { _value = c; }

bool Variable :: match ( Atom atom ){
	if ( assignable || _value == atom.getSymbol() ){
		_value = atom.getSymbol();
		assignable = false;	
		return true;
	}
	return false;
}

bool Variable :: match ( Number number ){
	string temp = std :: to_string ( number.symbol() );
	if ( assignable || _value == temp ){
		_value = temp;
		assignable = false;
		return true;
	}
	return false;
}
