#ifndef BITARRAY_HPP
#define BITARRAY_HPP
#include <stdint.h>
#include <string>

#include "bitset.hpp"

class BitArray : public Bitset
{
public:
  BitArray();

  BitArray(intmax_t size);

  BitArray(const std::string &value);

  ~BitArray();

  BitArray(const BitArray &) = delete;
  BitArray &operator=(const BitArray &) = delete;

  intmax_t size() const override;

  bool good() const override;

  void set(intmax_t index) override;

  void reset(intmax_t index) override;

  void toggle(intmax_t index) override;

  bool test(intmax_t index) override;

  std::string asString() const override;
   int countOnes() const;
private:
  intmax_t bit_size;
  uint8_t *bits;
  bool is_valid;
  void invalidate();
};

#endif
