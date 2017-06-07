// LC 121, find best time to buy and sell stock, return max profit
// if no profit, return 0
// given array prices, prices[i]: stock price on day[i]
// Input: [7, 1, 5, 3, 6, 4]
// Output: 5
// max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)

// Input: [7, 6, 4, 3, 1]
// Output: 0
// In this case, no transaction is done, i.e. max profit = 0.

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
// in [7, 1, 5, 3, 6, 4]
// pro 0  0  4  2  5  3
// min 7  1  1  1  1  1

int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    int maxVal = 0;     // max profit value
    
    int minPrice = prices[0];
    
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }
        else {
            maxVal = max(maxVal, prices[i] - minPrice);
        }
    }
    return maxVal;
}
int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int res = maxProfit(prices);
    printf("res = %d\n", res);
    assert(res == 5);

    prices = {7, 6, 4, 3, 1};
    res = maxProfit(prices);
    printf("res = %d\n", res);
    assert(res == 0);
    return 0;
}