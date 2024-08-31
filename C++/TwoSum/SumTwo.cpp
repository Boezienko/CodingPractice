#include "Solution.h"

vector<int> Solution::twoSum(vector<int>& nums, int target) {
	for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[i]+nums[j] == target){
                    vector<int> toReturn{i,j};
                    return toReturn;
                }
            }
        }
        return vector<int>();
}
