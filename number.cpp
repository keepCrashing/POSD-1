//#include <string>
#include <sstream>
#include "number.h"
#include "atom.h"
#include "variable.h"

using std :: string;

Number :: Number ( int n ) : _symbol ( n ) {}

int Number :: symbol () { return _symbol; }

int Number :: value () { return _symbol; }

bool Number :: match ( Number number ){
	return _symbol == number.symbol();
}

bool Number :: match ( Atom atom ){
	return false;
}

bool Number :: match ( Variable &variable ){
	//string temp = std :: to_string( _symbol );
	std :: stringstream ss;
	ss << _symbol;
	if ( variable.assignable() || variable.value() == ss.str() ){
		variable.setValue ( ss.str() );
		variable.setAssignable ( false );
		return true;	
	}
	return false; 
} 

