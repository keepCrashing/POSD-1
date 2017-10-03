#include <sstream>
#include "variable.h"
#include "number.h"
#include "atom.h"

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
	std :: stringstream ss;
	ss << number.symbol();
	if ( assignable || _value == ss.str() ){
		_value = ss.str();
		assignable = false;
		return true;
	}
	return false;
}
