/***********************************************************************
 *  https://leetcode.com/problems/first-missing-positive/
 *
 *  Difficulty: Hard
 *
 *  Related Topics: Hash Table
 *
 *  Time complexity : O(N)
 *
 *  Runtime: 148 ms, faster than 31.89% of C++
 *
 *  Memory Usage: 83 MB, less than 16.06% of C++
 *
 *  Note: Space need O(1) => reuse array
 *
 ***********************************************************************/ 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for(int i=0; i<len; i++){
            while(nums[i]>0 && nums[i]<len && nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for(int i=0; i<len; i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }
        return len + 1;
    }
};