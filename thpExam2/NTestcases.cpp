#include "thpExam2.h"
#include "..\\catch.hpp"


TEST_CASE( "checkString - with sections" )
{
    string word;

    SECTION ( "testing an empty string" )
    {
        word = "";
        checkString ( word );

        REQUIRE ( word == "" );
    }
    SECTION ( "testing with only punctuation" )
    {
        word = "..-";
        checkString ( word );

        REQUIRE ( word == "" );
    }
    SECTION( "testing a string without puctuation" )
    {
        word = "nico";
        checkString( word );

        REQUIRE( word == "nico" );
    }
    SECTION( "testing a string with outside puctuation" )
    {
        word = ".!nico<--";
        checkString( word );

        REQUIRE( word == "nico" );
    }
    SECTION( "testing a string with outside and inside puctuation" )
    {
        word = "!!Ni-Co<--";
        checkString( word );

        REQUIRE( word == "ni-co" );
    }
}