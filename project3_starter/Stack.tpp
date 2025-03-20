/** @file Stack.tpp */
// Finish this .tpp first to pass the first 3 unit tests

#include <stdexcept>
#include "Stack.hpp"
#include "Node.hpp"

template <typename ItemType>
Stack<ItemType>::Stack() : headPtr(nullptr), currentSize(0)
{
} // end default constructor

template <typename ItemType>
Stack<ItemType>::~Stack()
{
	clear();
} // end destructor

template <typename ItemType>
bool Stack<ItemType>::isEmpty() const
{
	return currentSize == 0;
} // end isEmpty

template <typename ItemType>
int Stack<ItemType>::size() const
{
	return currentSize;
} // end size

template <typename ItemType>
bool Stack<ItemType>::push(const ItemType &newItem)
{
    Node<ItemType>* newNode = new Node<ItemType>(newItem, headPtr);
    headPtr = newNode;
    currentSize++;
	return true;
} // end push

template <typename ItemType>
ItemType Stack<ItemType>::peek() const
{
if (isEmpty())
    throw std::logic_error("Stack is empty");
return headPtr->getItem();
} // end peek

template <typename ItemType>
bool Stack<ItemType>::pop()
{
if (isEmpty())
	return false;
Node<ItemType>* nodeToDelete = headPtr;
headPtr = headPtr->getNext();
delete nodeToDelete;
currentSize--;
return true;
} // end pop

template <typename ItemType>
void Stack<ItemType>::clear()
{
while (!isEmpty()) {
        pop();
}
} // end clear