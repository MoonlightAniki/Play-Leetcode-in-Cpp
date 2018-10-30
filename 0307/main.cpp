// 307. Range Sum Query -- Mutable
// https://leetcode.com/problems/range-sum-query-mutable/
/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
The update(i, val) function modifies nums by updating the element at index i to val.

Example:
Given nums = [1, 3, 5]
sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8

Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
 */

#include <iostream>
#include <vector>

using namespace std;

class NumArray {
private:
    class SegmentTree {
    private:
        struct Node {
            int start, end, val;
            Node *left, *right;

            Node(int start, int end) : start(start), end(end), val(0), left(NULL), right(NULL) {}
        };

        Node *root;

        vector<int> nums;

    public:
        SegmentTree(const vector<int> &nums) {
            if (nums.size() == 0) {
                return;
            }
            for (int i = 0; i < nums.size(); ++i) {
                this->nums.push_back(nums[i]);
            }
            root = buildSegmentTree(root, 0, nums.size() - 1);
        }

        int query(int queryL, int queryR) {
            return query(root, queryL, queryR);
        };

        void update(int index, int val) {
            update(root, index, val);
        }

    private:
        // 创建一棵以root为根的，表示 nums[start...end] 区间的线段树
        Node *buildSegmentTree(Node *root, int start, int end) {
            if (start > end) {
                return NULL;
            }
            root = new Node(start, end);
            if (start == end) {
                root->val = nums[start];
                return root;
            }
            int mid = start + (end - start) / 2;
            root->left = buildSegmentTree(root->left, start, mid);
            root->right = buildSegmentTree(root->right, mid + 1, end);
            root->val = root->left->val + root->right->val;
            return root;
        };

        int query(Node *node, int queryL, int queryR) {
            if (node == NULL) {
                return 0;
            }
            if (queryL == node->start && queryR == node->end) {
                return node->val;
            }
            int mid = node->start + (node->end - node->start) / 2;
            if (queryR <= mid) {
                return query(node->left, queryL, queryR);
            } else if (queryL >= mid + 1) {
                return query(node->right, queryL, queryR);
            } else {
                return query(node->left, queryL, mid) + query(node->right, mid + 1, queryR);
            }
        }

        int update(Node *node, int index, int val) {
            if (node == NULL) {
                return 0;
            }
            if (node->start == index && node->end == index) {
                int diff = val - node->val;
                node->val = val;
                return diff;
            }
            int mid = node->start + (node->end - node->start) / 2;
            int diff;
            if (index <= mid) {
                diff = update(node->left, index, val);
            } else {
                diff = update(node->right, index, val);
            }
            node->val += diff;
            return diff;
        }
    };

    SegmentTree tree;


public:
    NumArray(vector<int> nums) : tree(SegmentTree(nums)) {
    }

    void update(int index, int val) {
        tree.update(index, val);
    }

    int sumRange(int i, int j) {
        return tree.query(i, j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

int main() {
    vector<int> nums = {1, 3, 5, 4, 8, 9};
    NumArray a = NumArray(nums);
    cout << a.sumRange(0, 2) << endl;
    a.update(1, 2);
    cout << a.sumRange(0, 2) << endl;
    return 0;
}
// Runtime: 20 ms, faster than 93.63% of C++ online submissions for Range Sum Query - Mutable.