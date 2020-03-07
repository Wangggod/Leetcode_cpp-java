// Source: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/submissions/
// Author: Wangggod
// Date: 2020.3.7

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;
        vector<int> v;
        while(l<r) {
            if(numbers[l] + numbers[r] == target) {
                v.push_back(l+1);
                v.push_back(r+1);
                break;
            }else if (numbers[l] + numbers[r] > target) {
                r--;
            }else {
                l++;
            }
        }
        return v;
    }
};
