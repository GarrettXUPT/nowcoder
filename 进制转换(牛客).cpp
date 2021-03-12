#include<iostream>
#include<vector>

using namespace std;

string solve(int M, int N) {
    // write code here
    if (M == 0) return "0";
    string table = "0123456789ABCDEF";
    string ret = "";
    bool flag = true;  // ��ʾ����
    // ��MΪ����ʱ����������λ��Ȼ�󽫸���ת��Ϊ������Ϊ��������������
    if (M < 0) {
        flag = false;
        M = -M;
    }
    while (M) {
        ret += table[M % N];
        M /= N;
    }
    if (flag == false) ret += "-";
    reverse(ret.begin(), ret.end());
    return ret;
}