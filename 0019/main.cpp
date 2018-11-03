// 19. Remove Nth Node from End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:
Given linked list: 1->2->3->4->5->6, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->4->6.

Note:
Given n will always be valid.

Follow up:
Could you do this in one pass?
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

void printList(ListNode *head) {
    while (head) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *fast = head;
        for (int i = 0; i < n && fast; ++i) {
            fast = fast->next;
        }
        if (fast == NULL) {
            return head->next;
        }
        ListNode *slow = head;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *delNode = slow->next;
        slow->next = delNode->next;
        delNode->next = NULL;

        return head;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode *head = new ListNode(nums);
    printList(head);
    printList(Solution().removeNthFromEnd(head, 5));
    return 0;
}
// Runtime: 8 ms, faster than 33.85% of C++ online submissions for Remove Nth Node From End of List.