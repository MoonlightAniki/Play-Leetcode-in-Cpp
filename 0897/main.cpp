// 897. Increasing Order Search Tree
// https://leetcode.com/problems/increasing-order-search-tree/
/*
Given a tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only 1 right child.

Example 1:
Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \
1        7   9

Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9
Note:
    1. The number of nodes in the given tree will be between 1 and 100.
    2. Each node will have a unique integer value from 0 to 1000.
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
    TreeNode *increasingBST(TreeNode *root) {
        if (root == NULL) {
            return root;
        }
        vector<int> res;
        inOrder(root, res);

        TreeNode *dummyRoot = new TreeNode(0);
        TreeNode *cur = dummyRoot;
        for (int i = 0; i < res.size(); ++i) {
            cur->right = new TreeNode(res[i]);
            cur = cur->right;
        }
        return dummyRoot->right;
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
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
// Runtime: 68 ms, faster than 45.98% of C++ online submissions for Increasing Order Search Tree.