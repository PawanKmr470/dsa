# REF : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/solution/
# NOTES :
#       In rotated sorted array, min element will always be present in unsorted part of array

# T: O(logn)
# S: O(1)

class Solution:
    def findMin(self, nums: list[int]) -> int:
        N = len(nums)
        start = 0
        end = len(nums) - 1

        while start <= end:

            if nums[start] <= nums[end]: return nums[start]

            mid = (start + end) // 2
            next = (mid + 1) % N
            prev = (mid - 1 + N) % N

            if nums[mid] <= nums[prev] and nums[mid] <= nums[next]:
                return nums[mid]
            elif nums[start] <= nums[mid]:
                start = mid + 1
            elif nums[mid] <= nums[end]:
                end = mid - 1

        return -1


def main():
    print("output : {}".format(Solution().findMin([4,5,6,7,0,1,2])))

if __name__ == "__main__":
    main()