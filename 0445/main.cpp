// 445. Add Two Numbers II
// https://leetcode.com/problems/add-two-numbers-ii/
/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:
Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
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
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        stack<int> nums1;
        stack<int> nums2;
        traverse(l1, nums1);
        traverse(l2, nums2);
        ListNode *prev = new ListNode(-1);
        int carry = 0;
        int sum;
        while (!nums1.empty() || !nums2.empty()) {
            sum = carry;
            if (!nums1.empty()) {
                sum += nums1.top();
                nums1.pop();
            }
            if (!nums2.empty()) {
                sum += nums2.top();
                nums2.pop();
            }
            carry = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            node->next = prev->next;
            prev->next = node;
        }
        if (carry > 0) {
            ListNode *node = new ListNode(carry);
            node->next = prev->next;
            prev->next = node;
        }
        ListNode *ret = prev->next;
        delete prev;
        return ret;
    }

private:
    void traverse(ListNode *head, stack<int> &nums) {
        if (head == NULL) {
            return;
        }
        for (ListNode *cur = head; cur != NULL; cur = cur->next) {
            nums.push(cur->val);
        }
    }
};
// Runtime: 28 ms, faster than 99.50% of C++ online submissions for Add Two Numbers II.