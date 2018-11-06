// 160. Intersection of Two Linked Lists
// https://leetcode.com/problems/intersection-of-two-linked-lists/
// Time: 2018-11-06
/*
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
begin to intersect at node c1.

Notes:
    If the two linked lists have no intersection at all, return null.
    The linked lists must retain their original structure after the function returns.
    You may assume there are no cycles anywhere in the entire linked structure.
    Your code should preferably run in O(n) time and use only O(1) memory.

Credits:
    Special thanks to @stellari for adding this problem and creating all test cases.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> records;
        while (headA || headB) {
            if (headA) {
                if (records.find(headA) != records.end()) {
                    return headA;
                } else {
                    records.insert(headA);
                    headA = headA->next;
                }
            }
            if (headB) {
                if (records.find(headB) != records.end()) {
                    return headB;
                } else {
                    records.insert(headB);
                    headB = headB->next;
                }
            }
        }
        return NULL;
    }
};
// Runtime: 36 ms, faster than 36.03% of C++ online submissions for Intersection of Two Linked Lists.