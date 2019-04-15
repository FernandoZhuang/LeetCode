#include <iostream>
using namespace std;

bool divisorGame(int N) {
	return (!(N & 1));
}

int main() {
	int N = 2;
	divisorGame(N);

	return 0;
}