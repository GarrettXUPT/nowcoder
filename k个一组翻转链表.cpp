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
	// 分段使用头插法将链表反序
	for (int i = 0; i < length / k; ++i) {
		// preNode作为每一段链表的头节点，负责连接
		for (int j = 1; j < k; j++) {
			temp = curNode->next;
			curNode->next = temp->next;
			temp->next = preNode->next;
			preNode->next = temp;
		}
		// 每个子序列反序完成，preNode,curNode需要更新到下一个序列的头部
		preNode = curNode;
		curNode = curNode->next;
	}
	return retNode->next;
}

