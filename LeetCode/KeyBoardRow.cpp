#define LOCAL
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

vector<string> findWords(vector<string>& words) {
	vector<string> res;
	vector<unordered_set<char> > ref(3);
	ref[0] = { 'q' ,'w','e','r','t','y','u','i','o','p' };
	ref[1] = { 'a','s','d','f','g','h','j','k','l' };
	ref[2] = { 'z','x','c','v','b','n','m' };
	for (auto i : words) {
		int flag = 0, judge = 1;
		char tmp = tolower(i[0]);
		if (ref[0].find(tmp) != ref[0].end()) { flag = 0; }
		else if (ref[1].find(tmp) != ref[1].end()) { flag = 1; }
		else if (ref[2].find(tmp) != ref[2].end()) { flag = 2; }
		for (auto j : i) {
			if (ref[flag].find(tolower(j)) == ref[flag].end()) {
				judge = 0;
				break;
			}
		}
		if (judge == 1) { res.push_back(i); }
	}
	return res;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<string> words = { "Hello", "Alaska", "Dad", "Peace" };
	findWords(words);
	return 0;
}