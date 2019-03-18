#define LOCAL
#include <iostream>
#include <vector>
using namespace std;

int numPairsDivisibleBy60(vector<int>& time) {
	/*int ret = 0;
	for (int i = 0; i < time.size(); i++) 
		for (int j = i + 1; j < time.size(); j++)
			if ((time[i] + time[j]) % 60 == 0) { ret++; }
	return ret;*/
	int ret = 0;
	vector<int> data(60, 0);
	for (auto i : time) { data[i % 60]++; }
	for (int i = 1; i < 30; i++) { ret += data[i] * data[60 - i]; }
	for (int i = 1; i < data[0]; i++) { ret += i; }
	for (int i = 1; i < data[30]; i++) { ret += i; }
	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<int> time = { 60,60,60 };
	numPairsDivisibleBy60(time);
	return 0;
}