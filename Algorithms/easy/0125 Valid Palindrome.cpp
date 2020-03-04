// Sourse: https://leetcode.com/problems/valid-palindrome/
// Author: Wangggod
// Date :2020.3.5

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())
            return true;
        const char *s1 = s.c_str();
        const char *e = s1 + s.length() - 1;
        while(e>s1) {
            if (!isalnum(*s1)) {++s1;continue;}
            if (!isalnum(*e)) {--e;continue;}
            if(tolower(*s1) != tolower(*e)) return false;
            else {--e;++s1;}
        }
        return true;
    }
};
