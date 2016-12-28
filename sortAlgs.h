/*
 * sortAlgs.h
 * Header file of c++ implementations of sorting algorithms including 
 * insertion, merge, quick, shell, and radix.
 * By Julie Jiang
 * 2016 Nov
 *
 * Sorting algorithm header file
 * s1 -> insertion sort
 * s2 -> quick sort
 * s3 -> merge sort
 * s4 -> heap sort
 * s5 -> shell sort
 * s6 -> radix sort
 * 
 * To sort a list of integers of the type std::vector<int>, simply call one 
 * of the sorting algorithms like so:
 *      insertionSort(list);
 * The list is passed by reference.
 */
#ifndef SORTALGS_H
#define SORTALGS_H
#include <cstdlib>
#include <vector>
using namespace std;

/* Main sorting functions */
void insertionSort(vector<int> &);
void quickSort    (vector<int> &);
void mergeSort    (vector<int> &);
void heapSort     (vector<int> &);
void shellSort    (vector<int> &);
void radixSort    (vector<int> &);


/* Helper Functions */
void         quickSort     (vector<int> &, int, int);
int          partition     (vector<int> &, int, int);
void         mergeSort     (vector<int> &, int, int); 
void         merge         (vector<int> &, int, int, int);
vector<int> *deepCopy      (vector<int> &);
void         heapify       (vector<int> &);
void         downHeap      (vector<int> &, int, int);
void         radixSort     (vector<int> &, int, int);
void         bucketize     (vector<int> &, int, int, int);
int          getMax        (vector<int> &, int, int);
void         reverseOrder  (std::vector<int> &, int);
int          partition     (std::vector<int> &);
void         swap_heap     (vector<int> &, unsigned int, unsigned int);
void         swap_shell    (vector<int> &, unsigned int, unsigned int);
void         swap_quick    (vector<int> &, unsigned int, unsigned int);
void         swap_radix    (vector<int> &, unsigned int, unsigned int);

#endif