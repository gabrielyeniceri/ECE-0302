#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include <iostream>
#include "bitarray.hpp"

TEST_CASE("Bitarray: Test default construction and asString", "[bitarray]")
{
    BitArray b;
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
    REQUIRE(b.asString().compare("00000000") == 0);
}

TEST_CASE("Bitarray: Test construction with asString", "[bitarray]")
{
    BitArray b;
    REQUIRE(b.asString().compare("00000000") == 0);
}

TEST_CASE("Bitarray: Test construction size and asString", "[bitarray]")
{
    // You can construct a string s of as s(n, c)
    // where n is the number of characters and c is the character
    std::string s(64, '0');
    BitArray b(64);
    REQUIRE(b.size() == 64);
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);
}

TEST_CASE("Bitarray: Test construction std::string and asString", "[bitarray]")
{
    std::string s("00101110000011000001101000001");
    BitArray b(s);
    REQUIRE(b.size() == s.size());
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);
}

TEST_CASE("Bitarray: Test construction invalid std::string", "[bitarray]")
{
    std::string s("00101110000011002001101000001");
    BitArray b(s);
    REQUIRE_FALSE(b.good());
}

TEST_CASE("Bitarray: Test set method", "[bitarray]")
{
    std::string s("00010001");
    BitArray b;
    b.set(3);
    b.set(7);
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);

    std::string s1("00010");
    BitArray b1(5);
    b1.set(3);  
    REQUIRE(b1.size() == 5);
    REQUIRE(b1.good());
    REQUIRE(b1.asString().compare(s1) == 0);
}

TEST_CASE("Bitarray: Test many given methods combined", "[bitarray]")
{
    // << is the left shift operator for integers
    // e.g., 1 << 8 is 2^8=256, 1<<15 is 2^15=32768
    std::string s((1 << 15) + 3, '0');
    BitArray b(s);
    REQUIRE(b.size() == s.size());
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);

    for (int i = 1; i < (1 << 10); i++)
    {
        b.set(i);
        b.reset(i + (1 << 10));
        b.toggle(i + (1 << 11));
        REQUIRE(b.good());
        REQUIRE(b.test(i));
        REQUIRE_FALSE(b.test(i + (1 << 10)));
        REQUIRE((
            (b.test(i + (1 << 11)) == true && s.at(i + (1 << 11)) == '0') || // either this is true
            (b.test(i + (1 << 11)) == false && s.at(i + (1 << 11)) == '1')   // or this is true

            ));
    }
}

TEST_CASE("Bitarray: Test reset method", "[bitarray]")
{
    BitArray b("11111111");
    b.reset(2);
    b.reset(5);
    REQUIRE(b.asString() == "11011011");
}

TEST_CASE("Bitarray: Test toggle method", "[bitarray]")
{
    BitArray b("10101010");
    b.toggle(0);
    b.toggle(1);
    REQUIRE(b.asString() == "01101010");
    b.toggle(1);
    REQUIRE(b.asString() == "11101010");
}

TEST_CASE("Bitarray: Test test method", "[bitarray]")
{
    BitArray b("10000001");
    REQUIRE(b.test(0) == true);
    REQUIRE(b.test(7) == true);
    REQUIRE(b.test(1) == false);
}

TEST_CASE("Bitarray: Test invalid index operations", "[bitarray]")
{
    BitArray b(8);
    b.set(10); 
    REQUIRE_FALSE(b.good());

    BitArray b2(8);
    b2.reset(-1);
    REQUIRE_FALSE(b2.good());

    BitArray b3(8);
    b3.toggle(100);
    REQUIRE_FALSE(b3.good());
}

TEST_CASE("Bitarray: Test dynamic size handling", "[bitarray]")
{
    BitArray b(128);
    REQUIRE(b.size() == 128);
    REQUIRE(b.good());

    b.set(127);
    REQUIRE(b.test(127) == true);

    b.reset(127);
    REQUIRE(b.test(127) == false);
}

TEST_CASE("Bitarray: Test empty construction and invalid state", "[bitarray]")
{
    BitArray b(0);
    REQUIRE_FALSE(b.good());
}