#define LOCAL
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <list>
using namespace std;

vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
	sort(people.begin(), people.end(), [](pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) { return a.second < b.second; }
		else { return a.first > b.first; }
	});
	//Plan A vector
	/*vector<pair<int, int> > ret = {};
	for (const auto i : people) {
		if (ret.empty() || i.second >= ret.size()) { ret.push_back(i); }
		else { ret.insert(ret.begin() + i.second, i); }
	}
	
	return ret;
	*/

	//Plan B list
	list<pair<int, int> > res = {};
	for (const auto & i : people)
		res.insert(next(res.begin(), i.second), i);

	vector<pair<int, int> > ret(res.begin(), res.end());
	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<pair<int, int> > people = { {7,0},{4,4},{7,1},{5,0},{6,1},{5,2} };
	reconstructQueue(people);

	return 0;
}