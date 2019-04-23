#include <iostream>
using namespace std;

bool hasAlternatingBits(int n) {
	if (n <= 0) { return false; }

	int flag = n & 1;
	n = n >> 1;
	while (n) {
		if (flag == (n & 1)) { return false; }
		flag = n & 1;
		n = n >> 1;
	}

	return true;
}

int main() {
	int n = 10;
	hasAlternatingBits(n);

	return 0;
}