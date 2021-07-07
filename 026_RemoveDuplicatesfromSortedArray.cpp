/***********************************************************************
 *  https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 *
 *  Difficulty: Easy
 *
 *  Related Topics: Two Pointers
 *
 *  Time complexity : O(N)
 *
 *  Runtime: 12 ms, faster than 55.30% of C++
 *
 *  Memory Usage: 18.5 MB, less than 6.93% of C++
 *
 *  Note: N/A
 *
 ***********************************************************************/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int i = 0;
        for (int j=1; j<len; j++) {
            if(nums[j] != nums[i]){
                i++;
                nums[i] = nums[j];
            }
        }
        return len == 0 ? 0 : i+1;
    }
};