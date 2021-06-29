/***********************************************************************
 *  https://leetcode.com/problems/roman-to-integer/
 *
 *  Difficulty: Easy
 *
 *  Related Topics: Hash
 *
 *  Time complexity : O(n)
 *
 *  Runtime: 4 ms, faster than 92.27% of C++
 *
 *  Memory Usage: 6 MB, less than 63.13% of C++
 *
 *  Note: "Check Clean Solution, Don't use if/else"
 *
 ***********************************************************************/

class Solution {
   public:
    /* My first solution */
    int romanToInt(string s) {
        int ans = 0;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (s[i] == 'M') {
                ans += 1000;
            } else if (s[i] == 'D') {
                ans += 500;
            } else if (s[i] == 'L') {
                ans += 50;
            } else if (s[i] == 'V') {
                ans += 5;
            } else if (s[i] == 'C') {
                if (i + 1 < len && s[i + 1] == 'M') {  // CM
                    ans += 900;
                    i++;
                } else if (i + 1 < len && s[i + 1] == 'D') {  // CD
                    ans += 400;
                    i++;
                } else {
                    ans += 100;
                }
            } else if (s[i] == 'X') {
                if (i + 1 < len && s[i + 1] == 'C') {  // XC
                    ans += 90;
                    i++;
                } else if (i + 1 < len && s[i + 1] == 'L') {  // XL
                    ans += 40;
                    i++;
                } else {
                    ans += 10;
                }
            } else if (s[i] == 'I') {
                if (i + 1 < len && s[i + 1] == 'X') {  // IX
                    ans += 9;
                    i++;
                } else if (i + 1 < len && s[i + 1] == 'V') {  // IV
                    ans += 4;
                    i++;
                } else {
                    ans += 1;
                }
            }
        }
        return ans;
    }

    /* Clean Solution */
    int romanToInt(string s) {
        unordered_map<char, int> T = {{'I', 1},   {'V', 5},   {'X', 10},
                                      {'L', 50},  {'C', 100}, {'D', 500},
                                      {'M', 1000}};
        int len = s.size();
        int ans = T[s[len - 1]];
        for (int i = len - 2; i >= 0; i--) {
            if (T[s[i]] < T[s[i + 1]]) {
                ans -= T[s[i]];
            } else {
                ans += T[s[i]];
            }
        }
        return ans;
    }
};