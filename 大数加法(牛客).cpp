#include<iostream>

using namespace std;

string solve(string s, string t) {
    // write code here
    reverse(s.begin(), s.end()); reverse(t.begin(), t.end());
    int carry = 0;
    const char* ch1 = s.c_str(); const char* ch2 = t.c_str();
    string resStr;
    while (*ch1 != '\0' && *ch2 != '\0') {
        int tmp = (*ch1 - '0') + (*ch2 - '0') + carry;
        resStr.push_back(((tmp % 10) + '0'));
        carry = (tmp / 10);
        ch1++; ch2++;
    }
    const char* ch = *ch1 == '\0' ? ch2 : ch1;
    while (*ch != '\0') {
        int tmp = *ch - '0' + carry;
        resStr.push_back(((tmp % 10) + '0'));
        carry = (tmp / 10);
        ch++;
    }
    if (carry != 0) {
        resStr.push_back((carry + '0'));
        carry = 0;
    }
    reverse(resStr.begin(), resStr.end());
    return resStr;
}

int main() {
    cout << solve("1", "99") << endl;
    return 0;
}