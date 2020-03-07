// Source: https://leetcode.com/problems/majority-element/
// Author: Wangggod
// Date: 2020.3.7

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
	    int len = nums.size();
	    return nums[len/2];
    }
};
