// 677. Map Sum Pairs
// https://leetcode.com/problems/map-sum-pairs/
/*
Implement a MapSum class with insert, and sum methods.
For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.
For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.

Example 1:
Input: insert("apple", 3), Output: Null
Input: sum("ap"), Output: 3
Input: insert("app", 2), Output: Null
Input: sum("ap"), Output: 5
 */

#include <iostream>
#include <unordered_map>

using namespace std;

class MapSum {
private:
    class Trie {
    private:
        struct Node {
            int val;
            unordered_map<char, Node *> next;

            Node(int val) : val(val) {}

            Node() : val(0) {}
        };

        Node *root;

    public:
        Trie() {
            root = new Node();
        }

        void add(string s, int val) {
            Node *cur = root;
            for (int i = 0; i < s.size(); ++i) {
                if (cur->next.find(s[i]) == cur->next.end()) {
                    cur->next[s[i]] = new Node();
                }
                cur = cur->next[s[i]];
            }
            cur->val = val;
        }

        int sum(string prefix) {
            Node *cur = root;
            for (int i = 0; i < prefix.size(); ++i) {
                if (cur->next.find(prefix[i]) == cur->next.end()) {
                    return 0;
                }
                cur = cur->next[prefix[i]];
            }
            return sum(cur);
        }

    private:
        // 计算节点node和所有子节点的和，深度优先遍历
        int sum(Node *node) {
            int res = 0;
            if (node == NULL) {
                return res;
            }
            res += node->val;
            for (const pair<const char, Node *> &p : node->next) {
                res += sum(p.second);
            }
            return res;
        }
    };

    Trie trie;

public:
    /** Initialize your data structure here. */
    MapSum() : trie(Trie()) {

    }

    void insert(string key, int val) {
        trie.add(key, val);
    }

    int sum(string prefix) {
        return trie.sum(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */

int main() {
    MapSum ms = MapSum();
    ms.insert("apple", 3);
    cout << ms.sum("ap") << endl;
    ms.insert("app", 2);
    cout << ms.sum("ap") << endl;
    return 0;
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Map Sum Pairs.