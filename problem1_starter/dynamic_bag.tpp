#include "dynamic_bag.hpp"
#include <algorithm>
#include <stdexcept>
template <typename T>
DynamicBag<T>::DynamicBag() : items(new T[initialCapacity]), size(0), capacity(initialCapacity) {}

template <typename T>
DynamicBag<T>::DynamicBag(const DynamicBag<T>& x) : items(new T[x.capacity]), size(x.size), capacity(x.capacity) {
    std::copy(x.items, x.items + x.size, items);
}

template <typename T>
DynamicBag<T>::~DynamicBag()
{
   delete[] items;
}

template <typename T>
DynamicBag<T> &DynamicBag<T>::operator=(DynamicBag<T> x)
{
     swap(x);
  return *this;
}

template <typename T>
void DynamicBag<T>::swap(DynamicBag<T> &x)
{
    std::swap(items, x.items);
    std::swap(size, x.size);
    std::swap(capacity, x.capacity);
}

template <typename T>
bool DynamicBag<T>::add(const T &item)
{
 if (size == capacity) {
        capacity *= 2;
        T* newItems = new T[capacity];
        std::copy(items, items + size, newItems);
        delete[] items;
        items = newItems;
    }
    items[size++] = item;
    return true;
}

template <typename T>
bool DynamicBag<T>::remove(const T &item)
{
 for (std::size_t i = 0; i < size; ++i) {
        if (items[i] == item) {
            items[i] = items[--size];
            return true;
        }
    }
    return false;
}

template <typename T>
bool DynamicBag<T>::isEmpty() const
{
  return size == 0;
}

template <typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{
 return size;
}

template <typename T>
bool DynamicBag<T>::contains(const T &item) const
{
    return std::find(items, items + size, item) != items + size;
}

template <typename T>
void DynamicBag<T>::clear()
{
    size = 0;
}

template <typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T &item) const
{
return std::count(items, items + size, item);
};

template <typename T>
bool DynamicBag<T>::operator==(const AbstractBag<T> &other) const
{
    if (size != other.getCurrentSize()) return false;
    for (std::size_t i = 0; i < size; ++i) {
        if (getFrequencyOf(items[i]) != other.getFrequencyOf(items[i])) return false;
    }
    return true;
}