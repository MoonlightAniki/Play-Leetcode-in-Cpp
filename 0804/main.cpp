#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows: "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.
For convenience, the full table for the 26 letters of the English alphabet is given below:
[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter. For example, "cab" can be written as "-.-.-....-", (which is the concatenation "-.-." + "-..." + ".-"). We'll call such a concatenation, the transformation of a word.
Return the number of different transformations among all words we have.

Example:
Input: words = ["gin", "zen", "gig", "msg"]
Output: 2
Explanation:
The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."
There are 2 different transformations, "--...-." and "--...--.".
 */
class Solution {
private :
    vector<string> MORSE_WORDS  = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
                          "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
public:
    int uniqueMorseRepresentations(vector<string> &words) {
        unordered_set<string> record;
        for (const string &str : words) {
            string s;
            for (const char &c : str) {
                s += MORSE_WORDS[c - 'a'];
            }
            record.insert(s);
        }
        return record.size();
    }
};

int main() {
    vector<string> vec{"gin", "zen", "gig", "msg"};
    cout << Solution().uniqueMorseRepresentations(vec) << endl;
    return 0;
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Morse Code Words.