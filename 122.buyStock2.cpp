// LC 122, best time to buy and sell stock 2
// Say you have an array for which the ith element is the price of a given stock on day i.
// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
// greedy
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    int total = 0;
    for (int i = 0; i < prices.size() - 1; i++) {
        if (prices[i + 1] - prices[i] > 0) {
            total += (prices[i + 1] - prices[i]);
        }
    }
    return total;
}
int main() {
    vector<int> prices = {2,3,1,4,5};   // 1 + 3 + 1
    int exp = 5;
    int res = maxProfit(prices);
    printf("res = %d\n", res);
    assert(res == exp);
    return 0;
}
