#include "array_list.hpp"
#include <stdexcept>

template <typename T>
ArrayList<T>::ArrayList() : m_items(nullptr), m_length(0)
{
  // initilizes an empty list
}

template <typename T>
ArrayList<T>::~ArrayList()
{
 delete[] m_items;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList &rhs) : m_items(nullptr), m_length(rhs.m_length)
{
if (m_length > 0)
  {
    m_items = new T[m_length];
    for (std::size_t i = 0; i < m_length; ++i)
      m_items[i] = rhs.m_items[i];
  }
}

template <typename T>
ArrayList<T> &ArrayList<T>::operator=(ArrayList rhs)
{
  swap(rhs);
  return *this;
}

template <typename T>
void ArrayList<T>::swap(ArrayList &rhs)
{
  std::swap(m_items, rhs.m_items);
  std::swap(m_length, rhs.m_length);
}
//return true when list is empty
template <typename T>
bool ArrayList<T>::isEmpty() const noexcept
{
  return m_length == 0;
}
//return num of items in list
template <typename T>
std::size_t ArrayList<T>::getLength() const noexcept
{
  return m_length;
}
//inserts the item at a given 1 indexed positon 1 through m_lenght +1
template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T &item)
{
  if (position < 1 || position > m_length + 1)
  return false;
  T* newArray = new T[m_length + 1];
  for (std::size_t i = 0; i < position - 1; ++i)
  newArray[i] = m_items[i];
  newArray[position - 1] = item;

  for (std::size_t i = position -1; i < m_length; i++)
  newArray[i+1] = m_items[i];

  delete[] m_items;
  m_items = newArray;

  ++m_length;

  return true;
}
// similar to above but it removes item at given 1 index position and valid through pos 1 through m_length
template <typename T>
bool ArrayList<T>::remove(std::size_t position)
{
     if(position < 1 || position > m_length)
     return false;

     if (m_length ==1){
      delete[] m_items;
      m_items = nullptr;
      m_length = 0;
      return true;
     }

    T* newArray = new T[m_length - 1];

    for (std::size_t i = 0; i < position - 1; ++i)
    newArray[i] = m_items[i];

    for (std::size_t i = position; i < m_length; ++i)
    newArray[i - 1] = m_items[i];
    
    delete[] m_items;
    m_items = newArray;
    --m_length;
    return true;
}
//removes all items in the list
template <typename T>
void ArrayList<T>::clear()
{
  delete[] m_items;
  m_items = nullptr;
  m_length = 0;
}
//returns pos of given index and throws error if out of range
template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const
{
  if (position < 1 || position > m_length)
    throw std::out_of_range("Invalid position in getEntry");
  return m_items[position - 1];
}
//set to new val at given index
template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T &newValue)
{
 if (position < 1 || position > m_length)
    throw std::out_of_range("Invalid position in setEntry");
  m_items[position - 1] = newValue;
}
