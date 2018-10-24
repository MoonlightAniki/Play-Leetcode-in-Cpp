// 590. N-ary Tree Postorder Traversal
// https://leetcode.com/problems/n-ary-tree-postorder-traversal/
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
    vector<int> postorder(Node *root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }

private:
    void postorder(Node *node, vector<int> &vec) {
        if (node == NULL) {
            return;
        }
        for (Node *a : node->children) {
            postorder(a, vec);
        }
        vec.push_back(node->val);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
// Runtime: 56 ms, faster than 69.45% of C++ online submissions for N-ary Tree Postorder Traversal.