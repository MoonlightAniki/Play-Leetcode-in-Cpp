// 563. Binary Tree Tilt
// https://leetcode.com/problems/binary-tree-tilt/
/*
Given a binary tree, return the tilt of the whole tree.
The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.
The tilt of the whole tree is defined as the sum of all nodes' tilt.

Example:
Input:
         1
       /   \
      2     3
Output: 1
Explanation:
Tilt of node 2 : 0
Tilt of node 3 : 0
Tilt of node 1 : |2-3| = 1
Tilt of binary tree : 0 + 0 + 1 = 1

Note:
The sum of node values in any subtree won't exceed the range of 32-bit integer.
All the tilt values won't exceed the range of 32-bit integer.
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
    int findTilt(TreeNode *root) {
        tilt = 0;
        traverse(root);
        return tilt;
    }

private:
    int tilt = 0;

	// 使用后序遍历
    void traverse(TreeNode *node) {
        if (!node) {
            return;
        }
        traverse(node->left);
        traverse(node->right);
        int leftVal = node->left ? node->left->val : 0;
        int rightVal = node->right ? node->right->val : 0;
        node->val += (leftVal + rightVal);
        tilt += abs(leftVal - rightVal);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
// Runtime: 8 ms, faster than 98.70% of C++ online submissions for Binary Tree Tilt.