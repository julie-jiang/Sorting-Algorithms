/*
 * testSortingAlgs.cpp
 * By Julie Jiang
 * 2016 Nov
 * 
 * Tests for the six sorting algorithms。
 * Test cases include 
 *      1) empty list
 *      2) singleton list
 *      3) list with repeated elements
 *      4) list already sorted
 *      5) list sorted in reverse order
 *      6) list with negative numbers
 */
#include <iostream>
#include <sortAlgs.h>
#include <cassert>

/* Returns a pointer to a sorting function */
typedef void (*sortingFuncPtr) (std::vector<int> &);
sortingFuncPtr getSortingFunc(int i) 
{
    if (i == 1) {
        std::cout << "1. Insertion Sort\n";
        return insertionSort;
    } else if (i == 2) {
        std::cout << "2. Quick Sort\n";
        return quickSort;
    } else if (i == 3) {
        std::cout << "3. Merge Sort\n";
        return mergeSort;
    } else if (i == 4) {
        std::cout << "4. Heap Sort\n";
        return heapSort;
    } else if (i == 5) {
        std::cout << "5. Shell Sort\n";
        return shellSort;
    } else {
        std::cout << "6. Radix Sort\n";
        return radixSort;
    }
}

void test1(sortingFuncPtr sortingFunc)
{
    std::vector<int> testcase1;
    std::vector<int> answer1;
    sortingFunc(testcase1);
    assert(testcase1 == answer1);
}

void test2(sortingFuncPtr sortingFunc)
{
    std::vector<int> testcase2{0};
    std::vector<int> answer2  {0};
    sortingFunc(testcase2);
    assert(testcase2 == answer2);
}

void test3(sortingFuncPtr sortingFunc)
{
    std::vector<int> testcase3{0, 0};
    std::vector<int> answer3  {0, 0};
    sortingFunc(testcase3);
    assert(testcase3 == answer3);
}
void test4(sortingFuncPtr sortingFunc)
{
    std::vector<int> testcase4{0, 0, 0};
    std::vector<int> answer4  {0, 0, 0};
    sortingFunc(testcase4);
    assert(testcase4 == answer4);
}
void test5(sortingFuncPtr sortingFunc)
{
    std::vector<int> testcase5{0, 1};
    std::vector<int> answer5  {0, 1};
    sortingFunc(testcase5);
    assert(testcase5 == answer5);
}
void test6(sortingFuncPtr sortingFunc)
{
    std::vector<int> testcase6{1, 0};
    std::vector<int> answer6  {0, 1};
    sortingFunc(testcase6);
    assert(testcase6 == answer6);
}
void test7(sortingFuncPtr sortingFunc)
{
    std::vector<int> testcase7{0, 1, 2};
    std::vector<int> answer7  {0, 1, 2};
    sortingFunc(testcase7);
    assert(testcase7 == answer7);
}

void test8(sortingFuncPtr sortingFunc)
{
    std::vector<int> testcase8{0, 2, 1};
    std::vector<int> answer8  {0, 1, 2};
    sortingFunc(testcase8);
    assert(testcase8 == answer8);
}

void test9(sortingFuncPtr sortingFunc)
{
    std::vector<int> testcase9{1, 0, 2};
    std::vector<int> answer9  {0, 1, 2};
    sortingFunc(testcase9);
    assert(testcase9 == answer9);
}
void test10(sortingFuncPtr sortingFunc)
{
    std::vector<int> testcase10{1, 2, 0};
    std::vector<int> answer10  {0, 1, 2};
    sortingFunc(testcase10);
    assert(testcase10 == answer10);
}

void test11(sortingFuncPtr sortingFunc)
{
    std::vector<int> testcase11{2, 0, 1};
    std::vector<int> answer11  {0, 1, 2};
    sortingFunc(testcase11);
    assert(testcase11 == answer11);
}


void test12(sortingFuncPtr sortingFunc)
{
    std::vector<int> testcase12{2, 1, 0};
    std::vector<int> answer12  {0, 1, 2};
    sortingFunc(testcase12);
    assert(testcase12 == answer12);
}

void test13(sortingFuncPtr sortingFunc)
{
    std::vector<int> testcase13{0, 1, 1};
    std::vector<int> answer13  {0, 1, 1};
    sortingFunc(testcase13);
    assert(testcase13 == answer13);
}

void test14(sortingFuncPtr sortingFunc)
{
    std::vector<int> testcase14{1, 0, 1};
    std::vector<int> answer14  {0, 1, 1};
    sortingFunc(testcase14);
    assert(testcase14 == answer14);
}

void test15(sortingFuncPtr sortingFunc)
{
    std::vector<int> testcase15{1, 1, 0};
    std::vector<int> answer15  {0, 1, 1};
    sortingFunc(testcase15);
    assert(testcase15 == answer15);
}

void test16(sortingFuncPtr sortingFunc)
{
    std::vector<int> testcase16{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> answer16  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    sortingFunc(testcase16);
    assert(testcase16 == answer16);
}
void test17(sortingFuncPtr sortingFunc)
{
    std::vector<int> testcase17{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<int> answer17  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    sortingFunc(testcase17);
    assert(testcase17 == answer17);
}


void test18(sortingFuncPtr sortingFunc)
{
    std::vector<int> testcase18{42, 9, 17, 54, 602, -3, 54, 999, -11};
    std::vector<int> answer18  {-11, -3, 9, 17, 42, 54, 54, 602, 999};
    sortingFunc(testcase18);
    assert(testcase18 == answer18);
}



void test19(sortingFuncPtr sortingFunc)
{
    std::vector<int> testcase19{-11, -3, 9, 17, 42, 54, 54, 602, 999};
    std::vector<int> answer19  {-11, -3, 9, 17, 42, 54, 54, 602, 999};
    sortingFunc(testcase19);
    assert(testcase19 == answer19);
}


int main()
{
    std::cout << ">>>>>Begin testing sorting algorithms<<<<<\n\n";
    for (int i = 1; i <= 6; i++) {
        sortingFuncPtr sortingFunc = getSortingFunc(i);
        test1(sortingFunc);
        test2(sortingFunc);
        test3(sortingFunc);
        test4(sortingFunc);
        test5(sortingFunc);
        test6(sortingFunc);
        test7(sortingFunc);
        test8(sortingFunc);
        test9(sortingFunc);
        test10(sortingFunc);
        test11(sortingFunc);
        test12(sortingFunc);
        test13(sortingFunc);
        test14(sortingFunc);
        test15(sortingFunc);
        test16(sortingFunc);
        test17(sortingFunc);
        test18(sortingFunc);
        test19(sortingFunc);
        std::cout << "   Test passed.\n";
    }
    std::cout << ">>>>>Sorting algorithms all test passed<<<<\n\n";
    
}
