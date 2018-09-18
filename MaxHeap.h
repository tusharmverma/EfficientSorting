#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <algorithm>    // std::swap

int left (int value)
{
    return 2*value +1;
}

int right (int value)
{
    return 2*value +2;
}

int parent (int value)
{
    return (value-1)/2;
}

void max_heap_insert(int new_value, int heap_array[], int& heap_size)
{
    int i = heap_size;                                               // add at the current end of
    heap_array[i] = new_value;                                   // the heap + 1, then
    while (i > 0 && heap_array[i] > heap_array[parent(i)])      // restore heap property
    {
        swap(heap_array[i], heap_array[parent(i)]);              // by moving new value up the tree
        i = parent(i);                                           // while it is larger than its parent
    }
    heap_size++;                                                 // heap just got larger
    return;
}


void max_heap_sift_down(int heap_array[], int left_index, int right_index)
{
    bool done = false;                                                // assume there is work to be done
    int i    = left_index;                                          // starting with the "root" (left-most item)
    while ( !done && left(i) <= right_index)                  // scanning until done or h[i] has no children
    {
        int max_child = left(i);                                     // assume left child is max
        if (right(i) <= right_index && heap_array[right(i)] > heap_array[left(i)])                              // see if right child exists
        {                                                                                // and is larger than left
            max_child = right(i);                                // if so, mark right child as max_child
        }
        if (heap_array[max_child] > heap_array[i])               // if the max_child is bigger than h[i]
        {
            swap(heap_array[max_child], heap_array[i]);          // swap h[i] with its max_child
            i = max_child;                                       // and continue scanning from that index
        }
        else                                                   // otherwise, no swap was made, so
        {
            done = true;                                         // the heap property holds, and we can stop
        }
    }
}

void max_heap_sift_down(int heap_array[], int heap_size)              // a simpler interface given array and size
{
    max_heap_sift_down(heap_array, 0, heap_size-1);              // calls the more general algorithm shown below
}


int heap_remove(int heap_array[], int& heap_size)
{
    int result = heap_array[0];                                      // save the result to return later
    swap(heap_array[0], heap_array[heap_size-1]);                // swap root to the end
    heap_size--;                                                 // mark the heap as one item smaller
    max_heap_sift_down(heap_array, heap_size);                   // sift down the element just swapped to root
    return result;                                               // and return the saved result
}

void make_max_heap_top_down(int array[], int array_size)
{
    int heap_size = 0;                                               // pretend that the heap begins empty
    while (heap_size < array_size)                               // while all elements are not yet added
    {
        max_heap_insert(array[heap_size], array, heap_size);     // "add" elements (in-place) to the heap
    }
}

void make_max_heap_bottom_up(int array[], int array_size)
{
    int subroot = parent(array_size-1);                             // start with the last non-leaf node
    while (subroot >= 0)                                         // run until we reach the true root
    {
        max_heap_sift_down(array, subroot, array_size-1);        // sift down the new subroot's value
        subroot--;                                               // and move left to the next subroot
    }
    return;
}

void heap_sort (int array[], int array_size)
{
    make_max_heap_bottom_up(array, array_size);                  // begin by making the array a heap
    int elements_remaining = array_size;                             // store the initial number of elements
    while (elements_remaining > 1)                               // while the unsorted part of the array is non-empty
        heap_remove(array, elements_remaining);                  // "remove" the max (which moves it to the end!)
    return;
}

#endif

