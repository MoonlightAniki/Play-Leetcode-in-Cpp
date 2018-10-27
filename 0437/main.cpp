// 437. Path Sum III
// https://leetcode.com/problems/path-sum-iii/
/*
You are given a binary tree in which each node contains an integer value.
Find the number of paths that sum to a given value.
The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:
1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
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
    int pathSum(TreeNode *root, int sum) {
        res = 0;
        preOrder(root, sum);
        return res;
    }

private:
    int res;

    void __pathSum(TreeNode *node, int sum) {
        if (node == NULL) {
            return;
        }
        if (node->val == sum) {
            ++res;
            // 此处不可return，如果子树中还有路径的和等于0就被漏掉
            // return;
        }
        __pathSum(node->left, sum - node->val);
        __pathSum(node->right, sum - node->val);
    }

    void preOrder(TreeNode *node, int sum) {
        if (node == NULL) {
            return;
        }
        __pathSum(node, sum);
        preOrder(node->left, sum);
        preOrder(node->right, sum);
    }
};

int main() {
    return 0;
}
// Runtime: 12 ms, faster than 83.19% of C++ online submissions for Path Sum III.