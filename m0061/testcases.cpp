#include "strlib.h"
#include "..\\catch.hpp"

//test cases here

TEST_CASE("recCStrCmp - v1 initial check with the same strings")
{
    char s1[100] = "this is an initial test";
    char s2[100] = "this is an initial test";

    SECTION("equal - same case")
    {
        REQUIRE(recCStrCmp(s1, s2, 0) == 0);
    }
    SECTION("equal - different case")
    {
        s1[2] = toupper(s1[2]);
        REQUIRE(recCStrCmp(s1, s2, 0) == 0);
        REQUIRE(recCStrCmp(s2, s1, 0) == 0);
    }
}

TEST_CASE("recCStrCmp - v1 hello same")
{
    char s1[100] = "hello";
    char s2[100] = "HELLO";

    SECTION("equal - same case")
    {
        REQUIRE(recCStrCmp(s1, s2, 0) == 0);
    }
    SECTION("equal - different case")
    {
        s1[2] = toupper(s1[2]);
        REQUIRE(recCStrCmp(s1, s2, 0) == 0);
        REQUIRE(recCStrCmp(s2, s1, 0) == 0);
    }
}


TEST_CASE("recCStrCmp - v1 initial check with different strings")
{
    char s1[100] = "zhis is an initial test";
    char s2[100] = "this is an initial test";

    SECTION("different - same case")
    {
        REQUIRE(recCStrCmp(s1, s2, 0) > 0);
    }
    SECTION("different - different case")
    {
        s1[0] = toupper(s1[0]);
        REQUIRE(recCStrCmp(s1, s2, 0) > 0);
        REQUIRE(recCStrCmp(s2, s1, 0) < 0);
    }
}

TEST_CASE("recCStrCmp - v1 second check with different strings")
{
    char s1[100] = "thps is an initial test";
    char s2[100] = "this is an initial test";

    SECTION("different - same case")
    {
        REQUIRE(recCStrCmp(s1, s2, 0) > 0);
    }
    SECTION("different - different case")
    {
        s1[2] = toupper(s1[2]);
        REQUIRE(recCStrCmp(s1, s2, 0) > 0);
        REQUIRE(recCStrCmp(s2, s1, 0) < 0);
    }
}

TEST_CASE("recCStrCmp - v1 s1 is longer")
{
    char s1[100] = "this is an initial test";
    char s2[100] = "this is an initial";

    SECTION("different - same case")
    {
        REQUIRE(recCStrCmp(s1, s2, 0) > 0);
    }
    SECTION("different - different case")
    {
        s1[2] = toupper(s1[2]);
        REQUIRE(recCStrCmp(s1, s2, 0) > 0);
        REQUIRE(recCStrCmp(s2, s1, 0) < 0);
    }
}

TEST_CASE("recCStrCmp - v1 s2 is longer")
{
    char s1[100] = "this is an initial ";
    char s2[100] = "this is an initial test";

    SECTION("different - same case")
    {
        REQUIRE(recCStrCmp(s1, s2, 0) < 0);
    }
    SECTION("different - different case")
    {
        s1[2] = toupper(s1[2]);
        REQUIRE(recCStrCmp(s1, s2, 0) < 0);
        REQUIRE(recCStrCmp(s2, s1, 0) > 0);
    }
}

TEST_CASE("recCStrCmp - v1 s1 is empty")
{
    char s1[100] = "";
    char s2[100] = "this is an initial test";

    SECTION("different - same case")
    {
        REQUIRE(recCStrCmp(s1, s2, 0) < 0);
    }
    SECTION("different - different case")
    {
        s1[2] = toupper(s1[2]);
        REQUIRE(recCStrCmp(s1, s2, 0) < 0);
        REQUIRE(recCStrCmp(s2, s1, 0) > 0);
    }
}

TEST_CASE("recCStrCmp - v1 numbers")
{
    char s1[100] = "asdf3";
    char s2[100] = "asdf9";

    SECTION("different - same case")
    {
        REQUIRE(recCStrCmp(s1, s2, 0) < 0);
    }
    SECTION("different - different case")
    {
        s1[2] = toupper(s1[2]);
        REQUIRE(recCStrCmp(s1, s2, 0) < 0);
        REQUIRE(recCStrCmp(s2, s1, 0) > 0);
    }
}


TEST_CASE("recCStrCmp - v2 initial check with the same strings")
{
    char s1[100] = "this is an initial test";
    char s2[100] = "this is an initial test";

    SECTION("equal - same case")
    {
        REQUIRE(recCStrCmp(s1, s2) == 0);
    }
    SECTION("equal - different case")
    {
        s1[2] = toupper(s1[2]);
        REQUIRE(recCStrCmp(s1, s2) == 0);
        REQUIRE(recCStrCmp(s2, s1) == 0);
    }
}

TEST_CASE("recCStrCmp - v2 initial check with different strings")
{
    char s1[100] = "zhis is an initial test";
    char s2[100] = "this is an initial test";

    SECTION("different - same case")
    {
        REQUIRE(recCStrCmp(s1, s2) > 0);
    }
    SECTION("different - different case")
    {
        s1[0] = toupper(s1[0]);
        REQUIRE(recCStrCmp(s1, s2) > 0);
        REQUIRE(recCStrCmp(s2, s1) < 0);
    }
}

TEST_CASE("recCStrCmp - v2 second check with different strings")
{
    char s1[100] = "thps is an initial test";
    char s2[100] = "this is an initial test";

    SECTION("different - same case")
    {
        REQUIRE(recCStrCmp(s1, s2) > 0);
    }
    SECTION("different - different case")
    {
        s1[2] = toupper(s1[2]);
        REQUIRE(recCStrCmp(s1, s2) > 0);
        REQUIRE(recCStrCmp(s2, s1) < 0);
    }
}

TEST_CASE("recCStrCmp - v2 s1 is longer")
{
    char s1[100] = "this is an initial test";
    char s2[100] = "this is an initial";

    SECTION("different - same case")
    {
        REQUIRE(recCStrCmp(s1, s2) > 0);
    }
    SECTION("different - different case")
    {
        s1[2] = toupper(s1[2]);
        REQUIRE(recCStrCmp(s1, s2) > 0);
        REQUIRE(recCStrCmp(s2, s1) < 0);
    }
}

TEST_CASE("recCStrCmp - v2 s2 is longer")
{
    char s1[100] = "this is an initial ";
    char s2[100] = "this is an initial test";

    SECTION("different - same case")
    {
        REQUIRE(recCStrCmp(s1, s2) < 0);
    }
    SECTION("different - different case")
    {
        s1[2] = toupper(s1[2]);
        REQUIRE(recCStrCmp(s1, s2) < 0);
        REQUIRE(recCStrCmp(s2, s1) > 0);
    }
}

TEST_CASE("recCStrCmp - v2 s1 is empty")
{
    char s1[100] = "";
    char s2[100] = "this is an initial test";

    SECTION("different - same case")
    {
        REQUIRE(recCStrCmp(s1, s2) < 0);
    }
    SECTION("different - different case")
    {
        s1[2] = toupper(s1[2]);
        REQUIRE(recCStrCmp(s1, s2) < 0);
        REQUIRE(recCStrCmp(s2, s1) > 0);
    }
}

TEST_CASE("recCStrCmp - v2 numbers")
{
    char s1[100] = "asdf3";
    char s2[100] = "asdf9";

    SECTION("different - same case")
    {
        REQUIRE(recCStrCmp(s1, s2) < 0);
    }
    SECTION("different - different case")
    {
        s1[2] = toupper(s1[2]);
        REQUIRE(recCStrCmp(s1, s2) < 0);
        REQUIRE(recCStrCmp(s2, s1) > 0);
    }
}

TEST_CASE("recCStrCmp - v2 hello same")
{
    char s1[100] = "hello";
    char s2[100] = "HELLO";

    SECTION("equal - same case")
    {
        REQUIRE(recCStrCmp(s1, s2) == 0);
    }
    SECTION("equal - different case")
    {
        s1[2] = toupper(s1[2]);
        REQUIRE(recCStrCmp(s1, s2) == 0);
        REQUIRE(recCStrCmp(s2, s1) == 0);
    }
}

TEST_CASE("recCStrCmp - v2 hello different")
{
    char s1[100] = "hello";
    char s2[100] = "helP";

    SECTION("different - same case")
    {
        REQUIRE(recCStrCmp(s1, s2) < 0);
    }
    SECTION("different - different case")
    {
        s1[2] = toupper(s1[2]);
        REQUIRE(recCStrCmp(s1, s2) < 0);
        REQUIRE(recCStrCmp(s2, s1) > 0);
    }
}