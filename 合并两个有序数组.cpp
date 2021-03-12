#include<iostream>
#include<vector>

using namespace std;

void merge(int A[], int m, int B[], int n) {
    /*
        注意对情况的判断
    */
    if (m == 0) {
        for (int i = 0; i < n; ++i) {
            A[i] = B[i];
        }
        return;
    }
    else if (n == 0) {
        return;
    }
    for (int i = 0; i < n; ++i) {
        A[m + i] = B[i];
    }
    for (int i = 0; i < (m + n - 1); ++i) {
        for (int j = i + 1; j < m + n; ++j) {
            if (A[i] > A[j]) {
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
    }
}