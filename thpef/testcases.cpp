#include "thpef.h"
#include "..\\catch.hpp"

TEST_CASE("enque - testing adding to an empty queue")
{
    queue<int> myQueue;

    CHECK(myQueue.enque(1));

    REQUIRE(myQueue.size() == 1);
}

TEST_CASE("enque - testing adding multiple to a queue")
{
    queue<int> myQueue;
    CHECK(myQueue.size() == 0);
    CHECK(myQueue.enque(1));
    CHECK(myQueue.enque(4));
    CHECK(myQueue.enque(2));
    CHECK(myQueue.size() == 3);

}

TEST_CASE("deque - testing deque with size 1 queue")
{
    queue<int> myQueue;

    myQueue.enque(1);

    REQUIRE(myQueue.size() == 1);

    int item;

    myQueue.deque(item);

    REQUIRE(item == 1);

    REQUIRE(myQueue.size() == 0);

}

TEST_CASE("deque - testing deque with no item")
{
    queue<int> myQueue;

    int item;

    myQueue.deque(item);

    REQUIRE(myQueue.deque(item) == false);

}

TEST_CASE("deque - testing deque with bigger queue")
{
    queue<int> myQueue;

    myQueue.enque(1337);
    myQueue.enque(2);
    myQueue.enque(3);
    myQueue.enque(1);
    myQueue.enque(2);
    myQueue.enque(3);
    myQueue.enque(1);
    myQueue.enque(2);
    myQueue.enque(3);

    REQUIRE(myQueue.size() == 9);

    int item;

    myQueue.deque(item);

    REQUIRE(item == 1337);

    REQUIRE(myQueue.size() == 8);

}

TEST_CASE("isEmpty - testing true")
{
    queue<card> myQ;
    
    REQUIRE(myQ.isEmpty() == true);
}

TEST_CASE("isEmpty - testing false")
{
    queue<card> myQ;
    card a;
    a.faceValue = 1;
    a.suit = 1;
    myQ.enque(a);
    REQUIRE(myQ.isEmpty() == false);
}

TEST_CASE("front - testing with big queue")
{
    queue<int> myQueue;

    myQueue.enque(1337);
    myQueue.enque(2);
    myQueue.enque(3);
    myQueue.enque(1);
    myQueue.enque(2);
    myQueue.enque(3);
    myQueue.enque(1);
    myQueue.enque(2);
    myQueue.enque(3);

    REQUIRE(myQueue.size() == 9);

    int item;

    myQueue.front(item);

    REQUIRE(item == 1337);

    REQUIRE(myQueue.size() == 9);

    myQueue.deque(item);

    myQueue.front(item);

    REQUIRE(item == 2);

    REQUIRE(myQueue.size() == 8);

}

TEST_CASE("front - testing with empty queue")
{
    queue<int> myQueue;

    REQUIRE(myQueue.size() == 0);

    int item;

    REQUIRE(myQueue.front(item) == false);

}

TEST_CASE("<< - initial test")
{
    queue<card> q;
    card one;
    card two;
    card three;
    card curr;

    one.faceValue = 11;
    two.faceValue = 2;
    three.faceValue = 6;
    one.suit = 0;
    two.suit = 1;
    three.suit = 3;

    q.enque(one);
    q.enque(two);
    q.enque(three);

    while (!q.isEmpty())
    {
        q.front(curr);
        cout << curr;
        q.deque(curr);
    }
}

TEST_CASE("playRound - initial test")
{
    queue<card> p1;
    queue<card> p2;
    card one;
    one.faceValue = 9;
    one.suit = 0;

    card two;
    two.faceValue = 8;
    two.suit = 1;

    p1.enque(one);
    p2.enque(two);

    playRound(p1, p2);

    REQUIRE(p1.size() == 2);

    cOutput(p1, p2, 1);



}

TEST_CASE("playRound and equal - testing a tie")
{
    queue<card> p1;
    queue<card> p2;
    card a;
    a.faceValue = 9;
    a.suit = 0;

    card b;
    b.faceValue = 8;
    b.suit = 0;

    card c;
    c.faceValue = 0;
    c.suit = 1;

    card d;
    d.faceValue = 12;
    d.suit = 3;

    card one;
    one.faceValue = 9;
    one.suit = 1;

    card two;
    two.faceValue = 3;
    two.suit = 1;

    card three;
    three.faceValue = 8;
    three.suit = 3;

    card four;
    four.faceValue = 10;
    four.suit = 0;

    p1.enque(a);
    p1.enque(b);
    p1.enque(c);
    p1.enque(d);
    p2.enque(one);
    p2.enque(two);
    p2.enque(three);
    p2.enque(four);

    playRound(p1, p2);

    REQUIRE(p1.size() == 8);

    cOutput(p1, p2, 1);



}

TEST_CASE("playRound and equal - testing different suits and tie")
{
    queue<card> p1;
    queue<card> p2;
    card a;
    a.faceValue = 9;
    a.suit = 0;

    card b;
    b.faceValue = 8;
    b.suit = 1;

    card c;
    c.faceValue = 0;
    c.suit = 1;

    card d;
    d.faceValue = 12;
    d.suit = 3;

    card one;
    one.faceValue = 9;
    one.suit = 1;

    card two;
    two.faceValue = 3;
    two.suit = 1;

    card three;
    three.faceValue = 8;
    three.suit = 3;

    card four;
    four.faceValue = 10;
    four.suit = 2;

    p1.enque(a);
    p1.enque(b);
    p1.enque(c);
    p1.enque(d);
    p2.enque(one);
    p2.enque(two);
    p2.enque(three);
    p2.enque(four);

    playRound(p1, p2);

    REQUIRE(p1.size() == 8);

    cOutput(p1, p2, 1);
}

TEST_CASE("== - initial test")
{
    card a;
    card b;
    a.faceValue = 9;
    a.suit = 0;
    b.faceValue = 9;
    b.suit = 3;
    bool equal = (a == b);
    REQUIRE(equal == true);
}

TEST_CASE("== - testing false")
{
    card a;
    card b;
    a.faceValue = 9;
    a.suit = 0;
    b.faceValue = 10;
    b.suit = 3;

    bool equal = (a == b);
    REQUIRE(equal == false);
}

TEST_CASE("!= - testing true")
{
    card a;
    card b;
    a.faceValue = 9;
    a.suit = 0;
    b.faceValue = 10;
    b.suit = 3;
    bool inequal = (a != b);
    REQUIRE(inequal == true);
}

TEST_CASE("!= - testing false")
{
    card a;
    card b;
    a.faceValue = 9;
    a.suit = 0;
    b.faceValue = 9;
    b.suit = 3;

    bool inequal = (a != b);
    REQUIRE(inequal == false);
}

//both output functions tested in console and files respectively