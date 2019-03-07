class Solution {
public:
	int peakIndexInMountainArray(vector<int>& A) {
		int tmpret = 0, ret = 0;
		for (int i = 0; i < A.size(); i++) {
			tmpret = A[i] > A[A.size() - 1 - i] ? i : (A.size() - 1 - i);
			if (A[tmpret] < A[ret]) { break; }
			ret = tmpret;
		}
		return ret;
	}
};