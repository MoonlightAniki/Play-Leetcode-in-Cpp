// 114. Flatten Binary Tree to Linked List
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
/*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:
    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
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
    void flatten(TreeNode *root) {
        root = helper(root);
    }

private:
    TreeNode *helper(TreeNode *node) {
        if (node == NULL) {
            return node;
        }
        TreeNode *leftNode = node->left;
        TreeNode *rightNode = node->right;
        if (leftNode == NULL && rightNode == NULL) {
            return node;
        }
        node->left = NULL;
        TreeNode *cur = node;
        cur->right = helper(leftNode);
        while (cur->right) {
            cur = cur->right;
        }
        cur->right = helper(rightNode);
        return node;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution().flatten(root);

    return 0;
}
// Runtime: 8 ms, faster than 48.89% of C++ online submissions for Flatten Binary Tree to Linked List.