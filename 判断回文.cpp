#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool judge(string str) {
    // write code here
    if (str.empty() || str.size() == 1) {
        return true;
    }
    auto begin = str.begin();
    auto rbegin = str.rbegin();
    int len = str.size();
    int pos = len % 2 == 1 ? (len / 2) + 1 : len / 2;
    for (int i = 0; i < pos; ++i) {
        if (*begin != *rbegin) {
            return false;
        }
    }
    return true;
}