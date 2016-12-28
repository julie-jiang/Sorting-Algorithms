/*
 * heap_sort.cpp
 * C++ implementation of heap sort.
 * By Julie Jiang
 * 2016 Nov
 */
#include <cstdlib>
#include <vector>
#include "sortAlgs.h"

/*****************************************************************************/
/*                                 Heap Sort                                 */
/*****************************************************************************/
/*
 * Heapify the list. Then, take the first element (which is always the max) 
 * from the heap and put it in the back of the list. Repeat until there's no 
 * more elements left in the heap
 * Best:    O(nlog(n))
 * Worst:   O(nlog(n))
 * Average: O(nlog(n))
 * The time complexity is always O(nlog(n)). This is because down heap takes 
 * O(log(n)) time, and heapify takes O(n) time in each iteration. So Building a
 * max heap takes O(nlog(n)) time in total. Sorting the list by repeatedly 
 * extracting the max from the heap and re-heapify takes O(nlog(n)) time 
 * because each iteration requires one down heap (O(log(n))) time and there are
 * n iterations. Therefore, the total time complexity is O(nlog(n)). 
 *
 * Parameter: a vector of ints containing elements that need to be sorted.
 * Returns: none.
 */
void heapSort(std::vector<int> &list)
{
    // Build a max heap
    heapify(list); 

    // Walk through the list starting from the last index. Repeatly swap
    // the maximum element in the heap with the element at the current index, 
    // Decrement the size of the heap by 1 and then re-heapify the rest of the 
    // heap. 
    // Maintains the loop invariant:
    // sublist[:i - 1] contains the heap and sublist[i:] contains the largest
    // few elements of the list in sorted order. 
    for (int i = (int) list.size() - 1; i >= 0; i--) {
        swap_heap(list, 0, i);
        downHeap(list, 0, i);
    }
}

/* 
 * Build a max heap by repeatedly downheaping.
 * 
 * Parameter: a vector of ints containing elements that need to be heapified.
 * Returns: none.
 */
void heapify(std::vector<int> &list)
{
    int size = list.size();
    for (int i = size / 2; i >= 0 ; i--) {
        downHeap(list, i, size);
    }
}
/* 
 * Down heap from index i for a list of the given size via recursion.
 * 
 * Parameters: a vector of ints containing elements in the heap that need to 
 * be heapified,the index of specifying where to downheap from, and the size 
 * of the heap.
 * Returns: none.
 */ 
void downHeap(std::vector<int> &list, int i, int size)
{
    int left    = 2 * i + 1; // Index of left child
    int right   = 2 * i + 2; // Index of right child
    int largest = i;

    // Set index of largest to the largest of the parent and its two children
    // (if they exist).
    if (left < size and list[left] > list[largest]) {
        largest = left;
    }
    if (right < size and list[right] > list[largest]) {
        largest = right;
    }
    // Swap parent with the larger of its children if necessary
    if (largest != i) {
        swap_heap(list, i, largest);
        // Down heap from its larger children
        downHeap(list, largest, size);
    }
}

/* 
 * Swap the element at index i with the element at index j of the list
 * Parameter: a vector of ints, and two indices whose values need to be 
 * swapped.
 * Returns: none.
 */
void swap_heap(std::vector<int> &list, unsigned int i, unsigned int j)
{
    int temp = list[i];
    list[i]  = list[j];
    list[j]  = temp;
}
