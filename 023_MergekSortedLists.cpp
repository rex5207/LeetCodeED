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

    /* Merge Sort */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return partion(lists, 0, lists.size()-1);
    }
    
    ListNode* partion(vector<ListNode*>& lists, int l, int r) {
        if (l == r)
            return lists[l];
        else if (l < r) {
            int mid = (l + r) / 2;
            ListNode* left = partion(lists, l, mid);
            ListNode* right = partion(lists, mid+1, r);
            return merge(left, right);
        } else {
            return NULL;
        }
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        if (l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else  {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
};