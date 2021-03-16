#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = dp[i - 1][0] + triangle[i][0];
        for (int j = 1; j < i; ++j) {
            /*
                此时的dp[i][j - 1]没用
                因此要想走到位置 (i, j)，上一步就只能在位置(i−1,j−1) 或者位置(i−1,j)
            */
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
        }
        dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
    }
    return *min_element(dp[n - 1].begin(), dp[n - 1].end());
}