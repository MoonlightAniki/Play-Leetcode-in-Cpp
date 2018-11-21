// 82. Remove Duplicates from Sorted List II
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:
Input: 1->2->3->3->4->4->5
Output: 1->2->5

Example 2:
Input: 1->1->1->2->3
Output: 2->3
 */

#include <iostream>
#include <unordered_map>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        unordered_map<int, int> freq;
        for (ListNode *cur = head; cur; cur = cur->next) {
            ++freq[cur->val];
        }
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        for (ListNode *prev = dummyHead; prev->next != NULL;) {
            if (freq[prev->next->val] > 1) {
                ListNode *delNode = prev->next;
                prev->next = delNode->next;
                delNode->next = NULL;
            } else {
                prev = prev->next;
            }
        }
        ListNode *ret = dummyHead->next;
        dummyHead->next = NULL;
        delete dummyHead;
        return ret;
    }
};
// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Remove Duplicates from Sorted List II.