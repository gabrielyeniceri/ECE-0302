/** @file test_array.cpp
 * @author G. Zhou
 */

#define CATCH_CONFIG_MAIN
#include <iostream>
#include <chrono>
#include "ArrayBagInt.hpp"
#include "catch.hpp"

TEST_CASE("Test remove method", "[ArrayBagInt]")
{
    ArrayBagInt bag;
    REQUIRE(bag.isEmpty());

    for (int i = 0; i < 100; i++)
    {
        bag.add(i * i - 24 * i + 100); // Just add 100 items, some of which are duplicates
    }
    REQUIRE(bag.getCurrentSize() == 100);

    // Test remove method
    REQUIRE(bag.remove(100)); // Remove an item
    REQUIRE(bag.getCurrentSize() == 99);

    // Test remove2 method
    REQUIRE(bag.remove2(77)); // Remove an item
    REQUIRE(bag.getCurrentSize() == 98);
}

TEST_CASE("Performance Test for clear4()", "[ArrayBagInt]")
{
    int sizes[] = {5, 50, 500, 5000, 50000};
    
    for (int n : sizes)
    {
        ArrayBagInt bag;
        for (int i = 0; i < n; i++)
        {
            bag.add(i); // Populate the bag with n elements
        }

        REQUIRE(bag.getCurrentSize() == n);

        // Measure execution time
        auto start = std::chrono::high_resolution_clock::now();
        bag.clear4(); // Test clear4() performance
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;

        REQUIRE(bag.getCurrentSize() == 0); // Ensure it's empty after clearing

        // Print results
        std::cout << "clear4() execution time for n = " << n << " : " 
                  << duration.count() << " seconds" << std::endl;
    }
}