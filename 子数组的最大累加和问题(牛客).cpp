#include<iostream>
#include<vector>

using namespace std;

int maxsumofSubarray(vector<int>& arr) {
    if (arr.empty()) {
        return 0;
    }
    else if (arr.size() == 1) {
        return arr[0];
    }
    int m = 0; // 保存最大累加和
    for (int i = 1; i < arr.size(); i++)
    {
        arr[i] = max(arr[i], arr[i - 1] + arr[i]);
        m = max(m, arr[i]);
    }
    return m;
}