#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <string>
using namespace std;

string toLowerCase(string str) {
	string ans;
	int dis = 'A' - 'a';
	for (char c : str) 
		ans += (c >= 'A' &&  c <= 'Z') ? c - dis : c;
	return ans;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	string str;
	cin >> str;
	cout << toLowerCase(str);
	return 0;
}