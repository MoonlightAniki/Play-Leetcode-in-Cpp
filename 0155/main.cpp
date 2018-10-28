// 155. Min Stack
// https://leetcode.com/problems/min-stack/
/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.

Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
 */

#include <iostream>

using namespace std;

class MinStack {

private:
    struct Node {
        int val;
        int minVal;
        Node *next;

        Node(int val, int minVal) : val(val), minVal(minVal), next(NULL) {}
    };


    Node *dummyHead;

public:
    /** initialize your data structure here. */
    MinStack() {
        dummyHead = new Node(0, 0);
    }

    void push(int x) {
        if (dummyHead->next == NULL) {
            dummyHead->next = new Node(x, x);
        } else {
            Node *node = new Node(x, min(x, dummyHead->next->minVal));
            node->next = dummyHead->next;
            dummyHead->next = node;
        }
    }

    void pop() {
        if (dummyHead->next == NULL) {
            return;
        }
        Node *delNode = dummyHead->next;
        dummyHead->next = delNode->next;
        delNode->next = NULL;
    }

    int top() {
        if (dummyHead->next == NULL) {
            return -1;
        }
        return dummyHead->next->val;
    }

    int getMin() {
        if (dummyHead->next == NULL) {
            return -1;
        }
        return dummyHead->next->minVal;
    }
};

int main() {
    MinStack minStack = MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-1);
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;
    return 0;
}
// Runtime: 16 ms, faster than 98.93% of C++ online submissions for Min Stack.