#define LOCAL
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> fizzBuzz(int n) {
	vector<string> ret = {};
	
	if (!n) { return ret; }
	for (int i = 1; i <= n; i++) {
		int mod3 = i % 3, mod5 = i % 5;
		if (mod3 != 0 && mod5 != 0) { ret.push_back(to_string(i)); }
		else {
			if (mod3 == 0 && mod5 == 0) { ret.push_back("FizzBuzz"); }
			else if (mod3 == 0) { ret.push_back("Fizz"); }
			else if (mod5 == 0) { ret.push_back("Buzz"); }
		}
	}

	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif

	return 0;
}