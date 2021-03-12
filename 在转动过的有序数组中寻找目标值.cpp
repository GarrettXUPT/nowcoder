#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

int search(vector<int> A, int target) {
    return -1;
}

int search(int* A, int len, int target) {
    vector<int> vec;
    for (int i = 0; i < len; ++i) {
        if (*A == target) {
            return i;
        }
        vec.push_back(*A);
        A++;
    }
    return search(vec, target);;
}