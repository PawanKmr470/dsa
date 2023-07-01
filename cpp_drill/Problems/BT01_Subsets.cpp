#include <iostream>
#include <vector>
using namespace std;

// REF : https://leetcode.com/problems/subsets/description/
// NOTES :
//      Bruteforce way : cascading
//          [1] --> [], [1] & [1,2] --> [], [1], [2], [1,2] Here [], [1] is common
//          only 2 is being added into [], [1] to get [2], [1,2].
//      Another approach : Backtracking
//          Where each ith element is included or excluded from the given array
//          to form a subset. Draw the decision tree.

// T: O(n*2^n)
//      2^N subsets will be generated.
//      while generating each subset we have to copy one of the previous subset
// S: O(n*2^n)
//      we have to store 2^N subsets in ans each of size O(N)

// Cascading
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        // Added one empty set {} already as it always going to be present as first subset.
        vector<vector<int>> result = {{}}; // or do result.push_back({}) later.

        int n = nums.size();
        for (int i=0; i<n ; i++) {

            // we need to pick each subset from the result & add element in each subset
            // hence run the loop for result.size() times
            int size = result.size();
            for (int j = 0; j < size; j++) {
                vector<int> temp = result[j];   // take the subset from the result into temp
                temp.push_back(nums[i]);        // add the element into temp
                result.push_back(temp);         // add back temp to result
            }
        }
        return result;
    }
};

// Backtracking
class Solution1 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;

        dfs(0, subset, nums, result);
        return result;
    }

    void dfs(int i, vector<int>& subset, vector<int>& nums, vector<vector<int>>& result) {

        if (i >= nums.size()) {
            result.push_back(subset);
            return;
        }

        // including the ith element
        subset.push_back(nums[i]);
        dfs(i+1, subset, nums, result);

        // excluding the ith element
        subset.pop_back();
        dfs(i+1, subset, nums, result);
    }
};

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> result = Solution().subsets(nums);
    for (auto &i : result) {
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}