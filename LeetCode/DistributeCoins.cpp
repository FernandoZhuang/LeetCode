#define LOCAL
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int distributeCandies(vector<int>& candies) {
	unordered_set<int> st;
	for (const auto & i : candies) { st.insert(i); }
	int sz = st.size(), num = candies.size() / 2;
	return sz >= num ? num : sz;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<int> candies = { 1,1,2,2,3,3 };
	distributeCandies(candies);


	return 0;
}