// REF : https://leetcode.com/problems/top-k-frequent-elements/description/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }
        vector<vector<int>> freq(nums.size());
        for (auto &i : count) {
            freq[i.second].push_back(i.first);
        }

        vector<int> res;
        for (int i = freq.size()-1; i > 0; i--) {
            for (int j = 0; j < freq[i].size(); j++) {
                res.push_back(freq[i][j]);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};


int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> ans;
    ans = Solution().topKFrequent(nums, k);
    for (auto &i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}