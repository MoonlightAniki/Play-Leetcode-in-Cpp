// 24. Swap Nodes in Pairs
// https://leetcode.com/problems/swap-nodes-in-pairs/
/*
Given a linked list, swap every two adjacent nodes and return its head.

Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.

Note:
Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, only nodes itself may be changed.
 */

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        if (head->next->next == NULL) {
            ListNode *ret = head->next;
            ret->next = head;
            head->next = NULL;
            return ret;
        }
        ListNode *ret = head->next;
        head->next = swapPairs(ret->next);
        ret->next = head;
        return ret;
    }
};
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Swap Nodes in Pairs.