#ifndef UTTERM_H
#define UTTERM_H

#include "number.h"
#include "atom.h"
#include "variable.h"

//test Number.value()
TEST ( Number , ctor ) {
	Number number ( 15 );
	ASSERT_TRUE ( number.value() );
}

//test Number.symbol()
TEST ( Number , symbol ) {
	Number number ( 15 ) ;
	ASSERT_EQ ( 15 , number.symbol() );
}

//?- 25=25.
//true.
TEST ( Number , matchSuccess ) {
	Number numberOne ( 25 );
        Number numberTwo ( 25 );
	ASSERT_TRUE ( numberOne.match ( numberTwo ) );
}

//?- 25=0.
//false.
TEST ( Number , matchFailureDiffValue ) {
	Number numberOne ( 25 );
        Number numberTwo ( 0 );
	ASSERT_FALSE ( numberOne.match ( numberTwo ) );
}

//?- 25=tom.
//false.
TEST ( Number , matchFailureDiffConstant ) {
	Number number ( 25 );
	Atom tom( "tom" );
	ASSERT_FALSE ( number.match ( tom ) );	
}

//?- 25=X.
//true.
TEST ( Number , matchSuccessToVar ) {
	Number number ( 25 );
	Variable X ( "X" );
	number.match ( X );
	ASSERT_EQ ( "25" , X.value() );
}

//?- tom=25.
//false.
TEST ( Atom , matchFailureDiffConstant ) {
	Atom tom ( "tom" );
	Number number ( 25 );
	ASSERT_FALSE ( tom.match ( number ) );
}

// ?- tom = X.
// X = tom.
TEST ( Atom , matchSuccessToVar ) {
	Atom tom ( "tom" );
	Variable X ( "X" );
	tom.match ( X );
	ASSERT_EQ ( "tom" , X.value() );
}

// ?- X=tom, tom=X.
// X = tom.
TEST ( Atom , matchSuccessToVarInstantedToDiffConstant ) {
	Variable X ( "X" );
	Atom tom ( "tom" );
	X.match ( tom );
	tom.match ( X );
	ASSERT_EQ ( "tom" , X.value());
}

// ?- X=jerry, tom=X.
// false.
TEST ( Atom , matchFailureToVarInstantedToDiffConstant ) {
	Variable X ( "X" );
	Atom tom ( "tom" );
	Atom jerry ( "jerry" );
	X.match ( jerry );
	tom.match ( X );
	ASSERT_FALSE ( ( "tom" == X.value() ) ? true : false );
}

// ?- X = 5.
// X = 5.
TEST ( Variable , matchSuccessToNumber ) {
	Variable X ( "X" );
	Number number ( 5 );
	X.match ( number );
	ASSERT_EQ ( "5" , X.value() );
}

// ?- X=25, X= 100.
// false.
TEST ( Variable , matchFailureToTwoDiffNumbers ) {
	Variable X ( "X" );
	Number numberOne ( 25 );
	Number numberTwo ( 100 );
	X.match ( numberOne );
	X.match ( numberTwo );
	ASSERT_FALSE ( ( "100" == X.value() ) ? true : false ); 
}

// ?- X=tom, X= 25.
// false.
TEST ( Variable , matchSuccessToAtomThenFailureToNumber ) {
	Variable X ( "X" );
	Atom tom ( "tom" );
	Number number ( 25 );
	X.match ( tom );
	X.match ( number );
	ASSERT_FALSE ( ( "25" == X.value() ) ? true : false );
}

//?- tom=X, 25=X.
//false.
TEST ( Variable , matchSuccessToAtomThenFailureToNumber2 ) {
	Atom tom ( "tom" );
	Variable X ( "X" );
	Number number ( 25 );
	tom.match ( X );
	number.match ( X );
	ASSERT_FALSE ( ( "25" == X.value() ) ? true : false );
}

//?- X=tom, X=tom.
//true.
TEST( Variable , reAssignTheSameAtom ){
	Variable X ( "X" );
	Atom tom ( "XXX" );
	X.match ( tom );
	X.match ( tom );
	ASSERT_TRUE ( ( "tom" == X.value() ) ? true : false );
}

#endif
