// REF : https://leetcode.com/problems/task-scheduler/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> freq;
        for (auto &ch : tasks)
            freq[ch]++;

        priority_queue<int> maxHeap;
        for (auto &i : freq)
            maxHeap.push(i.second);

        deque<pair<int, int>> q;
        int time = 0;
        
        while ( (!maxHeap.empty()) || (!q.empty()) ) {
            time++;
            if (!maxHeap.empty()) {

                int cnt = maxHeap.top();
                maxHeap.pop();

                cnt--;          // It's not python
                if (cnt != 0)
                    q.push_back(make_pair(cnt, time + n));

            }

            if ( (!q.empty()) && (q.front().second == time) ) {
                int new_freq = q.front().first;
                q.pop_front();
                maxHeap.push(new_freq);
            }
        }
        return time;
    }
};


int main() {
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;
    cout << "output : " << Solution().leastInterval(tasks, n) << endl;
    return 0;
}