// 669. Trim a Binary Search Tree
// https://leetcode.com/problems/trim-a-binary-search-tree/
/*
Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that all its elements lies
in [L, R] (R >= L). You might need to change the root of the tree, so the result should return the new root of the trimmed binary search tree.

Example 1:
Input:
    1
   / \
  0   2

  L = 1
  R = 2

Output:
    1
      \
       2


Example 2:
Input:
    3
   / \
  0   4
   \
    2
   /
  1

  L = 1
  R = 3

Output:
      3
     /
   2
  /
 1
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
    TreeNode *trimBST(TreeNode *root, int L, int R) {
        if (root == NULL) {
            return root;
        }
        if (root->val < L) {
            return trimBST(root->right, L, R);
        } else if (root->val > R) {
            return trimBST(root->left, L, R);
        } else {
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
            return root;
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
// Runtime: 8 ms, faster than 99.18% of C++ online submissions for Trim a Binary Search Tree.