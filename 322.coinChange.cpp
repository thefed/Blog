// LC 322, coin change
// find the min num of coins needed to get the given total amount, with different denominations of coins,
// each coin can be used more than once
// return -1 if no such way to get the given amount
// [1 2 5], 11 => return 3 (5 + 5 + 1 = 11)
// [2], 3 => return -1
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// dp, O(kn), k: num of coins, n: amount
int coinChange(vector<int>& coins, int amount) {
    const int& n = amount;
    vector<int> minCoins(n + 1, INT_MAX);
    minCoins[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < coins.size(); j++) { // try each coin
            if (i >= coins[j] && minCoins[i - coins[j]] != INT_MAX) {
                minCoins[i] = min(minCoins[i], minCoins[i - coins[j]] + 1);    
            }
        }
    }
    return minCoins[n] == INT_MAX ? -1 : minCoins[n];
}

int main() {
    vector<vector<int>> coinsList = {{1,2,5},{2}};
    vector<int> amounts = {11, 3};
    vector<int> exps = {3, -1};
    for (int i = 0; i < coinsList.size(); i++) {
        int res = coinChange(coinsList[i], amounts[i]);
        assert(res == exps[i]);
    }
    return 0;
}