#include "thpExam2.h"
#include "..\\catch.hpp"

TEST_CASE("size - initial test")
{
    list testList;
    testList.insert("one");
    testList.insert("two");
    testList.insert("three");
    int lSize;
    lSize = testList.size();
    REQUIRE(lSize == 3);
}

TEST_CASE("size - testing empty list")
{
    list eList;
    int lSize;
    lSize = eList.size();
    REQUIRE(lSize == 0);
}

TEST_CASE("size - testing duplicates")
{
    list testList;
    testList.insert("one");
    testList.insert("two");
    testList.insert("three");
    testList.insert("three");
    int lSize;
    lSize = testList.size();
    REQUIRE(lSize == 3);
}