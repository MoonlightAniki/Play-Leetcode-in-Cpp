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
#include <vector>
#include <queue>

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
    TreeNode *convertBST(TreeNode *root) {
        vector<int> record;
        inOrder(root, record);
        if (record.size() <= 1) {
            return root;
        }
        for (int i = record.size() - 2; i >= 0; --i) {
            record[i] += record[i + 1];
        }
        inOrder2(root, record);
        return root;
    }

private:
    void inOrder(TreeNode *node, vector<int> &record) {
        if (!node) {
            return;
        }
        inOrder(node->left, record);
        record.push_back(node->val);
        inOrder(node->right, record);
    }

    void inOrder2(TreeNode *node, vector<int> &record) {
        if (!node) {
            return;
        }
        inOrder2(node->left, record);
        node->val = record.front();
        record.erase(record.begin());
        inOrder2(node->right, record);
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
// Runtime: 44 ms, faster than 21.98% of C++ online submissions for Convert BST to Greater Tree.