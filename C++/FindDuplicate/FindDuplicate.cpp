#include <iostream>
#include <vector>

class FindDuplicate{
	public:
		int findDuplicate(std::vector<int>& nums) {

			// finds the duplicate value in a vector by keeping track of the frequencies that we visit each value
			// we use the fact that accessing an element is o(1) process, so we use the values in nums as the index
			// so if the index gets higher than 0, we've visited it before

			// make frequency vector of size of nums with 0's
			std::vector<int> freq(nums.size(), 0);

			// go through nums, keep track of frequencies of values
			for(int i = 0; (unsigned long int)i < nums.size(); i++){
				
				// make sure the freq vector is big enough
				// if it is not, make it big enough for nums value
				if((unsigned long int)nums[i] >= freq.size()){
					freq.resize(nums[i] + 1, 0);
				}
				
				// check for duplicate
				if(freq[nums[i]] != 0){
					return nums[i];
				}
				
				// increment freq value so we know we've visited the value represented by that index
				freq[nums[i]]++;
			}
			
			return -1;
		}
};