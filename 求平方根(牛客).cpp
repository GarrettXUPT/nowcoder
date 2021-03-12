#include<iostream>

using namespace std;

int sqrt(int x) {
    // write code here
    if(x <= 0) return 0;
    int i = 1;
    for (i = 1; i <= x; i++) {
        if (i * i <= x && (i + 1) * (i + 1) > x) {
            break;
        }
    }
    return i;
}