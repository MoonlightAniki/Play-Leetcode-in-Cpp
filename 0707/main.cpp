// 707. Design Linked List
// https://leetcode.com/problems/design-linked-list/
/*
Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A
node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is
a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to
indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement these functions in your linked list class:
    get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
    addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
    addAtTail(val) : Append a node of value val to the last element of the linked list.
    addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
    deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.

Example:
    MyLinkedList linkedList = new MyLinkedList();
    linkedList.addAtHead(1);
    linkedList.addAtTail(3);
    linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
    linkedList.get(1);            // returns 2
    linkedList.deleteAtIndex(1);  // now the linked list is 1->3
    linkedList.get(1);            // returns 3

Note:
    All values will be in the range of [1, 1000].
    The number of operations will be in the range of [1, 1000].
    Please do not use the built-in LinkedList library.
 */

#include <iostream>

using namespace std;

class MyLinkedList {
private:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int val) : val(val), next(NULL) {}

        ListNode(int val, ListNode *next) : val(val), next(next) {}
    };

    ListNode *dummyHead;
    int count;

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        dummyHead = new ListNode(0);
        count = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= count || index < 0) {
            return -1;
        }
        ListNode *cur = dummyHead;
        for (int i = 0; i <= index; ++i) {
            cur = cur->next;
        }
        return cur->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
//        ListNode *node = new ListNode(val, dummyHead->next);
//        dummyHead->next = node;
//        ++count;
        addAtIndex(0, val);
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
//        ListNode *prev;
//        for (prev = dummyHead; prev->next != NULL; prev = prev->next) {}
//        prev->next = new ListNode(val);
//        ++count;
        addAtIndex(count, val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0 || index > count) {
            return;
        }
        ListNode *prev = dummyHead;
        for (int i = 0; i < index; ++i) {
            prev = prev->next;
        }
        prev->next = new ListNode(val, prev->next);
        ++count;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= count) {
            return;
        }
        ListNode *prev = dummyHead;
        for (int i = 0; i < index; ++i) {
            prev = prev->next;
        }
        ListNode *delNode = prev->next;
        prev->next = delNode->next;
        delNode->next = NULL;
        --count;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */

int main() {
    MyLinkedList linkedList = MyLinkedList();
    linkedList.addAtHead(1);
    linkedList.addAtTail(3);
    linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
    cout << linkedList.get(1) << endl;            // returns 2
    linkedList.deleteAtIndex(1);  // now the linked list is 1->3
    cout << linkedList.get(1) << endl;            // returns 3

    return 0;
}
// Runtime: 24 ms, faster than 96.83% of C++ online submissions for Design Linked List.