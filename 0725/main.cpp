// 725. Split Linked List in Parts
// https://leetcode.com/problems/split-linked-list-in-parts/
/*
Given a (singly) linked list with head node root, write a function to split the linked list into k consecutive linked list "parts".
The length of each part should be as equal as possible: no two parts should have a size differing by more than 1. This may lead to some parts being null.
The parts should be in order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal parts occurring later.
Return a List of ListNode's representing the linked list parts that are formed.
Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]

Example 1:
Input:
root = [1, 2, 3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The input and each element of the output are ListNodes, not arrays.
For example, the input root has root.val = 1, root.next.val = 2, \root.next.next.val = 3, and root.next.next.next = null.
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but it's string representation as a ListNode is [].

Example 2:
Input:
root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.

Note:
The length of root will be in the range [0, 1000].
Each value of a node in the input will be an integer in the range [0, 999].
k will be an integer in the range [1, 50].
 */

#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

    ListNode(vector<int> nums) {
        if (nums.size() == 0) {
            return;
        }
        this->val = nums[0];
        ListNode *cur = this;
        for (int i = 1; i < nums.size(); ++i) {
            cur->next = new ListNode(nums[i]);
            cur = cur->next;
        }
    }
};

class Solution {
public:
    vector<ListNode *> splitListToParts(ListNode *root, int k) {
        // 遍历得到链表的节点数
        int count = 0;
        for (ListNode *cur = root; cur != NULL; cur = cur->next) {
            ++count;
        }
        vector<ListNode *> res(k, NULL);
        int avg = count / k;//平均每个链表中有多少个节点
        int remain = k > count ? 0 : count % k;//剩余的节点
        int index = 0;
        while (root) {
            ListNode *node = root;
            ListNode *cur = node;
            for (int i = 1; i < avg + (remain > 0 ? 1 : 0); ++i) {
                cur = cur->next;
            }
            if (remain) {
                --remain;
            }
            root = cur->next;
            cur->next = NULL;
            res[index++] = node;
        }
        return res;
    }
};

void printList(ListNode *head) {
    for (ListNode *cur = head; cur; cur = cur->next) {
        cout << cur->val << "->";
    }
    cout << "NULL" << endl;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    ListNode *head = new ListNode(nums);
    vector<ListNode *> res = Solution().splitListToParts(head, 3);
    for (ListNode *node : res) {
        printList(node);
    }
    return 0;
}
// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Split Linked List in Parts.