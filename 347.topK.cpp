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

// unordered_map + prioriry_queue: O(n log(n - k))
// e.g. find top 2 frequent from 100 items, queue size: 98

// bucket sort: O(n)
// if top 1 or 2?  linear search... O(n)
vector<int> topKFrequent(vector<int>& nums, int k) {
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
    while (k > 0) { 
        res.push_back(pq.top().second); pq.pop(); 
        k--; 
    }
    return res;
}

vector<int> topK_q(vector<int>& nums, int k) {
    vector<int> res(k);
    unordered_map<int, int> cnt;
    for (int num : nums) cnt[num]++;

    auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2){
        return p1.second > p2.second;   // need to find most freq
    };
    priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(cmp)> q(cmp);
    for (auto it = cnt.begin(); it != cnt.end(); ++it) {
        if (q.size() < k) {
            q.push(make_pair(it->first, it->second));
        }
        else {
            if (it->second > q.top().second) {
                q.pop();
                q.push(make_pair(it->first, it->second));
            }
        }
    }
    for (int i = k - 1; i >= 0; i--) {
        res[i] = q.top().first; // add val
        q.pop();
    }
    return res;
}

void print(const vector<int> &v) {
    for (int it : v) printf("%d ", it);
    printf("\n");
}

int main() {
    vector<int> nums = {1,1,1,2,2,3,4, 5,5,5,5};
    int k = 2;
    vector<int> res = topK_q(nums, k); //topKFrequent(nums, k);
    print(res);
    assert(res == (vector<int> {5, 1}));
}
