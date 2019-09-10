#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
	if (start == destination) { return 0; }

	int res = 0, sum = 0;
	sum = accumulate(distance.begin(), distance.end(), 0);
	if (start > destination) { swap(start, destination); }
	for (int i = start; i < destination; i++) { res += distance[i]; }

	return res = res < (sum - res) ? res : (sum - res);
}

int main() {

	return 0;
}