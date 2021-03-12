#include<iostream>
#include<string>
#include<vector>

using namespace std;

/*
    �ڶ�char���������ʱ�� ֻ�ܳ���һ������Ϊ�������ַ� ��������ֱ�Ӽ�¼�ж��ٸ��ַ����ִ���Ϊ�����Ϳ����˰� ���ö����ж���
*/


/*
    dp[i][j]��һ��bool���͵ı������飬���dp[i][j]==true,��ô����ʾ�ַ���str��str[i]��str[j]�ǻ��Ĵ�

    �߽��ǣ�dp[i][i]=true,dp[i][i+1]=(str[i]==str[i+1]) ? true , false
    ״̬ת�Ʒ��̣�

    dp[i][j]=true if( dp[i+1][j-1] && str[i]==str[j] )
    dp[i][j]=false if( str[i]!=str[j] )

*/

int getLongestPalindrome(string A, int n) {
    // write code here
    vector<vector<int>> dp(n, vector<int>(n, 0));
    string ans = "";

    //l:�ַ�����β��ĸ���Ȳ� (d = j-i)
    for (int l = 0; l < n; ++l) {// �ַ�����ʼλ�� i
        for (int i = 0; i + l < n; ++i) {  // ��ǰ�ĳ���
            int j = i + l;// �ַ�������λ�� j
            
            if (l == 0) {  // ���е����ַ�
                dp[i][j] = 1;
            }
            else if (l == 1) {  // �����ַ�
                dp[i][j] = (A[i] == A[j]);
            }
            else {  // ����ַ�
                dp[i][j] = (A[i] == A[j] && dp[i + 1][j - 1]);
            }

            if (dp[i][j] && l + 1 > ans.length()) {  // ��Ŀǰ���ȴ��ڵ�ǰ��¼�������ʱ
                // ������󳤶�
                ans = A.substr(i, l + 1);
            }
        }
    }
    cout << ans << endl;
    return ans.length();


}