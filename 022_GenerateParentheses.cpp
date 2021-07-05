/***********************************************************************
 *  https://leetcode.com/problems/generate-parentheses/
 *
 *  Difficulty: Medium
 *
 *  Related Topics: DP, Backtracking
 *
 *  Time complexity : O(4^n / n^(1/2))
 *
 *  Runtime: 8 ms, faster than 32.93% of C++
 *
 *  Memory Usage: 13 MB, less than 72.37% of C++
 *
 *  Note: N/A
 *
 ***********************************************************************/
/* Closure Number */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if (n == 0) {
            ans.push_back("");
        } else {
            for (int i=0; i<n; i++) {
                for (auto left: generateParenthesis(i)) {
                    for (auto right: generateParenthesis(n-1-i)){
                        ans.push_back("(" + left + ")" + right);
                    }
                }
            }
        }
        return ans;
    }
};

/* Back Tracking */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        DFS(ans, "", 0, 0, n);
        return ans;
    }
    
    void DFS(vector<string> &ans, string cur, int open, int close, int max){
        if(cur.size() == max*2){
            ans.push_back(cur);
            return;
        }
        
        if(open < max){
            DFS(ans, cur+'(', open+1, close, max);
        }
        if(close < open){
            DFS(ans, cur+')', open, close+1, max);
        }
    }
};