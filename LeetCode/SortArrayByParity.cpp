#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		vector<int> odd, even;
		for (auto i : A) {
			if (i % 2 == 0)
				even.push_back(i);
			else
				odd.push_back(i);
		}
		for (auto i : odd)
			even.push_back(i);
		return even;
	}
	vector<int> sortArrayByParitySwap(vector<int>& A) {
		int oddFlag = 0;
		for (int i = 0; i < A.size(); i++)
			if(A[i] % 2 == 0)
				swap(A[i], A[oddFlag++]);
		return A;
	}
};