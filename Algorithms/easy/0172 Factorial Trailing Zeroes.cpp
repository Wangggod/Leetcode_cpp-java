// Source: https://leetcode.com/problems/factorial-trailing-zeroes/
// Author: Wangggod
// Date: 2020.3.8

class Solution {
public:
    int trailingZeroes(int n) {
    int result = 0;
    for(long long i=5; n/i>0; i*=5){
        result += (n/i);
    }
    return result;
    }
};
