// 572. Subtree of Another Tree
// https://leetcode.com/problems/subtree-of-another-tree/
/*
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:
     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.

Example 2:
Given tree s:
     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
 */

#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubtree(TreeNode *s, TreeNode *t) {
        if (s == NULL) {
            return t == NULL;
        }
        return isSame(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }

private:
    bool isSame(TreeNode *a, TreeNode *b) {
        if (a && b) {
            return a->val == b->val && isSame(a->left, b->left) && isSame(a->right, b->right);
        }
        return !a && !b;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
// Runtime: 16 ms, faster than 96.89% of C++ online submissions for Subtree of Another Tree.