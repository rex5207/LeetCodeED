/***********************************************************************
 *  https://leetcode.com/problems/container-with-most-water/
 * 
 *  Difficulty: Medium
 * 
 *  Related Topics: Greedy
 * 
 *  Time complexity : O(n)
 *
 *  Runtime: 80 ms, faster than 77.91% of C++
 * 
 *  Memory Usage: 59.1 MB, less than 37.08% of C++
 * 
 *  Note: N/A
 * 
 ***********************************************************************/

/* My solution */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int tail = height.size() - 1;
        int head = 0;
        while(head < tail){
            int h = min(height[head], height[tail]);
            int w = tail - head;
            ans = max(ans, h*w);
            if(height[head] < height[tail])
                head++;
            else
                tail--;
        }
        return ans;
    }
};
