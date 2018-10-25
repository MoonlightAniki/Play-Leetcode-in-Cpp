// 606. Construct String from Binary Tree
// https://leetcode.com/problems/construct-string-from-binary-tree/
/*
You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.
The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs
that don't affect the one-to-one mapping relationship between the string and the original binary tree.

Example 1:
Input: Binary tree: [1,2,3,4]
       1
     /   \
    2     3
   /
  4

Output: "1(2(4))(3)"

Explanation: Originallay it needs to be "1(2(4)())(3()())",
but you need to omit all the unnecessary empty parenthesis pairs.
And it will be "1(2(4))(3)".


Example 2:
Input: Binary tree: [1,2,3,null,4]
       1
     /   \
    2     3
     \
      4

Output: "1(2()(4))(3)"

Explanation: Almost the same as the first example,
except we can't omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.
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
    string tree2str(TreeNode *t) {
        string res;
        if (t == NULL) {
            return res;
        }
        helper(t, res);
        return res.substr(1, res.size() - 2);
    }

private:
    void helper(TreeNode *node, string &res) {
        if (node == NULL) {
            return;
        }
        res += '(';
        res += to_string(node->val);

        // 左孩子和右孩子都不等于空
        if (node->left && node->right) {
            helper(node->left, res);
            helper(node->right, res);
        } else if (node->left) {//右孩子为空
            helper(node->left, res);
        } else if (node->right) {//左孩子为空
            res += "()";
            helper(node->right, res);
        }
        res += ')';
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
// Runtime: 12 ms, faster than 75.60% of C++ online submissions for Construct String from Binary Tree.