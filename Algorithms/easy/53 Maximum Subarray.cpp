// Soure: https://leetcode.com/problems/maximum-subarray/
// Author: Wangggod
// Date: 2020.3.1
//************************************************************
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
**************************************************************

//Note:核心思路为动态规划，以给定数据为例，[-2,1,-3,4,-1,2,1,-5,4]
* 首先将currMaxSum设置为第一个数 -2，maxSum（全局最大）也设置为第一个数 -2.
* 随后从第二个数nums[1]开始，将当前最大的和currMaxSum相加后（-1）与当前数相比（1）
* 此时说明应该更新目前最大的序列为到第二个（1），随后与全局最大（-2）比较，更新全局最大为（1），即抛弃nums[0]，子序列从nums[1]开始
* 重复上述过程，此时-3+1=-2>-3,说明此时最大值还是截止到1（序列为[1]），与全局最大1比较，不变
* 重复上述，此时
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currMaxSum = nums[0];
        int maxSum = nums[0];
        for (int i = 1; i < nums.size(); i++){
            currMaxSum = max(currMaxSum + nums[i], nums[i]);
            maxSum = max(maxSum,currMaxSum);
        }
        return maxSum;
    }
};
