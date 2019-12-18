//proj5.cpp

#include <iostream>
#include <sstream>
#include <string>
#include "proj5.hpp"

bool isMinHeap(std::string s)
{
	std::vector<char> char_vec;
	char_vec.push_back('\0'); //"Waste" the 0 index in the vector.
	for(int i = 0; i < s.size(); i++) //Pushes back every character in the string into a vector.
	{
		char_vec.push_back(s[i]);
	}
	//"Node" because I am visualizing the vector as a tree.
	for(size_t i = 1; i < char_vec.size() - 1; i++)
	{
		if(2*i > char_vec.size() - 1) //If the current node does not have a left child
			return true;
		else if(2*i + 1 > char_vec.size() - 1) //If the current node does not have a right child.
			return true;
		if(char_vec[i] > char_vec[2*i]) //If the node's left child is greater than the node.
			return false;
		else if(char_vec[i] > char_vec[2*i+1]) //If the  node's right child is greater than the node.
			return false;
	}

	return true; 
}


void doSomeSort(std::vector<std::string> & vec)
{
	//BubbleSort
    for(int i = 0; i < vec.size()-1; i++) //Loop until size - 1
    {
        for(int j = 0; j < vec.size()-i-1; j++)
        {
            if(vec[j]>vec[j+1]) //If the current value is greater than the next value.
            {
            	//Swap current value with next value.
                std::string temp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = temp;
            }
        }
    }
}


std::vector<std::string> findHeaps(std::istream & in)
{
	std::vector<std::string> min_heap_vec;
	std::string line, word;
	std::stringstream ss;

	while(getline(in, line))
	{
		ss.clear();
		ss << line;
		while(ss >> word)
		{
			if(isMinHeap(word))
				min_heap_vec.push_back(word);
		}
	}

	doSomeSort(min_heap_vec);
	return min_heap_vec;
}
