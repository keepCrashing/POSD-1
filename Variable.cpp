#include <sstream>
#include "Variable.h"
#include "Number.h"
#include "Atom.h"

Variable :: Variable ( string variable ) : _symbol ( variable ) {}

bool Variable :: get_assignable () { return _assignable; }

string Variable :: get_symbol () { return _symbol; } 

void Variable :: set_assignable ( bool decide ) { _assignable = decide; }

void Variable :: set_symbol ( string changeForm ) { _symbol = changeForm; }

void Variable :: matchToAtom ( Atom atom ){
	if ( _assignable || _symbol == atom.get_symbol() ){
		_symbol = atom.get_symbol();
		_assignable = false;	
	}
}

void Variable :: matchToNumber ( Number number ){
	std :: stringstream ss;
	ss << number.get_symbol();
	if ( _assignable || _symbol == ss.str() ){
		_symbol = ss.str();
		_assignable = false;
	}
}
