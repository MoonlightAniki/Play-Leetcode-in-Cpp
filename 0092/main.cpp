// 92. Revert Linked List II
// https://leetcode.com/problems/reverse-linked-list-ii/
// Time: 2018-11-04
/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:
Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
 */

#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

    ListNode(const vector<int> nums) {
        if (nums.size() == 0) {
            return;
        }
        val = nums[0];
        ListNode *cur = this;
        for (int i = 1; i < nums.size(); ++i) {
            cur->next = new ListNode(nums[i]);
            cur = cur->next;
        }
    }
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *dummyHead = new ListNode(-1);
        ListNode *prev;
        ListNode *cur = dummyHead;
        int index = 1;
        while (head) {
            if (index <= m) {
                ListNode *node = head;
                head = head->next;
                node->next = NULL;

                cur->next = node;
                prev = cur;
                cur = cur->next;
            } else if (index <= n) {
                ListNode *node = head;
                head = head->next;
                node->next = NULL;

                node->next = prev->next;
                prev->next = node;
            } else {
                cur->next = head;
                break;
            }
            ++index;
        }
        ListNode *ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};

void printList(ListNode *head) {
    ListNode *cur = head;
    while (cur) {
        cout << cur->val << "->";
        cur = cur->next;
    }
    cout << "NULL" << endl;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode *head = new ListNode(nums);
    printList(head);
//    ListNode *res = Solution().reverseBetween(head, 2, 4);
    ListNode *res = Solution().reverseBetween(head, 1, 5);
    printList(res);
    return 0;
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Linked List II.