// 147. Insertion Sort List
// https://leetcode.com/problems/insertion-sort-list/
/*
Sort a linked list using insertion sort.

A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list

Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.

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
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        for (ListNode *prev = head; prev->next != NULL;) {
            int val = prev->next->val;
            bool swapped = false;
            for (ListNode *prev2 = dummyHead; !swapped && prev2 != prev; prev2 = prev2->next) {
                if (prev2->next->val > val) {
                    ListNode *node = prev->next;
                    prev->next = node->next;
                    node->next = NULL;

                    node->next = prev2->next;
                    prev2->next = node;
                    swapped = true;
                }
            }
            if (!swapped) {
                prev = prev->next;
            }
        }
        ListNode *ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};

void printList(ListNode *head) {
    for (ListNode *cur = head; cur; cur = cur->next) {
        cout << cur->val << "->";
    }
    cout << "NULL";
}

int main(void) {
    vector<int> nums = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    ListNode *head = new ListNode(nums);
    ListNode *res = Solution().insertionSortList(head);
    printList(res);

    return 0;
}
// Runtime: 48 ms, faster than 30.20% of C++ online submissions for Insertion Sort List.