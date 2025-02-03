#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>
#include "linked_list.hpp"

template class LinkedList<int>;

TEST_CASE("Lists: Test 1-indexing Corner Cases", "[LinkedList]")
{
    LinkedList<int> list;
    REQUIRE(list.isEmpty());

    REQUIRE_FALSE(list.insert(0, 0)); // invalid
    REQUIRE(list.isEmpty());          // still empty

    REQUIRE(list.insert(1, 1));     // valid
    REQUIRE(list.getLength() == 1); // length is 1

    REQUIRE_FALSE(list.remove(0));  // invalid
    REQUIRE(list.getLength() == 1); // length is still 1

    REQUIRE(list.remove(1)); // valid
    REQUIRE(list.isEmpty()); // now empty

    list.insert(1, 301);
    list.insert(2, 302);

    REQUIRE(list.getEntry(1) == 301);
    REQUIRE(list.getEntry(2) == 302);

    REQUIRE_THROWS_AS(list.getEntry(0), std::out_of_range);
    REQUIRE_THROWS_AS(list.setEntry(0, 300), std::out_of_range);

    // pos = 1 is the first item, that also indicates pos = n is the last item
    // your insertion at pos=n is valid, and your insertion at pos=n+1 is also valid
    // your removal at pos=1 is valid, but your removal at pos=n+1 is invalid
}
//first it confirms the news created list is empty, then it attempts to insert a value at pos 0 which is invalid and returns false. then it inserts at point 1,2 and the middle, tries to return at an invalid point which returns false then it does removals and updates elements and finally clears list
TEST_CASE("LinkedList test case", "[LinkedList]") {
    LinkedList<int> list;

    REQUIRE(list.isEmpty());
    REQUIRE(list.getLength() == 0);

    REQUIRE_FALSE(list.insert(0, 42));
    REQUIRE(list.isEmpty());

    REQUIRE(list.insert(1, 10));
    REQUIRE_FALSE(list.isEmpty());
    REQUIRE(list.getLength() == 1);
    REQUIRE(list.getEntry(1) == 10);

    REQUIRE(list.insert(2, 20));
    REQUIRE(list.getLength() == 2);
    REQUIRE(list.getEntry(2) == 20);

    REQUIRE(list.insert(2, 15));
    REQUIRE(list.getLength() == 3);
    REQUIRE(list.getEntry(1) == 10);
    REQUIRE(list.getEntry(2) == 15);
    REQUIRE(list.getEntry(3) == 20);

    REQUIRE_FALSE(list.remove(0));
    REQUIRE_FALSE(list.remove(4));

    REQUIRE(list.remove(1));
    REQUIRE(list.getLength() == 2);
    REQUIRE(list.getEntry(1) == 15);
    REQUIRE(list.getEntry(2) == 20);

    REQUIRE(list.remove(2));
    REQUIRE(list.getLength() == 1);
    REQUIRE(list.getEntry(1) == 15);

    list.setEntry(1, 100);
    REQUIRE(list.getEntry(1) == 100);

    list.clear();
    REQUIRE(list.isEmpty());
    REQUIRE(list.getLength() == 0);

    REQUIRE_THROWS_AS(list.getEntry(1), std::out_of_range);
    REQUIRE_THROWS_AS(list.setEntry(1, 55), std::out_of_range);
}