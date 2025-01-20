#include "bitarray.hpp"
#include <cstring>
#include <stdexcept>

//initializes a bitArray of size 8 with all bits set to 0
BitArray::BitArray() : bit_size(8), is_valid(true) {
    bits = new uint8_t[(bit_size + 7) / 8]();
}

//initializes a bitArray of size N with all bits set to 0
BitArray::BitArray(intmax_t size) : bit_size(size), is_valid(size > 0) {
    if (!is_valid) {
        bits = nullptr;
    } else {
        bits = new uint8_t[(bit_size + 7) / 8](); 
    }
}

//initializes a bitArray based on the given string
BitArray::BitArray(const std::string &value) : bit_size(value.size()), is_valid(true) {
    for (char c : value) {
        if (c != '0' && c != '1') {
            is_valid = false;
            break;
        }
    }
    if (!is_valid) {
        bits = nullptr;
    } else {
        bits = new uint8_t[(bit_size + 7) / 8]();
        for (size_t i = 0; i < value.size(); ++i) {
            if (value[i] == '1') {
                set(i);
            }
        }
    }
}

//frees memory
BitArray::~BitArray() {
    delete[] bits;
}

//returns the size
intmax_t BitArray::size() const {
    return bit_size;
}

//checks if bitarray is in valid state
bool BitArray::good() const {
    return is_valid;
}

//set nth bit to 1
void BitArray::set(intmax_t index) {
    if (index < 0 || index >= bit_size) {
        invalidate();
        return;
    }
    bits[index / 8] |= (1 << (7 - (index % 8)));
}

//reset nth bit to zero
void BitArray::reset(intmax_t index) {
    if (index < 0 || index >= bit_size) {
        invalidate();
        return;
    }
    bits[index / 8] &= ~(1 << (7 - (index % 8)));
}

//this toggles every nth bit
void BitArray::toggle(intmax_t index) {
    if (index < 0 || index >= bit_size) {
        invalidate();
        return;
    }
    bits[index / 8] ^= (1 << (7 - (index % 8)));
}

// tests if the nth is set to 1
bool BitArray::test(intmax_t index) {
    if (index < 0 || index >= bit_size) {
        invalidate();
        return false;
    }
    return bits[index / 8] & (1 << (7 - (index % 8)));
}
//this returns the bitset in a string of 0 and 1s
std::string BitArray::asString() const {
    if (!is_valid) {
        return "";
    }
    std::string result;
    for (intmax_t i = 0; i < bit_size; ++i) {
        result += const_cast<BitArray*>(this)->test(i) ? '1' : '0'; // "the object has type qualifiers that are not compatible with the member function" this is the only way around it
    }
    return result;
}


//marks bitarray invalid
void BitArray::invalidate() {
    is_valid = false;
}
