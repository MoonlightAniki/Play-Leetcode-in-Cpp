// 538. Convert BST to Greater Tree
// https://leetcode.com/problems/convert-bst-to-greater-tree/
/*
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the
original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
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
private:
    int sum = 0;

    void convert(TreeNode *node) {
        if (node == NULL) {
            return;
        }
        convert(node->right);
        sum += node->val;
        node->val = sum;
        convert(node->left);
    }

public:
    TreeNode *convertBST(TreeNode *root) {
        convert(root);
        return root;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
// Runtime: 24 ms, faster than 97.93% of C++ online submissions for Convert BST to Greater Tree.