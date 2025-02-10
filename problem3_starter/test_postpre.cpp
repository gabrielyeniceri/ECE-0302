#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include <string>

#include "algebraic_expressions.hpp"

/* Provided test cases */
TEST_CASE("Test endPost", "[postpre]")
{
  std::string postfix_valid = "ab+";
  int test_idx_valid = 0;
  std::string postfix_invalid = "+";
  int test_idx_invalid = -1;
  REQUIRE(endPost(postfix_valid, postfix_valid.length() - 1) == test_idx_valid);
  REQUIRE(endPost(postfix_invalid, postfix_invalid.length() - 1) == test_idx_invalid);
}

TEST_CASE("Test isPost", "[postpre]")
{
  std::string postfix_valid = "ab+";
  std::string postfix_invalid = "+ab";

  REQUIRE(isPost(postfix_valid));
  REQUIRE_FALSE(isPost(postfix_invalid));
}

TEST_CASE("Postpre: Test expression ab+", "[postpre]")
{
  std::string postfix = "ab+";
  std::string prefix = "";
  std::string test = "+ab";

  REQUIRE_NOTHROW(convert(postfix, prefix));

  REQUIRE(prefix == test);
}

TEST_CASE("Postpre: Test other operators", "[postpre]")
{
  std::string postfix = "ab-";
  std::string prefix = "";
  std::string test = "-ab";

  REQUIRE_NOTHROW(convert(postfix, prefix));
  REQUIRE(prefix == test);

  postfix = "ab*";
  prefix = "";
  test = "*ab";
  REQUIRE_NOTHROW(convert(postfix, prefix));
  REQUIRE(prefix == test);

  postfix = "ab/";
  prefix = "";
  test = "/ab";
  REQUIRE_NOTHROW(convert(postfix, prefix));
  REQUIRE(prefix == test);
}
//not much explanation needed, it takes input and compares to what is expected simply
TEST_CASE("Postpre: Test single operand", "[postpre]") {
  std::string postfix = "A";
  std::string prefix;
  std::string expected = "A";

  REQUIRE_NOTHROW(convert(postfix, prefix));
  REQUIRE(prefix == expected);
}

TEST_CASE("Postpre: Test complex expression", "[postpre]") {
  std::string postfix = "ab+c*";
  std::string prefix;
  std::string expected = "*+abc";
  REQUIRE_NOTHROW(convert(postfix, prefix));
  REQUIRE(prefix == expected);
}
TEST_CASE("Postpre: Test another complex expression", "[postpre]") {
  std::string postfix = "abc++";
  std::string prefix;
  std::string expected = "+a+bc";
  REQUIRE_NOTHROW(convert(postfix, prefix));
  REQUIRE(prefix == expected);
}
//invalid arg tests
TEST_CASE("Postpre: Test invalid empty string", "[postpre]") {
  std::string postfix = "";
  std::string prefix;

  REQUIRE_THROWS_AS(convert(postfix, prefix), std::invalid_argument);
}

TEST_CASE("Postpre: Test invalid character", "[postpre]") {
  std::string postfix = "a1+";
  std::string prefix;
  
  REQUIRE_THROWS_AS(convert(postfix, prefix), std::invalid_argument);
}

TEST_CASE("Postpre: Test missing operator", "[postpre]") {
  std::string postfix = "ab";
  std::string prefix;
  
  REQUIRE_THROWS_AS(convert(postfix, prefix), std::invalid_argument);
}

TEST_CASE("Postpre: Test extra operand", "[postpre]") {
  std::string postfix = "ab+c";
  std::string prefix;
  
  REQUIRE_THROWS_AS(convert(postfix, prefix), std::invalid_argument);
}