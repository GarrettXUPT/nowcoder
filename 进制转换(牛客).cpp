#include<iostream>
#include<vector>

using namespace std;

string solve(int M, int N) {
    // write code here
    if (M == 0) return "0";
    string table = "0123456789ABCDEF";
    string ret = "";
    bool flag = true;  // 表示正数
    // 当M为负数时，拨动符号位，然后将负数转化为正数，为后来处理做打算
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