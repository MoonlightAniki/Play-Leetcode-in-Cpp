// 589. N-ary Tree Preorder Traversal
// https://leetcode.com/problems/n-ary-tree-preorder-traversal/
#include <iostream>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node *root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }

private:
    void preorder(Node *node, vector<int> &vec) {
        if (node == NULL) {
            return;
        }
        vec.push_back(node->val);
        for (Node *n : node->children) {
            preorder(n, vec);
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
// Runtime: 48 ms, faster than 84.43% of C++ online submissions for N-ary Tree Preorder Traversal.