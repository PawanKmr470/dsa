#include <iostream>
#include <vector>
using namespace std;

// REF : https://leetcode.com/problems/subsets-ii/
// NOTES :
//      Backtrack. Subset I problem but with duplicates
//      need to skip duplcates only.

// T: O(n*2^n)
// S: O(n)

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        dfs(0, subset, nums, result);
        return result;
    }

    void dfs(int index, vector<int>& subset,
             vector<int>& nums, vector<vector<int>>& result) {

        result.push_back(subset);

        for (int i=index; i < nums.size(); i++) {

            if (i > index && nums[i] == nums[i-1])
                continue;

            subset.push_back(nums[i]);
            dfs(i+1, subset, nums, result);
            subset.pop_back();
        }
    }
};

class Solution1 {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        sort(nums.begin(), nums.end());     // Need to sort the input array to make the duplicate
        backtrack(0, subset, nums, result); // elements adjacent
        return result;
    }

    void backtrack(int i, vector<int>& subset,
                    vector<int>& nums, vector<vector<int>>& result) {

        if (i >= nums.size()) {
            result.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        backtrack(i+1, subset, nums, result);
        
        subset.pop_back();
        while (i+1 < nums.size() && nums[i] == nums[i+1])   // check boundary condition first
            i++;
        backtrack(i+1, subset, nums, result);
    }
};