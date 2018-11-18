// 236. Lowest Common Ancestor of a Binary Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of of nodes 5 and 1 is 3.


Example 2:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself
             according to the LCA definition.

Note:
All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.
 */

#include <iostream>
#include <unordered_map>

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        records.clear();
        records[p->val] = {};
        records[q->val] = {};
        return helper(root, p, q);
    }

private:
    unordered_map<int, unordered_map<TreeNode *, bool>> records;

    TreeNode *helper(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == NULL) return root;

        if (root->val == p->val || root->val == q->val) {
            return root;
        }
        if (contains(root->left, p->val) && contains(root->left, q->val)) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (contains(root->right, p->val) && contains(root->right, q->val)) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }

    bool contains(TreeNode *node, int val) {
        if (node == NULL) {
            return false;
        }
        if (records[val].find(node) != records[val].end()) {
            return records[val][node];
        }
        bool res = node->val == val || contains(node->left, val) || contains(node->right, val);
        records[val][node] = res;
        return res;
    }
};
// Time Limit Exceeded