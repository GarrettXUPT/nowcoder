#include<iostream>
#include<vector>

using namespace std;


string LCS(string str1, string str2) {
    // write code here
    vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1));
    for (int i = 0; i <= str1.size(); ++i) dp[i][0] = 0;
    for (int j = 0; j <= str2.size(); ++j) dp[0][j] = 0;
    int maxLength = 0;
    int end = 0;  // 记录最长子序列最后一个字符的位置
    for (int i = 1; i <= str1.size(); ++i) {
        for (int j = 1; j <= str2.size(); ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = 0;
            }
            if (dp[i][j] >= maxLength) {
                maxLength = dp[i][j];
                end = j;
            }
        }
    }
    if (maxLength == 0) {
        return "-1";
    }
    else {
        return str2.substr(end - maxLength, maxLength);
    }
}


int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    for (int i = 1; i <= text1.size(); i++) {
        for (int j = 1; j <= text2.size(); j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[text1.size()][text2.size()];

}