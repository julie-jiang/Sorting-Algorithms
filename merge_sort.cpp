/*
 * merge_sort.cpp
 * C++ implementation of merge sort.
 * By Julie Jiang
 * 2016 Nov
 */
#include <cstdlib>
#include <vector>
#include "sortAlgs.h"
/*****************************************************************************/
/*                                 Merge Sort                                */
/*****************************************************************************/

/* 
 * Divide, conquer, and combine.
 * Recursively divide the list into two disjoint sublists of nearly equal size.
 * Conquer them by sorting them individually, and then combine by merging two 
 * sublists together.
 * Best:    O(nlog(n))
 * Worst:   O(nlog(n))
 * Average: O(nlog(n))
 * It's always O(nlog(n)) because the recursion depth is always log(n), and the
 * time taken at each recursion level is always n. Very stable algorithm!
 *
 * Parameter: a vector of ints containing elements that need to be sorted.
 * Returns: none.
 */
void mergeSort(std::vector<int> &list)
{
    mergeSort(list, 0, (int) list.size() - 1);
}

/*
 * Partition the list into two (nearly) equal halves, and recurse. Then more 
 * two sublists together
 *
 * Parameters: a vector of ints containing elements that need to be sorted,
 * and the first and last indices of this sublist.
 * Returns: none.
 */
void mergeSort(std::vector<int> &list, int lo, int hi)
{
    if (lo < hi) {
        int mi = (lo + hi) / 2;
        mergeSort(list, lo, mi); 
        mergeSort(list, mi + 1, hi);
        merge(list, lo, mi, hi);
    }
}

/*
 * Merge two sublists list[lo, ..., mi] and list[mi + 1, ..., hi] together.
 * Assume the sublists are already sorted. Iterate through the list, and 
 * in each iteration, pick the smaller of the first elements from the sublists
 * that have yet to be picked.
 *
 * Parameters: a vector of ints containing elements that need to be sorted,
 * the index of the first element of the first sublist, the index that 
 * partitions the list into two, and the index of the last element of the 
 * second sublist.
 * Returns: none.
 */
void merge(std::vector<int> &list, int lo, int mi, int hi)
{
    // Make a copy of the list
    std::vector<int> *originalList = deepCopy(list);

    // Begin at the first elements of the two sublists
    int i = lo;
    int j = mi + 1;
    
    // Iterate through the list
    for (int k = lo; k <= hi; k++) {
        // Pick the element from the first sublist if it is smaller
        if (i <= mi and (j > hi or (*originalList)[i] < (*originalList)[j])) {
            list[k] = (*originalList)[i];
            i++;
        // Else pick the element from the second sublist if it is smaller
        } else {
            list[k] = (*originalList)[j];         
            j++;
        }
    }

    delete originalList;

}

/* 
 * Parameter: a vector of ints.
 * Returns: a pointer to a deep copy of the list.
 */
std::vector<int> *deepCopy(std::vector<int> &list)
{
    std::vector<int> *newList = new std::vector<int>(list.size());
    for (unsigned int i = 0; i < list.size(); i++) {
        (*newList)[i] = list[i];
    }
    return newList;
}