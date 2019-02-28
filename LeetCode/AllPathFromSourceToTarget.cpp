//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
#include <vector>
using namespace std;

void findWay(vector<int>& path, vector<vector<int>>& graph, int node, vector<vector<int> >& ret) {
	if (node == graph.size() - 1) {
		ret.push_back(path);
		return;
	}
	for (auto i : graph[node]) {
		path.push_back(i);
		findWay(path, graph, i, ret);
		path.pop_back();
	}
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
	vector<vector<int> > ret;
	vector<int> path;
	path.push_back(0);
	for (auto i : graph[0]) {
		path.push_back(i);
		findWay(path, graph, i, ret);
		path.pop_back();
	}
	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<vector<int> > data = { {1,2},{3},{3},{} };
	allPathsSourceTarget(data);
	return 0;
}