#include "sorted_list.hpp"

template <typename T, typename L>
SortedList<T, L>::SortedList()
{
  // nothing to do, plist gets created on the stack
}

template <typename T, typename L>
SortedList<T, L>::SortedList(const SortedList<T, L> &x)
{
  plist = x.plist; // use plist copy assignment
}

template <typename T, typename L>
SortedList<T, L> &SortedList<T, L>::operator=(SortedList<T, L> x)
{
  plist = x.plist; // use plist copy assignment
  return *this;
}

template <typename T, typename L>
SortedList<T, L>::~SortedList()
{
  // plist destructor gets called automatically
}

template <typename T, typename L>
bool SortedList<T, L>::isEmpty() const noexcept
{
  return plist.isEmpty();
}

template <typename T, typename L>
std::size_t SortedList<T, L>::getLength() const noexcept
{
  return plist.getLength();
}

template <typename T, typename L>
void SortedList<T, L>::insert(const T &item)
{
  std::size_t len = plist.getLength();
  std::size_t pos = 1;
  while (pos <= len && plist.getEntry(pos) < item)
  {
    ++pos;
  }
  plist.insert(pos, item);
}

template <typename T, typename L>
void SortedList<T, L>::remove(const T &item)
{
  std::size_t pos = getPosition(item);
  plist.remove(pos);
}

template <typename T, typename L>
void SortedList<T, L>::removeAt(std::size_t position)
{
  plist.remove(position);
}

template <typename T, typename L>
void SortedList<T, L>::clear()
{
  plist.clear();
}

template <typename T, typename L>
T SortedList<T, L>::getEntry(std::size_t position) const
{
  return plist.getEntry(position);
}

template <typename T, typename L>
std::size_t SortedList<T, L>::getPosition(const T &newValue)
{
std::size_t len = plist.getLength();
for (std::size_t pos = 1; pos <= len; pos++)
{
  T entry = plist.getEntry(pos);
  if (entry == newValue)
  {
    return pos;
  }
  if (entry > newValue)
   {
     break;
  }
  }
  throw std::invalid_argument("Item not found in SortedList");
}