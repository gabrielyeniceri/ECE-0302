#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "limited_size_bag.hpp"

// force template expansion for ints
template class LimitedSizeBag<int>;

TEST_CASE("Calling all public members", "[LimitedSizeBag]")
{
  LimitedSizeBag<int> b;

  b.add(0);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.clear();
  b.getFrequencyOf(0);
  b.contains(0);
}
TEST_CASE("LimitedSizeBag operations", "[LimitedSizeBag]") {
    LimitedSizeBag<int> bag;
    REQUIRE(bag.isEmpty());
    REQUIRE(bag.getCurrentSize() == 0);

    for (int i = 0; i < LimitedSizeBag<int>::maxsize; ++i) {
        REQUIRE(bag.add(i));
    }
    REQUIRE_FALSE(bag.add(101));

    REQUIRE(bag.getCurrentSize() == LimitedSizeBag<int>::maxsize);
    REQUIRE(bag.contains(50));

    REQUIRE(bag.remove(50));
    REQUIRE_FALSE(bag.contains(50));

    bag.clear();
    REQUIRE(bag.isEmpty());
}
