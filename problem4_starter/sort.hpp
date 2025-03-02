#ifndef _SORT_HPP
#define _SORT_HPP

#include "list.hpp"

/** Sorts a list into ascending order. Uses the quick sort method.
 @pre  list[first..last] is a list.
 @post  list[first..last] is sorted.
 @throw std::out_of_range if first < 1 or last > list.getLength()
 @param list  The given list.
 @param first  The start element to consider in list.
 @param last  The end element to consider in list. */

template <typename T>
 void swapByMove(List<T>& list, int i, int j) {
     if (i == j) return;
     if (i > j) {
         int temp = i;
         i = j;
         j = temp;
     }
     list.moveEntry(j, i);
     list.moveEntry(i + 1, j);
 }

template <typename T>
void quick_sort(List<T> &list, int first, int last)
{
//ensures error checking
  if (first < 1 || last > static_cast<int>(list.getLength()))
     throw std::out_of_range("quick_sort: index out of range");
if (first < last)
{
//partitions the list
int pivotIndex = partition(list, first, last);
//sorts the left and right sublist recursively
quick_sort(list, first, pivotIndex - 1);
quick_sort(list, pivotIndex + 1, last);
}
    // must call partition below
}

/** Partitions the entries in a list about a pivot entry for quicksort.
 @pre  list[first..last] is an list; first <= last.
 @throw std::out_of_range if first > last, or if first < 1 or last > list.getLength()
 @post  list[first..last] is partitioned such that:
 S1 = list[first..pivotIndex-1] <= pivot
      list[pivotIndex]          == pivot
 S2 = list[pivotIndex+1..last]  >= pivot
 @param list  The given list.
 @param first  The start entry to consider in list.
 @param last  The end entry to consider in list.
 @return  The index of the pivot.
 */

template <typename T>
int partition(List<T> &list, int first, int last)
{
if (first < 1 || last > static_cast<int>(list.getLength()) || first > last)
throw std::out_of_range("partition: index out of range");
T pivot = list.getEntry(last);
int i = first - 1;

//iterates through sublist
for (int j = first; j <= last - 1; j++)
{
    if (list.getEntry(j) <= pivot)
    {
        i++;
        //uses helper to swap i and j entries if they are different
        if (i != j)
            swapByMove(list, i, j);
    }
}
//pivot is placed in correct location by swapping with element at i+1
if (i + 1 != last)
    swapByMove(list, i + 1, last);
    
return i + 1;
    // list[first..pivotIndex-1] <= pivot, list[pivotIndex] == pivot, list[pivotIndex + 1..last] >= pivot
}
#endif
