# REF : https://leetcode.com/problems/group-anagrams/
# NOTES :
#       Hash map -> counts : strings

# T: O()
# S: O()

from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        hashmap = defaultdict(list)
        for s in strs:
            count = [0] * 26
            for c in s:
                count[ord(c) - ord('a')] += 1
            hashmap[tuple(count)].append(s)
        return hashmap.values()


def main():
    print("output : {}".format(Solution().groupAnagrams(["eat","tea","tan","ate","nat","bat"])))

if __name__ == "__main__":
    main()