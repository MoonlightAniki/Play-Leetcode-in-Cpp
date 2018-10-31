// 148. Sort List
// https://leetcode.com/problems/sort-list/
/*
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:
Input: 4->2->1->3
Output: 1->2->3->4

Example 2:
Input: -1->5->3->4->0
Output: -1->0->3->4->5
 */

#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

    ListNode(vector<int> &nums) {
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
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head2 = slow->next;
        slow->next = NULL;

        head = sortList(head);
        head2 = sortList(head2);
        ListNode *dummyHead = new ListNode(-1);
        ListNode *prev = dummyHead;
        while (true) {
            if (head == NULL && head2 == NULL) {
                break;
            }
            if (head == NULL) {
                prev->next = head2;
                break;
            }
            if (head2 == NULL) {
                prev->next = head;
                break;
            }
            if (head->val <= head2->val) {
                ListNode *node = head;
                head = head->next;
                node->next = NULL;

                prev->next = node;
                prev = prev->next;
            } else {
                ListNode *node = head2;
                head2 = head2->next;
                node->next = NULL;

                prev->next = node;
                prev = prev->next;
            }
        }
        ListNode *ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};


void printList(ListNode *head) {
    if (head == NULL) {
        cout << "NULL" << endl;
        return;
    }
    for (ListNode *cur = head; cur != NULL; cur = cur->next) {
        cout << cur->val << "->";
    }
    cout << "NULL" << endl;
}

int main() {
    vector<int> nums = {-1, 5, 3, 4, 0};
    ListNode *head = new ListNode(nums);
    printList(head);
    head = Solution().sortList(head);
    printList(head);
    return 0;
}
// Runtime: 48 ms, faster than 49.76% of C++ online submissions for Sort List.