#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "list.hpp"
#include "sort.hpp"

/* Provided test cases */
TEST_CASE("Sort: Test move entry", "[sorting]")
{
  List<int> lst;

  lst.insert(1, 100);
  lst.insert(2, 4);
  lst.insert(3, 10);
  lst.insert(4, 25);
  lst.insert(5, 11);

  // move forward
  lst.moveEntry(1, 3);

  REQUIRE(lst.getLength() == 5);
  REQUIRE(lst.getEntry(1) == 4);
  REQUIRE(lst.getEntry(2) == 10);
  REQUIRE(lst.getEntry(3) == 100);
  REQUIRE(lst.getEntry(4) == 25);
  REQUIRE(lst.getEntry(5) == 11);

  // move backward
  lst.moveEntry(5, 1);

  REQUIRE(lst.getLength() == 5);
  REQUIRE(lst.getEntry(1) == 11);
  REQUIRE(lst.getEntry(2) == 4);
  REQUIRE(lst.getEntry(3) == 10);
  REQUIRE(lst.getEntry(4) == 100);
  REQUIRE(lst.getEntry(5) == 25);
}

TEST_CASE("Sort: Integer sorting", "[sorting]")
{

  List<int> lst;

  lst.insert(1, 100);
  lst.insert(2, 4);
  lst.insert(3, 10);
  lst.insert(4, 25);
  lst.insert(5, 11);

  quick_sort(lst, 1, lst.getLength()); // note the change here!

  // check sorted list
  REQUIRE(lst.getEntry(1) == 4);
  REQUIRE(lst.getEntry(2) == 10);
  REQUIRE(lst.getEntry(3) == 11);
  REQUIRE(lst.getEntry(4) == 25);
  REQUIRE(lst.getEntry(5) == 100);
}

TEST_CASE("Sort: Test move entry throw", "[sorting]")
{
  List<int> lst;

  lst.insert(1, 100);
  lst.insert(2, 4);
  lst.insert(3, 10);
  lst.insert(4, 25);
  lst.insert(5, 11);

  // try to move forward
  REQUIRE_THROWS(lst.moveEntry(1, 6));
  REQUIRE_THROWS(lst.moveEntry(0, 5));

  lst.insert(5, 11);
  REQUIRE_NOTHROW(lst.moveEntry(1, 6));

  // try to move backward
  REQUIRE_THROWS(lst.moveEntry(7, 1));
  REQUIRE_THROWS(lst.moveEntry(6, -1));
}

/* Your test cases */
TEST_CASE("Sort: String sorting", "[sorting]") {
  List<std::string> lst;
  lst.insert(1, "bat");
  lst.insert(2, "action");
  lst.insert(3, "chiikawa");
  lst.insert(4, "door");
  lst.insert(5, "flight");
  lst.insert(6, "enter");

  quick_sort(lst, 1, lst.getLength());
  REQUIRE(lst.getEntry(1) == "action");
  REQUIRE(lst.getEntry(2) == "bat");
  REQUIRE(lst.getEntry(3) == "chiikawa");
  REQUIRE(lst.getEntry(4) == "door");
  REQUIRE(lst.getEntry(5) == "enter");
  REQUIRE(lst.getEntry(6) == "flight");
}

//quick sort move entrty single element
TEST_CASE("Sort: Single element list", "[sorting]") {
  List<int> lst;
  lst.insert(1, 42);
  REQUIRE_NOTHROW(lst.moveEntry(1, 1));
  REQUIRE(lst.getEntry(1) == 42);
  quick_sort(lst, 1, lst.getLength());
  REQUIRE(lst.getEntry(1) == 42);
}

TEST_CASE("Sort: Reverse sorted list", "[sorting]") {
  List<int> lst;
  lst.insert(1, 9);
  lst.insert(2, 7);
  lst.insert(3, 5);
  lst.insert(4, 3);
  lst.insert(5, 1);

  quick_sort(lst, 1, lst.getLength());

  //1,3,5,7,9
  REQUIRE(lst.getEntry(1) == 1);
  REQUIRE(lst.getEntry(2) == 3);
  REQUIRE(lst.getEntry(3) == 5);
  REQUIRE(lst.getEntry(4) == 7);
  REQUIRE(lst.getEntry(5) == 9);
}

//test with dupes
TEST_CASE("Sort: Duplicate elements", "[sorting]") {
  List<int> lst;
  lst.insert(1, 4);
  lst.insert(2, 2);
  lst.insert(3, 2);
  lst.insert(4, 8);
  lst.insert(5, 3);
  lst.insert(6, 3);
  lst.insert(7, 2);
  quick_sort(lst, 1, lst.getLength());
  REQUIRE(lst.getEntry(1) == 2);
  REQUIRE(lst.getEntry(2) == 2);
  REQUIRE(lst.getEntry(3) == 2);
  REQUIRE(lst.getEntry(4) == 3);
  REQUIRE(lst.getEntry(5) == 3);
  REQUIRE(lst.getEntry(6) == 4);
  REQUIRE(lst.getEntry(7) == 8);
}

//tests that moving an entry to the same index has no effect
TEST_CASE("List: Move entry same index", "[moveEntry]") {
  List<int> lst;
  lst.insert(1, 10);
  lst.insert(2, 20);
  lst.insert(3, 30);
  REQUIRE_NOTHROW(lst.moveEntry(2, 2));
  REQUIRE(lst.getEntry(1) == 10);
  REQUIRE(lst.getEntry(2) == 20);
  REQUIRE(lst.getEntry(3) == 30);
}

//clear test
TEST_CASE("List: Clear list", "[list]") {
  List<int> lst;
  lst.insert(1, 1);
  lst.insert(2, 2);
  lst.insert(3, 3);
  lst.clear();
  REQUIRE(lst.getLength() == 0);
  REQUIRE_THROWS(lst.getEntry(1));
}