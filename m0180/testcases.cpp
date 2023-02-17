#include "sortedSingle.h"
#include "..\catch.hpp"
#include <sstream>
#include <iostream>

using namespace std;


TEST_CASE("empty - initial test")
{
    sortedSingle<int> empList;
    bool emp = empList.empty();

    REQUIRE(emp == true);
}

TEST_CASE("size - initial test")
{
    sortedSingle<int> list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    int lSize;
    lSize = list.size();
    REQUIRE(lSize == 3);
}

TEST_CASE("size - testing empty list")
{
    sortedSingle<int> eList;
    int lSize;
    lSize = eList.size();
    REQUIRE(lSize == 0);
}

TEST_CASE("find - initial test")
{
    sortedSingle<int> list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    bool found = list.find(2);

    REQUIRE(found == true);
}

TEST_CASE("find - double initial test")
{
    sortedSingle<double> list;
    list.insert(1.1456);
    list.insert(2.1243);
    list.insert(3.1234);
    bool found = list.find(2.1243);

    REQUIRE(found == true);
}

TEST_CASE("find - string initial test")
{
    sortedSingle<string> list;
    list.insert("one");
    list.insert("two");
    list.insert("three");
    bool found = list.find("two");

    REQUIRE(found == true);
}

TEST_CASE("find - testing something not in the list")
{
    sortedSingle<int> list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    bool found = list.find(4);

    REQUIRE(found == false);
}

TEST_CASE("find - testing something at the end")
{
    sortedSingle<int> list;
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
    sortedSingle<int> list;
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
    sortedSingle<int> list;
    list.insert(2);
    list.insert(12);
    list.insert(36);
    int where = list.retrievePosition(2);

    REQUIRE(where == 1);
}

TEST_CASE("retrievePosition - double initial test")
{
    sortedSingle<double> list;
    list.insert(2.1234);
    list.insert(12.1234);
    list.insert(36.1234);
    int where = list.retrievePosition(2.1234);

    REQUIRE(where == 1);
}

TEST_CASE("retrievePosition - string initial test")
{
    sortedSingle<string> list;
    list.insert("two");
    list.insert("twelve");
    list.insert("thirty-six");
    int where = list.retrievePosition("two");

    REQUIRE(where == 3);
}

TEST_CASE("retrievePosition - testing something not in the list")
{
    sortedSingle<int> list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    int where = list.retrievePosition(4);

    REQUIRE(where == 0);
}

TEST_CASE("retrievePosition - testing something at the end")
{
    sortedSingle<int> list;
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
    sortedSingle<int> list;
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
    sortedSingle<int> list;
    list.insert(1);
    list.insert(2);
    list.insert(1);
    int where = list.retrievePosition(2);
    int size = list.size();
    REQUIRE(size == 3);
    REQUIRE(where == 3);

}

TEST_CASE("insert - double initial test")
{
    sortedSingle<double> list;
    list.insert(1.1234);
    list.insert(2.1234);
    list.insert(1.1234);
    int where = list.retrievePosition(2.1234);
    int size = list.size();
    REQUIRE(size == 3);
    REQUIRE(where == 3);

}

TEST_CASE("insert - string initial test")
{
    sortedSingle<string> list;
    list.insert("one");
    list.insert("two");
    list.insert("one");
    int where = list.retrievePosition("two");
    int size = list.size();
    REQUIRE(size == 3);
    REQUIRE(where == 3);

}

TEST_CASE("insert - further testing")
{
    sortedSingle<int> list;
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

/*TEST_CASE("print - initial test of print with cout")
{
    sortedSingle<int> list;
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
    sortedSingle<int> list;
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(69);
    list.insert(420);
    list.insert(3);
    list.insert(1543);
    list.insert(1337);
    list.print(cout, ", ");
}*/

TEST_CASE("remove - initial test of remove")
{
    sortedSingle<int> list;
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
    sortedSingle<int> list;
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
    sortedSingle<int> list;
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
    sortedSingle<int> list;
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
    sortedSingle<int> list;
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
    sortedSingle<int> list;
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
    sortedSingle<int> list;
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
    sortedSingle<int> list;
    int size = list.size();
    CHECK(size == 0);
    list.clear();
    size = list.size();
    REQUIRE(size == 0);
}

TEST_CASE("copy - copying an empty list")
{
    sortedSingle<int> eList;
    int size = eList.size();
    CHECK(size == 0);

    sortedSingle<int> destination(eList);
    int dsize = destination.size();
    REQUIRE(dsize == 0);
}

TEST_CASE("copy - copying a list with 1 item")
{
    sortedSingle<int> src;
    src.insert(69);
    int size = src.size();
    CHECK(size == 1);

    sortedSingle<int> destination(src);
    bool found = destination.find(69);
    REQUIRE(found == true);
}

TEST_CASE("copy - copying a list with multiple items")
{
    sortedSingle<int> src;
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

    sortedSingle<int> destination(src);
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

TEST_CASE("swap - swapping a list with 1 item")
{
    sortedSingle<int> src;
    src.insert(69);
    int size = src.size();
    CHECK(size == 1);
    sortedSingle<int> src2;
    src2.insert(420);
    size = src2.size();
    CHECK(size == 1);


    src2.swap(src);
    bool found = src2.find(69);
    CHECK(found == true);

    found = src.find(420);
    REQUIRE(found == true);
}

TEST_CASE("swap - further testing of int")
{
    sortedSingle<int> src;
    src.insert(69);
    src.insert(1337);
    src.insert(4576);
    src.insert(8008);
    int size = src.size();
    CHECK(size == 4);
    sortedSingle<int> src2;
    src2.insert(420);
    size = src2.size();
    CHECK(size == 1);


    src2.swap(src);
    bool found = src2.find(69);
    CHECK(found == true);
    found = src2.find(1337);
    CHECK(found == true);
    found = src2.find(4576);
    CHECK(found == true);
    found = src2.find(8008);
    CHECK(found == true);
    found = src2.find(420);
    CHECK(found == false);

    found = src.find(420);
    REQUIRE(found == true);
}

TEST_CASE("swap - testing double")
{
    sortedSingle<double> src;
    src.insert(69.6969);
    src.insert(1337);
    src.insert(4576);
    src.insert(8008.58008);
    int size = src.size();
    CHECK(size == 4);
    sortedSingle<double> src2;
    src2.insert(420);
    size = src2.size();
    CHECK(size == 1);


    src2.swap(src);
    bool found = src2.find(69.6969);
    CHECK(found == true);
    found = src2.find(1337);
    CHECK(found == true);
    found = src2.find(4576);
    CHECK(found == true);
    found = src2.find(8008.58008);
    CHECK(found == true);
    found = src2.find(420);
    CHECK(found == false);

    found = src.find(420);
    REQUIRE(found == true);
}

TEST_CASE("swap - string list with 1 item")
{
    sortedSingle<string> src;
    src.insert("sixty-nine");
    int size = src.size();
    CHECK(size == 1);
    sortedSingle<string> src2;
    src2.insert("ninety-six");
    size = src2.size();
    CHECK(size == 1);


    src2.swap(src);
    bool found = src2.find("sixty-nine");
    CHECK(found == true);

    found = src.find("ninety-six");
    REQUIRE(found == true);
}

TEST_CASE("= - testing an empty list")
{
    sortedSingle<int> list;
    sortedSingle<int> source;
    source.insert(1);
    source.insert(2);
    source.insert(3);
    source.insert(4);
    bool found = list.find(1);
    CHECK(found == false);
    found = list.find(2);
    CHECK(found == false);
    found = list.find(3);
    CHECK(found == false);
    found = list.find(4);
    CHECK(found == false);

    list = source;

    found = list.find(1);
    CHECK(found == true);
    found = list.find(2);
    CHECK(found == true);
    found = list.find(3);
    CHECK(found == true);
    found = list.find(4);
    CHECK(found == true);
}

TEST_CASE("= - testing doubles")
{
    sortedSingle<double> list;
    sortedSingle<double> source;
    source.insert(1.1);
    source.insert(2.2);
    source.insert(3.3);
    source.insert(4.4);
    bool found = list.find(1.1);
    CHECK(found == false);
    found = list.find(2.2);
    CHECK(found == false);
    found = list.find(3.3);
    CHECK(found == false);
    found = list.find(4.4);
    CHECK(found == false);

    list = source;

    found = list.find(1.1);
    CHECK(found == true);
    found = list.find(2.2);
    CHECK(found == true);
    found = list.find(3.3);
    CHECK(found == true);
    found = list.find(4.4);
    CHECK(found == true);
}

TEST_CASE("= - testing doubles with dupes")
{
    sortedSingle<double> list;
    sortedSingle<double> source;
    source.insert(10.8);
    source.insert(10.8);
    source.insert(20.8);
    source.insert(20.8);
    source.insert(30.8);
    source.insert(30.8);
    source.insert(40.8);
    source.insert(40.8);
    source.insert(50.8);

    list = source;

    REQUIRE(list.size() == 5);
}

TEST_CASE("= - testing strings")
{
    sortedSingle<string> list;
    sortedSingle<string> source;
    source.insert("one");
    source.insert("two");
    source.insert("three");
    source.insert("four");
    bool found = list.find("one");
    CHECK(found == false);
    found = list.find("two");
    CHECK(found == false);
    found = list.find("three");
    CHECK(found == false);
    found = list.find("four");
    CHECK(found == false);

    list = source;

    found = list.find("one");
    CHECK(found == true);
    found = list.find("two");
    CHECK(found == true);
    found = list.find("three");
    CHECK(found == true);
    found = list.find("four");
    CHECK(found == true);
}

TEST_CASE("== - initial test with ints")
{
    sortedSingle<int> first;
    sortedSingle<int> second;
    first.insert(1);
    second.insert(2);

    REQUIRE((first == second) == false);
}

TEST_CASE("== - longer test with ints")
{
    sortedSingle<int> first;
    sortedSingle<int> second;
    first.insert(1);
    first.insert(2);
    first.insert(3);
    first.insert(4);
    first.insert(5);
    second.insert(1);
    second.insert(2);
    second.insert(3);
    second.insert(4);
    second.insert(5);

    REQUIRE((first == second) == true);
}

TEST_CASE("== - different size test with ints")
{
    sortedSingle<int> first;
    sortedSingle<int> second;
    first.insert(1);
    first.insert(2);
    first.insert(3);
    first.insert(4);
    second.insert(1);
    second.insert(2);
    second.insert(3);
    second.insert(4);
    second.insert(5);

    REQUIRE((first == second) == false);
}

TEST_CASE("== - initial test with doubles")
{
    sortedSingle<double> first;
    sortedSingle<double> second;
    first.insert(1);
    first.insert(2);
    first.insert(69.696969);

    second = first;

    second.insert(1333.3333);

    REQUIRE((first == second) == false);
}

TEST_CASE("== - second test with doubles")
{
    sortedSingle<double> first;
    sortedSingle<double> second;
    first.insert(1);
    first.insert(2);
    first.insert(69.696969);

    second = first;

    REQUIRE((first == second) == true);
}

TEST_CASE("== - initial test with strings")
{
    sortedSingle<string> first;
    sortedSingle<string> second;
    first.insert("one");
    first.insert("two");
    first.insert("three");

    second = first;

    second.insert("four");

    REQUIRE((first == second) == false);
}

TEST_CASE("== - second test with strings")
{
    sortedSingle<string> first;
    sortedSingle<string> second;
    first.insert("one");
    first.insert("two");
    first.insert("three");

    second = first;

    REQUIRE((first == second) == true);
}

TEST_CASE("!= - initial test with ints")
{
    sortedSingle<int> first;
    sortedSingle<int> second;
    first.insert(1);
    second.insert(2);

    REQUIRE((first != second) == true);
}

TEST_CASE("!= - longer test with ints")
{
    sortedSingle<int> first;
    sortedSingle<int> second;
    first.insert(1);
    first.insert(2);
    first.insert(3);
    first.insert(4);
    first.insert(5);
    second.insert(1);
    second.insert(2);
    second.insert(3);
    second.insert(4);
    second.insert(5);

    REQUIRE((first != second) == false);
}

TEST_CASE("!= - different size test with ints")
{
    sortedSingle<int> first;
    sortedSingle<int> second;
    first.insert(1);
    first.insert(2);
    first.insert(3);
    first.insert(4);
    second.insert(1);
    second.insert(2);
    second.insert(3);
    second.insert(4);
    second.insert(5);

    REQUIRE((first != second) == true);
}

TEST_CASE("!= - initial test with doubles")
{
    sortedSingle<double> first;
    sortedSingle<double> second;
    first.insert(1);
    first.insert(2);
    first.insert(69.696969);

    second = first;

    second.insert(1333.3333);

    REQUIRE((first != second) == true);
}

TEST_CASE("!= - second test with doubles")
{
    sortedSingle<double> first;
    sortedSingle<double> second;
    first.insert(1);
    first.insert(2);
    first.insert(69.696969);

    second = first;

    REQUIRE((first != second) == false);
}

TEST_CASE("!= - initial test with strings")
{
    sortedSingle<string> first;
    sortedSingle<string> second;
    first.insert("one");
    first.insert("two");
    first.insert("three");

    second = first;

    second.insert("four");

    REQUIRE((first != second) == true);
}

TEST_CASE("!= - second test with strings")
{
    sortedSingle<string> first;
    sortedSingle<string> second;
    first.insert("one");
    first.insert("two");
    first.insert("three");

    second = first;

    REQUIRE((first != second) == false);
}

TEST_CASE("<< - initial test with ints")
{
    sortedSingle<int> list;
    list.insert(1);
    list.insert(69);
    list.insert(1337);
    list.insert(8008);

    cout << list << endl;
}

TEST_CASE("<< - initial test with doubles")
{
    sortedSingle<double> list;
    list.insert(1.1111);
    list.insert(69.69696969);
    list.insert(1337.13371337);
    list.insert(8008.5318008);

    cout << list << endl;
}

TEST_CASE("<< - initial test with strings")
{
    sortedSingle<string> list;
    list.insert("coding");
    list.insert("table");
    list.insert("rararara");
    list.insert("fun");

    cout << list << endl;
}