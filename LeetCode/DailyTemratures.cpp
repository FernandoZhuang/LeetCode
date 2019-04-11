#define LOCAL
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<int> dailyTemperatures(vector<int>& T) {
	//Plan A Time Limit Exceed
	/*int sz = T.size();
	vector<int> ret = {};

	for (int i = 0; i < sz; i++) {
		int j = i + 1;
		while (j < sz && T[i] >= T[j]) { j++; }
		if (j >= sz) { ret.push_back(0); }
		else { ret.push_back(j - i); }
	}

	return ret;*/

	//Plan B fail
	/*int sz = T.size();
	vector<int> ret = {};
	set<int> st;
	map<int, vector<int> > pos;

	for (int i = 0; i < sz;i++) {
		st.insert(T[i]);
		pos[T[i]].push_back(i);
	}
	for (int i = 0; i < sz; i++) {
		set<int>::iterator it = st.find(T[i]);
		if (++it != st.end()) {
			int j = 0, posz = pos[*it].size();
			while (j < posz && pos[*it][j] < i) { j++; }
			if (j == posz) { ret.push_back(0); }
			else { ret.push_back(pos[*it][j] - i); }
		}
		else { ret.push_back(0); }
	}

	return ret;*/

	//Plan C fail
	/*int sz = T.size();
	vector<int> ret(sz, 0);
	vector<bool> flag(sz, false);
	set<int> st;
	map<int, vector<int> > pos;

	for (int i = 0; i < sz; i++) {
		st.insert(T[i]);
		pos[T[i]].push_back(i);
	}
	for (set<int>::reverse_iterator it = st.rbegin() ; it != st.rend(); it++) {
		while (!pos[*it].empty()) {
			set<int>::reverse_iterator tmp = it;
			int cur = *pos[*it].crbegin();
			flag[cur] = true;
			if (cur - 1 >= 0 && !flag[cur - 1] && T[cur] != T[cur - 1])
				ret[cur - 1] = 1, flag[cur - 1] = true;
			if (++tmp != st.rend()) 
				for (int i = 0; i < pos[*tmp].size(); i++) {
					int licur = pos[*tmp][i];
					if (cur > licur) {
						if (!ret[licur]) { ret[licur] = cur - licur; }
						else if (ret[licur] > cur - licur) { ret[licur] = cur - licur; }
					}
				}
			pos[*it].pop_back();
		}
	}

	return ret;*/

	//Plan D DP
	vector<int> ret(T.size(), 0);
	for (int i = T.size() - 1; i >= 0; i--) {
		int j = i + 1;
		while (j<T.size() && T[i] >= T[j]) {
			if (ret[j] > 0) { j = j + ret[j]; }
			else { j = T.size(); }
		}
		if (j < T.size()) { ret[i] = j - i; }
	}

	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<int> T = { 73, 74, 75, 71, 69, 72, 76, 73 };
	dailyTemperatures(T);
	return 0;
}