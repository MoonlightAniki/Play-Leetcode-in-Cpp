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
        vector<int> res;
        while (head) {
            res.push_back(head->val);
            head = head->next;
        }
        for (int i = 0, j = res.size() - 1; i < j; ++i, --j) {
            if (res[i] != res[j]) {
                return false;
            }
        }
        return true;
    }
};
// Runtime: 16 ms, faster than 56.44% of C++ online submissions for Palindrome Linked List.