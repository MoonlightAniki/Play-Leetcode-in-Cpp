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
        ListNode *dummyHead = new ListNode(-1);
        ListNode *prev = dummyHead;
        int curIndex = 0;
        while (head) {
            if (curIndex % 2 == 0) {
                ListNode *node = head;
                head = head->next;
                node->next = NULL;

                prev->next = node;
            } else {
                ListNode *node = head;
                head = head->next;
                node->next = NULL;

                node->next = prev->next;
                prev->next = node;
                prev = prev->next->next;
            }
            ++curIndex;
        }
        ListNode *ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};
// Runtime: 4 ms, faster than 41.64% of C++ online submissions for Swap Nodes in Pairs.