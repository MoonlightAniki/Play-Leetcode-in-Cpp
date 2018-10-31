// 654. Maximum Binary Tree
// https://leetcode.com/problems/maximum-binary-tree/
/*
Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:
    1. The root is the maximum number in the array.
    2. The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
    3. The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.

Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:
      6
    /   \
   3     5
    \    /
     2  0
       \
        1

Note:
The size of the given array will be in the range [1,1000].
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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return constructMaximumBinaryTree(nums, 0, nums.size() - 1);
    }

private:
    TreeNode *constructMaximumBinaryTree(const vector<int> &nums, int lo, int hi) {
        if (lo > hi) {
            return NULL;
        }
        if (lo == hi) {
            return new TreeNode(nums[lo]);
        }
        int maxIndex = lo;
        for (int i = lo + 1; i <= hi; ++i) {
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }
        TreeNode *node = new TreeNode(nums[maxIndex]);
        node->left = constructMaximumBinaryTree(nums, lo, maxIndex - 1);
        node->right = constructMaximumBinaryTree(nums, maxIndex + 1, hi);
        return node;
    }
};
// Runtime: 40 ms, faster than 96.16% of C++ online submissions for Maximum Binary Tree.