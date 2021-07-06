/***********************************************************************
 *  https://leetcode.com/problems/merge-k-sorted-lists/
 *
 *  Difficulty: Hard
 *
 *  Related Topics: Heap(prioirty_queue), merge sort
 *
 *  Time complexity : O(N logK)
 *
 *  Runtime: 24 ms, faster than 63.46% of C++
 *
 *  Memory Usage: 13.9 MB, less than 24.80% of C++
 *
 *  Note: N/A
 *
 ***********************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /* Heap Solution */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int> > pq;
        for (auto list: lists) {
            while(list) {
                pq.push(list -> val);
                list = list->next;
            }
        }
        ListNode head = new ListNode(0);
        ListNode* tmp = head;
        while(!pq.empty()){
            tmp->next = new ListNode(pq.top());
            tmp = tmp->next;
            pq.pop();
        }

        return head->next;
    }
};