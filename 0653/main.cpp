// 653. Two Sum IV
// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
/*
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True


Example 2:
Input:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False
 */

#include <iostream>
#include <vector>
#include <unordered_set>

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
    bool findTarget(TreeNode *root, int k) {
        if (root == NULL) {
            return false;
        }
        vector<int> res;
        inOrder(root, res);
        if (res.size() < 2) {
            return false;
        }
        unordered_set<int> record;
        for (const int &num : res) {
            if (record.find(k - num) != record.end()) {
                return true;
            }
            record.insert(num);
        }
        return false;

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
//  28 ms, faster than 57.47% of C++ online submissions for Two Sum IV - Input is a BST.