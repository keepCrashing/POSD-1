#ifndef UTTERM_H
#define UTTERM_H

#include "include/Atom.h"
#include "include/Variable.h"
#include "include/Number.h"

//test Number.value()
TEST ( Number , ctor ) {
	Number number ( "one" , "15" );
	ASSERT_EQ ( "15" , number.get_value() );
}

//test Number.symbol()
TEST ( Number , symbol ) {
	Number number ( "one" , "15" ) ;
	ASSERT_EQ ( "one" , number.get_symbol() );
}

//?- 25=25.
//true.
TEST ( Number , matchSuccess ) {
	Number number1 ( "one" , "25" );
        Number number2 ( "two" , "25");
	ASSERT_TRUE ( number1.matchToNumber ( number2 ) );
}

//?- 25=0.
//false.
TEST ( Number , matchFailureDiffValue ) {
	Number number1 ( "one" , "25" );
        Number number2 ( "two" , "0" );
	ASSERT_FALSE ( number1.matchToNumber ( number2 ) );
}

//?- 25=tom.
//false.
TEST ( Number , matchFailureDiffConstant ) {
	Number number ( "one" , "25" );
	Atom tom( "tom" );
	ASSERT_FALSE ( number.matchToAtom ( tom ) );	
}

//?- 25=X.
//true.
TEST ( Number , matchSuccessToVar ) {
	Number number ( "one" , "25" );
	Variable X ( "X" );
	number.matchToVariable ( X );
	ASSERT_EQ ( "25" , X.get_symbol() );
}

//?- tom=25.
//false.
TEST ( Atom , matchFailureDiffConstant ) {
	Atom tom ( "tom" );
	Number number ( "one" , "25" );
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
	Number number ( "one" , "5" );
	X.matchToNumber ( number );
	ASSERT_EQ ( "5" , X.get_symbol() );
}

// ?- X=25, X= 100.
// false.
TEST ( Var , matchFailureToTwoDiffNumbers ) {
	Variable X ( "X" );
	Number number1 ( "one" , "25" );
	Number number2 ( "two" , "100" );
	X.matchToNumber ( number1 );
	X.matchToNumber ( number2 );
	ASSERT_FALSE ( ( "100" == X.get_symbol() ) ? true : false ); 
}

// ?- X=tom, X= 25.
// false.
TEST ( Var , matchSuccessToAtomThenFailureToNumber ) {
	Variable X ( "X" );
	Atom tom ( "tom" );
	Number number ( "one" , "25" );
	X.matchToAtom ( tom );
	X.matchToNumber ( number );
	ASSERT_FALSE ( ( "25" == X.get_symbol() ) ? true : false );
}

//?- tom=X, 25=X.
//false.
TEST ( Var , matchSuccessToAtomThenFailureToNumber2 ) {
	Atom tom ( "tom" );
	Variable X ( "X" );
	Number number ( "one" , "25" );
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
