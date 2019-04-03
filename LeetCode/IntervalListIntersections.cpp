#define LOCAL
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
 
//void judge(const Interval a, const Interval b, vector<int> data, vector<Interval> &ret) {
//	Interval node;
//	if (a.start == data[2] && data[2] != data[1]) { return; }
//	else {
//		node.start = a.start > b.start ? a.start : b.start, node.end = b.end;
//		ret.push_back(node);
//	}
//}
//
//vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
//	vector<Interval> ret;
//	for (int i = 0, j = 0; i < A.size() && j < B.size();) {
//		vector<int> data;
//		data.push_back(A[i].start), data.push_back(A[i].end);
//		data.push_back(B[j].start), data.push_back(B[j].end);
//		sort(data.begin(), data.end());
//		if (A[i].end != B[j].end) {
//			if (*data.rbegin() == A[i].end) {
//				judge(A[i], B[j], data, ret);
//				j++;
//			}
//			else {
//				judge(B[j], A[i], data, ret);
//				i++;
//			}
//		}
//		else {
//			Interval node;
//			node.start = A[i].start < B[j].start ? B[j].start : A[i].start, node.end = A[i].end;
//			ret.push_back(node);
//			i++, j++;
//		}
//	}
//
//	return ret;
//}

//Plan B
vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
	vector<Interval> ret;
	int mx = 0, mn = 0;
	for (int i = 0, j = 0; i < A.size() && j < B.size(); i++, j++) {
		mx = max(A[i].start, B[j].start);
		mn = min(A[i].end, B[j].end);
		if (mx <= mn) {
			ret.push_back({ mx,mn });
			if (mn == A[i].end) { i++; }
			else { j++; }
		}
		else {
			if (mx == A[i].start) { j++; }
			else { i++; }
		}
	}
	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	return 0;
}