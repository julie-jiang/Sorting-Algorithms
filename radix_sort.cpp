/*
 * radix_sort.cpp
 * C++ implementation of radix sort.
 * By Julie Jiang
 * 2016 Nov
 */
#include <cstdlib>
#include <vector>
#include "sortAlgs.h"
/*****************************************************************************/
/*                                Radix Sort                                 */
/*****************************************************************************/
/*
 * Radix sort sorts numbers by sorting the least significant digit first, then
 * move towards sorting the most significant digit. 
 * 
 * To sort negative integers using radix sort, the lists are partitioned into 
 * two disjoint lists such that list[0, ..., zeroDivider - 1] consist of all 
 * the negative integers and list[zeroDivider, ..., list.size() - 1] consist of
 * all the nonnegative integers. Then sort the absolute values of the elements 
 * in the two lists individually using radix sort. After that, order of the 
 * numbers in the negative sublist is reversed.
 * Best/Worst/Averge: O(n)
 *
 * Parameter: a vector of ints containing elements that need to be sorted.
 * Returns: none.
 */

void radixSort(std::vector<int> &list)
{
    if (list.size() <= 1) {
        return;
    }

    // Partition the list so that negative values come before the zeroDivider
    int zeroDivider = partition(list);
    
    // If there are negative numbers 
    if (0 < zeroDivider) {
        radixSort(list, 0, zeroDivider);
        reverseOrder(list, zeroDivider);
    }
    // If there are nonnegative numbers
    if (zeroDivider < (int) list.size()) {
        radixSort(list, zeroDivider, (int) list.size());
    }
}

/*
 * Partitions the list so that all the negative values are before the index i,
 * and all the positive values are at or after the index i
 *
 * Parameter: a vector of ints containing elements that need to be partitioned.
 * Returns: the index that partitions the list into a negative and a positive 
 * sublist.
 */
int partition(std::vector<int> &list)
{
    int i = 0;
    for (int j = 0; j < (int) list.size(); j++) {
        if (list[j] < 0) {
            swap_radix(list, i, j);
            i++;
        }
    }
    return i;
}

/*
 * Reverse the order of the elements in the list[0, ..., zeroDivider - 1].
 * This is used to reverse the order of the negative numbers in the list, 
 * which are sorted using their absolute values.
 *
 * Parameter: a vector of ints containing elements that need to be reversed in 
 * order, and an index that divides the negative sublist from the positive 
 * one.
 * Returns: none.
 */
void reverseOrder(std::vector<int> &list, int zeroDivider)
{
    for (int i = 0; i < zeroDivider / 2; i++) {
        swap_radix(list, i, zeroDivider - 1 - i);
    }

}
/*
 * Returns the largest absolute value of the numbers in the 
 * sublist[lo, ..., hi - 1]. 
 * Assumes lo < hi, which means there is at least one element in the list.
 *
 * Parameter: a vector of ints containing elements that need to be sorted, and
 * the first and last - 1 indices of the sublist
 * Returns: the maximum absolute value of this sublist[lo, ..., hi - 1].
 */
int getMax(std::vector<int> &list, int lo, int hi)
{
    int max = abs(list[lo]);
    for (int i = lo + 1; i < hi; i++) {
        if (abs(list[i]) > max) {
            max = abs(list[i]);
        }
    }
    return max;
}

/* 
 * Assuming lo < hi, sort the list[lo, ..., hi - 1] using radix sort.
 *
 * Parameter: a vector of ints containing elements that need to be sorted, and
 * the first and last - 1 indices of the sublist
 * Returns: none.
 */
void radixSort(std::vector<int> &list, int lo, int hi)
{
    // Get the maximum absolute value of the numbers in the sublist. 
    int max = getMax(list, lo, hi);
    
    // Continue bucketizing and sorting until the most significant digit in the
    // list has been sorted. 
    for (int n = 1; max / n > 0; n *= 10) {
        bucketize(list, n, lo, hi);
    }
}


/* 
 * Sorts the nth digit of the absolute values of the numbers in the 
 * sublist[lo, ..., hi - 1]. 
 * Assuming lo < hi.
 * Parameter: a vector of ints containing elements that need to be sorted, an 
 * int that specifies which digit to sort according to, and the first and 
 * last - 1 indices of the sublist.
 * Returns: none.
 * 
 */
void bucketize(std::vector<int> &list, int n, int lo, int hi)
{
    std::vector<std::vector<int>> buckets (10);

    // Put each number into a bucket depending on the value of its 
    // (log_10(n) + 1)th digit
    for (int i = lo; i < hi; i++) {
        buckets[(unsigned int) (abs(list[i]) % (n * 10)) / n].push_back(list[i]);
    }
    
    // The ith element of the list is set equal to the kth element of the 
    // jth bucket.
    int i = lo;
    for (int j = 0; j < 10; j++) {
        for (int k = 0; k < (int) buckets[j].size(); k++) {
            list[i] = buckets[j][k];
            i++;
        }
    }
        
}
/* 
 * Swap the element at index i with the element at index j of the list
 * Parameter: a vector of ints, and two indices whose values need to be 
 * swapped.
 * Returns: none.
 */
void swap_radix(std::vector<int> &list, unsigned int i, unsigned int j)
{
    int temp = list[i];
    list[i]  = list[j];
    list[j]  = temp;
}