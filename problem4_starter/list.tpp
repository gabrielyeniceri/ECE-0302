#include "list.hpp"
#include "Node.hpp"
#include <utility>
template <typename T>
List<T>::List() : head(nullptr), size(0)
{
}

template <typename T>
List<T>::~List()
{
  clear();
}

template <typename T>
List<T>::List(const List<T> &x) : head (nullptr), size (0)
{
  Node<T>* current = x.head;
  while (current) {
      insert(size + 1, current->getItem());
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
void List<T>::swap(List &x)
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
bool List<T>::insert(std::size_t position, const T &item)
{
if (position < 1 || position > size + 1)
throw std::out_of_range("insert: index out of range");

Node<T>* newNode = new Node<T>(item);
if (position == 1) {
  newNode->setNext(head);
  head = newNode;
} else {
  Node<T>* prev = head;
  for (std::size_t i = 1; i < position - 1; i++)
      prev = prev->getNext();
  newNode->setNext(prev->getNext());
  prev->setNext(newNode);
}
size++;
  return true;
}

template <typename T>
bool List<T>::remove(std::size_t position)
{
  if (position < 1 || position > size)
  throw std::out_of_range("remove: index out of range");

Node<T>* temp = nullptr;
if (position == 1) {
  temp = head;
  head = head->getNext();
} else {
  Node<T>* prev = head;
  for (std::size_t i = 1; i < position - 1; i++)
      prev = prev->getNext();
  temp = prev->getNext();
  prev->setNext(temp->getNext());
}
delete temp;
size--;
 return true;
}

template <typename T>
void List<T>::clear()
{
  while (!isEmpty())
  remove(1);
}

template <typename T>
T List<T>::getEntry(std::size_t position) const
{
if (position < 1 || position > size)
throw std::out_of_range("getEntry: index out of range");
Node<T>* current = head;
for (std::size_t i = 1; i < position; i++)
  current = current->getNext();
return current->getItem();
}

template <typename T>
void List<T>::setEntry(std::size_t position, const T &newValue)
{
if (position < 1 || position > size)
  throw std::out_of_range("setEntry: index out of range");

Node<T>* current = head;
for (std::size_t i = 1; i < position; i++)
  current = current->getNext();
current->setItem(newValue);
}

template <typename T>
void List<T>::moveEntry(std::size_t from, std::size_t to)
{
if (from < 1 || from > size || to < 1 || to > size)
 throw std::out_of_range("moveEntry: index out of range");

if (from == to)
 return;
//gets item at from pos, then removes the node at the pos
T item = getEntry(from);
remove(from);
//Removing shifts the remaining elements
//to have the moved item at the final index it is inserted at index to in the new list
insert(to, item);
}
