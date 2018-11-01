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
#include <map>

using namespace std;

class MapSum {

private:
    map<string, int> m;

public:
    /** Initialize your data structure here. */
    MapSum() {
        m.clear();
    }

    void insert(string key, int val) {
        m[key] = val;
    }

    int sum(string prefix) {
        int res = 0;
        for (auto beg = m.lower_bound(prefix), end = m.end(); beg != end; ++beg) {
            if (beg->first == prefix || beg->first.substr(0, prefix.size()) == prefix) {
                res += beg->second;
            }
        }
        return res;
    }
};
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Map Sum Pairs.