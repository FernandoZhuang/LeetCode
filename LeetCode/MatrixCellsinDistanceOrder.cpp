class Solution {
public:
	vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
		vector<vector<int> > ret;
		vector<pair<int, int> > dirs = { {0,-1},{0,1},{1,0},{-1,0} };
		queue<pair<int, int> > q;
		vector<vector<bool> > flag(R, vector<bool>(C, false));
		q.push({ r0,c0 }), flag[r0][c0] = true;
		while (!q.empty()) {
			int sz = q.size();
			for (int i = 0; i < sz; i++) {
				pair<int, int> cur = q.front();
				q.pop();
				ret.push_back({ cur.first,cur.second });

				for (int j = 0; j < 4; j++) {
					int r = cur.first + dirs[j].first, c = cur.second + dirs[j].second;
					if (r >= 0 && r < R && c >= 0 && c < C && !flag[r][c]) { q.push({ r,c }), flag[r][c] = true; }
				}
			}
		}

		return ret;
	}
};