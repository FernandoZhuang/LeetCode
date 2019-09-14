#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <string>
using namespace std;

//bool judgeSubstrings(string s, int start, int end) {
//	for (start, end; start <= end; start++, end--) 
//		if (s[start] != s[end]) { return false; }
//
//	return true;
//}
//
//int countSubstrings(string s) {
//	int sz = s.size();
//	int cnt = 0;
//
//	if (!sz) { return 0; }
//
//	for (int i = 1; i <= sz; i++) 
//		for (int j = 0; j + i <= sz; j++) 
//			cnt += judgeSubstrings(s, j, j + i - 1) == true ? 1 : 0;
//
//	return cnt;
//}


// Plan B
int countSubstrings(string s) {
	int res = 0;

	for (int i = 0; i < s.size(); i++) {
		for (int left = i, right = i; left >= 0 && right < s.size() && s[left] == s[right]; left--, right++) { res++; }
		for (int left = i, right = i + 1; left >= 0 && right < s.size() && s[left] == s[right]; left--, right++) { res++; }
	}

	return res;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	string s = "abc";

	countSubstrings(s);

	return 0;
}