/***********************************************************************
 *  https://leetcode.com/problems/two-sum/
 * 
 *  Difficulty: Easy
 * 
 *  Related Topics: Array, Hash Table, Sort
 * 
 *  Time complexity : O(n).
 *                    We traverse the list containing n elements only once.
 *                    Each look up in the table costs only O(1) time.
 *
 *  Runtime: 12 ms, faster than 58.03% of C++ online submissions for Two Sum.
 * 
 *  Memory Usage: 10.4 MB, less than 40.58% of C++ online submissions for Two Sum.
 * 
 *  Note: 看到exactly one solution => 要直接想到用Hash Table
 ***********************************************************************/

class Solution {
public:
    /* 1. Sort Solution */
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        vector<int> origin_nums;
        int v1, v2;
        origin_nums.assign(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        for (int i=0, j=nums.size()-1; i < j;) {
            if (nums[i] + nums[j] == target) {
                v1 = nums[i];
                v2 = nums[j];
                break;
            }
            else if (nums[i] + nums[j] > target) {
                j--;
            }
            else {
                i++;
            }
        }
        for (int i=0; i<origin_nums.size(); i++) {
            if (origin_nums[i] == v1 || origin_nums[i] == v2) {
                answer.push_back(i);
                if (answer.size() == 2) {
                    break;
                }
            }
        }
        return answer;
    }

    /* Hash Table Solution */
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> umap;
        unordered_map<int, int>::iterator iter;
        for (int i=0; i < nums.size(); i++) {
            iter = umap.find(target - nums[i]);
            if (iter != umap.end()) { // Find
                ans.push_back(i);
                ans.push_back(iter->second);
                break;
            }
            else {
                umap[nums[i]] = i;
            }
        }
        return ans;
    }

    /* Example Solution */
    vector<int> twoSum(vector<int> &nums, int target) {
        //Key is the number and value is its index in the vector.
        unordered_map<int, int> hash;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int numberToFind = target - nums[i];

            //if numberToFind is found in map, return them
            if (hash.find(numberToFind) != hash.end()) {
                result.push_back(hash[numberToFind]);
                result.push_back(i);			
                break;
            }

            //number was not found. Put it in the map.
            hash[nums[i]] = i;
        }
        return result;
    }
};