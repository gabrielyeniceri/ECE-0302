#ifndef _LIST_HPP_
#define _LIST_HPP_

#include "abstract_list.hpp"
#include <cstddef>
#include <utility>

template <typename T>
struct Node {
   T data;
   Node* next;
   Node(const T& d, Node* n = nullptr): data(d), next(n) {}
};

template <typename T>
class List : public AbstractList<T>
{
public:
  List();

  List(const List &x);

  ~List();

  List &operator=(List x);

  void swap(List &x);

  bool isEmpty() const noexcept;

  std::size_t getLength() const noexcept;

  void insert(std::size_t position, const T &item);

  void remove(std::size_t position);

  void clear();

  T getEntry(std::size_t position) const;

  void setEntry(std::size_t position, const T &newValue);

private:
Node<T>* head;
std::size_t length;
};

#include "list.tpp"

#endif
