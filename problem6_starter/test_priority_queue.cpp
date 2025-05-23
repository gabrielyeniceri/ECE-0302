#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "list.hpp"
#include "sorted_list.hpp"
#include "priority_queue.hpp"

typedef SortedList<int, List<int>> SortedListType;
typedef PriorityQueue<int, SortedListType> PriorityQueueType;

/* Provided test cases */
TEST_CASE("Priority: Testing Sorted List", "[sorted list]")
{
  SortedList<int, List<int>> sort;

  REQUIRE(sort.isEmpty());
  REQUIRE(sort.getLength() == 0);

  sort.insert(1);
  REQUIRE_FALSE(sort.isEmpty());
  REQUIRE(sort.getLength() == 1);
  sort.insert(2);
  REQUIRE(sort.getLength() == 2);
  sort.insert(8);
  REQUIRE(sort.getLength() == 3);
  sort.insert(6);
  REQUIRE(sort.getLength() == 4);
  sort.insert(9);
  REQUIRE(sort.getLength() == 5);
  sort.insert(0);
  REQUIRE(sort.getLength() == 6);

  REQUIRE(sort.getEntry(1) == 0);
  REQUIRE(sort.getPosition(0) == 1);
  REQUIRE(sort.getEntry(2) == 1);
  REQUIRE(sort.getPosition(1) == 2);
  REQUIRE(sort.getEntry(3) == 2);
  REQUIRE(sort.getPosition(2) == 3);
  REQUIRE(sort.getEntry(4) == 6);
  REQUIRE(sort.getPosition(6) == 4);
  REQUIRE(sort.getEntry(5) == 8);
  REQUIRE(sort.getPosition(8) == 5);
  REQUIRE(sort.getEntry(6) == 9);
  REQUIRE(sort.getPosition(9) == 6);

  sort.remove(0);
  REQUIRE(sort.getEntry(1) == 1);
  REQUIRE(sort.getLength() == 5);

  sort.remove(1);
  REQUIRE(sort.getEntry(1) == 2);
  REQUIRE(sort.getLength() == 4);

  sort.remove(9);
  REQUIRE(sort.getEntry(1) == 2);
  REQUIRE(sort.getLength() == 3);

  sort.removeAt(2);
  REQUIRE(sort.getEntry(1) == 2);
  REQUIRE(sort.getLength() == 2);

  sort.removeAt(1);
  REQUIRE(sort.getEntry(1) == 8);
  REQUIRE(sort.getLength() == 1);

  sort.removeAt(1);
  REQUIRE(sort.getLength() == 0);
  REQUIRE(sort.isEmpty());
}

TEST_CASE("Priority: Testing Priority Queue Add/isEmpty/peek/remove", "[priority queue]")
{
  PriorityQueueType pq;

  REQUIRE(pq.isEmpty());

  pq.add(3);
  REQUIRE_FALSE(pq.isEmpty());

  pq.add(1);
  pq.add(5);
  pq.add(2);
  REQUIRE(pq.peek() == 5);

  pq.remove();
  REQUIRE(pq.peek() == 3);

  pq.remove();
  REQUIRE(pq.peek() == 2);
}

TEST_CASE("SortedList: Duplicate Values", "[sorted list]") {
  SortedList<int, List<int>> sort;
  sort.insert(4);
  sort.insert(4);
  sort.insert(2);
  sort.insert(4);
  REQUIRE(sort.getLength() == 4);
  REQUIRE(sort.getEntry(1) == 2);
  REQUIRE(sort.getEntry(2) == 4);
  REQUIRE(sort.getEntry(3) == 4);
  REQUIRE(sort.getEntry(4) == 4);//2,4,4,4
  REQUIRE(sort.getPosition(4) == 2);
  sort.remove(4);// now it is 2,4,4
  REQUIRE(sort.getLength() == 3);
  REQUIRE(sort.getEntry(1) == 2);
  REQUIRE(sort.getEntry(2) == 4);
  REQUIRE(sort.getEntry(3) == 4);
}
TEST_CASE("SortedList: Exception Handling", "[sorted list]") {
  SortedList<int, List<int>> sort;
  REQUIRE_THROWS_AS(sort.getEntry(1), std::out_of_range);
  sort.insert(5);
  REQUIRE_THROWS_AS(sort.getEntry(2), std::out_of_range);
  REQUIRE_THROWS_AS(sort.getPosition(3), std::invalid_argument);
  REQUIRE_THROWS_AS(sort.remove(10), std::invalid_argument);
  REQUIRE_THROWS_AS(sort.removeAt(2), std::out_of_range);
}
TEST_CASE("PriorityQueue: Exception on Peek Empty", "[priority queue]") {
  PriorityQueueType pq;
  REQUIRE(pq.isEmpty());
  REQUIRE_THROWS_AS(pq.peek(), std::out_of_range);
}
TEST_CASE("PriorityQueue: Duplicate Values", "[priority queue]") {
  PriorityQueueType pq;
  pq.add(4);
  pq.add(4);
  pq.add(2);
  pq.add(4);
  REQUIRE(pq.peek() == 4);
  pq.remove();
  REQUIRE(pq.peek() == 4);
  pq.remove();
  pq.remove();
  REQUIRE(pq.peek() == 2);
}