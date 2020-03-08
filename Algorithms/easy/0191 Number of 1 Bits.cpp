    
// Source: https://leetcode.com/problems/factorial-trailing-zeroes/
// Author: Wangggod
// Date: 2020.3.8


class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> bs{n};
        int l{0};
        int count = 0;
        while(l < 32) {
            if (bs[l] == 1) count++;
            l++;
        }
        return count;
    }
};
