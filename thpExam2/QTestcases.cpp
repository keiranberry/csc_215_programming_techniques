#include "thpExam2.h"
#include "..\\catch.hpp"


TEST_CASE ( "insert test case - with sections" )
{
    list baseList;

    SECTION ( "begining insert" )
    {
        REQUIRE ( baseList.insert ( "Hello World" ) );
        REQUIRE ( baseList.wordAt(0) == "Hello World" );
    }

    SECTION ( "2 inserts" )
    {
        REQUIRE ( baseList.insert ( "Hello" ) );
        REQUIRE ( baseList.insert ( "World" ) );
        REQUIRE ( baseList.wordAt ( 0 ) == "Hello" );
        REQUIRE ( baseList.wordAt ( 1 ) == "World" );
    }
    
    SECTION ( "3 inserts" )
    {
        REQUIRE ( baseList.insert ( "Hello" ) );
        REQUIRE ( baseList.insert ( "There" ) );
        REQUIRE ( baseList.insert ( "World" ) );
        REQUIRE ( baseList.wordAt ( 0 ) == "Hello" );
        REQUIRE ( baseList.wordAt ( 1 ) == "There" );
        REQUIRE ( baseList.wordAt ( 2 ) == "World" );
    }

    SECTION ( "2 inserts then one in middle" )
    {
        baseList.insert ( "Hello" );
        baseList.insert ( "World" );
        baseList.insert ( "There" );
        REQUIRE ( baseList.wordAt ( 0 ) == "Hello" );
        REQUIRE ( baseList.wordAt ( 1 ) == "There" );
        REQUIRE ( baseList.wordAt ( 2 ) == "World" );
    }

    SECTION ( "2 inserts, second before first" )
    {
        baseList.insert ( "World" );
        baseList.insert ( "Hello" );
        REQUIRE ( baseList.wordAt ( 0 ) == "Hello" );
        REQUIRE ( baseList.wordAt ( 1 ) == "World" );
    }
    SECTION ( "Same word inserted twice" )
    {
        baseList.insert ( "Hello World" );
        REQUIRE ( baseList.insert ( "Hello World" ) );
        REQUIRE ( baseList.wordAt ( 0 ) == "Hello World" );
        REQUIRE ( baseList.freqAt ( 0 ) == 2 );
    }
}

TEST_CASE ( "getF - with sections" )
{
    list baseList;
    vector <int> freqVect;

    SECTION ( "single word" )
    {
        baseList.insert ( "Hello World" );
        baseList.getF ( freqVect );

        REQUIRE ( freqVect.at ( 0 ) == 1 );

    }

    SECTION ( "two words" )
    {
        baseList.insert ( "Hello" );
        baseList.insert ( "World" );

        baseList.getF ( freqVect );

        REQUIRE ( freqVect.at ( 0 ) == 1 );
        REQUIRE ( freqVect.size ( ) == 1 );
    }

    SECTION ( "Same word twice" )
    {
        baseList.insert ( "Hello World" );
        baseList.insert ( "Hello World" );

        baseList.getF ( freqVect );

        REQUIRE ( freqVect.at ( 0 ) == 2 );
        REQUIRE ( freqVect.size ( ) == 1 );
    }

    SECTION ( "Three words, then two, then one" )
    {
        baseList.insert ( "Hello" );
        baseList.insert ( "Hello" );
        baseList.insert ( "Hello" );
        baseList.insert ( "There" );
        baseList.insert ( "There" );
        baseList.insert ( "World" );

        baseList.getF ( freqVect );

        REQUIRE ( freqVect.at ( 0 ) == 3 );
        REQUIRE ( freqVect.at ( 1 ) == 2 );
        REQUIRE ( freqVect.at ( 2 ) == 1 );
        REQUIRE ( freqVect.size ( ) == 3 );
    }

    SECTION ( "One word, then two, then three" )
    {
        baseList.insert ( "Hello" );
        baseList.insert ( "There" );
        baseList.insert ( "There" );
        baseList.insert ( "World" );
        baseList.insert ( "World" );
        baseList.insert ( "World" );

        baseList.getF ( freqVect );

        REQUIRE ( freqVect.at ( 0 ) == 3 );
        REQUIRE ( freqVect.at ( 1 ) == 2 );
        REQUIRE ( freqVect.at ( 2 ) == 1 );
        REQUIRE ( freqVect.size ( ) == 3 );
    }

    SECTION ( "Two words, then two, then one" )
    {
        baseList.insert ( "Hello" );
        baseList.insert ( "Hello" );
        baseList.insert ( "There" );
        baseList.insert ( "There" );
        baseList.insert ( "World" );
        
        baseList.getF ( freqVect );
        
        REQUIRE ( freqVect.at ( 0 ) == 2 );
        REQUIRE ( freqVect.at ( 1 ) == 1 );
        REQUIRE ( freqVect.size ( ) == 2 );

    }
}


TEST_CASE ( "getL - with sections" )
{
    list baseList;
    vector <int> lengVect;

    SECTION ( "single word" )
    {
        baseList.insert ( "Hello World" );
        baseList.getL ( lengVect );

        REQUIRE ( lengVect.at ( 0 ) == 11 );
        REQUIRE ( lengVect.size ( ) == 1 );

    }

    SECTION ( "two same length words" )
    {
        baseList.insert ( "Hello" );
        baseList.insert ( "World" );

        baseList.getL ( lengVect );

        REQUIRE ( lengVect.at ( 0 ) == 5 );
        REQUIRE ( lengVect.size ( ) == 1 );
    }

    SECTION ( "Two words, different length" )
    {
        baseList.insert ( "Hi" );
        baseList.insert ( "World" );

        baseList.getL ( lengVect );

        REQUIRE ( lengVect.at ( 0 ) == 5 );
        REQUIRE ( lengVect.at ( 1 ) == 2 );
        REQUIRE ( lengVect.size ( ) == 2 );
    }

    SECTION ( "Three words of different length" )
    {
        baseList.insert ( "Hi" );
        baseList.insert ( "World" );
        baseList.insert ( "Cat" );

        baseList.getL ( lengVect );

        REQUIRE ( lengVect.at ( 0 ) == 5 );
        REQUIRE ( lengVect.at ( 1 ) == 3 );
        REQUIRE ( lengVect.at ( 2 ) == 2 );
        REQUIRE ( lengVect.size ( ) == 3 );
    }
}


TEST_CASE ( "printA - with sections" )
{
    list myWords;
    ostringstream sout;

    SECTION ( "one word insert" )
    {
        myWords.insert ( "book" );

        myWords.printA ( sout );
        string s = sout.str ( );
        REQUIRE ( sout.str ( ) == "********************************************************************************\n*"
            " words starting with b\n********************************************************************************\n"
            "book                      \n\n" );
    }
}
