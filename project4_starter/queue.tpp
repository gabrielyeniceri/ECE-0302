#include "queue.hpp"

template <typename T, typename L>
void Queue<T, L>::enqueue(const T &item)
{
  internal_list.insert(internal_list.getLength() + 1, item);
}

template <typename T, typename L>
void Queue<T, L>::dequeue()
{
  if (internal_list.isEmpty()) {
    throw std::out_of_range("Queue is empty");
  }
  internal_list.remove(1);
}

template <typename T, typename L>
T Queue<T, L>::peekFront()
{
  if (internal_list.isEmpty()) {
    throw std::out_of_range("Queue is empty");
  }
  return internal_list.getEntry(1);
}

template <typename T, typename L>
bool Queue<T, L>::isEmpty() const
{
  return internal_list.isEmpty();
}