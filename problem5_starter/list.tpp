#include "list.hpp"
#include <stdexcept>

template <typename T>
List<T>::List() : head(nullptr), length(0)
{
}

template <typename T>
List<T>::~List()
{
  clear();
}

template <typename T>
List<T>::List(const List<T>& x) : head(nullptr), length(0) 
{
  Node<T>* current = x.head;
  while (current != nullptr) {
    insert(length + 1, current->getItem());
    current = current->getNext();
  }
}

template <typename T>
List<T>& List<T>::operator=(List<T> x)
{
  swap(x);
  return *this;
}

template <typename T>
void List<T>::swap(List& x) 
{
  std::swap(head, x.head);
  std::swap(length, x.length);
}

template <typename T>
bool List<T>::isEmpty() const noexcept
{
  return length == 0;
}

template <typename T>
std::size_t List<T>::getLength() const noexcept
{
  return length;
}

template <typename T>
void List<T>::insert(std::size_t position, const T& item)
{
if (position < 1 || position > length + 1) {
  throw std::out_of_range("Invalid position for insert");
}
 Node<T>* newNode = new Node<T>(item);
if (position == 1) {
   newNode->setNext(head);
   head = newNode;
} else {
  Node<T>* prev = head;
  for (std::size_t i = 1; i < position - 1; i++) {
    prev = prev->getNext();
  }
  newNode->setNext(prev->getNext());
  prev->setNext(newNode);
  }
  ++length;
}

template <typename T>
void List<T>::remove(std::size_t position)
{
  if (position < 1 || position > length) {
    throw std::out_of_range("Invalid position for remove");
  }
  Node<T>* nodeToRemove = nullptr;
  if (position == 1) {
    nodeToRemove = head;
    head = head->getNext();
  } else {
    Node<T>* prev = head;
    for (std::size_t i = 1; i < position - 1; i++) {
      prev = prev->getNext();
    }
    nodeToRemove = prev->getNext();
    prev->setNext(nodeToRemove->getNext());
  }
  delete nodeToRemove;
  --length;
}

template <typename T>
void List<T>::clear()
{
 while (!isEmpty()) {
    remove(1);
 }
}

template <typename T>
T List<T>::getEntry(std::size_t position) const
{
  if (position < 1 || position > length) {
    throw std::out_of_range("Invalid position for getEntry");
  }
  Node<T>* current = head;
  for (std::size_t i = 1; i < position; i++) {
    current = current->getNext();
  }
  return current->getItem();
}

template <typename T>
void List<T>::setEntry(std::size_t position, const T& newValue)
{
  if (position < 1 || position > length) {
    throw std::out_of_range("Invalid position for setEntry");
  }
  Node<T>* current = head;
  for (std::size_t i = 1; i < position; i++) {
    current = current->getNext();
  }
  current->setItem(newValue);
}
