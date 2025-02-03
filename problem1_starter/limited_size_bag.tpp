#include "limited_size_bag.hpp"
#include <algorithm>

template <typename T>
LimitedSizeBag<T>::LimitedSizeBag(): size(0) {}

template <typename T>
bool LimitedSizeBag<T>::add(const T &item)
{
    if (size >= maxsize) return false;
    items[size++] = item;
    return true;
}

template <typename T>
bool LimitedSizeBag<T>::remove(const T &item)
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
bool LimitedSizeBag<T>::isEmpty() const
{
return size == 0;
}

template <typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const
{
    return size;
}

template <typename T>
bool LimitedSizeBag<T>::contains(const T &item) const
{
    return std::find(items, items + size, item) != items + size;
}

template <typename T>
void LimitedSizeBag<T>::clear()
{
    size = 0;
}

template <typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T &item) const
{
    return std::count(items, items + size, item);
};

template <typename T>
bool LimitedSizeBag<T>::operator==(const AbstractBag<T> &other) const
{
    if (size != other.getCurrentSize()) return false;
    for (std::size_t i = 0; i < size; ++i) {
        if (getFrequencyOf(items[i]) != other.getFrequencyOf(items[i])) return false;
    }
    return true;
}