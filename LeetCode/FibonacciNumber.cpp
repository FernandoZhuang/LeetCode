class Solution {
public:
	int fib(int N) {
		int x0 = 0, x1 = 1, tmp;
		if (!N) { return x0; }
		for (int i = 1; i < N; i++) {
			tmp = x0 + x1;
			x0 = x1, x1 = tmp;
		}
		return x1;
	}
};