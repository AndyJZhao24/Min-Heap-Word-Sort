#ifndef __MIN_HEAP_HEADER___
#define __MIN_HEAP_HEADER___


#include <iostream>
#include <string>
#include <vector>

// Returns true if and only if the given parameter,
// interpreted as a character array, is a min-heap.
// Use ASCII value ordering.  The natural < will serve this purpose.
bool isMinHeap(std::string s);


void bubbleSort(std::vector<std::string> & vec);


// Return a SORTED vector of which elements of the
// given input stream are min heaps. 
std::vector<std::string> findMinHeaps(std::istream & in);




#endif 
