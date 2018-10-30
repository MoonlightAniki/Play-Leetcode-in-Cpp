// 98. Validate Binary Search Tree
// https://leetcode.com/problems/validate-binary-search-tree/
/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:
    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

Example 1:
Input:
    2
   / \
  1   3
Output: true

Example 2:
    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.
 */

#include <iostream>
#include <vector>

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
    bool isValidBST(TreeNode *root) {
        vector<int> res;
        inOrder(root, res);
        return isAscendOrder(res);
    }

private:
    void inOrder(TreeNode *node, vector<int> &res) {
        if (node == NULL) {
            return;
        }
        inOrder(node->left, res);
        res.push_back(node->val);
        inOrder(node->right, res);
    }

    bool isAscendOrder(vector<int> &nums) {
        for (int i = 0; i + 1 < nums.size(); ++i) {
            if (nums[i] >= nums[i + 1]) {
                return false;
            }
        }
        return true;
    }
};
// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Validate Binary Search Tree.