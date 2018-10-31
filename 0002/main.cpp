// 2. Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/
/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order
and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
 */

#include <iostream>
#include <stack>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummyHead = new ListNode(-1);
        ListNode *prev = dummyHead;
        int carry = 0;
        while (l1 || l2) {
            int sum = 0;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            prev->next = new ListNode(sum % 10);
            prev = prev->next;
        }
        if (carry > 0) {
            prev->next = new ListNode(carry);
        }
        ListNode *ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};
// Runtime: 64 ms, faster than 11.24% of C++ online submissions for Add Two Numbers.