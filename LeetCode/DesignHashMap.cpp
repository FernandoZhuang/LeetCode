#define LOCAL
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

vector<int> table;

/** Initialize your data structure here. */
MyHashMap() {
	table.assign(1000001, -1);
}

/** value will always be non-negative. */
void put(int key, int value) {
	table[key] = value;
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int get(int key) {
	return table[key];
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void remove(int key) {
	table[key] = -1;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif

	return 0;
}