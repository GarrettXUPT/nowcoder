#include<iostream>
#include<vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 

/*
    线性表解决问题
*/

void reorderList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    vector<ListNode*> NodeVec;
    ListNode* tmphead = head;
    while (tmphead) {
        NodeVec.push_back(tmphead);
        tmphead = tmphead->next;
    }
    int i = 0, j = NodeVec.size() - 1;
    while (i < j) {
        NodeVec[i]->next = NodeVec[j];
        i++;
        if (i == j) break;
        NodeVec[j]->next = NodeVec[i];
        j--;
    }
    NodeVec[i]->next = nullptr;
}