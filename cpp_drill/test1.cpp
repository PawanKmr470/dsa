#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp (pair<int, pair<int,char>>& x, pair<int, pair<int,char>>& y) {
    return x.second.second < y.second.second;
}

int main() {
    
    vector<pair<int, pair<int,char>>> l;
    l.push_back({2, {802, 'a'}});
    l.push_back({1, {901, 'b'}});
    l.push_back({3, {703, 'c'}});
    
    sort(l.begin(), l.end(), comp);
    
    for (auto &x : l) {
        cout << x.first << " " << x.second.first << " " << x.second.second << endl;
    }

    return 0;
}