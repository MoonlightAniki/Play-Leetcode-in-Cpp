// 404. Sum of Left Leaves
// https://leetcode.com/problems/sum-of-left-leaves/
/*
Find the sum of all left leaves in a given binary tree.

Example:
    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
    int sumOfLeftLeaves(TreeNode *root) {
        sum = 0;
        traverse(root);
        return sum;
    }

private:
    int sum = 0;

    void traverse(TreeNode *node) {
        if (!node) {
            return;
        }
        traverse(node->left);
        if (node->left && !node->left->left && !node->left->right) {
            sum += node->left->val;
        }
        traverse(node->right);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
// Runtime: 4 ms, faster than 76.34% of C++ online submissions for Sum of Left Leaves.