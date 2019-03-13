#define LOCAL
#include <iostream>
#include <vector>
using namespace std;

vector<int> sortArrayByParityII(vector<int>& A) {
	/*for (int i = 0; i < A.size(); i++) {
		if (i & 1) {
			if (A[i] & 1) { continue; }
			for(int j=i+1;j<A.size();j++)
				if (A[j] & 1) {
					swap(A[i], A[j]);
					break;
				}
		}
		else {
			if (!(A[i] & 1)) { continue; }
			for(int j=i+1;j<A.size();j++)
				if (!(A[j] & 1)) {
					swap(A[i], A[j]);
					break;
				}
		}
	}
	return A;*/
	for (int i = 0; i < A.size(); i++) {
		if (((i & 1) && (A[i] & 1)) || (!(A[i] & 1) && !(i & 1))) { continue; }
		for (int j = i + 1; j < A.size(); j++) 
			if (((i & 1) && (A[j] & 1)) || (!(A[j] & 1) && !(i & 1))) {
				swap(A[i], A[j]);
				break;
			}
	}
	return A;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<int> A = { 4,2,5,7 };
	sortArrayByParityII(A);
	return 0;
}