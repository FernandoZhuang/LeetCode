#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//ListNode* res;

//ListNode* recursive(ListNode* node) {
//	if (!(node->next)) {
//		res = node;
//		return node;
//	}
//
//	auto ret = recursive(node->next);
//	ret->next = node;
//
//	return node;
//}

ListNode* reverseList(ListNode* head) {
	//Plan A Iterative
	/*if (!head) { return NULL; }

	ListNode* tmp;
	stack<ListNode*> sk;
	while (head) {
		sk.push(head);
		head = head->next;
	}
	tmp = head = sk.top(), sk.pop();
	while (!sk.empty()) {
		tmp->next = sk.top(), sk.pop();
		tmp = tmp->next;
	}
	tmp->next = NULL;

	return head;*/

	//Plan B Recursive
	/*if (!head) { return NULL; }
	auto ret = recursive(head);
	ret->next = NULL;

	return res;*/

	//Plan C Iterative 
	ListNode* cur = head;
	ListNode* next = NULL, *prev = NULL;
	while (cur) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	return prev;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif

	return 0;
}