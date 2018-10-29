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
        if (lists.size() == 0) {
            return NULL;
        }
        ListNode *ret = NULL;
        for (ListNode *list : lists) {
            ret = mergeTwoLists(ret, list);
        }
        return ret;
    }

private:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (list1 == NULL && list2 == NULL) {
            return NULL;
        }
        if (list1 == NULL) {
            return list2;
        }

        if (list2 == NULL) {
            return list1;
        }

        ListNode *dummyHead = new ListNode(-1);
        ListNode *curNode = dummyHead;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                ListNode *node = list1;
                list1 = list1->next;
                node->next = NULL;

                curNode->next = node;
                curNode = curNode->next;
            } else {
                ListNode *node = list2;
                list2 = list2->next;
                node->next = NULL;

                curNode->next = node;
                curNode = curNode->next;
            }
        }
        if (list1) {
            curNode->next = list1;
        }
        if (list2) {
            curNode->next = list2;
        }
        ListNode *ret = dummyHead->next;
        delete dummyHead;
        return ret;
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
// Runtime: 136 ms, faster than 21.63% of C++ online submissions for Merge k Sorted Lists.