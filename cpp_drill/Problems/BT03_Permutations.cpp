#include <iostream>
#include <vector>
using namespace std;

// REF : https://leetcode.com/problems/permutations/
// NOTES :
//      Backtrack

// T: O(n! * n) n -> array lenght & n! is number of permutations
// S: O(n) stack lenght

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        dfs(cur, result, nums);
        return result;
    }

    void dfs(vector<int>& cur, vector<vector<int>>& result, vector<int>& nums) {

        if (cur.size() == nums.size()) {
            result.push_back(cur);
            return;
        }

        for (auto num : nums) {

            // if element is present in the cur then skip it
            if (find(cur.begin(), cur.end(), num) != cur.end())
                continue;

            cur.push_back(num);
            dfs(cur, result, nums);
            cur.pop_back();
        }
    }
};