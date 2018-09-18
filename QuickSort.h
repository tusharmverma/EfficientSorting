#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <algorithm>    // std::swap
using std::swap;
#include <time.h>

int choose_pivot(int left, int right)
{
    int pivot;
    srand (time(NULL));
    pivot = rand() % (right-left) +left;
    //pivot = (left+right)/2;
    return pivot;
}

int partition(int array[], int left, int right)
{
    int pivot_index, pivot_value;
    pivot_index = choose_pivot(left, right);
    cout << "Pivot: " << pivot_index << endl;
    pivot_value = array[pivot_index];                   // pivot value for easy reference
    cout << "Pivot value: " << pivot_value << endl;
    swap(array[pivot_index], array[right]);         // move pivot to end (out of the way)
    pivot_index = left;                             // start looking for "correct" location
    for (int i = left; i <= right-1; i++)    // by scanning the entire array
    {
        if (array[i] < pivot_value)                          // if value smaller than pivot is found
        {
            swap(array[i], array[pivot_index]);                  // swap it into left partition
            pivot_index++;                               // and move the dividing point
        }
    }
    if (array[pivot_index] < pivot_value)
    {
        pivot_index++;
    }
    swap(array[pivot_index], array[right]);            // swap pivot into its correct location
    return pivot_index;                              // and return the location of the split
}

void quicksort(int array[], int left, int right)
{
    int division;
    if (left < right)                            // being "unsorted" requires 2 or more values...
    {
        division = partition(array, left, right);  // smaller values to left of division, larger to right
        quicksort(array, left, division-1);              // now quicksort everything left of division
        quicksort(array, division+1, right);            // and everything right of division
    }
    return;
}

void quicksort(int array[], int size)
{
    int left = 0;
    int right = size-1;
    quicksort(array, left, right);
    return;
}

#endif

