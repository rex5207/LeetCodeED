/***********************************************************************
 *  https://leetcode.com/problems/count-and-say/
 *
 *  Difficulty: Medium
 *
 *  Related Topics: String
 *
 *  Time complexity : O(N)
 *
 *  Runtime: 16 ms, faster than 28.97% of C++
 *
 *  Memory Usage: 6.5 MB, less than 86.72% of C++
 *
 *  Note: N/A
 *
 ***********************************************************************/ 
class Solution {
public:
    string countAndSay(int n) {
        string input = "1";
        for (int i=2; i<=n; i++) {
            int len = input.length();
            string tmp = "";
            int index = 0;
            for (int j=0; j<len; j++) {
                if((j+1 < len && input[j] != input[j+1]) || (j == len-1)) {
                    tmp += to_string(j - index + 1);
                    tmp += input[j];
                    index = j + 1;
                } 
            }
            input.swap(tmp);
        }
        return input;
    }
};