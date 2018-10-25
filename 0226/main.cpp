// 226. Invert Binary Tree
// https://leetcode.com/problems/invert-binary-tree/
/*
Invert a binary tree.

Example:

Input:
     4
   /   \
  2     7
 / \   / \
1   3 6   9

Output:
     4
   /   \
  7     2
 / \   / \
9   6 3   1

Trivia:
This problem was inspired by this original tweet by Max Howell:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.
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
    TreeNode *invertTree(TreeNode *root) {
        if (root == NULL) {
            return root;
        }
        TreeNode *leftNode = root->left;
        TreeNode *rightNode = root->right;
        root->left = invertTree(rightNode);
        root->right = invertTree(leftNode);
        return root;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Invert Binary Tree.