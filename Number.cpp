#include <sstream>
#include "Number.h"
#include "Atom.h"
#include "Variable.h"

Number :: Number (string symbol , int value ) : _symbol ( symbol ) , _value ( value ){}

string Number :: get_symbol () { return _symbol; }

int Number :: get_value () { return _value; }

bool Number :: matchToNumber ( Number number ){
	return _value == number.get_value();
}

bool Number :: matchToAtom ( Atom atom ){
	return false;
}

void Number :: matchToVariable ( Variable &variable ){
	std :: stringstream ss;
	ss << _value;
	if ( variable.get_assignable() || variable.get_symbol() == ss.str() ){
		variable.set_symbol ( ss.str() );
		variable.set_assignable ( false );	
	}
} 

