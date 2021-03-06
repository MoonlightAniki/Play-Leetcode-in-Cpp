// 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/
/*
Reverse a singly linked list.

Example:
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

Follow up:
A linked list can be reversed either iteratively or recursively. Could you implement both?
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
    ListNode *reverseList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *dummyHead = new ListNode(0);
        ListNode *prev = dummyHead;

        while (head) {
            ListNode *node = head;
            head = head->next;

            node->next = prev->next;
            prev->next = node;
        }

        return dummyHead->next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
// Runtime: 12 ms, faster than 14.06% of C++ online submissions for Reverse Linked List.