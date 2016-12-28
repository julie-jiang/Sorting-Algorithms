# Makefile for sorting algorithms program and its unit test
# By Julie Jiang
# 2016 Nov

CXX = clang++
CXXFLAGS = -std=c++11 -Wall -Wextra

sorter: sorter.o sortAlgs.o 
	${CXX} ${CXXFLAGS} -o sorter sorter.cpp insertion_sort.cpp heap_sort.cpp \
    					  merge_sort.cpp quick_sort.cpp radix_sort.cpp \
    					  shell_sort.cpp



test: testSortingAlgs.o sortAlgs.o 
	${CXX} ${CXXFLAGS} -o tester testSortingAlgs.cpp insertion_sort.cpp \
						  heap_sort.cpp merge_sort.cpp quick_sort.cpp \
						  radix_sort.cpp shell_sort.cpp
sorter.o: sorter.cpp sortAlgs.h
sortAlgs.o: insertion_sort.cpp heap_sort.cpp merge_sort.cpp quick_sort.cpp \
	        radix_sort.cpp shell_sort.cpp
testSortingAlgs.o: testSortingAlgs.cpp sortAlgs.h

