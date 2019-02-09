#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int uniqueMorseRepresentations(vector<string>& words) {
	vector<string> word = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
	unordered_set<string> res;
	for (auto str : words) {
		string tmp;
		for (auto ch : str)
			tmp += word[ch - 'a'];
		res.insert(tmp);
	}
	return res.size();
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	vector<string> words(4);
	for (int i = 0; i < 4; i++)
		cin >> words[i];
	cout << uniqueMorseRepresentations(words);
	return 0;
}