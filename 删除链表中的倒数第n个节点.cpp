#include<iostream>

using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
};
 


ListNode* removeNthFromEnd(ListNode* head, int n) {
    // write code here
    ListNode* countNode = head;
    int count = 0;
    while (countNode) {
        count++;
        countNode = countNode->next;
    }
    /*
        删除头节点
    */
    if (count == n) {
        ListNode* tmpNode = head;
        head = head->next;
        delete tmpNode;
        return head;
    }
    int pos = count - n - 1;
    ListNode* tmphead = head;
    /*
        到达待删除结点的前一个节点
    */
    for (int i = 0; i < pos; ++i) {
        tmphead = tmphead->next;
    }
    /*
    *   是否为最后一个节点
    */
    if (tmphead->next) {
        tmphead->next = tmphead->next->next;
    }
    else
    {
        tmphead = tmphead->next;
    }
    return head;
}