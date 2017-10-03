#include <string>
#include "number.h"
#include "atom.h"
#include "variable.h"

using std :: string;

Number :: Number ( int n ) : _symbol ( n ) {}

int Number :: symbol () { return _symbol; }

int Number :: value () { return _symbol; }

bool Number :: match ( Number number ){
	//string a = std :: to_string ( _symbol );
	//string b =  std :: to_string ( number.symbol() ); 
	//return ( std :: to_string (_symbol) ) == ( std :: to_string ( number.symbol() ) );
	//return ( (a == b) ? true : false );
	//return _symbol == number.symbol();
	return true;
}

bool Number :: match ( Atom atom ){
	return false;
}

bool Number :: match ( Variable &variable ){
	//string temp = std :: to_string( _symbol );
	//if ( variable.assignable() || ( variable.value() == temp ) ){
	//	variable.setValue ( temp );
	//	variable.setAssignable ( false );
	//	return true;	
	//}
	return false; 
} 

