#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    // write code here
    int profit = 0; int minPrice = 1e9;
    for (auto& price : prices) {
        profit = max(profit, price - minPrice);
        minPrice = min(minPrice, price);
    }
    return profit;
}