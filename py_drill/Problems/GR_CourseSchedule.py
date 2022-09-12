# DFS to visit every node
# If visited node is encountered again then it's a loop, so return false
# DFS needs to be applied for each node as we want to check for each course
# visited node is removed because when dfs will start from 1 then it will be filled again
# prerequisites adj list is updated once and for all when first iteration is run

# T: O(V + E)
# S: O(V) due to hash set - visited

class Solution:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:

        def dfs(crs):
            if crs in visited:
                return False

            if pre_lists[crs] == []:
                return True

            visited.add(crs)
            for pre in pre_lists[crs]:
                if not dfs(pre):
                    return False

            visited.remove(crs)
            pre_lists[crs] = []
            return True


        pre_lists = { i:[] for i in range(numCourses)}
        for course, pre in prerequisites:
            pre_lists[course].append(pre)

        visited = set()
        for crs in range(numCourses):
            if not dfs(crs):
                return False
        return True


def main():
    print("can finish : {}".format(Solution().canFinish(2, [[1,0]])))

if __name__ == '__main__':
    main()