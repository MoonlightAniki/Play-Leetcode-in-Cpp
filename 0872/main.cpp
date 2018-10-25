// 872. Leaf-Similar Trees
// https://leetcode.com/problems/leaf-similar-trees/

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
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> vec1;
        vector<int> vec2;
        inOrder(root1, vec1);
        inOrder(root2, vec2);

//        if (vec1.size() != vec2.size()) {
//            return false;
//        }
//
//        for (int i = 0; i < vec1.size(); ++i) {
//            if (vec1[i] != vec2[i]) {
//                return false;
//            }
//        }
//        return true;
        return vec1 == vec2;
    }

private:
    void inOrder(TreeNode *node, vector<int> &record) {
        if (node == NULL) {
            return;
        }
        inOrder(node->left, record);
        if (node->left == NULL && node->right == NULL) {
            record.push_back(node->val);
            return;
        }
        inOrder(node->right, record);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Leaf-Similar Trees.