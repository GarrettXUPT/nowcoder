#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int> a) {
    // write code here
    int len = a.size();
    int i;
    for (i = 0; i < len; ++i) {
        if (a[i] != i) {
            break;
        }
    }
    return i;
}