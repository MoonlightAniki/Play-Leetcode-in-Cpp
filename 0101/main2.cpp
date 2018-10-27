// 101. Symmetric Tree
// https://leetcode.com/problems/symmetric-tree/
/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3

Note:
Bonus points if you could solve it both recursively and iteratively.
 */

#include <iostream>
#include <stack>

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
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        stack<TreeNode *> record;
        record.push(root->left);
        record.push(root->right);
        TreeNode *left, *right;
        while (!record.empty()) {
            left = record.top();//原来的node->right
            record.pop();
            right = record.top();//原来的node->left
            record.pop();
            if (left == NULL && right == NULL) {
                continue;
            }
            if (left == NULL || right == NULL || left->val != right->val) {
                return false;
            }
            record.push(left->left);
            record.push(right->right);
            record.push(left->right);
            record.push(right->left);
        }
        return true;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    cout << Solution().isSymmetric(root) << endl;
    return 0;
}
// Runtime: 4 ms, faster than 98.75% of C++ online submissions for Symmetric Tree.