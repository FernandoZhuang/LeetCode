#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <vector>
using namespace std;

//Plan A
//vector<vector<int> > res;
//vector<int> record;

//vector<vector<int>> permute(vector<int>& nums) {
//	vector<int> tmp;
//
//	if (nums.size() == 1) {
//		record.push_back(nums[0]);
//		res.push_back(record);
//		record.pop_back();
//		return res;
//	}
//
//	for (int i = 0; i < nums.size(); i++) {
//		swap(nums[0], nums[i]);
//		record.push_back(nums[0]);
//		tmp.assign(nums.begin() + 1, nums.end());
//		permute(tmp);
//		record.pop_back();
//		swap(nums[0], nums[i]);
//	}
//
//	return res;
//}

//Plan B
void recursive(vector<int>& num, int idx, vector<vector<int>>& res) {
	if (idx >= num.size()) {
		res.push_back(num);
		return;
	}

	for (int i = idx; i < num.size(); i++) {
		swap(num[idx], num[i]);
		recursive(num, idx + 1, res);
		swap(num[idx], num[i]);
	}
}

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> res;

	recursive(nums, 0, res);

	return res;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<int> nums = { 1,2,3 };

	permute(nums);

	return 0;
}