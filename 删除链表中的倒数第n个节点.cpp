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
        ɾ��ͷ�ڵ�
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
        �����ɾ������ǰһ���ڵ�
    */
    for (int i = 0; i < pos; ++i) {
        tmphead = tmphead->next;
    }
    /*
    *   �Ƿ�Ϊ���һ���ڵ�
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