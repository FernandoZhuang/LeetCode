class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		int ret = 0;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 1; i = i + 2) { ret += nums[i]; }
		return ret;
	}
};