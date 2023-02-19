// REF : https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_set<char> charSet;
        int l = 0;
        for (int r = 0; r < s.length(); r++) {
            while (charSet.find(s[r]) != charSet.end()) {
                charSet.erase(s[l]);
                l++;
            }
            charSet.insert(s[r]);
            res = max(res, r - l + 1);
        }
        return res;
    }
};


int main() {
    string s = "abcabcbb";
    cout << "output : " << Solution().lengthOfLongestSubstring(s) << endl;
    return 0;
}
