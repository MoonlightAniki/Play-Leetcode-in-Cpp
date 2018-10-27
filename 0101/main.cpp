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
        root->right = mirror(root->right);
        return isSame(root->left, root->right);
    }

private:
    TreeNode *mirror(TreeNode *node) {
        if (node == NULL) {
            return node;
        }
        TreeNode *leftNode = node->left;
        TreeNode *rightNode = node->right;
        node->left = mirror(rightNode);
        node->right = mirror(leftNode);

        // 上面四行代码不能用下面两行代码代替
//        node->left = mirror(node->right);
//        node->right = mirror(node->left);

        return node;
    }

    bool isSame(TreeNode *root1, TreeNode *root2) {
        if (root1 && root2) {
            return root1->val == root2->val && isSame(root1->left, root2->left) && isSame(root1->right, root2->right);
        }
        return !root1 && !root2;
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