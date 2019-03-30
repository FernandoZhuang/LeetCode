#define LOCAL
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
void traversal(ListNode* head, int *cnt) {
	if (!head) { return; }
	*cnt = *cnt + 1;
	traversal(head->next, cnt);
}

ListNode* judge(ListNode* head, int cur, const int cnt, const int flag) {
	if (flag) { if (cur == (cnt + 1) / 2) { return head; } }
	else if (cur == (cnt / 2 + 1)) { return head; }
	return judge(head->next, cur + 1, cnt, flag);
}

ListNode* middleNode(ListNode* head) {
	int cnt = 0, cur = 1;
	traversal(head, &cnt);
	int flag = cnt & 1;
	return judge(head, cur, cnt, flag);
}

int main() {
	
	return 0;
}