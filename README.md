# Sorting Algorithms
This program contains six sorting algorithms: insertion sort, quick sort, merge sort, heap sort, shell sort, and radix sort. 
## Acknowledgements:
I would like to thank CLRS, Wikipedia, and numerous youtube videos for clarifying how each sorting algorithm works. I also wouldn't be able to implement function pointers without the generous help of Stack Overflow. 
## Compile and run
To compile:
```
make
```
To run:
```
./sorter sortAlg outputMode [fileName]
    where  sortAlg is -s1, -s2, -s3, -s4, -s5, or -s6
    and    outputMode is --print or --save

    s1 - insertion sort
    s2 - quick sort
    s3 - merge sort
    s4 - heap sort
    s5 - shell sort
    s6 - radix sort
```
To compile test files:
```
make test
```
To run:
```
./tester
```

## Algorithms
### Insertion sort.

Sorts the list by iterating through the list once. In each iteration, pick up an element from the list, walk backwards from that element to the front of the list until either a element bigger than it is found or the front of the list is reached. Then swap the element at that index with the element we picked up. Repeat this until each element has been iterated. Note that in each iteration, the elements before the one we're interested in has already been sorted. 

Best: O(n). List is already sorted and so the while loop is never executed.

Worst: O(n^2). List is already sorted but in reverse order. The while loop is always executed and will always be executed a number of times equal the elements index in the list. 

Average: O(n^2). Assume that for each element in the array, we need to walk through half of the elements before it in the while loop before placing it down. 

### Quick sort

Recursively partition the list into two sublists so that every element that comes before the picked pivot is smaller than the pivot, and every element that comes after it is larger. The pivot is always chosen to be the last element in the sublist. 

Best: O(nlog(n)). In each partition the list is divided into two sublists of nearly equal size. Therefore, the recursion depth is log_2(n).

Worse: O(n^2). In each partition the list is divided into two sublists of zero and n-1. Therefore the recursion depth is n-1.

Average: O(nlog(n)).

### Merge sort

Divide, conquer, and combine.

Recursively divide the list into two disjoint sublists of nearly equal size. Conquer them by sorting them individually, and then combine by merging two sublists together.

Best/Worst/Average: O(nlog(n))

It's always O(nlog(n)) because the recursion depth is always log(n), and the time taken at each recursion level is always n. Very stable algorithm!

### Heap sort

Heapify the list. Then take the first element (which is always the max) from the heap and put it in the back of the list. Repeat until there's no more elements left in the heap

Best/worst/Average: O(nlog(n))

The time complexity is always O(nlog(n)). This is because down heap takes O(log(n)) time, and heapify takes O(n) time in each iteration. So Building a max heap takes O(nlog(n)) time in total. Sorting the list by repeatedly extracting the max from the heap and re-heapify takes O(nlog(n)) time because each iteration requires one down heap (O(log(n))) time and there are n iterations. Therefore, the total time complexity is O(nlog(n)). 

### Shell sort

This is basically a twist on insertion sort. Instead of comparing and each element with the elements that come before it one by one, shell sort compares each element with an element some gap size apart. Pick gaps of size n/2, n/4, n/8, ..., 1. For each gap, iterate through the list and swap elements gap size apart if necessary. 

### Radix sort

Radix sort sorts numbers by sorting the least significant digit first, then move towards sorting the most significant digit. 

To sort negative integers using radix sort, the lists are partitioned into two disjoint lists such that `list[0, ..., zeroDivider - 1]` consist of all the negative integers and `list[zeroDivider, ..., list.size() - 1]` consist of all the nonnegative integers. Then sort the absolute values of the elements in the two lists individually using radix sort. After that, order of the numbers in the negative sublist is reversed.
Best/Worst/Averge: O(n)

## Data Structures
The program sorts lists of integers that are contained in `std::vector<int>`, provided by the STL.

## Unit Tests
A concise and through testing is performed on all six sorting algorithms. 
Test cases include: 

1. empty list
2. singleton list
3. list with repeated elements
4. list already sorted
5. list sorted in reverse order
6. list with negative numbers

Please see `testSortingAlgs.cpp` for details.

