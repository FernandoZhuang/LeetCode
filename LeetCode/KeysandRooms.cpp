#define LOCAL
#include <iostream>
#include <vector>
using namespace std;

int cnt = 1;
vector<bool> flag;
vector<vector<int> > cp = {};

void helper(int num) {
	if (flag[num]) { return; }

	cnt++, flag[num] = true;
	for (int i = 0; i < cp[num].size(); i++)
		helper(cp[num][i]);
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
	cp = rooms;
	flag.resize(rooms.size(), false);
	flag[0] = true;

	for (int i = 0; i < rooms[0].size(); i++) 
		helper(rooms[0][i]);

	return cnt == rooms.size();
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<vector<int> > rooms = { {1,3},{3,0,1},{2},{0} };
	canVisitAllRooms(rooms);
	return 0;
}