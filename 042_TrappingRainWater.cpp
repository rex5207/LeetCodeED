/***********************************************************************
 *  https://leetcode.com/problems/trapping-rain-water/
 *
 *  Difficulty: Hard
 *
 *  Related Topics: Two Pointers, Dymamic Programming, Monotonic Stack
 *
 *  Time complexity : O(N)
 *
 *  Runtime: 8 ms, faster than 55.88% of C++
 *
 *  Memory Usage: 14.4 MB, less than 25.95% of C++
 *
 *  Note: Need to know all solutions
 *
 ***********************************************************************/ 

class Solution {
public:

    /* Dymamic Programming Solution */
    int trap(vector<int>& height) {
        if (height.empty())
            return 0;
        int len = height.size();
        int ans = 0;
        vector<int> left_max(len), right_max(len);
        left_max[0] = height[0];
        for (int i = 1; i < len; i++) {
            left_max[i] = max(left_max[i-1], height[i]);
        }
        right_max[len-1] = height[len-1];
        for (int i = len-2; i>=0; i--) {
            right_max[i] = max(right_max[i+1], height[i]);
        }
        
        for (int i=1; i<len-1; i++) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }


    /* Monotonic Stack */
    int trap(vector<int>& height) {
        int len = height.size();
        int ans = 0;
        int cur = 0;
        stack<int> st;
        while (cur < len) {
            while (!st.empty() && height[cur] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty())
                    break;
                // height[st.top()] => Left Wall
                // height[cur] => Right Wall
                // height[top] => Middle Floow 凹
                int dis = cur - st.top() - 1;
                int lower_bound = min(height[st.top()], height[cur]) - height[top];
                ans += dis * lower_bound;
            }
            st.push(cur++);
        }
        return ans;
    }

};