// 109. Convert Sorted List to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:
Given the sorted linked list: [-10,-3,0,5,9],
One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
      0
     / \
   -3   9
   /   /
 -10  5
 */

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL) {
            return new TreeNode(head->val);
        }

        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *prevSlow = dummyHead;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next && fast->next->next) {
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prevSlow->next = NULL;
        ListNode *leftHead = dummyHead->next;
        dummyHead->next = NULL;
        delete dummyHead;

        ListNode *rightHead = slow->next;
        slow->next = NULL;

        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(leftHead);
        root->right = sortedListToBST(rightHead);
        return root;
    }
};
// Runtime: 16 ms, faster than 70.05% of C++ online submissions for Convert Sorted List to Binary Search Tree.