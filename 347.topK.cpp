// LC 347, find top k frequent elements in an array using priority queue
// 4/12/2017

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cassert>
using namespace std;

void printQ(priority_queue<pair<int, int> > pq) {
    printf("(freq, item)\n");
    while (!pq.empty()) {
        int freq = pq.top().first;
        int val = pq.top().second;
        pq.pop();
        printf("(%d:%d), ", freq, val);
    }
    printf("\n");
}

vector<int> topKFrequent(const vector<int> &nums, int k) {
    vector<int> res;
    unordered_map<int, int> map;
    for (int num : nums) map[num]++;
    priority_queue<pair<int, int> > pq;
    for (auto it = map.begin(); it != map.end(); it++) {
       // {freq, item}
       pq.push(make_pair(it->second, it->first)); 
       printf("(%d: %d) added\n", it->second, it->first);

       // if add items to result now, the order will not be kept
//       if (pq.size() > map.size() - k) {
//            res.push_back(pq.top().second);
//            pq.pop(); 
//       }
    }
    printQ(pq);
    while (k > 0) { res.push_back(pq.top().second); pq.pop(); k--; }
    return res;
}

void print(const vector<int> &v) {
    for (int it : v) printf("%d ", it);
    printf("\n");
}

int main() {
    vector<int> nums = {1,1,1,2,2,3,4, 5,5,5,5};
    int k = 2;
    vector<int> res = topKFrequent(nums, k);
    print(res);
    assert(res == (vector<int> {5, 1}));
}
