#include<iostream>

using namespace std;


struct ListNode {
 	int val;
 	struct ListNode *next;
 	ListNode(int x) : val(x), next(nullptr) {}
  };

ListNode* FindKthToTail(ListNode* pHead, int k) {
    // write code here
    if (pHead == nullptr || k < 0) {
        return pHead;
    }
    ListNode* countNode = pHead;
    int count = 0;
    while (countNode && countNode->next) {
        count++;
        countNode = countNode->next;
    }

    if (k > count) {
        return nullptr;
    }    
    // �״α�������,ǰ���ָ������k��
    ListNode* first = pHead;
    for (int i = 0; i < k; ++i) {
        first = first->next;
        if (first->next == nullptr) {
            return pHead;
        }
    }
    ListNode* second = pHead;
    // ���α�������Ȼ������ָ���ͷ��ʼ�ߣ�����ǰ���ָ���ߵ�ͷ����ô�ڶ���ָ�����һ����������ָ��
    while (first != nullptr && first->next != nullptr) {
        first = first->next;
        second = second->next;
    }
    return second->next;
}
 