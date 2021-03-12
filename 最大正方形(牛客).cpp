#include<iostream>
#include<vector>

using namespace std;

int solve(vector<vector<char> >& matrix) {
    // write code here
    int row = matrix.size(); int col = matrix[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));
    for (int i = 0; i < row; ++i) {
        if (matrix[i][0] == '1') {
            dp[i][0] = 1;
        }
    }
    for (int j = 0; j < col; ++j) {
        if (matrix[0][j] == '1') {
            dp[0][j] = 1;
        }
    }
    int MaxLeng = 0;
    for (int i = 1; i < row; ++i) {
        for (int j = 1; j < col; ++j) {
            if (matrix[i][j] == '1') {
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }
            if (MaxLeng < dp[i][j]) {
                MaxLeng = dp[i][j];
            }
        }
    }
    return MaxLeng * MaxLeng;

}
