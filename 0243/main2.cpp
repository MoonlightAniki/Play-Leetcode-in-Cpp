// 243. Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/
/*
Given a singly linked list, determine if it is a palindrome.

Example 1:
Input: 1->2
Output: false

Example 2:
Input: 1->2->2->1
Output: true

Follow up:
Could you do it in O(n) time and O(1) space?
 */

#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }

        // 将链表从中间分成两段
        // 如果链表的节点个数为奇数，则左半部分节点数比右半部分多1
        // 1->2->1 分成 1—>2 和 1
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head2 = slow->next;
        slow->next = NULL;

        // 将右半部分链表反转
        ListNode *dummHead = new ListNode(0);
        ListNode *prev = dummHead;
        while (head2) {
            ListNode *node = head2;
            head2 = head2->next;
            node->next = NULL;

            node->next = prev->next;
            prev->next = node;
        }
        head2 = dummHead->next;

        // 比较左右两部分链表对应的节点上的值是否相等
        while (head) {
            if (head->val != head2->val) {
                return false;
            }
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
};
// Runtime: 16 ms, faster than 56.44% of C++ online submissions for Palindrome Linked List.