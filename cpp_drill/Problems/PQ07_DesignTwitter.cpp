#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

// REF : https://leetcode.com/problems/design-twitter/
// NOTES :
//      It's getNewsFeed is based on "Merge K-Sorted Lists/Arrays" Logic.
//      Instead of k-sorted lists here we have 10 followers newsfeed.
//      Max Heap application

// T: 
// S: 

class Twitter {
private:
    unordered_map<int, unordered_set<int>> followerMap;
    unordered_map<int, list<pair<int, int>>> tweetMap;
    int time;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        if (tweetMap.find(userId) == tweetMap.end()) return result;

        followerMap[userId].insert(userId);
        priority_queue<pair<int, pair<int, int>>> maxHeap;   // time, {tweet, fo}

        for (auto &follower : followerMap[userId]) {
            if (tweetMap.find(follower) != tweetMap.end()) {
                pair<int, int> time_n_tweet = tweetMap[follower].back();
                tweetMap[follower].pop_back();
                maxHeap.push({time_n_tweet.first, {time_n_tweet.second, follower}});
            }
        }

        while (!maxHeap.empty() && result.size() < 10) {
            pair<int, pair<int, int>> n = maxHeap.top(); maxHeap.pop();
            result.push_back(n.second.first);
            if (maxHeap.size() < 10) {
                // push
                if (tweetMap[n.second.second].size() > 0) {
                    pair<int, int> x = tweetMap[n.second.second].back();
                    tweetMap[n.second.second].pop_back();
                    maxHeap.push({x.first, {x.second, n.second.second}});
                }
            }
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        followerMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followerMap[followerId].erase(followeeId);
    }
};