/***********************************************************************
 *  https://leetcode.com/problems/3sum/
 *
 *  Difficulty: Medium
 *
 *  Related Topics: String, Sorting, Two Pointers
 *
 *  Time complexity : O(n^2)
 *
 *  Runtime: 204 ms, faster than 25.57% of C++
 *
 *  Memory Usage: 21.8 MB, less than 38.71% of C++
 *
 *  Note: Need to use two pointer
 *
 ***********************************************************************/
class Solution {
public:
    /* My solution */
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int len = nums.size();
        unordered_map<int, int> umap;
        // Recording maximum index
        for (int i=0; i<len; i++) {
            if (umap.find(nums[i]) == umap.end()) {
                umap[nums[i]] = i;
            }
            else if (umap[nums[i]] < i){
                umap[nums[i]] = i;
            }
        }
        for (int i=0; i<len; i++) {
            // Same element
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            for (int j=i+1; j<len; j++) {
                // Same element
                if (j > i+1 && nums[j] == nums[j-1]) {
                    continue;
                }
                int target = 0 - (nums[i] + nums[j]) ;
                if (umap.find(target) != umap.end() && umap[target] > j) {
                    vector tmp = {nums[i], nums[j], target};
                    ans.push_back(tmp);
                } 
            }
        }
        return ans;
    }

    /* Two Pointer */
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int len = nums.size();
        // Recording maximum index
        for (int i=0; i<len; i++) {
            int front = i+1;
            int back = len-1;
            int target = -nums[i];
            while (front < back) {
                if (nums[front] + nums[back] > target) {
                    back --;
                }
                else if (nums[front] + nums[back] < target) {
                    front ++;
                }
                else {
                    // Found
                    vector<int> triplet = {nums[i], nums[front], nums[back]};
                    ans.push_back(triplet);
                    while (front < back && nums[front] == triplet[1])
                        front ++;
                    while (front < back && nums[back] == triplet[2])
                        back --;
                }
            }
            while (i+1 < len && nums[i] == nums[i+1])
                i++;
        }
        return ans;
    }
};