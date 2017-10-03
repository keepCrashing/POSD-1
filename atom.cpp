#include "atom.h"
#include "number.h"
#include "variable.h"

Atom :: Atom ( string a ) : symbol ( a ) {}

string Atom :: getSymbol ( ) { return symbol; }

bool Atom :: match ( Number number ) {
	return false;
}

void Atom :: match ( Variable &variable ){
	if ( variable.getAssignable() || variable.value() == symbol ){
		variable.setValue ( symbol );
		variable.setAssignable (false);
	}
}

