/***********************************************************************
 *  https://leetcode.com/problems/add-two-numbers/
 * 
 *  Difficulty: Medium
 * 
 *  Related Topics: Linked List, Recursion
 * 
 *  Time complexity :  O(max(m,n)). Assume that mm and nn represents the length of l1 and l2 respectively
 *
 *  Runtime: 28 ms, faster than 70.53%
 * 
 *  Memory Usage: 71.4 MB, less than 43.09%
 * 
 *  Note: None
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
    /* My solution */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(0);
        ListNode *head = ans;
        while(l1 || l2) {
            if (l1) {
                ans->val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                ans->val += l2->val;
                l2 = l2->next;
            }
            if (ans->val >= 10 || l1 || l2) {
                ans->next = new ListNode(ans->val / 10);
                ans->val %= 10;
                ans = ans->next;
            }
        }
        return head;
    }

    /* Short solution */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(0);
        ListNode *head = ans;
        int carry = 0;
        while(l1 || l2 || carry) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            ans->next = new ListNode(sum % 10);
            ans = ans->next;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        return head->next;
    }
};