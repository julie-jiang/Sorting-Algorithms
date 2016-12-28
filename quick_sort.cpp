/*
 * quick_sort.cpp
 * C++ implementation of quick sort.
 * By Julie Jiang
 * 2016 Nov
 */
#include <cstdlib>
#include <vector>
#include "sortAlgs.h"
/*****************************************************************************/
/*                                 Quick Sort                                */
/*****************************************************************************/

/*
 * Recursively partition the list into two sublists so that every element that 
 * comes before the picked pivot is smaller than the pivot, and every element 
 * that comes after it is larger. The pivot is always chosen to be the last 
 * element in the sublist. 
 * 
 * Best:    O(nlog(n)). In each partition the list is divided into two sublists
 *          of nearly equal size. Therefore, the recursion depth is log_2(n)
 * Worse:   O(n^2). In each partition the list is divided into two sublists of 
 *          zero and n-1. Therefore the recursion depth is n-1.
 * Average: O(nlog(n))
 *
 * Parameter: a vector of ints containing elements that need to be sorted.
 */
void quickSort(std::vector<int> &list)
{
    quickSort(list, 0, (int)list.size() - 1);
}

/* 
 * Quick sort recursive version.
 * Recursively partition the list until the sublist is of length 1 or 0.
 * 
 * Parameters: a vector of ints containing elements that need to be sorted,
 * and the first and last indices of this sublist.
 */
void quickSort(std::vector<int> &list, int lo, int hi)
{
    if (lo < hi) {
        int p = partition(list, lo, hi);
        quickSort(list, lo, p - 1);
        quickSort(list, p + 1, hi);
    }
}
/* 
 * Quick sort helper function. Pick the last element in the sublist as the 
 * pivot and partition the list so that all elements smaller than the pivot 
 * lies before the pivot, and all elements greater than the pivot lies after 
 * the pivot. 
 * In the for loop, the sublist is iterated from index lo up to the index
 * before the pivot (hi - 1). In each iteration, the values are swapped if the 
 * element at that index smaller than the pivot. This way, the elements 
 * from lo to i is always smaller than the pivot, and the elements from i
 * to j is always greater than the pivot. 
 * 
 * Parameters: a vector of ints containing elements that need to be sorted, 
 * and the first and last indices of this sublist.
 * Returns: the index that partitions the list into two sublists.
 */
int partition(std::vector<int> &list, int lo, int hi)
{
    int pivot = list[hi];
    int i     = lo;

    for (int j = lo; j < hi; j++) {
        if (list[j] < pivot) {
            swap_quick(list, i, j);
            i++;
        }
    }
    swap_quick(list, i, hi);
    return i; 
}
/* 
 * Swap the element at index i with the element at index j of the list
 * Parameter: a vector of ints, and two indices whose values need to be 
 * swapped.
 * Returns: none.
 */
void swap_quick(std::vector<int> &list, unsigned int i, unsigned int j)
{
    int temp = list[i];
    list[i]  = list[j];
    list[j]  = temp;
}