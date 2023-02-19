// REF : https://leetcode.com/problems/valid-palindrome-iii/description/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    vector<vector<int>> memo;
public:
    int __dfs(string &s, int i, int j) {
        if (i == j)
            return 0;

        if (i == j - 1)
            return s[i] != s[j];

        if (memo[i][j] != -1)
            return memo[i][j];

        if (s[i] == s[j])
            return memo[i][j] = __dfs(s, i + 1, j - 1);
        else
            return memo[i][j] = 1 + min(__dfs(s, i + 1, j), __dfs(s, i, j - 1));
    }

    bool isValidPalindrome(string s, int k) {
        memo.resize(s.length(), vector<int>(s.length(), -1));
        return __dfs(s, 0, s.length() - 1) <= k;
    }
};


int main() {
    string s = "abcdeca";
    int k = 2;
    cout << "output : " << Solution().isValidPalindrome(s, k) << endl;
    return 0;
}