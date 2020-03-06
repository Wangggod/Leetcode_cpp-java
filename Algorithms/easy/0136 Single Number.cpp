// Source: https://leetcode.com/problems/single-number/submissions/
// Author: Wangggod
// Data: 2020.3.6

//Note:
#A better explanation why this technique works-

#Let's say we have an array - [2,1,4,5,2,4,1].
#What we are doing is essentially this-

#=> 0 ^ 2 ^ 1 ^ 4 ^ 5 ^ 2 ^ 4 ^ 1

#=> 0^ 2^2 ^ 1^1 ^ 4^4 ^5 (Rearranging, taking same numbers together)

#=> 0 ^ 0 ^ 0 ^ 0 ^ 5

#=> 0 ^ 5

#=> 5 :)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(nums.cbegin(), nums.cend(), 0, bit_xor<int>());
    }
};
