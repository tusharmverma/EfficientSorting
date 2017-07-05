#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <algorithm>    // std::swap
using std::swap;
#include <time.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include "QuickSort.h"
#include "MaxHeap.h"

int main()
{
    int array[8]= {4, 5, 6, 8, 12, 51, 23, 43};
    quicksort(array, 8);
    for(int i = 0; i < 8; i++)
    {
        cout << array[i] << '\t';
    }
    cout << endl;
    
    const int SIZE = 10;
    int heap_size = 0;
    int heap_array[SIZE];
    int value =  rand() % 100;
    srand (time(NULL));
    for(int i = 0; i < SIZE; i++)
    {
        int random = rand() % 100;
        value += random;
        max_heap_insert(value, heap_array, heap_size);
        srand (time(NULL));
    }
    cout << "Heap:" << endl;
    for(int i = 0; i < SIZE; i++)
    {
        cout << heap_array[i] << '\t';
    }
    cout << endl;
    
    cout << "Make max heap bottom up: " << endl;
    heap_size = SIZE;
    for(int i = 0; i < SIZE; i++)
    {
        cout << "\nRemoving: \t( " << heap_remove(heap_array, heap_size) << " ) : \t";
        make_max_heap_bottom_up(heap_array, heap_size);
        for(int j=0; j < heap_size; j++)
        {
            cout << heap_array[j] << '\t';
        }
    }
    
    cout << "\n\nMake max heap top down: " << endl;
    make_max_heap_top_down(heap_array, heap_size);
    for(int j=0; j < heap_size; j++)
    {
        cout << heap_array[j] << '\t';
    }
    
    
    
    
    heap_sort(heap_array, SIZE);
    cout << "\n\nSort heap: " << endl;
    for(int i = 0; i < SIZE; i++)
    {
        cout << heap_array[i] << '\t';
    }
    cout << endl;
    return 0;
}
