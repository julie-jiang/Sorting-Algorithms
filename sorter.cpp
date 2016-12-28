/*
 * sorter.cpp 
 * main() executable and other end user interface functions of the c++ 
 * implementations of sorting algorithms including insertion, merge, quick, 
 * shell, and radix.
 * By Julie Jiang
 * 2016 Nov
 */

#include <iostream> 
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <vector>
#include <tuple>
#include "sortAlgs.h"

/* Define function pointers */
typedef int  (*inputFuncPtr)   (std::vector<int> &, std::string);
typedef void (*sortingFuncPtr) (std::vector<int> &);
typedef void (*outputFuncPtr)  (std::vector<int> &, std::string, std::string, 
                                int);

/* Function declarations*/
std::tuple<inputFuncPtr, sortingFuncPtr, outputFuncPtr, std::string, 
std::string>   parse(int, char * []);
outputFuncPtr  getOutputFunc(std::string arg2);
sortingFuncPtr getSortingFunc(std::string arg1); 
int            cinInput(std::vector<int> &, std::string);
int            readInput(std::vector<int> &, std::string);
void           printList(std::vector<int> &, std::string, std::string, int);
void           saveList(std::vector<int> &, std::string, std::string, int);
void           error();
std::string    int2string(int);
int            string2int(std::string);


/* 
 * Main function
 * Parameters: sortAlg, outputMode, and an optional filename
 * where sortAlg is -s1, -s2, or -s3 and outputMode is --print or --save.
 * Returns: none
 */
int main(int argc, char *argv [])
{
    try {
        // Parse command line input
        inputFuncPtr   inputFunc; 
        sortingFuncPtr sortingFunc; 
        outputFuncPtr  outputFunc;
        std::string    listOrigin; 
        std::string    sortAlg; 
        tie(inputFunc, sortingFunc, outputFunc, listOrigin, sortAlg) 
        = parse(argc, argv);

        // Initialize list
        std::vector<int> list;
        
        // Process input 
        int numElements = inputFunc(list, listOrigin); 
        
        // Sort input
        sortingFunc(list); 

        // Output sorted input                          
        outputFunc(list, listOrigin, sortAlg, numElements);

    } catch (...) {
        // Print error message and exit if any exceptions are caught
        error(); 
    }
}
/*
 * Parses command line input and return approriate input function, sorting 
 * function, output function, as well as strings that represent list origin
 * and sorting algorithm.
 * 
 * Parameters: command line inputs (sortAlg, outputMode, and an optional 
 * filename)
 * Returns: a tuple of a input function pointer, sorting function pointer, 
 * output function pointer, a string that represents the origin of input, 
 * and a string that represents the sorting function used.
 */
std::tuple<inputFuncPtr, sortingFuncPtr, outputFuncPtr, std::string, 
           std::string> 
parse(int argc, char *argv [])
{
    inputFuncPtr   inputFunc   = cinInput;
    std::string    listOrigin  = "cin";
    if (argc == 4) {
        listOrigin = argv[3];
        inputFunc  = readInput;
    }
    sortingFuncPtr sortingFunc = getSortingFunc(argv[1]);
    outputFuncPtr  outputFunc  = getOutputFunc(argv[2]);
    std::string    sortAlg     = std::string(argv[1]).substr(1);

    
    return make_tuple(inputFunc, sortingFunc, outputFunc, listOrigin, sortAlg);
}

/* 
 * Returns a pointer to a sorting function depending on the input string. 
 * Throws exception if there is no such sorting function. 
 * 
 * Parameters: a command line argument that specifies the sorting function 
 * to be used
 * Returns: a sorting function pointer
 */
sortingFuncPtr getSortingFunc(std::string arg1) 
{
    if (arg1 == "-s1") {
        return insertionSort;
    } else if (arg1 == "-s2") {
        return quickSort;
    } else if (arg1 == "-s3") {
        return mergeSort;
    } else if (arg1 == "-s4") {
        return heapSort;
    } else if (arg1 == "-s5") {
        return shellSort;
    } else if (arg1 == "-s6") {
        return radixSort;
    } else {
        throw std::logic_error("Invalid sorting function reference");
    }
}
/*
 * Returns a pointer to an ouput function depending on the input string. 
 * Throws exception if there is no such output function.
 *
 * Parameters: a command line argument that specifies the output function
 * to be used
 * Returns: an output function pointer
 */
outputFuncPtr getOutputFunc(std::string arg2)
{
    if (arg2 == "--print") {
        return printList;
    } else if (arg2 == "--save") {
        return saveList; 
    } else {
        throw std::logic_error("Invalid output function reference");
    }
}


/* 
 * Gets cin input and pushes to list.
 *
 * Parameters: an empty int vector and a string filename that doesn't need to 
 * be used here (but is used in the other input function readInput).
 * Returns: the number of elements in the vector
 */
int cinInput(std::vector<int> &list, std::string filename_str)
{
    // Void unnecessary parameter to silence warning
    (void) filename_str;
    std::string input;
    int numElements = 0;
    while (std::cin >> input) {
            list.push_back(string2int(input));
            numElements++;
        }
    return numElements;
}

/* 
 * Reads input from file and pushes to list.
 * Parameters: an empty int vector and a string filename from which to read 
 * input from.
 * Returns: the number of elements in the vector
 */
int readInput(std::vector<int> &list, std::string filename_str)
{
    // Convert the string filename to an array of char
    char filename [filename_str.size() + 1];
    strcpy(filename, filename_str.c_str());
    
    // Open file 
    std::ifstream inFile;
    inFile.open(filename);
    if (inFile.fail()) {
        throw std::logic_error("File does not exist");
    }

    // Read input
    std::string input;
    int numElements = 0;
    while (inFile >> input){
        list.push_back(string2int(input));
        numElements++;
    }
    return numElements;
}


/* 
 * Prints sorted list.
 * 
 * Parameters: an int vector containing sorted elements, and three other
 * arguments that don't need to be used here (but is used in the other output
 * function saveList).
 * Returns: none.
 */
void printList(std::vector<int> &list, std::string listOrigin, 
              std::string sortAlg, int numElements)
{
    // Void unnecessary parameters to silence warning
    (void) listOrigin; (void) sortAlg; (void) numElements;
    for (unsigned int i = 0; i < list.size(); i++) {
        std::cout << list[i] << std::endl;
    }
}

/*
 * Writes sorted list to file.
 * 
 * Parameters: an int vector containing sorted elements, a string that 
 * represents the origin of the list, a string that represents the sorting 
 * algorithm used, and the number of elements in the list.
 * Returns: none.
 */
void saveList(std::vector<int> &list, std::string listOrigin, 
              std::string sortAlg, int numElements) 
{
    // Create output file
    std::ofstream outFile;
    std::string filename_str = listOrigin + "_" + sortAlg + "_" 
                           + int2string(numElements) + "_sorted.txt";
   // Convert the string filename to an array of char
    char filename [filename_str.size() + 1];
    strcpy(filename, filename_str.c_str());
    
    outFile.open(filename);
    if (outFile.fail()) {
        throw std::logic_error("File cannot be opened");
    }

    // Write to file
    for (unsigned int i = 0; i < list.size(); i++) {
        outFile << list[i] << std::endl;
    }
    outFile.close();
}

/* 
 * Prints error message and exit.
 * Parameters: none
 * Returns: none
 */
void error()
{
    std::cerr << "Usage:  sorter sortAlg outputMode [fileName]\n";
    std::cerr << "    where  sortAlg is -s1, -s2, -s3, -s4, -s5, or -s6\n";
    std::cerr << "    and    outputMode is --print or --save\n";
    std::cerr << "    s1 - insertion sort\n";
    std::cerr << "    s2 - quick sort\n";
    std::cerr << "    s3 - merge sort\n";
    std::cerr << "    s4 - heap sort\n";
    std::cerr << "    s5 - shell sort\n";
    std::cerr << "    s6 - radix sort\n";
    exit(1);
}

/* 
 * Converts an int to string.
 * Parameters: an int that needs to be converted a string.
 * Returns: the string form of the int
 */
std::string int2string(int num)
{
    std::string result;
    std::ostringstream oss;
    oss << num;
    result = oss.str();
    return result;
}

/* 
 * Converts a string to int 
 * Parameters: a string that needs to be converted to an int
 * Returns: the int that the string is converted to. Throws exception if the 
 * string is not a number.
 */
int string2int(std::string s)
{
    std::stringstream ss(s);
    int result;

    ss >> result;
    if (ss.fail())
        throw std::runtime_error("string2int: non-numeric value: " + s);

    return result;
}

