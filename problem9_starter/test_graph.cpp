#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "graph.hpp"

TEST_CASE("Test Construction", "[construction]")
{
  Graph<int> g;
  REQUIRE(g.getNumVertices() == 0);
  REQUIRE(g.getNumEdges() == 0);
}
TEST_CASE("Edge insertion rules", "[add]")
{
    Graph<int> g;
    REQUIRE(g.add(1, 2));
    REQUIRE(g.getNumVertices() == 2);
    REQUIRE(g.getNumEdges() == 1);
    REQUIRE_FALSE(g.add(1, 2));
    REQUIRE_FALSE(g.add(1, 1));
    REQUIRE(g.add(2, 3));
    REQUIRE(g.getNumVertices() == 3);
    REQUIRE(g.getNumEdges() == 2);
    REQUIRE_FALSE(g.add(10, 11));
    REQUIRE(g.getNumVertices() == 3);
    REQUIRE(g.getNumEdges() == 2);
}