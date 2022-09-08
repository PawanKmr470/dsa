#include <iostream>
#include <vector>
using namespace std;

/*
Brute force method - Recursion
T - O(2^n)
S - O(2^n)
*/
class Solution1 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return min(stairs(cost, 0), stairs(cost, 1));
    }
    int stairs(vector<int> &cost, int i) {
        if (i >= cost.size()) return 0;
        return cost[i] + min(stairs(cost, i + 1), stairs(cost, i + 2));
    }
};

/*
Memoization method - Recursion
T - O(n)
S - O(n)
*/
class Solution2 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp (cost.size(), 0);
        return min(stairs(cost, 0, dp), stairs(cost, 1, dp));
    }
    int stairs(vector<int> &cost, int i, vector<int> &dp) {
        if (i >= cost.size()) return 0;
        if (dp[i]) return dp[i];
        dp[i] = cost[i] + min(stairs(cost, i + 1, dp), stairs(cost, i + 2, dp));
        return dp[i];
    }
};

/*
Tabulation Method
T - O(n)
S - O(n)
*/
class Solution3 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 2) return min(cost[0], cost[1]);
        int n = cost.size();
        vector<int> dp (n + 1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[n - 1], dp[n - 2]);
        // for (int i = 2; i <= n; i++) {
        //     dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        // }
        // return dp[n - 1];
    }
};

/*
Tabulation Method
T - O(n)
S - O(1)
*/
class Solution4 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 2) return min(cost[0], cost[1]);
        int n = cost.size();
        int first = cost[0];
        int second = cost[1];
        for (int i = 2; i < n; i++) {
            int cur = cost[i] + min(first, second);
            first = second;
            second = cur;
        }
        return min(first, second);
    }
};

int main() {
    //vector<int> cost = {10, 15, 20};
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    int result;
    
    Solution1 s1;
    result = s1.minCostClimbingStairs(cost);
    cout << "Min cost is : " << result << endl;

    Solution1 s2;
    result = s2.minCostClimbingStairs(cost);
    cout << "Min cost is : " << result << endl;

    Solution1 s3;
    result = s3.minCostClimbingStairs(cost);
    cout << "Min cost is : " << result << endl;

    Solution1 s4;
    result = s4.minCostClimbingStairs(cost);
    cout << "Min cost is : " << result << endl;

    return 0;
}