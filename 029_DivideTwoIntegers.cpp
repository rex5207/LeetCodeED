/***********************************************************************
 *  https://leetcode.com/problems/divide-two-integers/
 *
 *  Difficulty: Medium
 *
 *  Related Topics: Big Manipulation
 *
 *  Time complexity : O(N)
 *
 *  Runtime: 8 ms, faster than 9.61% of C++
 *
 *  Memory Usage: 5.9 MB, less than 72.43% of C++
 *
 *  Note: N/A
 *
 ***********************************************************************/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long dvd = labs(dividend);
        long dvs = labs(divisor);
        long ans = 0;
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        while(dvd >= dvs) {
            long temp = dvs;
            long m = 1;
            while(dvd >= (temp << 1)) {
                temp = temp << 1;
                m = m << 1;
            }
            dvd -= temp;
            ans += m;
        }
        return sign * ans;
    }
};
