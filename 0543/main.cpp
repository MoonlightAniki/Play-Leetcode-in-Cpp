// 543. Diameter of Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree/
/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \
      4   5
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
 */

#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode *root) {
        diameter = 0;
        maxDepth(root);
        return diameter;
    }

private:
    int diameter = 0;

    int maxDepth(TreeNode *node) {
        if (!node) {
            return 0;
        }
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);
        diameter = max(diameter, leftDepth + rightDepth);

        return 1 + max(leftDepth, rightDepth);
    }
};

int main() {
    return 0;
}
// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Diameter of Binary Tree.