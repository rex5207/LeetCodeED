/***********************************************************************
 *  https://leetcode.com/problems/valid-parentheses/
 *
 *  Difficulty: Eady
 *
 *  Related Topics: Stack
 *
 *  Time complexity : O(n)
 *
 *  Runtime: 0 ms, faster than 100.00% of C++
 *
 *  Memory Usage: 6.3 MB, less than 72.86% of C++
 *
 *  Note: N/A
 *
 ***********************************************************************/
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mapping = {{ ')', '(' },
                                             { '}', '{' },
                                             { ']', '[' }};
        stack<char> stk;
        for (auto ch: s) {
            if (mapping.find(ch) != mapping.end()) {
                if (stk.empty() || stk.top() != mapping[ch]) {
                    return false;
                }
                stk.pop();
            }
            else {
                stk.push(ch);
            }
        }
        return stk.empty();
    }
};