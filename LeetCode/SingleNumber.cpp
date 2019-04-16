#define LOCAL
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int singleNumber(vector<int>& nums) {
	/*unordered_map<int, int> up;
	for (int i = 0; i < nums.size(); i++) {
		up[nums[i]]++;
		if (up[nums[i]] == 2) { up.erase(nums[i]); }
	}

	return up.begin()->first;*/

	int ret = 0;
	for (const auto i : nums) { ret ^= i; }

	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<int> nums = { 4,1,2,1,2 };
	singleNumber(nums);

	return 0;
}