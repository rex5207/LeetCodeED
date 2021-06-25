/***********************************************************************
 *  https://leetcode.com/problems/reverse-integer/
 * 
 *  Difficulty: Easy
 * 
 *  Related Topics: Math
 * 
 *  Time complexity :  O(log(x))
 *
 *  Runtime: 4 ms, faster than 43.02% of C++
 * 
 *  Memory Usage: 5.8 MB, less than 95.14% of C++ 
 * 
 *  Note: N/A
 * 
 ***********************************************************************/

class Solution {
public:
    /* My Solution */
    int reverse(int x) {
        int ans = 0;
        while(x != 0) {
            // Overflow checking
            if (ans > INT_MAX/10 || ans < INT_MIN/10){
                return 0;
            }
            ans = ans * 10 + x % 10;
            x = x / 10;
        }
        return ans;
    }
};