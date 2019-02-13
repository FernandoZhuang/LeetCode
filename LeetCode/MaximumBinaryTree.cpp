#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool Cmp(int A, int B) {
	return A > B;
}

TreeNode* buildTree(TreeNode* head, int val, map<int, int>& seq) {
	if (head == NULL) {
		head = new TreeNode(val);
		return head;
	}
	if (seq[val] < seq[head->val])
		head->left = buildTree(head->left, val, seq);
	else if (seq[val] > seq[head->val])
		head->right = buildTree(head->right, val, seq);
	return head;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
	map<int, int> seq;
	for (int i = 0; i < nums.size(); i++)
		seq[nums[i]] = i;

	sort(nums.begin(), nums.end(), Cmp);

	TreeNode* head = new TreeNode(*nums.begin());
	for (auto i : nums) {
		if (i == *nums.begin()) 
			continue;
		else
			buildTree(head, i, seq);
	}
	return head;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	//HACK: 数据读入 存储于Num的值很奇怪
	vector<int> num(6);
	for (int i = 0; i < 6; i++)
		cin >> num[i];
	constructMaximumBinaryTree(num);
	return 0;
}