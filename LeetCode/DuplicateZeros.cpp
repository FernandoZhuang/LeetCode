#define LOCAL
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

void duplicateZeros(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) 
		if (!arr[i]) {
			arr.insert(arr.begin() + i, 0);
			arr.pop_back();
			i++;
		}

	return;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<int> arr = { 1,2,3,0 };

	duplicateZeros(arr);

	return 0;
}