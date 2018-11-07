// 96. Unique Binary Search Trees
// https://leetcode.com/problems/unique-binary-search-trees/
// Time: 2018-11-07
/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:
Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        vector<int> dp(n + 1, 0);//dp[index]表示[1...index]能组成的不同结构的BST的数量
        // F(i,n)表示以i为根节点的BST的数量
        // dp[n] = F(1,n)+F(2,n)+...+F(n-1,n)+F(n,n);
        // F(i,n)以i为根节点,i左侧[1...i-1]能组成的BST的数量等于dp[i-1],右侧的[i+1,n]能组成的BST的数量等于dp[n-i]
        // dp[n]=dp[0]*dp[n-1] + dp[1]*dp[n-2] + ... + dp[n-2]*dp[1] + dp[n-1]*dp[0]
        dp[0] = 1;//空的BST
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }

private:
    class BST {
    private:
        struct Node {
            int val;
            Node *left;
            Node *right;

            Node(int val) : val(val) {}
        };

        Node *root;
        int size = 0;

    public:
        BST() : size(0), root(NULL) {}

        void add(int val) {
            root = add(root, val);
        }

        void remove(int val) {
            root = remove(root, val);
        }

    private:
        Node *add(Node *node, int val) {
            if (node == NULL) {
                Node *node = new Node(val);
                ++size;
                return node;
            }
            if (val < node->val) {
                node->left = add(node->left, val);
            } else if (val > node->val) {
                node->right = add(node->right, val);
            }
            return node;
        }

        Node *remove(Node *node, int val) {
            if (node == NULL) {
                return NULL;
            }
            if (val < node->val) {
                node->left = remove(node->left, val);
                return node;
            } else if (val > node->val) {
                node->right = remove(node->right, val);
                return node;
            } else {// val == node->val
                if (node->left == NULL) {
                    Node *rightNode = node->right;
                    node->right = NULL;
                    --size;
                    return rightNode;
                }
                if (node->right == NULL) {
                    Node *leftNode = node->left;
                    node->left = NULL;
                    --size;
                    return leftNode;
                }
                // node->left != NULL && node->right != NULL
                Node *leftNode = node->left;
                Node *rightNode = node->right;
                node->left = NULL;
                node->right = NULL;

                Node *minNode = minimum(rightNode);
                Node *successor = new Node(minNode->val);
                successor->left = leftNode;
                successor->right = remove(rightNode, minNode->val);
                return successor;
            }
        }

        Node *minimum(Node *node) {
            if (node == NULL) {
                return node;
            }
            if (node->left) {
                return minimum(node->left);
            }
            return node;
        }

        int getSize() {
            return size;
        }

        bool isEmpty() {
            return size == 0;
        }
    };
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Binary Search Trees.