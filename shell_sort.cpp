/*
 * shell_sort.cpp
 * C++ implementation of shell sort.
 * By Julie Jiang
 * 2016 Nov
 */
#include <cstdlib>
#include <vector>
#include "sortAlgs.h"
/*****************************************************************************/
/*                                 Shell Sort                                */
/*****************************************************************************/

/*
 * This is basically a twist on insertion sort. Instead of comparing and each 
 * element with the elements that come before it one by one, shell sort 
 * compares each element with an element some gap size apart. Pick gaps of 
 * size n/2, n/4, n/8, ..., 1. For each gap, iterate through the list and swap 
 * elements gap size apart if necessary. 
 *
 * Parameter: a vector of ints containing elements that need to be sorted.
 * Returns: none.
 */
void shellSort(std::vector<int> &list)
{
    // Pick gaps fo size n/2, n/4, n/8, ..., 1
    for (int gap = (int) list.size() / 2; gap >= 1; gap /= 2) {

        // Compare elements gap size apart
        for (int i = gap; i < (int) list.size(); i++) {

            // Swap elements if the element later in the list is smaller than 
            // the element earlier in the list. Once 
            for (int j = i; j >= gap; j-= gap) {
                if (list[j] < list[j - gap]) {
                    swap_shell(list, j, j - gap); 
                } else {
                    break;
                }
            } 
        }
    }
}
/* 
 * Swap the element at index i with the element at index j of the list
 * Parameter: a vector of ints, and two indices whose values need to be 
 * swapped.
 * Returns: none.
 */
void swap_shell(std::vector<int> &list, unsigned int i, unsigned int j)
{
    int temp = list[i];
    list[i]  = list[j];
    list[j]  = temp;
}