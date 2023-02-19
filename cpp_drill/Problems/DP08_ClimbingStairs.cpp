#include <iostream>
#include <vector>
using namespace std;

/*
Basic recursion method
T - O(2^n)
S - O(2^n)
*/
class Solution1 {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

/*
Recursion method with Memoization method
T - O(n)
S - O(n)
*/
class Solution2 {
public:
    int climbStairs(int n) {
        vector<int> vec (n, -1);
        int result = stairs(n, vec);
        return result;
    }

    int stairs(int n, vector<int> &vec) {
        if (n <= 2) {
            return n;
        }
        if (vec[n - 1] != -1) {
            return vec[n - 1];
        }
        vec[n - 1] = stairs(n - 1, vec) + stairs(n - 2, vec);
        return vec[n - 1];
    }
};

/*
Tabulation Method
T - O(n)
S - O(constant)
*/
class Solution3 {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int x = 1;
        int y = 2;
        int temp;
        for (int i = 3; i <= n; i++) {
            temp = y;
            // new y is the sum of prev x and y
            y = y + x;
            // new x is the prev y
            x = temp;
        }
        return y;
    }
};

int main() {
    int result;
    Solution1 s1;
    result = s1.climbStairs(4);
    cout << "No of ways : " << result << endl;

    Solution2 s2;
    result = s2.climbStairs(4);
    cout << "No of ways : " << result << endl;

    Solution3 s3;
    result = s3.climbStairs(4);
    cout << "No of ways : " << result << endl;

    return 0;
}