/***********************************************************************
 *  https://leetcode.com/problems/implement-strstr/
 *
 *  Difficulty: Easy
 *
 *  Related Topics: Two Pointers
 *
 *  Time complexity : O(N)
 *
 *  Runtime: 0 ms, faster than 100.00% of C++
 *
 *  Memory Usage: 6.8 MB, less than 43.79%
 *
 *  Note: N/A
 *
 ***********************************************************************/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len_hs = haystack.length();
        int len_nd = needle.length();
        for (int i=0; i<len_hs; i++) {
            for (int j=0; j<len_nd; j++) {
                if (i+j >= len_hs)
                    return -1;
                else if (haystack[i+j] != needle[j])
                    break;
                else if (j == len_nd - 1)
                    return i;
            }
        }
        return len_nd == 0 ? 0 : -1;
    }
};