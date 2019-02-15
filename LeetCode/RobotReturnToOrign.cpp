#include <string>
using namespace std;

class Solution {
public:
	bool judgeCircle(string moves) {
		int hori = 0, vert = 0;
		for (auto i : moves) {
			if (i == 'U' || i == 'D')
				vert += i == 'U' ? 1 : -1;
			else
				hori += i == 'R' ? 1 : -1;
		}
		return (hori == 0 && vert == 0);
	}
};