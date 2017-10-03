//#include <string>
#include <sstream>
#include "variable.h"
#include "number.h"
#include "atom.h"

using std :: string;

Variable :: Variable ( string v ) : _value ( v ) {}

bool Variable :: assignable () { return _assignable; }

string Variable :: value () { return _value; } 

void Variable :: setAssignable ( bool d ) { _assignable = d; }

void Variable :: setValue ( string c ) { _value = c; }

bool Variable :: match ( Atom atom ){
	if ( _assignable || _value == atom.symbol() ){
		_value = atom.symbol();
		_assignable = false;	
		return true;
	}
	return false;
}

bool Variable :: match ( Number number ){
	//string temp = std :: to_string ( number.symbol() );
	std :: stringstream ss;
	ss << number.symbol();
	if ( _assignable || _value == ss.str() ){
		_value = ss.str();
		_assignable = false;
		return true;
	}
	return false;
}
