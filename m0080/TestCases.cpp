#include "sortedSingle.h"
#include "..\catch.hpp"
#include <sstream>
#include <iostream>

using namespace std;


TEST_CASE("empty - initial test")
{
    sortedSingle empList;
    bool emp = empList.empty();

    REQUIRE(emp == true);
}

TEST_CASE("size - initial test")
{
    sortedSingle list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    int lSize;
    lSize = list.size();
    REQUIRE(lSize == 3);
}

TEST_CASE("size - testing empty list")
{
    sortedSingle eList;
    int lSize;
    lSize = eList.size();
    REQUIRE(lSize == 0);
}

TEST_CASE("find - initial test")
{
    sortedSingle list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    bool found = list.find(2);

    REQUIRE(found == true);
}

TEST_CASE("find - testing something not in the list")
{
    sortedSingle list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    bool found = list.find(4);

    REQUIRE(found == false);
}

TEST_CASE("find - testing something at the end")
{
    sortedSingle list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(5);
    list.insert(6);
    bool found = list.find(6);

    REQUIRE(found == true);
}

TEST_CASE("find - testing something at the start")
{
    sortedSingle list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(5);
    list.insert(6);
    bool found = list.find(1);

    REQUIRE(found == true);
}

TEST_CASE("retrievePosition - initial test")
{
    sortedSingle list;
    list.insert(2);
    list.insert(12);
    list.insert(36);
    int where = list.retrievePosition(2);

    REQUIRE(where == 1);
}

TEST_CASE("retrievePosition - testing something not in the list")
{
    sortedSingle list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    int where = list.retrievePosition(4);

    REQUIRE(where == 0);
}

TEST_CASE("retrievePosition - testing something at the end")
{
    sortedSingle list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(5);
    list.insert(6);
    int where = list.retrievePosition(6);

    REQUIRE(where == 5);
}

TEST_CASE("retrievePosition - testing something in the middle")
{
    sortedSingle list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(5);
    list.insert(6);
    int where = list.retrievePosition(5);

    REQUIRE(where == 4);
}

TEST_CASE("insert - initial test")
{
    sortedSingle list;
    list.insert(1);
    list.insert(2);
    list.insert(1);
    int where = list.retrievePosition(2);
    int size = list.size();
    REQUIRE(size == 3);
    REQUIRE(where == 3);

}

TEST_CASE("insert - further testing")
{
    sortedSingle list;
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(69);
    list.insert(420);
    list.insert(3);
    int where = list.retrievePosition(69);
    int size = list.size();
    REQUIRE(size == 6);
    REQUIRE(where == 5);

}

TEST_CASE("print - initial test of print with cout")
{
    sortedSingle list;
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(69);
    list.insert(420);
    list.insert(3);
    list.print(cout, ", ");
}

TEST_CASE("print - second test of print with cout")
{
    sortedSingle list;
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(69);
    list.insert(420);
    list.insert(3);
    list.insert(1543);
    list.insert(1337);
    list.print(cout, ", ");
}

TEST_CASE("remove - initial test of remove")
{
    sortedSingle list;
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(69);
    list.insert(420);
    list.insert(3);
    list.insert(1543);
    list.insert(1337);
    int size = list.size();
    CHECK(size == 8);
    list.remove(69);
    size = list.size();
    REQUIRE(size == 7);
}

TEST_CASE("remove - testing multiple removes")
{
    sortedSingle list;
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(69);
    list.insert(420);
    list.insert(3);
    list.insert(1543);
    list.insert(1337);
    int size = list.size();
    CHECK(size == 8);
    bool removed = list.remove(69);
    CHECK(removed == true);
    removed = list.remove(1337);
    size = list.size();
    CHECK(size == 6);
    REQUIRE(removed == true);
}

TEST_CASE("remove - testing that only the first instance is removed")
{
    sortedSingle list;
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(69);
    list.insert(420);
    list.insert(3);
    list.insert(1543);
    list.insert(1337);
    int size = list.size();
    CHECK(size == 8);
    bool removed = list.remove(1);
    CHECK(removed == true);
    size = list.size();
    CHECK(size == 7);
    REQUIRE(removed == true);
}

TEST_CASE("remove - testing removing something that doesnt exist")
{
    sortedSingle list;
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(69);
    list.insert(420);
    list.insert(3);
    list.insert(1543);
    list.insert(1337);
    int size = list.size();
    CHECK(size == 8);
    bool removed = list.remove(242);
    size = list.size();
    CHECK(size == 8);
    REQUIRE(removed == false);

}

TEST_CASE("remove - testing removing from an empty list")
{
    sortedSingle list;
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(69);
    list.insert(420);
    list.insert(3);
    list.insert(1543);
    list.insert(1337);
    int size = list.size();
    CHECK(size == 8);
    list.clear();
    size = list.size();
    CHECK(size == 0);
    bool removed = list.remove(69);
    REQUIRE(removed == false);

}

TEST_CASE("clear - initial test of clear")
{
    sortedSingle list;
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(69);
    list.insert(420);
    list.insert(3);
    list.insert(1543);
    list.insert(1337);
    int size = list.size();
    CHECK(size == 8);
    list.clear();
    size = list.size();
    REQUIRE(size == 0);
}

TEST_CASE("clear - second test of clear")
{
    sortedSingle list;
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(69);
    int size = list.size();
    CHECK(size == 4);
    list.clear();
    size = list.size();
    REQUIRE(size == 0);
}

TEST_CASE("clear - clearing an empty list")
{
    sortedSingle list;
    int size = list.size();
    CHECK(size == 0);
    list.clear();
    size = list.size();
    REQUIRE(size == 0);
}

TEST_CASE("copy - copying an empty list")
{
    sortedSingle eList;
    int size = eList.size();
    CHECK(size == 0);

    sortedSingle destination;
    destination = sortedSingle(eList);
    int dsize = destination.size();
    REQUIRE(dsize == 0);
}

TEST_CASE("copy - copying a list with 1 item")
{
    sortedSingle src;
    src.insert(69);
    int size = src.size();
    CHECK(size == 1);

    sortedSingle destination(src);
    bool found = destination.find(69);
    REQUIRE(found == true);
}

TEST_CASE("copy - copying a list with multiple items")
{
    sortedSingle src;
    src.insert(1);
    src.insert(2);
    src.insert(1);
    src.insert(69);
    src.insert(420);
    src.insert(3);
    src.insert(1543);
    src.insert(1337);
    int size = src.size();
    CHECK(size == 8);

    sortedSingle destination(src);
    bool found = destination.find(69);
    REQUIRE(found == true);
    found = destination.find(1);
    REQUIRE(found == true);
    found = destination.find(2);
    REQUIRE(found == true);
    found = destination.find(420);
    REQUIRE(found == true);
    found = destination.find(3);
    REQUIRE(found == true);
    found = destination.find(1543);
    REQUIRE(found == true);
    found = destination.find(1337);
    REQUIRE(found == true);
}