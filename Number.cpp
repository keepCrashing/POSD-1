#include <sstream>
#include "Number.h"
#include "Atom.h"
#include "Variable.h"

Number :: Number ( int n ) : symbol ( n ) {}

int Number :: getSymbol () { return symbol; }

bool Number :: getValue () { return value; }

bool Number :: match ( Number number ){
	return symbol == number.getSymbol();
}

bool Number :: match ( Atom atom ){
	return false;
}

void Number :: match ( Variable &variable ){
	std :: stringstream ss;
	ss << symbol;
	if ( variable.getAssignable() || variable.getSymbol() == ss.str() ){
		variable.setSymbol ( ss.str() );
		variable.setAssignable ( false );	
	}
} 

