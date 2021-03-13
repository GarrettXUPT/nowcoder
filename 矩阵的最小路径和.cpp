#include<iostream>
#include<vector>

using namespace std;

int minPathSum(vector<vector<int> >& matrix) {
    // write code here
    if (matrix.empty()) {
        return 0;
    }
    int m = matrix.size(); int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = matrix[0][0];
    for (int i = 1; i < m; ++i) {
        dp[i][0] = dp[i - 1][0] + matrix[i][0];
    }
    for (int i = 1; i < n; ++i) {
        dp[0][i] = dp[0][i - 1] + matrix[0][i];
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m - 1][n - 1];
}