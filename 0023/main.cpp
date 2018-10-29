// 23. Merge K Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/
/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
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
            throw exception();
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *dummyHead = new ListNode(0);
        ListNode *prev = dummyHead;
        int minVal = 0x7fffffff;
        int index = -1;

        bool flag = true;
        while (flag) {
            flag = false;
            for (int i = 0; i < lists.size(); ++i) {
                if (lists[i] && lists[i]->val < minVal) {
                    minVal = lists[i]->val;
                    index = i;
                    flag = true;
                }
            }
            if (flag) {
                prev->next = new ListNode(minVal);
                prev = prev->next;

                lists[index] = lists[index]->next;
                minVal = 0x7fffffff;
            }
        }
        return dummyHead->next;
    }
};

void printList(ListNode *node) {
    if (node == NULL) {
        cout << "NULL" << endl;
        return;
    }
    for (ListNode *cur = node; cur != NULL; cur = cur->next) {
        cout << cur->val << "->";
    }
    cout << "NULL" << endl;
}

int main() {
    vector<int> nums1 = {1, 4, 5};
    vector<int> nums2 = {1, 3, 4};
    vector<int> nums3 = {2, 6};
    vector<ListNode *> lists;
    lists.push_back(new ListNode(nums1));
    lists.push_back(new ListNode(nums2));
    lists.push_back(new ListNode(nums3));

    ListNode *res = Solution().mergeKLists(lists);

    printList(res);

    return 0;
}
// Runtime: 412 ms, faster than 5.95% of C++ online submissions for Merge k Sorted Lists.