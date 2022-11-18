# REF : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
# NOTES :
#       Brute force is to calculate profit with whole list for each element but that is O(n^2)
#       Sliding window : if selling is low that is the next left ptr, if selling is high
#       that is next right ptr

# T: O(n)
# S: O(1)

class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        l, r = 0, 1
        max_profit = 0
        while r < len(prices):
            if prices[l] < prices[r]:
                profit = prices[r] - prices[l]
                max_profit = max(max_profit, profit)
            else:
                l = r
            r += 1

        return max_profit


def main():
    prices = [7, 1, 5, 3, 6, 4]
    print("output : {}".format(Solution().maxProfit(prices)))

if __name__ == "__main__":
    main()