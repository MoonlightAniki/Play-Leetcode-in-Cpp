// 211. Add and Search Word - Data Structure Design
// https://leetcode.com/problems/add-and-search-word-data-structure-design/
/*
Design a data structure that supports the following two operations:
void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or ..
A . means it can represent any one letter.

Example:
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

Note:
You may assume that all words are consist of lowercase letters a-z.
 */

#include <iostream>
#include <unordered_map>

using namespace std;

class WordDictionary {
private:
    struct Node {
        bool isWord = false;

        unordered_map<char, Node *> next;
    };

    Node *root;

public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node *cur = root;
        for (int i = 0; i < word.size(); ++i) {
            if (cur->next.find(word[i]) == cur->next.end()) {
                cur->next[word[i]] = new Node();
            }
            cur = cur->next[word[i]];
        }
        cur->isWord = true;
    }

//    bool contains(string word) {
//        Node *cur = root;
//        for (int i = 0; i < word.size(); ++i) {
//            if (cur->next.find(word[i]) == cur->next.end()) {
//                return false;
//            }
//            cur = cur->next[word[i]];
//        }
//        return cur->isWord;
//    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(root, word, 0);
    }

private:
    bool search(Node *node, const string &word, int index) {
//        if (node == NULL) {
//            return false;
//        }
//        if (index > word.size()) {
//            return false;
//        }
        if (index == word.size()) {
            return node->isWord;
        }
        if (word[index] == '.') {
            for (auto a : node->next) {
                if (search(a.second, word, index + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            return node->next.find(word[index]) != node->next.end() && search(node->next[word[index]], word, index + 1);
        }

    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

int main() {
    WordDictionary wd = WordDictionary();
    wd.addWord("bad");
    wd.addWord("dad");
    wd.addWord("mad");
    cout << wd.search("pad") << endl;
    cout << wd.search("bad") << endl;
    cout << wd.search(".ad") << endl;
    cout << wd.search("b..") << endl;
    return 0;
}
// Runtime: 72 ms, faster than 56.42% of C++ online submissions for Add and Search Word - Data structure design.