#include<set>
#include<iostream>

using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
	set<ListNode*> checkSet;
	while (pHead1 != nullptr) {
		checkSet.insert(pHead1);
		pHead1 = pHead1->next;
	}
	while (pHead2 != nullptr) {
		if (checkSet.count(pHead2)) {
			return pHead2;
		}
		pHead2 = pHead2->next;
	}
	return nullptr;
}