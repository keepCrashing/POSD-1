#include "include/Variable.h"
#include "include/Number.h"
#include "include/Atom.h"

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
	if ( _assignable || _symbol == number.get_value() ){
		_symbol = number.get_value();
		_assignable = false;
	}
}
