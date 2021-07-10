/***********************************************************************
 *  https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 *
 *  Difficulty: Medium
 *
 *  Related Topics: Binary Search
 *
 *  Time complexity : O(log N)
 *
 *  Runtime: 8 ms, faster than 68.49% of C++
 *
 *  Memory Usage: 13.7 MB, less than 61.92% of C++ 
 *
 *  Note: N/A
 *
 ***********************************************************************/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0)
            return vector{-1, -1};
        int l = 0;
        int r = len - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                break;
            }
            else if (nums[mid] > target) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        if (nums[(l+r)/2] == target) {
            int idx_left = (l+r)/2;
            int idx_right = (l+r)/2;
            while(idx_left-1 >= 0 && nums[idx_left-1] == target) idx_left --;
            while(idx_right+1 < len && nums[idx_right+1] == target) idx_right ++;
            return vector{idx_left, idx_right};
        }
        else {
            return vector{-1, -1};
        }
    }
};