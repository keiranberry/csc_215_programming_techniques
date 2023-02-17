#include "..\\catch.hpp"
#include "bitpacking.h"

TEST_CASE("packThree - initial test of packThree")
{
	char hi = 'a';
	char mid = 'b';
    char lo = 'c';

	short int output = packThree(hi, mid, lo);

	REQUIRE(output == 1091);

}

TEST_CASE("packThree - second test of packThree with lowercase")
{
	char hi = 'a';
	char mid = 'x';
	char lo = 'y';

	short int output = packThree(hi, mid, lo);

	REQUIRE(output == 1817);

}

TEST_CASE("packThree - third lowercase test of packThree")
{
	char hi = 'f';
	char mid = 'b';
	char lo = 'z';

	short int output = packThree(hi, mid, lo);

	REQUIRE(output == 6234);

}

TEST_CASE("packThree - first uppercase test of packThree")
{
	char hi = 'A';
	char mid = 'B';
	char lo = 'C';

	short int output = packThree(hi, mid, lo);

	REQUIRE(output == 1091);

}

TEST_CASE("packThree - second uppercase test of packThree")
{
	char hi = 'A';
	char mid = 'X';
	char lo = 'Y';

	short int output = packThree(hi, mid, lo);

	REQUIRE(output == 1817);

}

TEST_CASE("packThree - third uppercase test of packThree")
{
	char hi = 'F';
	char mid = 'B';
	char lo = 'Z';

	short int output = packThree(hi, mid, lo);

	REQUIRE(output == 6234);

}

TEST_CASE("packThree - mixed case test of packThree")
{
	char hi = 'F';
	char mid = 'b';
	char lo = 'Z';

	short int output = packThree(hi, mid, lo);

	REQUIRE(output == 6234);

}

TEST_CASE("unpackThree - first test of unpackThree")
{
	char high;
	char mid;
	char low;
	CHARCASE caseIn = LOWERCASE;
	short int code = 1091;

	unpackThree(code, high, mid, low, caseIn);

	CHECK(high == 'a');
	CHECK(mid == 'b');
	CHECK(low == 'c');

}

TEST_CASE("unpackThree - second lowercase test of unpackThree")
{
	char high;
	char mid;
	char low;
	CHARCASE caseIn = LOWERCASE;
	short int code = 1817;

	unpackThree(code, high, mid, low, caseIn);

	CHECK(high == 'a');
	CHECK(mid == 'x');
	CHECK(low == 'y');

}

TEST_CASE("unpackThree - third lowercase test of unpackThree")
{
	char high;
	char mid;
	char low;
	CHARCASE caseIn = LOWERCASE;
	short int code = 6234;

	unpackThree(code, high, mid, low, caseIn);

	CHECK(high == 'f');
	CHECK(mid == 'b');
	CHECK(low == 'z');

}

TEST_CASE("unpackThree - first test of unpackThree uppercase")
{
	char high;
	char mid;
	char low;
	CHARCASE caseIn = UPPERCASE;
	short int code = 1091;

	unpackThree(code, high, mid, low, caseIn);

	CHECK(high == 'A');
	CHECK(mid == 'B');
	CHECK(low == 'C');

}

TEST_CASE("unpackThree - second test of unpackThree uppercase")
{
	char high;
	char mid;
	char low;
	CHARCASE caseIn = UPPERCASE;
	short int code = 1817;

	unpackThree(code, high, mid, low, caseIn);

	CHECK(high == 'A');
	CHECK(mid == 'X');
	CHECK(low == 'Y');

}

TEST_CASE("unpackThree - third test of unpackThree uppercase")
{
	char high;
	char mid;
	char low;
	CHARCASE caseIn = UPPERCASE;
	short int code = 6234;

	unpackThree(code, high, mid, low, caseIn);

	CHECK(high == 'F');
	CHECK(mid == 'B');
	CHECK(low == 'Z');

}