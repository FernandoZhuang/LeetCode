#define LOCAL
#include <iostream>
#include <string>
using namespace std;

string reverseWords(string s) {
	//Plan A
	/*int val = 0;
	string tmp = s;
	while (1) {
		size_t pos = tmp.find(' ');
		if (pos == std::string::npos) { 
			reverse(s.begin() + val, s.end());
			return s;
		}
		reverse(s.begin() + val, s.begin() + val + pos);
		val += pos + 1;
		tmp = s.substr(val);
	}*/
	//Plan B
	size_t pos = s.find(' ');
	size_t prepos = 0;
	if (s == "") { return ""; }
	while (pos != std::string::npos) {
		reverse(s.begin() + prepos, s.begin() + pos);
		prepos = pos + 1;
		pos = s.find(' ', prepos);
	}
	reverse(s.begin() + prepos, s.end());
	return s;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	string s = "Let's take LeetCode contest";
	reverseWords(s);
	return 0;
}