/***********************************************************************
 *  https://leetcode.com/problems/valid-sudoku/
 *
 *  Difficulty: Medium
 *
 *  Related Topics: Hash Table
 *
 *  Time complexity : O(N^2)
 *
 *  Runtime: 16 ms, faster than 91.73% of C++
 *
 *  Memory Usage: 18.1 MB, less than 70.50% of C++
 *
 *  Note: N/A
 *
 ***********************************************************************/ 
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool r_used[9][9] = {0};
        bool c_used[9][9] = {0};
        bool mt_used[9][9] = {0};
        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                if (board[i][j] != '.'){
                    int num = board[i][j] - '0' - 1;
                    int k = i / 3 * 3 + j / 3;
                    if (r_used[i][num] || c_used[j][num] || mt_used[k][num]){
                        return false;
                    }
                    else {
                        r_used[i][num] = c_used[j][num] = mt_used[k][num] = true;
                    }
                }
            }
        }
        return true;
    }
};