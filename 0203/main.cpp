// 203. Remove Linked List Elements
// https://leetcode.com/problems/remove-linked-list-elements/
/*
Remove all elements from a linked list of integers that have value val.

Example:
Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
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
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *prev = dummyHead;
        while (prev->next) {
            if (prev->next->val == val) {
                ListNode *delNode = prev->next;
                prev->next = delNode->next;
                delNode->next = NULL;
            } else {
                prev = prev->next;
            }
        }
        return dummyHead->next;
    }
};
// Runtime: 16 ms, faster than 100.00% of C++ online submissions for Remove Linked List Elements.