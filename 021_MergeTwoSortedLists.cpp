/***********************************************************************
 *  https://leetcode.com/problems/merge-two-sorted-lists/
 *
 *  Difficulty: Eady
 *
 *  Related Topics: LLinked List, Rescursion
 *
 *  Time complexity : O(n)
 *
 *  Runtime: 8 ms, faster than 74.76% of C++
 *
 *  Memory Usage: 15.1 MB, less than 10.75% of C++
 *
 *  Note: Check the Rescursion solution
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head = ListNode(0);
        ListNode *ans = &head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                ans->next = l1;
                l1 = l1->next;
            } else {
                ans->next = l2;
                l2 = l2->next;
            }
            ans = ans->next;
        }
        ans->next = l1 ? l1 : l2;
        return head.next;
    }

    /* Rescursion Solution */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};