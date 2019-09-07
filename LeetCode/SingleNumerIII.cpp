#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
#include <unordered_set>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
	/*vector<int> res;
	unordered_set<int> unique_num;
	
	for (const auto& i : nums) {
		if (unique_num.empty() || unique_num.find(i) == unique_num.end()) { unique_num.insert(i); }
		else { unique_num.erase(i); }
	}
	res.assign(unique_num.begin(), unique_num.end());

	return res;*/

	//Pass 1 :
	// Get the XOR of the two numbers we need to find
	int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
	// Get its last set bit
	diff &= -diff;

	// Pass 2 :
	vector<int> rets = { 0, 0 }; // this vector stores the two numbers we will return
	for (int num : nums)
	{
		if ((num & diff) == 0) // the bit is not set
		{
			rets[0] ^= num;
		}
		else // the bit is set
		{
			rets[1] ^= num;
		}
	}
	return rets;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<int> nums = { 1,2,1,3,2,5 };
	singleNumber(nums);

	return 0;
}