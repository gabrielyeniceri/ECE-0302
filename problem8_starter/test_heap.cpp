#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "ArrayMaxHeap.hpp"

/* Provided test cases */
TEST_CASE("Heap: test construct from array", "[construct]")
{
   int array[] = {80, 70, 60, 50, 40, 30, 20, 10};
   ArrayMaxHeap<int> heap(array, 8);
   REQUIRE(heap.getNumberOfNodes() == 8);
   REQUIRE(heap.getHeight() == 4);
   REQUIRE(heap.isEmpty() == false);
   heap.clear();
   REQUIRE(heap.getNumberOfNodes() == 0);
   REQUIRE(heap.getHeight() == 0);
   REQUIRE(heap.isEmpty() == true);
}

TEST_CASE("Heap: test heap sort", "[sort]")
{
   int array[] = {15, 5, 20, 10, 30};
   ArrayMaxHeap<int> heap(array, 5);
   heap.heapSort(array, 5);
   REQUIRE(array[0] == 30);
   REQUIRE(array[1] == 20);
   REQUIRE(array[2] == 15);
   REQUIRE(array[3] == 10);
   REQUIRE(array[4] == 5);
}

/* Additional test cases */
TEST_CASE("Heap: test add elements and duplicates", "[add]") {
   ArrayMaxHeap<int> heap;
   REQUIRE(heap.add(10) == true);
   REQUIRE(heap.add(20) == true);
   REQUIRE(heap.add(15) == true);
   REQUIRE(heap.peekTop() == 20);
   REQUIRE(heap.add(20) == false);
   REQUIRE(heap.getNumberOfNodes() == 3);
}
TEST_CASE("Heap: test peekTop on empty heap", "[peekTop]") {
   ArrayMaxHeap<int> heap;
   REQUIRE_THROWS_AS(heap.peekTop(), std::out_of_range);
}
TEST_CASE("Heap: test heapSort with duplicates", "[sort]") {
   int arrayWithDupes[] = {40, 30, 40, 20, 10};
   ArrayMaxHeap<int> heap;
   REQUIRE_THROWS_AS(heap.heapSort(arrayWithDupes, 5), std::invalid_argument);
}