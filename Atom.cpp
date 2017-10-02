#include "include/Atom.h"
#include "include/Number.h"
#include "include/Variable.h"

Atom :: Atom ( string atom ) : _symbol ( atom ) {}

string Atom :: get_symbol ( ) { return _symbol; }

bool Atom :: matchToNumber ( Number number ) {
	return false;
}

void Atom :: matchToVariable ( Variable &variable ){
	if ( variable.get_assignable() || variable.get_symbol() == _symbol){
		variable.set_symbol( _symbol );
		variable.set_assignable (false);
	}
}
