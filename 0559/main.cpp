// 559. Maximum Depth of N-ary Tree
// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

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
    int maxDepth(Node *root) {
        if (root == NULL) {
            return 0;
        }
        int res = 0;
        for (Node *node : root->children) {
            res = max(res, maxDepth(node));
        }
        return res + 1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
// Runtime: 64 ms, faster than 45.03% of C++ online submissions for Maximum Depth of N-ary Tree.