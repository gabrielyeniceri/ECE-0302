#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method

TEST_CASE( "Test adding words", "[FindPalindrome]" )
{
	FindPalindrome b;
	REQUIRE(b.add("kayak"));
	REQUIRE(!b.add("kayak1"));
}
TEST_CASE("Test adding valid and invalid words", "[add]") {
    FindPalindrome fp;
    REQUIRE(fp.add("kayak"));
    REQUIRE_FALSE(fp.add("kayak1"));
    REQUIRE_FALSE(fp.add(""));
    REQUIRE_FALSE(fp.add("Kayak"));
} //tests the error checking for invalid characters, dupes and empty chars
TEST_CASE("test recursion", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("a"));
	REQUIRE(b.add("AA"));
	REQUIRE(b.add("AaA"));
	REQUIRE(b.number() == 6);
}
TEST_CASE("Test clear method", "[clear]") {
    FindPalindrome fp;
    fp.add("a");
    fp.add("AA");
    fp.add("AaA");
    REQUIRE(fp.number() == 6);
    fp.clear();
    REQUIRE(fp.number() == 0);
    auto vec = fp.toVector();
    REQUIRE(vec.empty());
} //self explanatory, adds chars clears it and checks


TEST_CASE("Test number and toVector consistency", "[toVector]") {
    FindPalindrome fp;
    fp.add("a");
    fp.add("AA");
    fp.add("AaA");
    auto palVec = fp.toVector();
    REQUIRE(palVec.size() == fp.number());
} //the size of the palindrome sentence should equal the reported num
