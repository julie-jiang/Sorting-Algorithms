/*
 * insertion_sort.cpp
 * C++ implementation of insertion sort.
 * By Julie Jiang
 * 2016 Nov
 */
#include <cstdlib>
#include <vector>
#include "sortAlgs.h"

/*****************************************************************************/
/*                              Insertion Sort                               */
/*****************************************************************************/

/*
 * Iterate through the list. In each iteration, pick up an element from the 
 * list, walk backwards from that element to the front of the list until 
 * either a element bigger than it is found or the front of the list is 
 * reached. Then swap the element at that index with the element we picked up.
 * Repeat this until each element has been iterated. Note that in each 
 * iteration, the elements before the one we're interested in has already been
 * sorted. 
 * Best:    O(n). List is already sorted and so the while loop is never 
 *          executed.
 * Worst:   O(n^2). List is already sorted but in reverse order. The while loop
 *          is always executed and will always be executed a number of times 
 *          equal the elements index in the list. 
 * Average: O(n^2). Assume that for each element in the array, we need to walk 
 *          through half of the elements before it in the while loop before 
 *          placing it down. 
 *
 * Parameter: a vector of ints containing elements that need to be sorted.
 * Returns: none.
 */
void insertionSort(std::vector<int> &list)
{
    // Iterate through the list
    for (unsigned int i = 1; i < list.size(); i++) {
        int elem = list[i];
        int j    = i - 1;

        // Compare elem with the elements before it, and swap if necessary. 
        // Swapping is done by repeatedly moving the elements one unit back.
        while (j >= 0 and list[j] > elem) {
            list[j + 1] = list[j]; 
            j--;
        }
        list[j + 1] = elem;
    }
}