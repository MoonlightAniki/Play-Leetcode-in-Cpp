// 337. House Robber III
// https://leetcode.com/problems/house-robber-iii/
// Time: 2018-11-07
/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \
     3   1
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

Example 2:
Input: [3,4,5,1,3,null,1]
     3
    / \
   4   5
  / \   \
 1   3   1
Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
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
    int rob(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int maxIncludeRoot = root->val;
        int maxExcludeRoot = 0;
        if (root->left) {
            maxIncludeRoot += rob(root->left->left) + rob(root->left->right);
            maxExcludeRoot += rob(root->left);
        }
        if (root->right) {
            maxIncludeRoot += rob(root->right->left) + rob(root->right->right);
            maxExcludeRoot += rob(root->right);
        }
        return max(maxIncludeRoot, maxExcludeRoot);
    }
};
// Runtime: 708 ms, faster than 25.47% of C++ online submissions for House Robber III.