#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int tribonacci(int n) {
	int tmp = 0;
	int q0 = 0, q1 = 1, q2 = 1;

	if (n < 3) { return n == 2 ? 1 : n; }
	for (int flag = 2; flag < n ; flag++) {
		tmp = q0 + q1 + q2;
		q0 = q1, q1 = q2, q2 = tmp;
	}

	return q2;
}

int main() {
	int n = 25;

	tribonacci(n);

	return 0;
}