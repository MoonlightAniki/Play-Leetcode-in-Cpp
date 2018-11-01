// 328. Odd Even Linked List
// https://leetcode.com/problems/odd-even-linked-list/
/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:
Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL

Example 2:
Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL

Note:
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
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
    ListNode *oddEvenList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *oddDummy = new ListNode(-1);
        ListNode *evenDummy = new ListNode(-1);
        ListNode *oddPrev = oddDummy;
        ListNode *evenPrev = evenDummy;


        int index = 0;
        while (head) {
            if (index % 2 == 0) {
                ListNode *node = head;
                head = head->next;
                node->next = NULL;

                evenPrev->next = node;
                evenPrev = evenPrev->next;
            } else {
                ListNode *node = head;
                head = head->next;
                node->next = NULL;

                oddPrev->next = node;
                oddPrev = oddPrev->next;
            }
            ++index;
        }
        evenPrev->next = oddDummy->next;
        delete oddDummy;
        ListNode *ret = evenDummy->next;
        delete evenDummy;
        return ret;

    }
};
// Runtime: 12 ms, faster than 84.56% of C++ online submissions for Odd Even Linked List.