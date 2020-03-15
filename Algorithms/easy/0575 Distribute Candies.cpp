// Source: https://leetcode.com/problems/distribute-candies/
// Author: Wangggod
// Date: 2020.3.15
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        return min(unordered_set<int>(begin(candies), end(candies)).size(), candies.size() / 2);

    }
};
