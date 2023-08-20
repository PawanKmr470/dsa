#include <iostream>
#include <vector>
using namespace std;

// REF : https://leetcode.com/problems/target-sum/editorial/
// NOTES :
//      Target sum --> Same as DP10 - Count number of subset sum with given diff
//      Edge case : arr = [1,1,1] target = -700 --> not possible
//                  so abs(target) won't exceed sum value. So, abs(target) <= sum

// T: O(2^n)
// S: O(n) stack lenght
class Solution {
public:
    int targetSum(vector<int> &set, int target) {
        int sum = 0;
        for (auto &i : set)
            sum += i;

        if (target > sum || (sum - target) % 2 != 0)    // sum - target ??
            return 0;                                   // instead sum + target % 2 != 0 also works
                                                        // bcz if it's not divisible then return 0
        int s1 = (sum + target)/2;
        return __subsetSum(set, s1, set.size());
    }

    int __subsetSum(vector<int> &set, int sum, int n) {
        if (sum == 0) return 1;
        if (n == 0 && sum > 0) return 0;

        if (set[n-1] <= sum) {
            return __subsetSum(set, sum - set[n-1], n-1) +
                    __subsetSum(set, sum, n-1);
        }
        else {
            return __subsetSum(set, sum, n-1);
        }
    }
};

// T: O(n*sum)
// S: O(n*sum) including aux space
// Tabulation method
// class Solution2 {
// public:
//     int partitionWithGivenDiff(vector<int> &set, int diff) {
// };

// Leetcode Editorial
// T: O(2^n)
// S: O(n) stack lenght
class Solution2 {
private:
    int count;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        calculate(nums, 0, 0, target);
        return count;
    }

    void calculate(vector<int> &nums, int i, int cur_sum, int target) {
        
        if (i == nums.size()) {     // if we process all the elements
            if (cur_sum == target)  // and cur_sum gets equal to target
                count++;
        }
        else {
            calculate(nums, i + 1, cur_sum + nums[i], target);
            calculate(nums, i + 1, cur_sum - nums[i], target);
        }

    }
};

// Memoization then DP

int main() {
    vector<int> set = {1,1,1,1,1};
    int target = 3;   // Question is calling this as sum
    cout << "Solution  : " << Solution().targetSum(set, target) << endl;
    cout << "Solution2 : " << Solution2().findTargetSumWays(set, target) << endl;
    return 0;
}

