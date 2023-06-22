#include <iostream>
#include <queue>
using namespace std;

// REF : https://leetcode.com/problems/kth-largest-element-in-an-array/description/
// NOTES :
//      Brute force way will be sort the array in descending order & return k-1 element (O(nlogn)).
//      Efficient approach will be use of Min Heap.
//      Min Heap of size k. Keep filling the elements and at last return the top element.
//      pushing k elements into Min Heap -> O(n*logk)

// T: O(n*logk)
// S: O(k)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto &i : nums) {
            minHeap.push(i);
            if (minHeap.size() > k)
                minHeap.pop();
        }
        return minHeap.top();
    }
};

int main() {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout << Solution().findKthLargest(nums, k) << endl;
}