#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "sorted_list.hpp"
#include "list.hpp"

/* Provided tests */
TEST_CASE("SortedList: Testing size", "[sorted list]") {
  SortedList<char> lst;

  REQUIRE(lst.isEmpty());
  REQUIRE(lst.getLength() == 0);

  lst.insert('b');
  REQUIRE(!lst.isEmpty());
  REQUIRE(lst.getLength() == 1);

  lst.insert('a');
  REQUIRE(lst.getLength() == 2);

  lst.removeAt(1);
  REQUIRE(lst.getLength() == 1);

  lst.removeAt(1);
  REQUIRE(lst.getLength() == 0);
  REQUIRE(lst.isEmpty());
}


TEST_CASE("SortedList: Testing insert", "[sorted list]") {
  SortedList<char> lst;

  char c = 'a';
  while (c <= 'z') {
    lst.insert(c);
    ++c;
  }
  REQUIRE(lst.getLength() == 26);

  bool getEntryCheck;
  for (int i = 1; i <= 26; ++i) {
    getEntryCheck = (lst.getEntry(i) == 'a' + i);
    if (!getEntryCheck) {
      break;
    }
  }
  REQUIRE(getEntryCheck);
}


TEST_CASE("SortedList: Testing remove", "[sorted list]") {
  SortedList<char> lst;

  char c = 'a';
  int size = 10;
  while (c < 'a'+size) {
    lst.insert(c);
    ++c;
  }
  REQUIRE(lst.getLength() == size);

  lst.remove('c');
  REQUIRE(lst.getLength() == size-1);
  REQUIRE(lst.getEntry(3) == 'd');

  lst.remove('e');
  REQUIRE(lst.getLength() == size-2);
  REQUIRE(lst.getEntry(6) == 'h');

  lst.remove('a');
  REQUIRE(lst.getLength() == size-3);
  REQUIRE(lst.getEntry(1) == 'b');
}


TEST_CASE("SortedList: Testing getPosition", "[sorted list]") {
  SortedList<char> lst;

  lst.insert('a');
  lst.insert('d');
  lst.insert('e');
  lst.insert('c');
  lst.insert('b');

  REQUIRE(lst.getPosition('a') == 1);
  REQUIRE(lst.getPosition('b') == 2);
  REQUIRE(lst.getPosition('c') == 3);
  REQUIRE(lst.getPosition('d') == 4);
  REQUIRE(lst.getPosition('e') == 5);
}


TEST_CASE("Testing init from list", "[sorted list]") {
  List<char> unsorted;

  unsorted.insert(1,'a');
  unsorted.insert(2,'d');
  unsorted.insert(3,'e');
  unsorted.insert(4,'c');
  unsorted.insert(5,'b');

  SortedList<char> sorted(unsorted);

  REQUIRE(sorted.getPosition('a') == 1);
  REQUIRE(sorted.getPosition('b') == 2);
  REQUIRE(sorted.getPosition('c') == 3);
  REQUIRE(sorted.getPosition('d') == 4);
  REQUIRE(sorted.getPosition('e') == 5);
}


TEST_CASE("SortedList: Testing list exceptions", "[list]") {
  List<char> lst;

  REQUIRE_THROWS_AS(lst.remove(1), std::out_of_range);
  REQUIRE_THROWS_AS(lst.insert(2,'a'), std::out_of_range);
  REQUIRE_THROWS_AS(lst.getEntry(1), std::out_of_range);
  REQUIRE_THROWS_AS(lst.setEntry(1,'a'), std::out_of_range);

  lst.insert(1,'a');
  lst.insert(2,'b');

  REQUIRE_THROWS_AS(lst.remove(3), std::out_of_range);
  REQUIRE_THROWS_AS(lst.insert(4,'c'), std::out_of_range);
  REQUIRE_THROWS_AS(lst.getEntry(3), std::out_of_range);
  REQUIRE_THROWS_AS(lst.setEntry(3,'c'), std::out_of_range);

}

/* Your tests here */
TEST_CASE("SortedList: Testing exceptions", "[sorted list]") {
  SortedList<int> lst;
  
  REQUIRE_THROWS_AS(lst.remove(5), std::invalid_argument);

  REQUIRE_THROWS_AS(lst.getPosition(5), std::invalid_argument);
  
  lst.insert(1);
  lst.insert(3);
  lst.insert(2);

  REQUIRE_NOTHROW(lst.remove(2));
  REQUIRE(lst.getPosition(1) == 1);
  REQUIRE(lst.getPosition(3) == 2);
}

TEST_CASE("SortedList: Testing string sorting", "[sorted list]") {
  SortedList<std::string> lst;
  
  lst.insert("zoo");
  lst.insert("abstract");
  lst.insert("cathy");
  lst.insert("button");
  
  REQUIRE(lst.getEntry(1) == "abstract");
  REQUIRE(lst.getEntry(2) == "button");
  REQUIRE(lst.getEntry(3) == "cathy");
  REQUIRE(lst.getEntry(4) == "zoo");
  REQUIRE(lst.getLength() == 4);
}