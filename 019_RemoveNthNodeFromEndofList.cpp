/***********************************************************************
 *  https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 *
 *  Difficulty: Medium
 *
 *  Related Topics: Linked List, Two Pointer
 *
 *  Time complexity : O(n)
 *
 *  Runtime: 4 ms, faster than 81.47% of C++
 *
 *  Memory Usage: 11 MB, less than 27.26% of C++
 *
 *  Note: Check Two Pointer
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
    /* My Solution */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        unordered_map<int, ListNode*> umap;
        umap[0] = head;
        while (head != NULL) {
            len ++;
            umap[len] = head;
            head = head -> next;
        }
        // Head case
        if (len == n){
            umap[0] = umap[0] -> next;
        }
        else{
            umap[len - n]->next = umap[len - n + 2];
        }
        return umap[0];
    }

    /* Two Pointer*/
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* second = head;
        for (int i=0; i<n; i++) {
            first = first->next;
        }
        // Head need to remove
        if (first == NULL) {
            return head -> next;
        }
        while(first->next) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return head;
    }
};