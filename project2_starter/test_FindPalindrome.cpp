#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"
#include <string>
#include <vector>
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
TEST_CASE("Test cutTest1", "[cutTest1]") {
    FindPalindrome fp;
    std::vector<std::string> vec1 = {"a", "b"};
    REQUIRE(fp.cutTest1(vec1) == false);
    std::vector<std::string> v3 = {"ab","a"};
    REQUIRE(fp.cutTest1(v3));
    std::vector<std::string> vec2 = {"a", "aa"};
    REQUIRE(fp.cutTest1(vec2) == true);
}//tests the cuttest1 with odd frequency and concatenated string

TEST_CASE("Test cutTest2", "[cutTest2]") {
    FindPalindrome fp;
    std::vector<std::string> vec1 = {"a", "b"};
    std::vector<std::string> vec2 = {"ab", "a"};
    REQUIRE(fp.cutTest2(vec1, vec2) == true);
  
    std::vector<std::string> vec3 = {"a"};
    std::vector<std::string> vec4 = {"b"};
    REQUIRE(fp.cutTest2(vec3, vec4) == false);

    std::vector<std::string> vec5 = {"a", "b", "a"};
    std::vector<std::string> vec6 = {"a", "b", "a"};
    REQUIRE(fp.cutTest2(vec5, vec6) == true);
}//tests cuttest2 function as well with concatenated strings, has a failing case

TEST_CASE("Test add(vector<string>) method", "[add_vector]") {
    FindPalindrome fp;
    std::vector<std::string> words = {"odd", "even", "never", "or"};
    REQUIRE(fp.add(words));
    REQUIRE(fp.number() > 0);
    auto vec = fp.toVector();
    REQUIRE_FALSE(vec.empty());
}//adds all words since they are unique and at least one palindrome is found

TEST_CASE("Test countRecursion", "[countRecursion]") {
    FindPalindrome fp;
    REQUIRE(fp.add("aba"));
    REQUIRE(fp.countRecursion() == 2);
}
/**
//Checkoff assignment adds a variable that increments on entry
decremented on return, maxRecursionLevel is updated whenever
currentRecursionlevel exceeds its current value
should return two because it is called twice
resets are added to ensure it is properly set back to 0 when needed
added to private
int currentRecursionLevel;
int maxRecursionLevel;
added to public
int countRecursion() const;
*/