#include "include/Number.h"
#include "include/Atom.h"
#include "include/Variable.h"

Number :: Number (string symbol , string value ) : _symbol ( symbol ) , _value ( value ){}

string Number :: get_symbol () { return _symbol; }

string Number :: get_value () { return _value; }

bool Number :: matchToNumber ( Number number ){
	return _value == number._value;
}

bool Number :: matchToAtom ( Atom atom ){
	return false;
}

void Number :: matchToVariable ( Variable &variable ){
	if ( variable.get_assignable() || variable.get_symbol() == _value){
		variable.set_symbol ( _value );
		variable.set_assignable ( false );	
	}
} 

