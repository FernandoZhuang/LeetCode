#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
	if (nums.empty()) { return 0; }

	for (int i = 0; i < nums.size() - 1;) {
		if (nums[i] != nums[i + 1]) { return nums[i]; }
		i += 2;
	}

	return *nums.rbegin();
}

int main( ){

	return 0;
}