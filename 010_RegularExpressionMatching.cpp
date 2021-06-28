/***********************************************************************
 *  https://leetcode.com/problems/regular-expression-matching/
 * 
 *  Difficulty: Hard
 * 
 *  Related Topics: Dynamic Programming, Recursion
 * 
 *  Time complexity :  O(TP)
 *
 *  Runtime: 4 ms, faster than 84.86% of C++
 * 
 *  Memory Usage: 0.5 MB, less than 22.72% of C++
 * 
 *  Note: ["aa" / "a"], ["aaa" / "a*a"], ["a" / "ab*"]
 * 
 ***********************************************************************/

/* My solution */
class Solution {
public:
    int DP[35][35] = {{0}};
    bool isMatch(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();
        if (DP[s_len][p_len] != 0) {
            return DP[s_len][p_len] == 1;
        }
        bool flag = false;
        bool first_match = (s_len != 0) && (s[0] == p[0] || p[0] == '.');
        if (p_len == 0) {
            return s_len == 0;
        }
        if (p_len >= 2 && p[1] == '*') {
            if (first_match) {
                flag = flag || isMatch(s.substr(1), p);
            }
            flag = flag || isMatch(s, p.substr(2));
        }
        else if (first_match){
            flag = flag || isMatch(s.substr(1), p.substr(1));
        }
        DP[s_len][p_len] = flag == 1 ? 1 : -1;
        return flag;
    }
};
