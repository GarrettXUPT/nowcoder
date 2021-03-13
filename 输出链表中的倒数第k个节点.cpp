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
    // 首次遍历链表,前面的指针先走k步
    ListNode* first = pHead;
    for (int i = 0; i < k; ++i) {
        first = first->next;
        if (first->next == nullptr) {
            return pHead;
        }
    }
    ListNode* second = pHead;
    // 二次遍历链表，然后后面的指针从头开始走，若是前面的指针走到头，那么第二个指针的下一个就是所求指针
    while (first != nullptr && first->next != nullptr) {
        first = first->next;
        second = second->next;
    }
    return second->next;
}
 