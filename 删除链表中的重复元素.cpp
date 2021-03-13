#include<iostream>
#include<set>

using namespace std;


struct ListNode {
 	int val;
 	struct ListNode *next;
};
 

ListNode* deleteDuplicates(ListNode* head) {
    // write code here
    if (head == nullptr)return head;
    ListNode* temp = head;
    while (temp->next != nullptr) {
        if (temp->val == temp->next->val) {
            temp->next = temp->next->next;
        }
        else {
            temp = temp->next;
        }
    }
    return head;
}