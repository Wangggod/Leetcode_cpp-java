// Source: https://leetcode.com/problems/move-zeroes/
// Author: Wangggod
// Date: 2020.3.13

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>::size_type nonZero = 0;
        vector<int>::size_type next = 0;
        while (next < nums.size()) {
            if (nums[next] != 0) {
                auto tmp = nums[next];
                nums[next] = nums[nonZero];
                nums[nonZero] = tmp;
                ++nonZero;
            }
            ++next;
        }
    }
};
