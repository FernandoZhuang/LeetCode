#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <string>
#include <map>
using namespace std;

int numJewelsInStones(string J, string S) {
	int res = 0;
	map<char, int> record;
	for (int i = 0; i < S.size(); i++)
		record[S[i]]++;
	for (int i = 0; i < J.size(); i++)
		res += record[J[i]];
	return res;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	string str1, str2;
	cin >> str1 >> str2;
	cout << numJewelsInStones(str1, str2);
	return 0;
}