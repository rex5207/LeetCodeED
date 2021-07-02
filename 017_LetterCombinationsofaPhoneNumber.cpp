/***********************************************************************
 *  https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 *
 *  Difficulty: Medium
 *
 *  Related Topics: Hash Table, Backtracking
 *
 *  Time complexity : O(n)
 *
 *  Runtime: 0 ms, faster than 100.00% of C++
 *
 *  Memory Usage: 6.7 MB, less than 21.77%
 *
 *  Note: N/A
 *
 ***********************************************************************/

/* My Solution with BFS*/
class Solution {
public:
    vector<string> mapping = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void BFS(string digits, string output, vector<string>& ans) {
        if (digits.length() == 0) {
            ans.push_back(output);
        }
        else {
            string letters = mapping[digits[0]-'0'];
            for (int i=0; i < letters.length(); i++) {
                BFS(digits.substr(1), output + letters[i], ans);
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() != 0)
            BFS(digits, "", ans);
        return ans;
    }
};

/* Iterative Solution */
class Solution {
public:
    vector<string> mapping = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return {};
        vector<string> ans = {""};
        for (auto digit:digits) {
            vector<string> tmp;
            for (auto candidate: mapping[digit-'0']) {
                for (auto s: ans) {
                    tmp.push_back(s + candidate);
                }
            }
            ans.swap(tmp);
        }
        return ans;
    }
};