#define LOCAL
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

vector<string> subdomainVisits(vector<string>& cpdomains) {
	vector<string> ret;
	unordered_map<string, int> data;
	int cnt, pos;
	string domain;
	for (auto i : cpdomains) {
		stringstream ss(i);
		ss >> cnt >> domain;
		data[domain] += cnt;
		while ((pos = domain.find('.')) != std::string::npos) {
			domain = domain.substr(pos + 1);
			//domain.assign(domain.begin() + pos + 1, domain.end());
			data[domain] += cnt;
		}
	}
	for (auto i : data) { ret.push_back(to_string(i.second) + " " + i.first); }
	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<string> cpdomains = { {"9001 discuss.leetcode.com"} };
	subdomainVisits(cpdomains);
	return 0;
}