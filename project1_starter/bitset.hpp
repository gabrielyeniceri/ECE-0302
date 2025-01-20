#ifndef BITSET_HPP
#define BITSET_HPP
#include <stdint.h>
#include <string>

class Bitset
{
public:
  virtual ~Bitset() {}; // virtual destructor, no need to comment

//returns the size of the bitset
  virtual intmax_t size() const = 0;

//true if bitset is valid if not then false
  virtual bool good() const = 0;

//set bit at specified index to one
  virtual void set(intmax_t index) = 0;

//resets the bit at specified index to zero
  virtual void reset(intmax_t index) = 0;

 //toggles the bit at specified index
  virtual void toggle(intmax_t index) = 0;
  //true if bit is set otherwise false
  virtual bool test(intmax_t index) = 0;

 //this returns the bitset in a string of 0 and 1s
  virtual std::string asString() const = 0;
};

#endif
