/***********************************************************************
 *  https://leetcode.com/problems/longest-substring-without-repeating-characters
 * 
 *  Difficulty: Medium
 * 
 *  Related Topics: Hash Table, Two Pointers, String, Sliding Window
 * 
 *  Time complexity :  O(2n)=O(n). In the worst case each character will be visited twice by i and j.
 *
 *  Runtime: 8 ms, faster than 84.75%
 * 
 *  Memory Usage: 8.3 MB, less than 67.18%
 * 
 *  Note: None
 * 
 ***********************************************************************/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> umap;
        unordered_map<char, int>::iterator iter;
        int len = s.length(), start = 0, ans = 0;
        for (int i=0; i<len; i++) {
            iter = umap.find(s[i]);
            if (iter != umap.end() && iter->second >= start){
                ans = max(ans, i-start);
                start = iter->second + 1;
            }
            umap[s[i]] = i;
        }
        return max(ans, len-start);
    }
};