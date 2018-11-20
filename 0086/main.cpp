// 86. Partition List
// https://leetcode.com/problems/partition-list/
/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.

Example:
Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
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
    ListNode *partition(ListNode *head, int x) {
        ListNode *dummyHead1 = new ListNode(-1);
        ListNode *dummyHead2 = new ListNode(-1);
        dummyHead1->next = head;
        ListNode *lessPrev = dummyHead2;
        for (ListNode *prev = dummyHead1; prev->next != NULL;) {
            if (prev->next->val < x) {
                ListNode *delNode = prev->next;
                prev->next = delNode->next;
                delNode->next = NULL;

                lessPrev->next = delNode;
                lessPrev = lessPrev->next;
            } else {
                prev = prev->next;
            }
        }
        lessPrev->next = dummyHead1->next;
        dummyHead1->next = NULL;
        delete dummyHead1;

        ListNode *ret = dummyHead2->next;
        delete dummyHead2;
        return ret;
    }
};
// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Partition List.