#ifndef UTTERM_H
#define UTTERM_H

#include "Number.h"
#include "Atom.h"
#include "Variable.h"

//test Number.value()
TEST ( Number , ctor ) {
	Number number ( 15 );
	ASSERT_TRUE ( number.get_value() );
}

//test Number.symbol()
TEST ( Number , symbol ) {
	Number number ( 15 ) ;
	ASSERT_EQ ( 15 , number.get_symbol() );
}

//?- 25=25.
//true.
TEST ( Number , matchSuccess ) {
	Number numberOne ( 25 );
        Number numberTwo ( 25 );
	ASSERT_TRUE ( numberOne.matchToNumber ( numberTwo ) );
}

//?- 25=0.
//false.
TEST ( Number , matchFailureDiffValue ) {
	Number numberOne ( 25 );
        Number numberTwo ( 0 );
	ASSERT_FALSE ( numberOne.matchToNumber ( numberTwo ) );
}

//?- 25=tom.
//false.
TEST ( Number , matchFailureDiffConstant ) {
	Number number ( 25 );
	Atom tom( "tom" );
	ASSERT_FALSE ( number.matchToAtom ( tom ) );	
}

//?- 25=X.
//true.
TEST ( Number , matchSuccessToVar ) {
	Number number ( 25 );
	Variable X ( "X" );
	number.matchToVariable ( X );
	ASSERT_EQ ( "25" , X.get_symbol() );
}

//?- tom=25.
//false.
TEST ( Atom , matchFailureDiffConstant ) {
	Atom tom ( "tom" );
	Number number ( 25 );
	ASSERT_FALSE ( tom.matchToNumber ( number ) );
}

// ?- tom = X.
// X = tom.
TEST ( Atom , matchSuccessToVar ) {
	Atom tom ( "tom" );
	Variable X ( "X" );
	tom.matchToVariable ( X );
	ASSERT_EQ ( "tom" , X.get_symbol() );
}

// ?- X=tom, tom=X.
// X = tom.
TEST ( Atom , matchSuccessToVarInstantedToDiffConstant ) {
	Variable X ( "X" );
	Atom tom ( "tom" );
	X.matchToAtom ( tom );
	tom.matchToVariable ( X );
	ASSERT_EQ ( "tom" , X.get_symbol());
}

// ?- X=jerry, tom=X.
// false.
TEST ( Atom , matchFailureToVarInstantedToDiffConstant ) {
	Variable X ( "X" );
	Atom tom ( "tom" );
	Atom jerry ( "jerry" );
	X.matchToAtom ( jerry );
	tom.matchToVariable ( X );
	ASSERT_FALSE ( ( "tom" == X.get_symbol() ) ? true : false );
}

// ?- X = 5.
// X = 5.
TEST ( Var , matchSuccessToNumber ) {
	Variable X ( "X" );
	Number number ( 5 );
	X.matchToNumber ( number );
	ASSERT_EQ ( "5" , X.get_symbol() );
}

// ?- X=25, X= 100.
// false.
TEST ( Var , matchFailureToTwoDiffNumbers ) {
	Variable X ( "X" );
	Number numberOne ( 25 );
	Number numberTwo ( 100 );
	X.matchToNumber ( numberOne );
	X.matchToNumber ( numberTwo );
	ASSERT_FALSE ( ( "100" == X.get_symbol() ) ? true : false ); 
}

// ?- X=tom, X= 25.
// false.
TEST ( Var , matchSuccessToAtomThenFailureToNumber ) {
	Variable X ( "X" );
	Atom tom ( "tom" );
	Number number ( 25 );
	X.matchToAtom ( tom );
	X.matchToNumber ( number );
	ASSERT_FALSE ( ( "25" == X.get_symbol() ) ? true : false );
}

//?- tom=X, 25=X.
//false.
TEST ( Var , matchSuccessToAtomThenFailureToNumber2 ) {
	Atom tom ( "tom" );
	Variable X ( "X" );
	Number number ( 25 );
	tom.matchToVariable ( X );
	number.matchToVariable ( X );
	ASSERT_FALSE ( ( "25" == X.get_symbol() ) ? true : false );
}

//?- X=tom, X=tom.
//true.
TEST( Var , reAssignTheSameAtom ){
	Variable X ( "X" );
	Atom tom ( "tom" );
	X.matchToAtom ( tom );
	X.matchToAtom ( tom );
	ASSERT_TRUE ( ( "tom" == X.get_symbol() ) ? true : false );
}

#endif
