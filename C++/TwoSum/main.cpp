#include"Solution.h"
#include<iostream>

int main(){
	
	vector<int> arr{2, 4, 6};
	Solution soln;
	vector<int> result = soln.twoSum(arr, 6);
	
	for(int i: result){
		std::cout << i << std::endl;
	}
	
	return 0;
}