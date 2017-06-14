// LC 123, best time to buy and sell stock 3
// Say you have an array for which the ith element is the price of a given stock on day i.
// Design an algorithm to find the maximum profit. You may complete at most two transactions.
// one transaction: a buy and a sell
// dp
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// TODO
int maxProfit(vector<int>& prices) {
    // f[k, i] represents the max profit up until prices[i] (Note: NOT ending with prices[i]) using at most k transactions. 
    // f[k, i] = max(f[k, i-1], prices[i] - prices[jj] + f[k-1, jj]) { jj in range of [0, i-1] }
    //          = max(f[k, i-1], prices[i] + max(f[k-1, jj] - prices[jj]))
    // f[0, i] = 0; 0 times transation makes 0 profit
    // f[k, 0] = 0; if there is only one price data point you can't make any money no matter how many times you can trade
    if (prices.size() <= 1) return 0;
    else {
        int K = 2; // number of max transation allowed
        int maxProf = 0;
        vector<vector<int>> f(K+1, vector<int>(prices.size(), 0));
        for (int kk = 1; kk <= K; kk++) {
            int tmpMax = f[kk-1][0] - prices[0];
            for (int i = 1; i < prices.size(); i++) {
                f[kk][i] = max(f[kk][i-1], prices[i] + tmpMax);
                tmpMax = max(tmpMax, f[kk-1][i] - prices[i]);
                // update global max profit
                maxProf = max(f[kk][i], maxProf);
            }
        }
        return maxProf;
    }
}
int main() {
    vector<int> pricesList = {
        {2,1,2,0,1} // 2-1 + (1-0)
        // {2,3,1,4,5};  // 4
    };
    int exp = 2;
    int res = maxProfit(prices);
    printf("res = %d\n", res);
    assert(res == exp);
    return 0;
}
