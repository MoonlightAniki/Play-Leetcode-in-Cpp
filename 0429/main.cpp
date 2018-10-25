// 429. N-ary Tree Level Order Traversal
// https://leetcode.com/problems/n-ary-tree-level-order-traversal/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node *> children;

    Node() {}

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        queue<Node *> q;
        q.push(root);
        int lastLevel = 0;
        while (!q.empty()) {
            int count = q.size();
            vector<int> vec;
            for (int i = 0; i < count; ++i) {
                Node *node = q.front();
                q.pop();
                vec.push_back(node->val);
                for (Node *n : node->children) {
                    q.push(n);
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
// Runtime: 64 ms, faster than 56.04% of C++ online submissions for N-ary Tree Level Order Traversal.