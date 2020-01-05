#include "minheap.hpp"
#include <sstream>

int main()
{
	std::vector<std::string> word_vec;
	std::string line;
	std::string full_line;

	std::cout << "Enter your words in a line or input \"end\" on a newline to stop.\n";

	while(std::getline(std::cin, line))
	{
		if(line == "end")
			break;
		full_line += line + "\n";
		
	}

	std::istringstream stream(full_line);

	if(full_line != "")
	{
		word_vec = findMinHeaps(stream);
		std::cout << "\nThe following words are min heaps and they have been sorted alphabetically.\n";

		for(int i = 0 ; i < word_vec.size(); i++)
		{
			std::cout << word_vec[i] << std::endl;
		}
	}

    return 0;
}