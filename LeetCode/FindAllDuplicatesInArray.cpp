#define LOCAL
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
	/*vector<int> res;
	set<int> data;
	map<int, int> mp;
	for (auto i : nums) { 
		mp[i]++; 
		data.insert(i);
	}
	for (auto i : data)
		if (mp[i] > 1)
			res.push_back(i);

	return res;*/

	//Plan B
	/*vector<int> res;
	if (nums.empty()) { return {}; }
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 1;) {
		if (nums[i] == nums[i + 1]) { 
			res.push_back(nums[i]); 
			i = i + 2;
		}
		else { i++; }
	}

	return res;*/

	//Plan C
	/*vector<int> res = {};
	map<int, int> mp;
	for (auto i : nums)
		if (++mp[i] == 2)
			res.push_back(i);
	

	return res;*/

	//Plan D
	vector<int> res = {};
	for (auto i : nums) {
		nums[abs(i) - 1] *= -1;
		if (nums[abs(i) - 1] > 0) { res.push_back(abs(i)); }
	}

	return res;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<int> nums = { 4,3,2,7,8,2,3,1 };
	findDuplicates(nums);
	return 0;
}