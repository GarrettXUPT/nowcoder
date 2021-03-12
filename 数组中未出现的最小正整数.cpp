#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minNumberdisappered(vector<int>& arr) {
    // write code here
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] < 0) {
            continue;
        }   
        if (arr[i] > 0 && i >= 1 && arr[i] - arr[i - 1] != 1) {
            return arr[i] - 1;
        }
        else if (arr[i] > 0 && i == 0 && arr[i] != 1) {
            return arr[i] - 1;
        }
    }
    return arr[arr.size() - 1] + 1;
}