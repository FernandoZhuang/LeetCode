class Solution {
public:
	vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
		vector<string> res;
		for (auto i : words) {
			bool flag = true;
			map<char, char> recordp, recordw;
			for (int j = 0; j < pattern.size(); j++) {
				if (!recordp[pattern[j]] && !recordw[i[j]])
					recordp[pattern[j]] = i[j], recordw[i[j]] = pattern[j];
				else if (recordp[pattern[j]] != i[j] && recordw[i[j]] != pattern[j]) {
					flag = false;
					break;
				}
			}
			if (flag)
				res.push_back(i);
		}
		return res;
	}
};