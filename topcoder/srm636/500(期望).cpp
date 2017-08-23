#include <bits/stdc++.h>
using namespace std;
#define sz(x)  (int)((x).size())
#define pb push_back
const int N = 25;
double c[N * N][N * N], dis[N * N][N * N];
vector<int> x, y;
class ClosestRabbit {
    public:
	double getExpected(vector <string> board, int r) {
		int h = sz(board);
		int w = sz(board[0]);
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				if (board[i][j] == '.') {
					x.pb(i);
					y.pb(j);
				}
		int n = sz(x);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				int dx = x[i] - x[j];
				int dy = y[i] - y[j];
				dis[i][j] = dx * dx + dy * dy;
			}
		memset(c, 0, sizeof(c));
		for (int i = 0; i <= n; ++i) {
			c[i][0] = 1;
			for (int j = 1; j <= i; ++j)	c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
		double ans = 0.0;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j) {
				int cnt = 0;
				for (int k = 0; k < n; ++k) {
					bool ok = 1;
					if ((k == i) || (k == j))	continue;
					if ((dis[k][j] < dis[i][j]) || (dis[k][j] == dis[i][j] && k < i))	ok = 0;
					if ((dis[i][k] < dis[j][i]) || (dis[i][k] == dis[j][i] && k < j))	ok = 0;
					if (!ok)	++cnt;
				}
				ans += c[n - 2 - cnt][r - 2] / c[n][r];
			}
		return ans;
	}
};
