class Solution {
public:
	vector<int> diStringMatch(string S) {
		vector<int> res;
		int smallest = 0, largest = S.size();
		for (int i = 0; i < S.size(); i++) {
			if (S[i] == 'I') {
				res.push_back(smallest);
				smallest++;
			}
			else {
				res.push_back(largest);
				largest--;
			}
		}
		res.push_back(smallest);
		return res;
	}
};