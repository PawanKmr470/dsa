# REF : https://leetcode.com/problems/meeting-rooms/
# NOTES:
#       Sort the intervals list with start time
#       In loop, keep checking if prev meeting's end time is not greater than
#       current meeting's start time

# T: O(nlogn)
# S: O(1)

class Solution:
    def canAttendMeetings(self, intervals: list[list[int]]) -> bool:
        if not intervals:
            return False

        intervals.sort()
        prev_end = intervals[0][1]
        for i in range(1,len(intervals)):
            cur_start = intervals[i][0]
            if cur_start < prev_end:
                return False
        return True


def main():
    # intervals = [[7,10],[2,4]]  # True
    intervals = [[0,30],[5,10],[15,20]]  # False
    print("can attend all meetings : {}".format(Solution().canAttendMeetings(intervals)))

if __name__ == "__main__":
    main()