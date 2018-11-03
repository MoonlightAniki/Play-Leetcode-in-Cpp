// 113. Path Sum II
// https://leetcode.com/problems/path-sum-ii/
/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:
Given the below binary tree and sum = 22,
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:
[
   [5,4,11,2],
   [5,8,4,5]
]
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
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(root, sum, path, res);
        return res;
    }

private:
    void backtrack(TreeNode *node, int sum, vector<int> &path, vector<vector<int>> &res) {
        if (node == NULL) {
            return;
        }
        if (node->left == NULL && node->right == NULL && node->val == sum) {
            path.push_back(node->val);
            res.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(node->val);
        backtrack(node->left, sum - node->val, path, res);
        backtrack(node->right, sum - node->val, path, res);
        path.pop_back();
    }
};
// Runtime: 8 ms, faster than 85.24% of C++ online submissions for Path Sum II.