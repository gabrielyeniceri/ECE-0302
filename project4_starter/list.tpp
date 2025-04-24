#include "list.hpp"

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
List<T>::List(const List<T> &x) : head(nullptr), length(0)
{

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
void List<T>::insert(std::size_t position, const T &item)
{
  if(position < 1 || position > length + 1) {
    throw std::out_of_range("Invalid position for insert");
}
if(position == 1) {
    head = new Node<T>(item, head);
} else {
    Node<T>* prev = head;
    for(std::size_t i = 1; i < position - 1; i++) {
        prev = prev->next;
    }
    prev->next = new Node<T>(item, prev->next);
}
++length;
}

template <typename T>
void List<T>::remove(std::size_t position)
{
  if(position < 1 || position > length) {
    throw std::out_of_range("Invalid position for remove");
}
Node<T>* toDelete = nullptr;
if(position == 1) {
    toDelete = head;
    head = head->next;
} else {
    Node<T>* prev = head;
    for(std::size_t i = 1; i < position - 1; i++) {
        prev = prev->next;
    }
    toDelete = prev->next;
    prev->next = toDelete->next;
}
delete toDelete;
--length;
}

template <typename T>
void List<T>::clear()
{
  while(head) {
    Node<T>* temp = head;
    head = head->next;
    delete temp;
}
length = 0;
}

template <typename T>
T List<T>::getEntry(std::size_t position) const
{
if(position < 1 || position > length) {
    throw std::out_of_range("Invalid position for getEntry");
}
Node<T>* current = head;
for(std::size_t i = 1; i < position; i++) {
    current = current->next;
}
return current->data;
}

template <typename T>
void List<T>::setEntry(std::size_t position, const T &newValue)
{
if(position < 1 || position > length) {
  throw std::out_of_range("Invalid position for setEntry");
}
Node<T>* current = head;
for(std::size_t i = 1; i < position; i++) {
    current = current->next;
}
current->data = newValue;
}
