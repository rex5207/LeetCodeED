/***********************************************************************
 *  https://leetcode.com/problems/longest-common-prefix/
 *
 *  Difficulty: Easy
 *
 *  Related Topics: String
 *
 *  Time complexity : O(n^2)
 *
 *  Runtime: 0 ms, faster than 100.00% of C++ 
 *
 *  Memory Usage: 9.2 MB, less than 44.73% of C++
 *
 *  Note: Check the "Divide and Conquer" and "Binary Search" solutions
 *
 ***********************************************************************/
/* My Solution */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int num = strs.size();
        string ans = "";
        for (int i=0; i<strs[0].size(); i++) {
            for (int j=1; j<num; j++) {
                if (strs[j][i] != strs[0][i]) {
                    return ans;
                }
            }
            ans.push_back(strs[0][i]);
        }
        return ans;
    }
};

/* Divide and Conquer */
class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if (strs.size() == 0) return ""; 
            return longestCommonPrefix(strs, 0, strs.size()-1);
        }
        
        string longestCommonPrefix(vector<string>& strs, int l, int r) {
            if (l == r)
                return strs[l];
            else {
                int mid = (l + r) / 2;
                string lcpLeft = longestCommonPrefix(strs, l, mid);
                string lcpRight = longestCommonPrefix(strs, mid+1, r);
                return commonPrefix(lcpLeft, lcpRight);
            }
        }
        
        string commonPrefix(string left, string right) {
            int len = min(left.length(), right.length());
            for(int i=0; i<len; i++) {
                if (left[i] != right[i])
                    return left.substr(0, i);
            }
            return left.substr(0, len);
        }
};

/* Binary Search */
class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if (strs.size() == 0) return "";
            int minLen = strs[0].length();
            for (int i=1; i<strs.size(); i++) {
                minLen = min(minLen, (int)strs[i].length());
            }
            int low = 1;
            int high = minLen;
            while (low <= high) {
                int middle = (low + high) / 2;
                if (isCommonPrefix(strs, middle))
                    low = middle + 1;
                else
                    high = middle - 1;
            } 
            return strs[0].substr(0, (low+high) / 2 );
        }
        
        bool isCommonPrefix(vector<string>& strs, int len) {
            string target = strs[0].substr(0, len);
            for (int i=1; i<strs.size(); i++) {
                if (strs[i].find(target) != 0)
                    return false;
            }
            return true;
        }
};