// 105. Construct Binary Tree from Preorder and Inorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Time: 2018-11-09
/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:
    3
   / \
  9  20
    /  \
   15   7
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size());
    }

private:
    TreeNode *buildTree(const vector<int> &preorder, int preL, int preR, const vector<int> &inorder, int inL, int inR) {
        if (preL > preR) {
            return NULL;
        }
        if (preL == preR) {
            return new TreeNode(preorder[preL]);
        }
        TreeNode *node = new TreeNode(preorder[preL]);
        int i = inL;//查找根节点在inorder中的索引
        for (; i <= inR; ++i) {
            if (inorder[i] == node->val) {
                break;
            }
        }
        // 左子树的节点数: i - inL
        // 右子树的节点数: inR - i
        node->left = buildTree(preorder, preL + 1, preL + (i - inL),
                               inorder, inL, i - 1);
        node->right = buildTree(preorder, preL + 1 + (i - inL), preR,
                                inorder, i + 1, inR);
        return node;
    }
};
// Runtime: 24 ms, faster than 27.73% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.