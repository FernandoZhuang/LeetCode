#define LOCAL
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sumup;

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
	int cnt = 1;
	vector<int> idx;
	vector<vector<int> > ret;
	for (int i = 0; i < points.size(); i++) {
		sumup.push_back(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
		idx.push_back(i);
	}
	sort(idx.begin(), idx.end(), [&](int a, int b) {return sumup[a] < sumup[b]; });
	for (int i = 0; i < K && i < idx.size(); i++) { ret.push_back(points[idx[i]]); }
	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<vector<int> > points = { {3,3},{5,-1},{-2,4} };
	int K = 2;
	kClosest(points, K);
	return 0;
}