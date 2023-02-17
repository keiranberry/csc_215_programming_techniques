#include "..\\catch.hpp"
#include "strLib.h"

//include test cases from document here
TEST_CASE("replaceAllCString - single substitution, same size")
{
	char array[100] = "This is a simple sentence.";
	char answer[100] = "This is a sample sentence.";
	char searchStr[20] = "simple";
	char replaceStr[20] = "sample";

	replaceAllCString(array, searchStr, replaceStr);
	REQUIRE(strcmp(answer, array) == 0);
}

TEST_CASE("replaceAllCString - single substitution, smaller replacement")
{
	char array[100] = "This is a simple sentence.";
	char answer[100] = "This is a silly sentence.";
	char searchStr[20] = "simple";
	char replaceStr[20] = "silly";

	replaceAllCString(array, searchStr, replaceStr);
	REQUIRE(strcmp(answer, array) == 0);
}

TEST_CASE("replaceAllCString - single substitution, larger replacement")
{
	char array[100] = "This is a silly sentence.";
	char answer[100] = "This is a really simple sentence.";
	char searchStr[20] = "silly";
	char replaceStr[20] = "really simple";

	replaceAllCString(array, searchStr, replaceStr);
	REQUIRE(strcmp(answer, array) == 0);
}

TEST_CASE("replaceAllCString - multiple subs, same size")
{
	char array[100] = "This is a long long program.";
	char answer[100] = "This is a hard hard program.";
	char searchStr[20] = "long";
	char replaceStr[20] = "hard";

	replaceAllCString(array, searchStr, replaceStr);
	REQUIRE(strcmp(answer, array) == 0);
}

TEST_CASE("replaceAllCString - multiple subs, larger size")
{
	char array[100] = "This is a long long program.";
	char answer[100] = "This is a challenging challenging program.";
	char searchStr[20] = "long";
	char replaceStr[20] = "challenging";

	replaceAllCString(array, searchStr, replaceStr);
	REQUIRE(strcmp(answer, array) == 0);
}

TEST_CASE("replaceAllCString - multiple subs, smaller size")
{
	char array[100] = "This is a difficult difficult program.";
	char answer[100] = "This is a long long program.";
	char searchStr[20] = "difficult";
	char replaceStr[20] = "long";

	replaceAllCString(array, searchStr, replaceStr);
	REQUIRE(strcmp(answer, array) == 0);
}

TEST_CASE("replaceAllCString - no subs")
{
	char array[100] = "This is a difficult difficult program.";
	char answer[100] = "This is a difficult difficult program.";
	char searchStr[20] = "blue";
	char replaceStr[20] = "long";

	replaceAllCString(array, searchStr, replaceStr);
	REQUIRE(strcmp(answer, array) == 0);
}

TEST_CASE("replaceAllCString - loop")
{
	char array[100] = "This is a difficult program.";
	char answer[100] = "This is a very difficult program.";
	char searchStr[20] = "difficult";
	char replaceStr[20] = "very difficult";

	replaceAllCString(array, searchStr, replaceStr);
	REQUIRE(strcmp(answer, array) == 0);
}

TEST_CASE("replaceAllCString - nothing to replace")
{
	char array[100] = "This is a difficult difficult program.";
	char answer[100] = "This is a   program.";
	char searchStr[20] = "difficult";
	char replaceStr[20] = "";

	replaceAllCString(array, searchStr, replaceStr);
	REQUIRE(strcmp(answer, array) == 0);
}

TEST_CASE("replaceAllCString - empty string")
{
	char array[100] = "";
	char answer[100] = "";
	char searchStr[20] = "blue";
	char replaceStr[20] = "long";

	replaceAllCString(array, searchStr, replaceStr);
	REQUIRE(strcmp(answer, array) == 0);
}

TEST_CASE("replaceAllCString - fo to of")
{
	char array[100] = "fofofofofofofofofofofofofofofofo";
	char answer[100] = "ofofofofofofofofofofofofofofofof";
	char searchStr[20] = "fo";
	char replaceStr[20] = "of";

	replaceAllCString(array, searchStr, replaceStr);
	REQUIRE(strcmp(answer, array) == 0);
}

TEST_CASE("replaceAllString - single substitution, same size")
{
	string array = "This is a simple sentence.";
	string answer = "This is a sample sentence.";
	string searchStr = "simple";
	string replaceStr = "sample";

	replaceAllString(array, searchStr, replaceStr);
	REQUIRE( answer == array );
}

TEST_CASE("replaceAllString - single substitution, smaller replacement")
{
	string array = "This is a simple sentence.";
	string answer = "This is a silly sentence.";
	string searchStr = "simple";
	string replaceStr = "silly";

	replaceAllString(array, searchStr, replaceStr);
	REQUIRE( answer == array);
}

TEST_CASE("replaceAllString - single substitution, larger replacement")
{
	string array = "This is a silly sentence.";
	string answer = "This is a really simple sentence.";
	string searchStr = "silly";
	string replaceStr = "really simple";

	replaceAllString(array, searchStr, replaceStr);
	REQUIRE(answer == array);
}

TEST_CASE("replaceAllString - multiple subs, same size")
{
	string array = "The brown dog is brown.";
	string answer = "The black dog is black.";
	string searchStr = "brown";
	string replaceStr = "black";

	replaceAllString(array, searchStr, replaceStr);
	REQUIRE(answer == array);
}

TEST_CASE("replaceAllString - multiple subs, larger size")
{
	string array = "The brown dog is brown.";
	string answer = "The maroon dog is maroon.";
	string searchStr = "brown";
	string replaceStr = "maroon";

	replaceAllString(array, searchStr, replaceStr);
	REQUIRE(answer == array);
}

TEST_CASE("replaceAllString - multiple subs, smaller size")
{
	string array = "The brown dog is brown.";
	string answer = "The red dog is red.";
	string searchStr = "brown";
	string replaceStr = "red";

	replaceAllString(array, searchStr, replaceStr);
	REQUIRE(answer == array);
}

TEST_CASE("replaceAllString - no subs")
{
	string array = "The brown dog is brown.";
	string answer = "The brown dog is brown.";
	string searchStr = "red";
	string replaceStr = "seventeen";

	replaceAllString(array, searchStr, replaceStr);
	REQUIRE(answer == array);
}

TEST_CASE("replaceAllString - empty string")
{
	string array = "";
	string answer = "";
	string searchStr = "red";
	string replaceStr = "seventeen";

	replaceAllString(array, searchStr, replaceStr);
	REQUIRE(answer == array);
}

TEST_CASE("replaceAllString - loop")
{
	string array = "This is a loop.";
	string answer = "This is not a loop.";
	string searchStr = "a";
	string replaceStr = "not a";

	replaceAllString(array, searchStr, replaceStr);
	REQUIRE(answer == array);
}