// 817. Linked List Components
// https://leetcode.com/problems/linked-list-components/
/*
We are given head, the head node of a linked list containing unique integer values.
We are also given the list G, a subset of the values in the linked list.
Return the number of connected components in G, where two values are connected if they appear consecutively in the linked list.

Example 1:
Input:
head: 0->1->2->3
G = [0, 1, 3]
Output: 2
Explanation:
0 and 1 are connected, so [0, 1] and [3] are the two connected components.

Example 2:
Input:
head: 0->1->2->3->4
G = [0, 3, 1, 4]
Output: 2
Explanation:
0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.

Note:
    If N is the length of the linked list given by head, 1 <= N <= 10000.
    The value of each node in the linked list will be in the range [0, N - 1].
    1 <= G.length <= 10000.
    G is a subset of all values in the linked list.
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

    ListNode(const vector<int> &nums) {
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
    int numComponents(ListNode *head, vector<int> &G) {
        int res = 0;
        int count = 0;
        unordered_set<int> record(G.begin(), G.end());
        for (ListNode *cur = head; cur != NULL; cur = cur->next) {
            if (record.find(cur->val) != record.end()) {
                ++count;
            } else {
                if (count > 0) {
                    ++res;
                    count = 0;
                }
            }
        }
        res += count > 0;
        return res;
    }
};

void printList(ListNode *head) {
    for (ListNode *cur = head; cur != NULL; cur = cur->next) {
        cout << cur->val << "->";
    }
    cout << "NULL" << endl;
}

int main() {
    vector<int> nums = {0, 1, 2, 3, 4};
    vector<int> G = {0, 3, 1, 4};
    ListNode *head = new ListNode(nums);
    printList(head);
    int res = Solution().numComponents(head, G);
    cout << res << endl;
    return 0;
}
// Runtime: 20 ms, faster than 96.46% of C++ online submissions for Linked List Components.