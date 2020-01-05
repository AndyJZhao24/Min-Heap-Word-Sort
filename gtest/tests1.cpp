#include "gtest/gtest.h"
#include "minheap.hpp"
#include <string>
#include <fstream>
namespace{


TEST(HeapTests, Bedpost)
{
	EXPECT_TRUE(isMinHeap("bedpost"));
}

TEST(HeapTests, Pinhead)
{
	EXPECT_TRUE(! isMinHeap("pinhead")); 
}



// test the sorting function.

TEST(Sorting, Sort1)
{
	std::vector<std::string> vec = {"bedpost", "adjusts", "adjourns", "despot"};
	bubbleSort(vec);

	std::vector<std::string> expected = {"adjourns", "adjusts", "bedpost", "despot"};

	EXPECT_TRUE( vec == expected );
}


// test the collection of heaps 

TEST(Collection, SetOfHeaps)
{
	std::string someWords = "bedpost despot pinhead\nadjourns adjusts\n";

	std::istringstream stream( someWords );

	std::vector<std::string> vec = findMinHeaps(stream);
	
	std::vector<std::string> expected = {"adjourns", "adjusts", "bedpost", "despot"};

	EXPECT_TRUE( vec == expected );
}





}