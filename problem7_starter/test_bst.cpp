#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "binary_search_tree.hpp"

typedef BinarySearchTree<int, int> TreeType;

/* Provided test cases */

TEST_CASE("BST: Test Insert", "[insert]")
{
    TreeType bst1;

    REQUIRE(bst1.isEmpty());

    bst1.insert(10, 10);
    REQUIRE_FALSE(bst1.isEmpty());
}

TEST_CASE("BST: Test Duplicate Insert", "[duplicate insert]")
{
    TreeType bst1;

    REQUIRE(bst1.insert(12, 12));
    REQUIRE(!bst1.insert(12, 12));
}

TEST_CASE("BST: Test Remove With No Children", "[remove]")
{
    TreeType bst1;

    bst1.insert(10, 10);
    bst1.insert(5, 5);
    bst1.insert(15, 15);

    int item;

    REQUIRE(bst1.retrieve(10, item));
    REQUIRE(bst1.retrieve(5, item));
    REQUIRE(bst1.retrieve(15, item));

    bst1.remove(5);
    REQUIRE_FALSE(bst1.retrieve(5, item));

    bst1.remove(15);
    REQUIRE_FALSE(bst1.retrieve(15, item));

    bst1.remove(10);
    REQUIRE_FALSE(bst1.retrieve(10, item));

    REQUIRE(bst1.isEmpty());
}

TEST_CASE("BST: Test Copy Assign", "[copy assign]")
{
    TreeType bst1;

    bst1.insert(50, 50);
    bst1.insert(0, 0);
    bst1.insert(100, 100);
    bst1.insert(25, 25);
    bst1.insert(75, 75);

    TreeType bst2;

    bst2 = bst1;

    bst1.destroy();

    REQUIRE(bst1.isEmpty());

    REQUIRE_FALSE(bst2.isEmpty());

    int item;
    REQUIRE(bst2.retrieve(100, item));
    REQUIRE(bst2.retrieve(75, item));
    REQUIRE(bst2.retrieve(50, item));
    REQUIRE(bst2.retrieve(25, item));
    REQUIRE_FALSE(bst2.retrieve(51, item));
}

/* Your test cases here */
TEST_CASE("BST: Test Remove With Two Children", "[remove]") {
    TreeType bst;
    bst.insert(50, 50);
    bst.insert(30, 30);
    bst.insert(70, 70);
    bst.insert(20, 20);
    bst.insert(40, 40);
    bst.insert(60, 60);
    bst.insert(80, 80);
    int item;
    REQUIRE(bst.remove(50));
    REQUIRE_FALSE(bst.retrieve(50, item));
    REQUIRE(bst.retrieve(30, item));
    REQUIRE(bst.retrieve(70, item));
    REQUIRE(bst.retrieve(20, item));
    REQUIRE(bst.retrieve(40, item));
    REQUIRE(bst.retrieve(60, item));
    REQUIRE(bst.retrieve(80, item));
}
TEST_CASE("BST: Test Destroy", "[destroy]") {
    TreeType bst;
    bst.insert(10, 10);
    bst.insert(5, 5);
    bst.insert(15, 15);

    bst.destroy();
    REQUIRE(bst.isEmpty());
}
TEST_CASE("BST: Test Remove With One Child", "[remove]") {
    TreeType bst;
    bst.insert(10, 10);
    bst.insert(5, 5);
    bst.insert(7, 7);
    int item;
    REQUIRE(bst.retrieve(5, item));
    REQUIRE(bst.retrieve(7, item));
    REQUIRE(bst.remove(5));
    REQUIRE_FALSE(bst.retrieve(5, item));
    REQUIRE(bst.retrieve(7, item));
}
TEST_CASE("BST: TreeSort with reverse sorted array", "[treeSort]") {
    TreeType bst;
    int arr[] = {5, 4, 3, 2, 1};
    int expected[] = {1, 2, 3, 4, 5};
    bst.treeSort(arr, 5);
    for (int i = 0; i < 5; ++i) {
        REQUIRE(arr[i] == expected[i]);
    }
}
TEST_CASE("BST: TreeSort with duplicates throws", "[treeSort][exceptions]") {
    TreeType bst;
    int arr[] = {3, 1, 2, 3};
    REQUIRE_THROWS_AS(bst.treeSort(arr, 4), std::logic_error);
}
TEST_CASE("BST: TreeSort with one element", "[treeSort]") {
    TreeType bst;
    int arr[] = {42};
    bst.treeSort(arr, 1);
    REQUIRE(arr[0] == 42);
}
