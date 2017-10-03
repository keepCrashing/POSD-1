#include <sstream>
#include "Variable.h"
#include "Number.h"
#include "Atom.h"

Variable :: Variable ( string v ) : symbol ( v ) {}

bool Variable :: getAssignable () { return assignable; }

string Variable :: getSymbol () { return symbol; } 

void Variable :: setAssignable ( bool d ) { assignable = d; }

void Variable :: setSymbol ( string c ) { symbol = c; }

void Variable :: match ( Atom atom ){
	if ( assignable || symbol == atom.getSymbol() ){
		symbol = atom.getSymbol();
		assignable = false;	
	}
}

void Variable :: match ( Number number ){
	std :: stringstream ss;
	ss << number.getSymbol();
	if ( assignable || symbol == ss.str() ){
		symbol = ss.str();
		assignable = false;
	}
}
