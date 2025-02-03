#include "linked_list.hpp"
#include <stdexcept>
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), m_length(0)
{
  // empty list initialize
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  clear(); //clears the list
}
//copy
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &x)  : head(nullptr), m_length(0)
{
Node<T>* current = x.head;
  while (current != nullptr)
  {
    insert(m_length + 1, current->getItem());
    current = current->getNext();
  }
}
//copy swap
template <typename T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> x)
{
  swap(x);
  return *this;
}
//head pntr and length
template <typename T>
void LinkedList<T>::swap(LinkedList &x)
{
  std::swap(head, x.head);
  std::swap(m_length, x.m_length);
}
//if empty then  true
template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{
  return m_length == 0;
}
//num of list
template <typename T>
std::size_t LinkedList<T>::getLength() const noexcept
{
   return m_length;
}
//inserts item at the index pos valid 1 through m_length +1
template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T &item)
{
if (position < 1 || position > m_length + 1)
    return false;
Node<T>* newNode = new Node<T>(item, nullptr);
if (position == 1)
  {
    newNode->setNext(head);
    head = newNode;
  }
  else
  {
    Node<T>* prev = head;
    for (std::size_t i = 1; i < position - 1; ++i)
    prev = prev->getNext();
    newNode->setNext(prev->getNext());
    prev->setNext(newNode);
  }
++m_length;
return true;
}
//removes item at index pos valid through 1 to m_length
template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
if (position < 1 || position > m_length)
    return false;
  
Node<T>* nodeToDelete = nullptr;
if (position == 1)
  {
    nodeToDelete = head;
    head = head->getNext();
  }
  else
  {
    Node<T>* prev = head;
    for (std::size_t i = 1; i < position - 1; ++i)
    prev = prev->getNext();
    nodeToDelete = prev->getNext();
    prev->setNext(nodeToDelete->getNext());
  }
delete nodeToDelete;
--m_length;
return true;
}
//removes all items in list
template <typename T>
void LinkedList<T>::clear()
{
while (head != nullptr)
  {
  Node<T>* temp = head;
  head = head->getNext();
  delete temp;
  }
  m_length = 0;
}
//returns item at given index pos throw out of range if invalid
template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  if (position < 1 || position > m_length)
  throw std::out_of_range("Invalid position in getEntry");
  Node<T>* current = head;
  for (std::size_t i = 1; i < position; ++i)
  current = current->getNext();
  return current->getItem();
}
//sets item at given index pos to new value or throws out of range if inavlid
template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T &newValue)
{
if (position < 1 || position > m_length)
    throw std::out_of_range("Invalid position in setEntry"); 
  Node<T>* current = head;
  for (std::size_t i = 1; i < position; ++i)
    current = current->getNext();
current->setItem(newValue);
}
