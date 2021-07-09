/***********************************************************************
 *  https://leetcode.com/problems/search-in-rotated-sorted-array/
 *
 *  Difficulty: Medium
 *
 *  Related Topics: Binary Search
 *
 *  Time complexity : O(log N)
 *
 *  Runtime: 8 ms, faster than 20.04% of C++
 *
 *  Memory Usage: 11 MB, less than 73.02% of C++
 *
 *  Note: N/A
 *
 ***********************************************************************/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int l = 0, r = len-1;
        while (l <= r) {
            int mid = (l+r) / 2;
            if (nums[mid] == target)
                return mid;

            if (nums[l] <= nums[mid]) { // The order of left is correct
                if (nums[l] <= target && target < nums[mid]){
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            else { // The order of right is correct
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};