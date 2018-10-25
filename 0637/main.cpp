// 637. Average of Levels in Binary Tree
// https://leetcode.com/problems/average-of-levels-in-binary-tree/
/*
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].

Note:
    The range of node's value is in the range of 32-bit signed integer.
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
    vector<double> averageOfLevels(TreeNode *root) {
        vector<vector<int>> vec;
        levelOrder(root, vec);

        vector<double> res;
        for (int i = 0; i < vec.size(); ++i) {
            long long sum = 0;
            for (int j = 0; j < vec[i].size(); ++j) {
                sum += vec[i][j];
            }
            res.push_back(1.0 * sum / vec[i].size());
        }
        return res;
    }

private:
    void levelOrder(TreeNode *root, vector<vector<int>> &vec) {
        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            pair<TreeNode *, int> &e = q.front();
            q.pop();
            if (e.second == vec.size()) {
                vec.push_back(vector<int>());
            }
            vec.back().push_back(e.first->val);
            if (e.first->left) {
                q.push(make_pair(e.first->left, e.second + 1));
            }
            if (e.first->right) {
                q.push(make_pair(e.first->right, e.second + 1));
            }
        }
    }
};

int main() {
//    TreeNode *root = new TreeNode(3);
//    root->left = new TreeNode(9);
//    root->left->left = new TreeNode(1);
//    root->left->right = new TreeNode(1);
//    root->right = new TreeNode(20);
//    root->right->left = new TreeNode(15);
//    root->right->right = new TreeNode(7);

    // [2147483647,2147483647,2147483647]
    TreeNode *root = new TreeNode(2147483647);
    root->left = new TreeNode(2147483647);
    root->right = new TreeNode(2147483647);
    vector<double> res = Solution().averageOfLevels(root);
    for (auto d : res) {
        cout << d << " ";
    }
    cout << endl;
    return 0;
}
// Runtime: 8 ms, faster than 99.82% of C++ online submissions for Average of Levels in Binary Tree.