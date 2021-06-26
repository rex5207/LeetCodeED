/***********************************************************************
 *  https://leetcode.com/problems/string-to-integer-atoi/
 * 
 *  Difficulty: Medium
 * 
 *  Related Topics: String
 * 
 *  Time complexity :  O(n)
 *
 *  Runtime: 0 ms, faster than 100.00% of C++
 * 
 *  Memory Usage: 7.1 MB, less than 35.61% of C++
 * 
 *  Note: N/A
 * 
 ***********************************************************************/

class Solution {
public:
    int myAtoi(string s) {
        int len = s.length();
        int i = 0;
        int sign = 1;
        long ans = 0;
        // Remove leading spaces
        while(s[i] == ' ') {
            i++;
        }
        // Check the sign
        if(s[i] == '-' || s[i] == '+') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        for (; s[i] >= '0' && s[i] <= '9'; i++) {
            ans = ans*10 + s[i] - '0';
            if(sign == 1 && ans > INT_MAX) {
                return INT_MAX;
            }
            else if(sign == -1 && ans - 1 > INT_MAX) {
                return INT_MIN;
            }
        }
        return sign * ans;
    }
};