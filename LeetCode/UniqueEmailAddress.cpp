#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int numUniqueEmails(vector<string>& emails) {
	int res = 0;
	map<string, map<string, int> > record;
	for (int i = 0; i < emails.size(); i++) {
		string tmp, tmp1, tmp2;
		tmp.assign(emails[i].begin() + emails[i].find('@'), emails[i].end());
		tmp1.assign(emails[i].begin(), emails[i].begin() + (emails[i].find('+') == string::npos ?emails[i].find('@') : emails[i].find('+')));
		for (int i = 0; i < tmp1.size(); i++)
			if (tmp1[i] != '.')
				tmp2 += tmp1[i];
		if (record[tmp][tmp2] == 0) {
			res++;
			record[tmp][tmp2]++;
		}
	}
	return res;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	vector<string> email(3);
	for (int i = 0; i < 3; i++)
		cin >> email[i];
	cout << numUniqueEmails(email);
	return 0;
}