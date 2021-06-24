/***********************************************************************
 *  https://leetcode.com/problems/longest-palindromic-substring/
 * 
 *  Difficulty: Medium
 * 
 *  Related Topics: Dynamic Programming
 * 
 *  Time complexity :  O(n^2)
 *
 *  Runtime: 8 ms, faster than 96.48% of C++
 * 
 *  Memory Usage: 7.1 MB, less than 89.46% of C++
 * 
 *  Note:檢查size可以大大加速
 *  if (s.size() - i <= max_len / 2) break;
 * 
 ***********************************************************************/

class Solution {
public:
    /** My Solution **/
    string longestPalindrome(string s) {
        int len = s.size();
        int max_len = 0;
        int left = 0;
        for(int i=0; i<len; i++){
            // Speed up
            if (s.size() - i <= max_len / 2) break;

            // 奇數個 以此為中心，如果左右均相同就繼續延伸
            int head = i;
            int tail = i;
            while(head-1 >= 0 && tail+1 < len && s[head-1] == s[tail+1]){
                head --;
                tail ++;
            }
            if(tail - head + 1 > max_len){
                left = head;
                max_len = tail - head + 1;
            }
            
            //偶數個
            head = tail = i;
            if(head+1 < len && s[head] == s[head+1]){
                tail = head + 1;
                while(head-1 >= 0 && tail+1 < len && s[head-1] == s[tail+1]){
                    head --;
                    tail ++;
                }
            }
            if(tail - head + 1 > max_len){
                left = head;
                max_len = tail - head + 1;
            }
        }
        return s.substr(left, max_len);
    }

    /* Dynamic Programming Solution */
    string longestPalindrome(string s) {
        int len = s.length();
        int left = 0, max_len = 1;
        // Corner cases.
        if (len <= 1)
            return s;
        
        // state[i][j] true if s[i, j] is palindrome.
        bool state[1001][1001] = {{false}};
        
        // Base cases.
        for (int i = 0; i < len; i++) { 
            state[i][i] = true; // dist = 0.
        }
        
        for (int i = len - 1; i >= 0; i--) {
            for (int dist = 1; dist < len - i; dist++) {
                int j = dist + i;
                state[i][j] = (dist == 1) ? s[i] == s[j] : (s[i] == s[j]) && state[i + 1][j - 1];
                if (state[i][j] && (j - i + 1 > max_len)) {
                    max_len = j - i + 1;
                    left = i;
                }
            }
        }     
        
        return s.substr(left, max_len);
    }
};