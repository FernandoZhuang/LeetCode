#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <vector>
using namespace std;

vector<int> distributeCandies(int candies, int num_people) {
	vector<int> res(num_people, 0);

	for (int i = 0;; i++) {
		int tmp, start = i * num_people + 1;
		tmp = start;

		for (int j = 0; j < num_people; j++) {
			if (candies >= tmp) { 
				res[j] += tmp; 
				candies -= (tmp++);
			}
			else { 
				res[j] += candies; 
				candies = 0;
			}
			if (!candies) { return res; }
		}
	}

	return res;
}

int main() {
	int candies = 7, num_people = 4;

	distributeCandies(candies, num_people);

	return 0;
}