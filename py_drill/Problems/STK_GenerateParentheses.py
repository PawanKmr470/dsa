# REF : https://leetcode.com/problems/generate-parentheses/
# NOTES :
#       Stack + DFS + Backtracking
#       if open count == close count == n then it's one of the results
#       if open count < n then we can add "("
#       if close count < open count then we can add ")"

# T: O()
# S: O()

class Solution:
    def generateParenthesis(self, n: int) -> list[str]:

        res = []
        stack = []

        def backtrack(open_cnt, close_cnt):
            if open_cnt == close_cnt == n:
                res.append("".join(stack))
                return

            if open_cnt < n:
                stack.append("(")
                backtrack(open_cnt + 1, close_cnt)
                stack.pop()     # Need to pop the same element that we added

            if close_cnt < open_cnt:
                stack.append(")")
                backtrack(open_cnt, close_cnt + 1)
                stack.pop()     # Need to pop the same element that we added

        backtrack(0, 0)
        return res

def main():
    print(Solution().generateParenthesis(3))

if __name__ == "__main__":
    main()