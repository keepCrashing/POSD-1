#include <sstream>
#include "Number.h"
#include "Atom.h"
#include "Variable.h"

Number :: Number ( int symbol ) : _symbol ( symbol ) {}

int Number :: get_symbol () { return _symbol; }

bool Number :: get_value () { return _value; }

bool Number :: matchToNumber ( Number number ){
	return _symbol == number.get_symbol();
}

bool Number :: matchToAtom ( Atom atom ){
	return false;
}

void Number :: matchToVariable ( Variable &variable ){
	std :: stringstream ss;
	ss << _symbol;
	if ( variable.get_assignable() || variable.get_symbol() == ss.str() ){
		variable.set_symbol ( ss.str() );
		variable.set_assignable ( false );	
	}
} 

