#include<iostream>
#include<stack>

using namespace std;

bool isValid(string s) {
    int minFlag = ')' + '('; int midFlag = ']' + '['; int maxFlag = '}' + '{';

    stack<char> stak;
    const char* ch = s.c_str();
    while (*ch != '\0') {
        stak.push(*ch);
        ch++;
    }


    if (stak.size() % 2 != 0) {
        return false;
    }
    stack<char> stak2;
    while (!stak.empty()) {
        int top = stak.top();
        if ((top == ')') || (top == ']') || (top == '}')) {
            stak2.push(top);
            stak.pop();
        }
        else if ((top == '(') || (top == '[') || (top == '{'))
        {
            if (!stak2.empty()) {
                int judge = stak2.top() + top;
                if ((judge == minFlag) || (judge == midFlag) || (judge == maxFlag)) {
                    stak2.pop();
                    stak.pop();
                }
                else {
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    if (stak.size() != stak2.size()) {
        return false;
    }
    while (!stak.empty()) {
        int judge = stak.top() + stak2.top();
        if ((judge == minFlag) || (judge == midFlag) || (judge == maxFlag)) {
            stak.pop(); stak2.pop();
        }
        else {
            return false;
        }
    }
    return true;
}

int main() {
    cout << isValid("[]") << endl;
    return 0;
}