/*
 * sort_helper.cpp
 * Helper function of the sorting algorithms.
 * By Julie Jiang
 * 2016 Nov
 */
#include <cstdlib>
#include <vector>
#include "sortAlgs.h"
/* 
 * Swap the element at index i with the element at index j of the list
 * Parameter: a vector of ints, and two indices whose values need to be 
 * swapped.
 * Returns: none.
 */
void swap(std::vector<int> &list, unsigned int i, unsigned int j)
{
    int temp = list[i];
    list[i]  = list[j];
    list[j]  = temp;
}