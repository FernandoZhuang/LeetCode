#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
	vector<vector<int> > res(text1.size() + 1, vector<int>(text2.size() + 1, 0));
	for (int i = 1; i <= text1.size(); i++) {
		for (int j = 1; j <= text2.size(); j++) {
			if (text1[i - 1] == text2[j - 1]) { res[i][j] = res[i - 1][j - 1] + 1; }
			else { res[i][j] = max(res[i - 1][j], res[i][j - 1]); }
		}
	}

	return res[text1.size()][text2.size()];
}

int main() {
	string text1 = "mhunuzqrkzsnidwbun", text2 = "szulspmhwpazoxijwbq";

	longestCommonSubsequence(text1, text2);

	return 0;
}