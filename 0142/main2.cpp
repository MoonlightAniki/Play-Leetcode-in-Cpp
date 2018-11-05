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
#include <unordered_set>

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
        unordered_set<ListNode *> records;
        ListNode *cur = head;
        while (cur) {
            if (records.find(cur) == records.end()) {
                records.insert(cur);
                cur = cur->next;
            } else {
                return cur;
            }
        }
        return NULL;
    }
};
// Runtime: 12 ms, faster than 25.63% of C++ online submissions for Linked List Cycle II.