// Soure: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Author: Wangggod
// Date: 2020.3.1
// Note: 核心思想为设定一个指针定位，随后往后遍历，遇到相同则替换
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        
        int targetIndex = 1;
        int OG = nums[0];
        
        for (int i = 1; i < len; i++) {
            if (nums[i] != OG){
                OG = nums[i];
                nums[targetIndex] = nums[i];
                targetIndex++;
            }
        }
        return targetIndex;
    }
    
};
