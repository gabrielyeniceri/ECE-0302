#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "dynamic_bag.hpp"

// force template expansion for ints
template class DynamicBag<int>;

TEST_CASE("Calling all public members", "[DynamicBag]")
{
  DynamicBag<int> b;

  b.add(0);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.clear();
  b.getFrequencyOf(0);
  b.contains(0);
}
TEST_CASE("DynamicBag operations", "[DynamicBag]") {
    DynamicBag<int> bag;
    REQUIRE(bag.isEmpty());
    REQUIRE(bag.getCurrentSize() == 0);

    REQUIRE(bag.add(1));
    REQUIRE(bag.add(2));
    REQUIRE(bag.add(1));

    REQUIRE(bag.getCurrentSize() == 3);
    REQUIRE(bag.getFrequencyOf(1) == 2);
    REQUIRE(bag.contains(2));

    REQUIRE(bag.remove(1));
    REQUIRE(bag.getFrequencyOf(1) == 1);

    bag.clear();
    REQUIRE(bag.isEmpty());
}
