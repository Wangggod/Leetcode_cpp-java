// Source: https://leetcode.com/problems/contains-duplicate-ii/
// Author: Wangggod
// Date: 2020.3.11
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        auto m = unordered_map<int, int>();
        for (int i = 0;i<nums.size(); ++i) {
            auto iter = m.find(nums[i]);
            if (iter != m.end()) {
                if (i - m[nums[i]] <= k) {
                    return true;
                }
            }
            m[nums[i]] = i;
        }
        return false;
    }
};
