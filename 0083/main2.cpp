// 83. Remove Duplicates from Sorted List
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:
Input: 1->1->2
Output: 1->2

Example 2:
Input: 1->1->2->3->3
Output: 1->2->3
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        head->next = deleteDuplicates(head->next);
        if (head->val == head->next->val) {
            return head->next;
        } else {
            return head;
        }
    }
};

int main() {
    return 0;
}
//Runtime: 8 ms, faster than 98.53% of C++ online submissions for Remove Duplicates from Sorted List.