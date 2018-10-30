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
        vector<int> data;
        vector<int> tree;

    public:
        SegmentTree(const vector<int> &nums) {
            if (nums.size() == 0) {
                return;
            }
            for (int i = 0; i < nums.size(); ++i) {
                data.push_back(nums[i]);
            }
            int sz = 4 * nums.size();
            for (int i = 0; i < sz; ++i) {
                tree.push_back(-1);
            }
            buildSegTree(0, 0, nums.size() - 1);
        }

        int query(int queryL, int queryR) {
            return query(0, 0, data.size() - 1, queryL, queryR);
        }

        void update(int index, int val) {
            data[index] = val;
            update(0, 0, data.size() - 1, index, val);
        }

    private:
        // 在树的treeIndex位置创建表示区间[l...r]的线段树
        void buildSegTree(int treeIndex, int l, int r) {
            if (l == r) {
                tree[treeIndex] = data[l];
                return;
            }
            int leftChild = leftChildIndex(treeIndex);
            int rightChild = rightChildIndex(treeIndex);
            int mid = l + (r - l) / 2;
            buildSegTree(leftChild, l, mid);
            buildSegTree(rightChild, mid + 1, r);

            tree[treeIndex] = tree[leftChild] + tree[rightChild];
        }

        int query(int treeIndex, int l, int r, int queryL, int queryR) {
            if (queryL == l && queryR == r) {
                return tree[treeIndex];
            }
            int leftChild = leftChildIndex(treeIndex);
            int rightChild = rightChildIndex(treeIndex);
            int mid = l + (r - l) / 2;
            if (queryR <= mid) {
                return query(leftChild, l, mid, queryL, queryR);
            } else if (queryL >= mid + 1) {
                return query(rightChild, mid + 1, r, queryL, queryR);
            } else {
                return query(leftChild, l, mid, queryL, mid) + query(rightChild, mid + 1, r, mid + 1, queryR);
            }
        }

        void update(int treeIndex, int l, int r, int index, int val) {
            if (l == r) {
                tree[treeIndex] = val;
                return;
            }
            int mid = l + (r - l) / 2;
            int leftChild = leftChildIndex(treeIndex);
            int rightChild = rightChildIndex(treeIndex);
            if (index <= mid) {
                update(leftChild, l, mid, index, val);
            } else {
                update(rightChild, mid + 1, r, index, val);
            }
            tree[treeIndex] = tree[leftChild] + tree[rightChild];
        }

        int leftChildIndex(int index) {
            return index * 2 + 1;
        }

        int rightChildIndex(int index) {
            return index * 2 + 2;
        }
    };

    SegmentTree segTree;

public:
    NumArray(vector<int> nums) : segTree(SegmentTree(nums)) {
    }

    void update(int index, int val) {
        segTree.update(index, val);
    }

    int sumRange(int i, int j) {
        return segTree.query(i, j);
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
// Runtime: 24 ms, faster than 66.42% of C++ online submissions for Range Sum Query - Mutable.