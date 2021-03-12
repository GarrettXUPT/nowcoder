#include<iostream>
#include<vector>

using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int value) : val(value), next(nullptr) {};
};


ListNode* reverseKGroup(ListNode* head, int k) {
	if (head == nullptr || head->next == nullptr || k == 1) {
		return head;
	}
	ListNode* retNode = new ListNode(0);
	retNode->next = head;
	ListNode* preNode = retNode, *curNode = head, *temp = nullptr;
	int length = 0;
	while (head) {
		length++;
		head = head->next;
	}
	// �ֶ�ʹ��ͷ�巨��������
	for (int i = 0; i < length / k; ++i) {
		// preNode��Ϊÿһ�������ͷ�ڵ㣬��������
		for (int j = 1; j < k; j++) {
			temp = curNode->next;
			curNode->next = temp->next;
			temp->next = preNode->next;
			preNode->next = temp;
		}
		// ÿ�������з�����ɣ�preNode,curNode��Ҫ���µ���һ�����е�ͷ��
		preNode = curNode;
		curNode = curNode->next;
	}
	return retNode->next;
}

