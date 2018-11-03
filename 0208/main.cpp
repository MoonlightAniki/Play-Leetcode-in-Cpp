// 208. Implement Trie (Prefix Tree)
// https://leetcode.com/problems/implement-trie-prefix-tree/
/*
Implement a trie with insert, search, and startsWith methods.

Example:
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true

Note:
You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
 */

#include <iostream>

using namespace std;

class Trie {
private:
    struct Node {
        bool end = false;
        Node *next[26];
    };

    Node *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *cur = root;
        for (const char &c : word) {
            if (cur->next[c - 'a'] == NULL) {
                cur->next[c - 'a'] = new Node();
            }
            cur = cur->next[c - 'a'];
        }
        cur->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *cur = root;
        for (const char &c : word) {
            if (cur->next[c - 'a'] == NULL) {
                return false;
            }
            cur = cur->next[c - 'a'];
        }
        return cur->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *cur = root;
        for (const char &c : prefix) {
            if (cur->next[c - 'a'] == NULL) {
                return false;
            }
            cur = cur->next[c - 'a'];
        }
        return cur != NULL;
    }
};
// Runtime: 48 ms, faster than 79.85% of C++ online submissions for Implement Trie (Prefix Tree).