#include<iostream>
#include<deque>

using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
};
 

bool isPail(ListNode* head) {
    // write code here
    deque<int> dq;
    while (head != nullptr) {
        dq.push_back(head->val);
        head = head->next;
    }
    
    while (!dq.empty()) {
        if (dq.front() != dq.back()) {
            return false;
        }
        else
        {
            dq.pop_back();
            dq.pop_front();
        }
    }
    return true;
}