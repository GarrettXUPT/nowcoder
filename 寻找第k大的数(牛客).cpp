#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findKth(vector<int> a, int n, int K) {
    // write code here
    sort(a.begin(), a.end(), [](int val1, int val2) {return val1 > val2; });
    return a[K - 1];
}