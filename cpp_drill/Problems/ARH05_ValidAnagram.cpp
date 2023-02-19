// REF : https://leetcode.com/problems/valid-anagram/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        unordered_map<char, int> countS;
        unordered_map<char, int> countT;

        for (int i = 0; i < s.size(); i++) {
            countS[s[i]]++;
            countT[t[i]]++;
        }

        for (auto &[key, value] : countS) {
            try {
                if (value != countT.at(key))    // try catch this countT could raise exception
                    return false;
            }
            catch(const exception& e) {
                cerr << e.what() << '\n';
                return false;
            }
        }

        return true;
    }
};

class Solution2 {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        unordered_map<char, int> hashmap;

        for (int i = 0; i < s.size(); i++) {
            hashmap[s[i]]++;
            hashmap[t[i]]--;
        }

        for (auto &[key, value] : hashmap) {
            if (value != 0)
                return false;
        }

        return true;
    }
};

int main() {
    cout << "hello" << endl;
    cout << "output : " << Solution().isAnagram("anagram", "nagaram") << endl;
    cout << "output : " << Solution2().isAnagram("anagram", "nagaram") << endl;
    return 0;
}