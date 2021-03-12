#include<iostream>
#include<string>
#include<vector>

using namespace std;

/*
    在对char数组遍历的时候 只能出现一个个数为奇数的字符 所以我们直接记录有多少个字符出现次数为奇数就可以了啊 不用额外判断了
*/


/*
    dp[i][j]是一个bool类型的变量数组，如果dp[i][j]==true,那么他表示字符串str从str[i]到str[j]是回文串

    边界是：dp[i][i]=true,dp[i][i+1]=(str[i]==str[i+1]) ? true , false
    状态转移方程：

    dp[i][j]=true if( dp[i+1][j-1] && str[i]==str[j] )
    dp[i][j]=false if( str[i]!=str[j] )

*/

int getLongestPalindrome(string A, int n) {
    // write code here
    vector<vector<int>> dp(n, vector<int>(n, 0));
    string ans = "";

    //l:字符串首尾字母长度差 (d = j-i)
    for (int l = 0; l < n; ++l) {// 字符串起始位置 i
        for (int i = 0; i + l < n; ++i) {  // 向前的长度
            int j = i + l;// 字符串结束位置 j
            
            if (l == 0) {  // 仅有单个字符
                dp[i][j] = 1;
            }
            else if (l == 1) {  // 两个字符
                dp[i][j] = (A[i] == A[j]);
            }
            else {  // 多个字符
                dp[i][j] = (A[i] == A[j] && dp[i + 1][j - 1]);
            }

            if (dp[i][j] && l + 1 > ans.length()) {  // 当目前长度大于当前记录的最长长度时
                // 更新最大长度
                ans = A.substr(i, l + 1);
            }
        }
    }
    cout << ans << endl;
    return ans.length();


}