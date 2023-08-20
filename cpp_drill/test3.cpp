#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> mypair;

// Max Heap
// class comp {
//     public:
//         bool operator() (const mypair& a, const mypair& b) {
// 		    return a.second < b.second;
//             // return a.first < b.first;
//         }
// };

struct comp {
    bool operator() (const mypair& a, const mypair& b) {
        return a.second < b.second;
    }
};

int main() {
    priority_queue<mypair, vector<mypair>, comp> pq;
    pq.push({20, 200});
    pq.push({30, 300});
    pq.push({40, 400});
    pq.push({10, 100});
    
    while (!pq.empty()) {
        mypair val = pq.top(); pq.pop();
        cout << val.second << endl;
    }
}