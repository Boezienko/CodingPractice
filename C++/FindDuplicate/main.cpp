#include <iostream>
#include <vector>
#include "FindDuplicate.cpp"

int main(){
	
	FindDuplicate sol;
	
	std::vector<int> test = {65, 788, 43243, 23443, 4535, 6543, 78, 12, 1, 90, 65};
	
	std::cout << "The duplicate value is: " << sol.findDuplicate(test) << std::endl;
	
		
	return 0;
}