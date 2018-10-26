// 21. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/
/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dummyHead = new ListNode(0);
        ListNode *prev = dummyHead;
        while (true) {
            if (l1 && l2) {
                if (l1->val <= l2->val) {
                    ListNode *node = l1;
                    l1 = l1->next;
                    node->next = NULL;
                    prev->next = node;
                    prev = prev->next;
                } else {
                    ListNode *node = l2;
                    l2 = l2->next;
                    node->next = NULL;
                    prev->next = node;
                    prev = prev->next;
                }
            } else if (l1) {
                prev->next = l1;
                break;
            } else if (l2) {
                prev->next = l2;
                break;
            } else {
                break;
            }
        }
        return dummyHead->next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
// Runtime: 8 ms, faster than 89.91% of C++ online submissions for Merge Two Sorted Lists.