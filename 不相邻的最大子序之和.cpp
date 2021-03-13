#include<iostream>
#include<vector>

using namespace std;

long long subsequence(int n, vector<int>& array) {
    // write code here
    int dpi = 0, dp1 = 0, dp2 = 0;
    for (int i = 0; i < n; ++i) {
        dpi = max(dp1, array[i] + dp2);
        dp2 = dp1;
        dp1 = dpi;
    }
    return dpi;
}