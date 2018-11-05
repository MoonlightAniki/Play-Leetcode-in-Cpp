// 142. Linked List Cycle II
// https://leetcode.com/problems/linked-list-cycle-ii/
// Time : 2018-11-05
/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
 */

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode *entrance = head;
                while (entrance != slow) {
                    entrance = entrance->next;
                    slow = slow->next;
                }
                return entrance;
            }
        }
        return NULL;
    }
};
// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Linked List Cycle II.