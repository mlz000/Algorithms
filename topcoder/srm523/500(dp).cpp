#include <bits/stdc++.h>
using namespace std;
const int N = 55, M = 1e9 + 7;
int dp[N][N], a[N];
class BricksN {
	public:
	int k;
	int ways(int w) {
		if (!w)	return 1;
		if (w < 0)	return 0;
		int &t = a[w];
		if (t == -1)	{
			t = 0;
			for (int i = 1; i <= k; ++i)	{
				t += ways(w - i);
				if (t >= M)	t -= M;
			}
		}
		return t;
	}
	int f(int w, int h) {
		if (!w || !h)	return 1;
		int &t = dp[w][h];
		if (t == -1) {
			t = (long long)ways(w) * f(w, h - 1) % M;
			for (int i = 0; i < w; ++i) {
				t += (long long)f(i, h) * ways(w - i - 1) % M * f(w - i - 1, h - 1) % M;
				if (t >= M)	 t -= M;
			}
		}
		return t;
	}
	int countStructures(int w, int h, int k) {
		memset(dp, -1, sizeof(dp));
		memset(a, -1, sizeof(a));
		this -> k = k;
		return f(w, h);
	}
};
