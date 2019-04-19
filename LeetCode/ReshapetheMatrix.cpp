#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
	if (r > 10000 || c > 10000 || r * c > 10000 || nums.size()*nums[0].size() != r * c) { return nums; }

	vector<int> tmp;
	for (const auto i : nums)
		for (const auto j : i)
			tmp.push_back(j);

	int cnt = 0;
	vector<vector<int> > ret(r, vector<int>(c, 0));
	for(int i=0;i<r;i++)
		for (int j = 0; j < c; j++) 
			ret[i][j] = tmp[cnt++];

	return ret;
}

int main{
	

}