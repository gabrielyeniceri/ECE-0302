#include <cmath> // for log2
#include "ArrayMaxHeap.hpp"
#include <stdexcept>

template <typename ItemType>
int ArrayMaxHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const
{
   return (2 * nodeIndex) + 1;
} // end getLeftChildIndex, private method

template <typename ItemType>
int ArrayMaxHeap<ItemType>::getRightChildIndex(const int nodeIndex) const
{
   return (2 * nodeIndex) + 2;
} // end getRightChildIndex, private method

template <typename ItemType>
int ArrayMaxHeap<ItemType>::getParentIndex(const int nodeIndex) const
{
   return (nodeIndex - 1) / 2;
} // end getParentIndex, private method

template <typename ItemType>
bool ArrayMaxHeap<ItemType>::isLeaf(const int nodeIndex) const
{
   return (getLeftChildIndex(nodeIndex) >= itemCount);
} // end isLeaf, private method

template <typename ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(const int subTreeNodeIndex)
{
   if (!isLeaf(subTreeNodeIndex))
   {
      int leftChildIndex = getLeftChildIndex(subTreeNodeIndex);
      int rightChildIndex = getRightChildIndex(subTreeNodeIndex);
      int largerChildIndex = leftChildIndex;
      if (rightChildIndex < itemCount && items[rightChildIndex] > items[leftChildIndex])
         largerChildIndex = rightChildIndex;
      if (items[subTreeNodeIndex] < items[largerChildIndex])
      {
         ItemType temp = items[subTreeNodeIndex];
         items[subTreeNodeIndex] = items[largerChildIndex];
         items[largerChildIndex] = temp;
         heapRebuild(largerChildIndex);
      }
   } // end if
} // end heapRebuild, private method

template <typename ItemType>
void ArrayMaxHeap<ItemType>::heapCreate()
{
   // Start with the last parent node and rebuild the heap to the root
   for (int index = itemCount / 2 - 1; index >= 0; index--)
   {
      heapRebuild(index);
   } // end for
} // end heapCreate, private method

//******************************************************************
//
// Public methods start here
//
//******************************************************************

template <typename ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap() : itemCount(0)
{
} // end default constructor

template <typename ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(const ItemType someArray[], const int arraySize) : itemCount(arraySize)
{
   // Copy given values into the array
   for (int i = 0; i < itemCount; i++)
      items[i] = someArray[i];

   // Reorganize the array into a heap
   heapCreate();
} // end constructor

template <typename ItemType>
ArrayMaxHeap<ItemType>::~ArrayMaxHeap()
{
   clear();
} // end destructor

template <typename ItemType>
bool ArrayMaxHeap<ItemType>::isEmpty() const noexcept
{
   return itemCount == 0;
} // end isEmpty

template <typename ItemType>
int ArrayMaxHeap<ItemType>::getHeight() const noexcept
{
   return ceil(log2(itemCount + 1));
} // end getHeight

template <typename ItemType>
int ArrayMaxHeap<ItemType>::getNumberOfNodes() const noexcept
{
   return itemCount;
} // end getNumberOfNodes

template <typename ItemType>
void ArrayMaxHeap<ItemType>::clear() noexcept
{
   itemCount = 0;
} // end clear

template <typename ItemType>
ItemType ArrayMaxHeap<ItemType>::peekTop() const
{
   if (isEmpty())
      throw std::out_of_range("Heap is empty");
   return items[0];
} // end peekTop

template <typename ItemType>
bool ArrayMaxHeap<ItemType>::add(const ItemType &newData)
{
   if (itemCount >= DEFAULT_CAPACITY)
      return false;
   for (int i = 0; i < itemCount; i++)
   {
      if (items[i] == newData)
         return false;
   }
   int currentIndex = itemCount;
   items[currentIndex] = newData;
   itemCount++;
   int parentIndex = getParentIndex(currentIndex);
   while (currentIndex > 0 && items[currentIndex] > items[parentIndex])
   {
      ItemType temp = items[currentIndex];
      items[currentIndex] = items[parentIndex];
      items[parentIndex] = temp;
      currentIndex = parentIndex;
      parentIndex = getParentIndex(currentIndex);
   }
   return true;
} // end add

template <typename ItemType>
bool ArrayMaxHeap<ItemType>::remove()
{
   if (isEmpty())
      return false;
   itemCount--;  
   if (itemCount > 0)
   {
      items[0] = items[itemCount];
      heapRebuild(0);
   }
   return true;
} // end remove

template <typename ItemType>
void ArrayMaxHeap<ItemType>::heapSort(ItemType anArray[], int n)
{
   if (n > DEFAULT_CAPACITY)
      throw std::invalid_argument("Array size exceeds capacity");


   for (int i = 0; i < n; i++)
   {
      for (int j = i + 1; j < n; j++)
      {
         if (anArray[i] == anArray[j])
            throw std::invalid_argument("Duplicate values found in array");
      }
   }
   for (int i = 0; i < n; i++)
   {
      items[i] = anArray[i];
   }
   itemCount = n;
   heapCreate();
   for (int i = 0; i < n; i++)
   {
      anArray[i] = peekTop();
      remove();
   }
} // end heapSort
