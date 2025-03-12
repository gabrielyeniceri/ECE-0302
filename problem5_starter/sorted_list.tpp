#include "sorted_list.hpp"
#include <stdexcept>
#include <cstddef>
template <typename T>
SortedList<T>::SortedList(): List<T>()
{
}

template <typename T>
SortedList<T>::SortedList(List<T> unsorted_list) 
{
  std::size_t unsortedLength = unsorted_list.getLength();
  for (std::size_t i = 1; i <= unsortedLength; i++) {
    T item = unsorted_list.getEntry(i);
    insert(item);
  }
}

template <typename T>
SortedList<T>::SortedList(const SortedList<T> & x):
  List<T>(x)
{
}

template <typename T>
SortedList<T>& SortedList<T>::operator=(SortedList<T> x)
{
  List<T>::operator=(x);
  return *this;
}

template <typename T>
SortedList<T>::~SortedList()
{
  // base destructor gets called automatically
}

template <typename T>
bool SortedList<T>::isEmpty() const noexcept
{
  return List<T>::isEmpty();
}

template <typename T>
std::size_t SortedList<T>::getLength() const noexcept
{
  return List<T>::getLength();
}

template <typename T>
void SortedList<T>::insert(const T& item)
{
  //finds correct pos
  std::size_t pos = 1;
  std::size_t len = List<T>::getLength();
  while (pos <= len && List<T>::getEntry(pos) < item) {
    pos++;
  }
  List<T>::insert(pos, item);
}

template <typename T>
void SortedList<T>::remove(const T& item)
{
  //finds the first occurance, throws error if not found
  long int pos = getPosition(item);
  List<T>::remove(static_cast<std::size_t>(pos));
}

template <typename T>
void SortedList<T>::removeAt(std::size_t position)
{
  List<T>::remove(position);
}

template <typename T>
void SortedList<T>::clear()
{
  List<T>::clear();
}

template <typename T>
T SortedList<T>::getEntry(std::size_t position) const
{
  return List<T>::getEntry(position);
}

template <typename T>
std::size_t SortedList<T>::getPosition(const T& item)
{
  std::size_t len = List<T>::getLength();
  for (std::size_t pos = 1; pos <= len; pos++) {
    if (List<T>::getEntry(pos) == item) {
      return pos;
    }
  }
throw std::invalid_argument("Item not found in getPosition");
}
