/***********************************************************************
 *  https://leetcode.com/problems/median-of-two-sorted-arrays/
 * 
 *  Difficulty: Hard
 * 
 *  Related Topics: Binary Search, Divide and Conquer
 * 
 *  Time complexity :  O(log (m+n))
 *
 *  Runtime: 28 ms, faster than 76.21%
 * 
 *  Memory Usage: 89.7 MB, less than 31.82%
 * 
 *  Note: None
 * 
 ***********************************************************************/

class Solution {
public:
    /* My Solution */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int i, j = 0;
        vector<int> merged;
        for(i=0, j=0; i+j < (m+n)/2 + 1; ) {
            if (i >= m) {
                merged.push_back(nums2[j]);
                j++;
            }
            else if (j >= n) {
                merged.push_back(nums1[i]);
                i++;
            }
            else if (nums1[i] < nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            }
            else {
                merged.push_back(nums2[j]);
                j++;
            }
        }
        if ( (m+n) % 2 == 0) {
            return (double)(merged[i+j-1] + merged[i+j-2]) / 2;
        }
        else {
            return merged[i+j-1];
        }
    }

    
};