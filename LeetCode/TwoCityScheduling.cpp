#define LOCAL
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int twoCitySchedCost(vector<vector<int>>& costs) {
	int ret = 0;
	vector<int> dif;
	for (const auto i : costs) { 
		ret += i[0]; 
		dif.push_back(i[1] - i[0]);
	}
	sort(dif.begin(), dif.end(), [](int a,int b) {
		return a < b;
	});
	for (int i = 0; i < dif.size() / 2; i++) { ret += dif[i]; }

	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<vector<int> > costs = { {259,770},{448,54},{926,667},{184,139},{840,118},{577,469} };

	twoCitySchedCost(costs);
	return 0;
}