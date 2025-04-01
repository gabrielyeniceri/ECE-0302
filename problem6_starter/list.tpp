#include "list.hpp"

template <typename T>
List<T>::List() : head(nullptr), size(0)
{
  // TODO
}

template <typename T>
List<T>::~List()
{
  clear();
}

template <typename T>
List<T>::List(const List<T> &x) : head(nullptr), size(0)
{
  Node<T>* current = x.head;
  if (current == nullptr)
  return;
  head = new Node<T>(current->getItem());
  size = 1;
  Node<T>* tail = head;
  current = current->getNext();
  while (current != nullptr)
  {
    tail->setNext(new Node<T>(current->getItem()));
    tail = tail->getNext();
    size++;
    current = current->getNext();
  }
}

template <typename T>
List<T> &List<T>::operator=(List<T> x)
{
  swap(x);
  return *this;
}

template <typename T>
void List<T>::swap(List<T> &x)
{
  std::swap(head, x.head);
  std::swap(size, x.size);
}

template <typename T>
bool List<T>::isEmpty() const noexcept
{
  return size == 0;
}

template <typename T>
std::size_t List<T>::getLength() const noexcept
{
  return size;
}

template <typename T>
void List<T>::insert(std::size_t position, const T &item)
{
  if (position < 1 || position > size + 1)
  {
    throw std::out_of_range("Position out of range");
  }
  if (position == 1)
  {
    head = new Node<T>(item, head);
  }
  else
  {
    Node<T>* prev = head;
    for (std::size_t i = 1; i < position - 1; i++)
    {
      prev = prev->getNext();
    }
    Node<T>* newNode = new Node<T>(item, prev->getNext());
    prev->setNext(newNode);
  }
  size++;
}

template <typename T>
void List<T>::remove(std::size_t position)
{
  if (position < 1 || position > size)
  {
    throw std::out_of_range("Position out of range");
  }
  Node<T>* toDelete;
  if (position == 1)
  {
    toDelete = head;
    head = head->getNext();
  }
  else
  {
    Node<T>* prev = head;
    for (std::size_t i = 1; i < position - 1; i++)
    {
      prev = prev->getNext();
    }
    toDelete = prev->getNext();
    prev->setNext(toDelete->getNext());
  }
  delete toDelete;
  size--;
}

template <typename T>
void List<T>::clear()
{
  while (!isEmpty())
  {
    remove(1);
  }
}

template <typename T>
T List<T>::getEntry(std::size_t position) const
{
  if (position < 1 || position > size)
  {
    throw std::out_of_range("Position out of range");
  }
  Node<T>* current = head;
  for (std::size_t i = 1; i < position; i++)
  {
    current = current->getNext();
  }
  return current->getItem();
}

template <typename T>
void List<T>::setEntry(std::size_t position, const T &newValue)
{
  if (position < 1 || position > size)
  {
    throw std::out_of_range("Position out of range");
  }
  Node<T>* current = head;
  for (std::size_t i = 1; i < position; i++)
  {
    current = current->getNext();
  }
  current->setItem(newValue);
}
