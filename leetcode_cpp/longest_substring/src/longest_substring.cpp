#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, bool> hash_table;
        int count = 0, max = 1;
        if (s.length() == 0) max = 0;
        for (unsigned int i = 0; i < s.length(); i++) {
            if (hash_table[s[i]] == true) {
                if (count >= max) {
                    max = count;
                }
                hash_table.clear();
                hash_table[s[i]] = true;
                count -= 1;
            }
            else
            {
                hash_table[s[i]] = true;
                if (++count >= max) {
                    max = count;
                }
            }
        }
        return max;
    }
};

void main() {
    Solution solution;
    string test = "dbvdfa";
    cout << "The longest length of " << test << ": " << solution.lengthOfLongestSubstring(test) << endl;
}